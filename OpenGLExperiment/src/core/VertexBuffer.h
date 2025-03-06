#pragma once
#include <iostream>
#include <stdexcept>
#include "..\include\GL\glew.h"

class VertexBuffer
{
public:
    VertexBuffer(const float* data, GLsizeiptr size) {
        this->size = size;
        glGenBuffers(1, &vboID);
        if (vboID == 0) {
            throw std::runtime_error("Failed to generate VBO");
        }
        bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

        GLenum err;
        while ((err = glGetError()) != GL_NO_ERROR) {
            std::cerr << "OpenGL Error: " << err << std::endl;
        }
    }

    ~VertexBuffer() {
        if (vboID != 0) {
            glDeleteBuffers(1, &vboID);
            vboID = 0;
        }
    }

    // 禁用拷贝构造函数和拷贝赋值运算符
    VertexBuffer(const VertexBuffer&) = delete;
    VertexBuffer& operator=(const VertexBuffer&) = delete;

    // 支持移动语义
    VertexBuffer(VertexBuffer&& other) noexcept
        : vboID(other.vboID), size(other.size) {
        other.vboID = 0;
        other.size = 0;
    }

    VertexBuffer& operator=(VertexBuffer&& other) noexcept {
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

    void bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, vboID);
    }

    void unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void updateData(const float* data, GLsizeiptr size, GLenum usage = GL_STATIC_DRAW) {
        bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, usage);
        this->size = size;
    }

    GLuint getID() const { return vboID; }
    GLsizeiptr getSize() const { return size; }

private:
    GLuint vboID = 0;
    GLsizeiptr size = 0;
};