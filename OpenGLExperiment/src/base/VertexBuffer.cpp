#include "VertexBuffer.h"
#include <stdexcept> // 异常处理
#include <iostream>  // 错误输出

// 构造函数
VertexBuffer::VertexBuffer(const float* data, GLsizeiptr size) {
    this->size = size;
    glGenBuffers(1, &vboID);
    if (vboID == 0) {
        throw std::runtime_error("Failed to generate VBO");
    }
    bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

    // 检查 OpenGL 错误
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR) {
        std::cerr << "OpenGL Error: " << err << std::endl;
    }
}

// 析构函数
VertexBuffer::~VertexBuffer() {
    if (vboID != 0) {
        glDeleteBuffers(1, &vboID);
        vboID = 0;
    }
}

// 移动构造函数
VertexBuffer::VertexBuffer(VertexBuffer&& other) noexcept
    : vboID(other.vboID), size(other.size) {
    other.vboID = 0;
    other.size = 0;
}

// 移动赋值运算符
VertexBuffer& VertexBuffer::operator=(VertexBuffer&& other) noexcept {
    if (this != &other) {
        if (vboID != 0) {
            glDeleteBuffers(1, &vboID);
        }
        vboID = other.vboID;
        size = other.size;
        other.vboID = 0;
        other.size = 0;
    }
    return *this;
}

// 绑定 VBO
void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
}

// 解绑 VBO
void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// 更新缓冲区数据
void VertexBuffer::updateData(const float* data, GLsizeiptr size, GLenum usage) {
    bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    this->size = size;
}

// 获取 VBO ID
GLuint VertexBuffer::getID() const {
    return vboID;
}

// 获取缓冲区大小
GLsizeiptr VertexBuffer::getSize() const {
    return size;
}