#include "VertexBuffer.h"
#include <stdexcept> // �쳣����
#include <iostream>  // �������

// ���캯��
VertexBuffer::VertexBuffer(const float* data, GLsizeiptr size) {
    this->size = size;
    glGenBuffers(1, &vboID);
    if (vboID == 0) {
        throw std::runtime_error("Failed to generate VBO");
    }
    bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

    // ��� OpenGL ����
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR) {
        std::cerr << "OpenGL Error: " << err << std::endl;
    }
}

// ��������
VertexBuffer::~VertexBuffer() {
    if (vboID != 0) {
        glDeleteBuffers(1, &vboID);
        vboID = 0;
    }
}

// �ƶ����캯��
VertexBuffer::VertexBuffer(VertexBuffer&& other) noexcept
    : vboID(other.vboID), size(other.size) {
    other.vboID = 0;
    other.size = 0;
}

// �ƶ���ֵ�����
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

// �� VBO
void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
}

// ��� VBO
void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// ���»���������
void VertexBuffer::updateData(const float* data, GLsizeiptr size, GLenum usage) {
    bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    this->size = size;
}

// ��ȡ VBO ID
GLuint VertexBuffer::getID() const {
    return vboID;
}

// ��ȡ��������С
GLsizeiptr VertexBuffer::getSize() const {
    return size;
}