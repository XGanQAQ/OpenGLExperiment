// Texture.cpp
#include "Texture.h"

// ���캯��
Texture::Texture(const std::string& filePath)
    : m_FilePath(filePath), m_RendererID(0) {
    // �����������
    glGenTextures(1, &m_RendererID);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);

    // �����������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // ʹ��SOIL2����ͼ��
    int width, height, channels;
    unsigned char* image = SOIL_load_image(filePath.c_str(), &width, &height, &channels, SOIL_LOAD_AUTO);

    if (image) {
        GLenum format;
        if (channels == 1)
            format = GL_RED;
        else if (channels == 3)
            format = GL_RGB;
        else if (channels == 4)
            format = GL_RGBA;

        // �ϴ���������
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, image);

        // ����Mipmap
        glGenerateMipmap(GL_TEXTURE_2D);

        // �ͷ�ͼ������
        SOIL_free_image_data(image);
    }
    else {
        std::cerr << "SOIL2��������ʧ��: " << filePath << std::endl;
    }

    // �������
    glBindTexture(GL_TEXTURE_2D, 0);
}


// �ƶ����캯��
Texture::Texture(Texture&& other) noexcept
    : m_RendererID(other.m_RendererID), m_FilePath(std::move(other.m_FilePath)) {
    other.m_RendererID = 0; // ��ԭ�������ȾID��Ϊ0����ֹ����ʱɾ������
}

// �ƶ���ֵ������
Texture& Texture::operator=(Texture&& other) noexcept {
    if (this != &other) {
        // ɾ����ǰ����
        glDeleteTextures(1, &m_RendererID);

        // ת����Դ
        m_RendererID = other.m_RendererID;
        m_FilePath = std::move(other.m_FilePath);

        // ��ԭ�������ȾID��Ϊ0
        other.m_RendererID = 0;
    }
    return *this;
}

// ��������
Texture::~Texture() {
    if (m_RendererID) {
        glDeleteTextures(1, &m_RendererID);
    }
}

// ������ָ��������Ԫ
void Texture::bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot); // ��������Ԫ
    glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

// �������
void Texture::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}