#pragma once
#include <GL/glew.h>
#include <vector>

struct VertexBufferElement {
	unsigned int locationPos; // 顶点属性位置
    unsigned int count;  // 分量数（例如 3 表示 vec3）
    unsigned int type;   // 数据类型（例如 GL_FLOAT）
    unsigned char normalized; // 是否归一化
	unsigned int stride; // 偏移量
	unsigned int beginPos; // 起始位置

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
    std::vector<VertexBufferElement> m_Elements; // 存储顶点属性
    unsigned int m_Stride; // 顶点数据之间的字节偏移

public:
    VertexBufferLayout() : m_Stride(0) {}

    // 添加顶点属性
    template<typename T>
    void Push(unsigned int count) {
        static_assert(false); // 默认情况下不支持
    }

    // 特化模板：支持 float 类型
    template<>
    void Push<float>(unsigned int count) {
        m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
        m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
    }

    // 特化模板：支持 unsigned int 类型
    template<>
    void Push<unsigned int>(unsigned int count) {
        m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
        m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
    }

    // 特化模板：支持 unsigned char 类型
    template<>
    void Push<unsigned char>(unsigned int count) {
        m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
        m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
    }

    // 获取顶点属性列表
    inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }

    // 获取步长（stride）
    inline unsigned int GetStride() const { return m_Stride; }
};