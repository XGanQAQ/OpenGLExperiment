#pragma once
#include <GL/glew.h>
#include <vector>

struct VertexBufferElement {
	unsigned int locationPos; // ��������λ��
    unsigned int count;  // ������������ 3 ��ʾ vec3��
    unsigned int type;   // �������ͣ����� GL_FLOAT��
    unsigned char normalized; // �Ƿ��һ��
	unsigned int stride; // ƫ����
	unsigned int beginPos; // ��ʼλ��

    static unsigned int GetSizeOfType(unsigned int type) {
        switch (type) {
        case GL_FLOAT:         return 4;
        case GL_UNSIGNED_INT:  return 4;
        case GL_UNSIGNED_BYTE: return 1;
        }
        return 0;
    }
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_Elements; // �洢��������
    unsigned int m_Stride; // ��������֮����ֽ�ƫ��

public:
    VertexBufferLayout() : m_Stride(0) {}

    // ��Ӷ�������
    template<typename T>
    void Push(unsigned int count) {
        static_assert(false); // Ĭ������²�֧��
    }

    // �ػ�ģ�壺֧�� float ����
    template<>
    void Push<float>(unsigned int count) {
        m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
        m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
    }

    // �ػ�ģ�壺֧�� unsigned int ����
    template<>
    void Push<unsigned int>(unsigned int count) {
        m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
        m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
    }

    // �ػ�ģ�壺֧�� unsigned char ����
    template<>
    void Push<unsigned char>(unsigned int count) {
        m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
        m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
    }

    // ��ȡ���������б�
    inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }

    // ��ȡ������stride��
    inline unsigned int GetStride() const { return m_Stride; }
};