#pragma once
#include "..\include\GL\glew.h"
#include <unordered_map>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <string>

// ShaderProgram类用于管理OpenGL着色器程序
class ShaderProgram
{
public:
    GLuint programID = 0; // 着色器程序的ID
    std::string vertexUrl; // 顶点着色器文件路径
    std::string fragmentUrl; // 片段着色器文件路径
    std::unordered_map<std::string, GLint> uniformLocations; // 缓存的uniform变量位置
    bool isCompiled = false; // 标记着色器是否已编译

    // 构造函数，接受顶点和片段着色器文件路径
    ShaderProgram(std::string vertexUrl, std::string fragmentUrl) :vertexUrl(vertexUrl), fragmentUrl(fragmentUrl) {}

    // 编译着色器程序
    void compile();

    // 使用着色器程序
    void use();

    // 停止使用着色器程序
    void unuse();

    // 设置int类型的uniform变量
    void setUniform(const std::string& name, int value);

    // 设置float类型的uniform变量
    void setUniform(const std::string& name, float value);

    // 设置mat4类型的uniform变量
    void setUniform(const std::string& name, const glm::mat4& matrix);

    // 设置vec3类型的uniform变量
    void setUniform(const std::string& name, const glm::vec3& vector);

	// 设置vec4类型的uniform变量
    void setUniform(const std::string& name, const glm::vec4& vector);

private:
    // 读取文件内容为字符串
    std::string readFile(const char* filePath);

    // 从字符串编译着色器
    void compile_string(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);

    // 从文件路径编译着色器
    void compile_path(const char* vShaderFilePath, const char* fShaderFilePath);
};