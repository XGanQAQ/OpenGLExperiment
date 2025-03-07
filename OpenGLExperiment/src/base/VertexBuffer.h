#pragma once
#include "..\include\GL\glew.h"

class VertexBuffer
{
public:
    // ���캯��
    VertexBuffer(const float* data, GLsizeiptr size);

    // ��������
    ~VertexBuffer();

    // ���ÿ������캯���Ϳ�����ֵ�����
    VertexBuffer(const VertexBuffer&) = delete;
    VertexBuffer& operator=(const VertexBuffer&) = delete;

    // �ƶ����캯��
    VertexBuffer(VertexBuffer&& other) noexcept;

    // �ƶ���ֵ�����
    VertexBuffer& operator=(VertexBuffer&& other) noexcept;

    // �� VBO
    void bind() const;

    // ��� VBO
    void unbind() const;

    // ���»���������
    void updateData(const float* data, GLsizeiptr size, GLenum usage = GL_STATIC_DRAW);

    // ��ȡ VBO ID
    GLuint getID() const;

    // ��ȡ��������С
    GLsizeiptr getSize() const;

private:
    GLuint vboID = 0;       // VBO ID
    GLsizeiptr size = 0;     // ��������С
};