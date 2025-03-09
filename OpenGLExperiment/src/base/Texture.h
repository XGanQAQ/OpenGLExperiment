#pragma once
#include "..\include\GL\glew.h"
#include <string>
#include <iostream>
#include "SOIL2/SOIL2.h" // 包含SOIL2库

class Texture {
public:
    // 构造函数，接受纹理文件路径
    Texture(const std::string& filePath);

    // 禁用拷贝构造函数和赋值操作符
    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;

    // 移动构造函数和移动赋值操作符
    Texture(Texture&& other) noexcept;
    Texture& operator=(Texture&& other) noexcept;

    // 析构函数，释放纹理资源
    ~Texture();

    // 绑定纹理到指定的纹理单元
    void bind(unsigned int slot = 0) const;

    // 解绑纹理
    void unbind() const;

    // 获取纹理ID
    GLuint getID() const { return m_RendererID; }

private:
    // 纹理渲染ID
    GLuint m_RendererID;
    // 纹理文件路径
    std::string m_FilePath;
};