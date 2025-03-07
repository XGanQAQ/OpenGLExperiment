#pragma once
#include "..\include\GL\glew.h"

class VertexBuffer
{
public:
    // 构造函数
    VertexBuffer(const float* data, GLsizeiptr size);

    // 析构函数
    ~VertexBuffer();

    // 禁用拷贝构造函数和拷贝赋值运算符
    VertexBuffer(const VertexBuffer&) = delete;
    VertexBuffer& operator=(const VertexBuffer&) = delete;

    // 移动构造函数
    VertexBuffer(VertexBuffer&& other) noexcept;

    // 移动赋值运算符
    VertexBuffer& operator=(VertexBuffer&& other) noexcept;

    // 绑定 VBO
    void bind() const;

    // 解绑 VBO
    void unbind() const;

    // 更新缓冲区数据
    void updateData(const float* data, GLsizeiptr size, GLenum usage = GL_STATIC_DRAW);

    // 获取 VBO ID
    GLuint getID() const;

    // 获取缓冲区大小
    GLsizeiptr getSize() const;

private:
    GLuint vboID = 0;       // VBO ID
    GLsizeiptr size = 0;     // 缓冲区大小
};