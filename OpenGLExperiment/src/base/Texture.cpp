// Texture.cpp
#include "Texture.h"

// 构造函数
Texture::Texture(const std::string& filePath)
    : m_FilePath(filePath), m_RendererID(0) {
    // 生成纹理对象
    glGenTextures(1, &m_RendererID);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);

    // 设置纹理参数
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // 使用SOIL2加载图像
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

        // 上传纹理数据
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, image);

        // 生成Mipmap
        glGenerateMipmap(GL_TEXTURE_2D);

        // 释放图像数据
        SOIL_free_image_data(image);
    }
    else {
        std::cerr << "SOIL2加载纹理失败: " << filePath << std::endl;
    }

    // 解绑纹理
    glBindTexture(GL_TEXTURE_2D, 0);
}


// 移动构造函数
Texture::Texture(Texture&& other) noexcept
    : m_RendererID(other.m_RendererID), m_FilePath(std::move(other.m_FilePath)) {
    other.m_RendererID = 0; // 将原对象的渲染ID置为0，防止析构时删除纹理
}

// 移动赋值操作符
Texture& Texture::operator=(Texture&& other) noexcept {
    if (this != &other) {
        // 删除当前纹理
        glDeleteTextures(1, &m_RendererID);

        // 转移资源
        m_RendererID = other.m_RendererID;
        m_FilePath = std::move(other.m_FilePath);

        // 将原对象的渲染ID置为0
        other.m_RendererID = 0;
    }
    return *this;
}

// 析构函数
Texture::~Texture() {
    if (m_RendererID) {
        glDeleteTextures(1, &m_RendererID);
    }
}

// 绑定纹理到指定的纹理单元
void Texture::bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot); // 激活纹理单元
    glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

// 解绑纹理
void Texture::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}