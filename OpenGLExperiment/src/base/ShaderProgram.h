#pragma once
#include "..\include\GL\glew.h"
#include <unordered_map>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <string>

// ShaderProgram�����ڹ���OpenGL��ɫ������
class ShaderProgram
{
public:
    GLuint programID = 0; // ��ɫ�������ID
    std::string vertexUrl; // ������ɫ���ļ�·��
    std::string fragmentUrl; // Ƭ����ɫ���ļ�·��
    std::unordered_map<std::string, GLint> uniformLocations; // �����uniform����λ��
    bool isCompiled = false; // �����ɫ���Ƿ��ѱ���

    // ���캯�������ܶ����Ƭ����ɫ���ļ�·��
    ShaderProgram(std::string vertexUrl, std::string fragmentUrl) :vertexUrl(vertexUrl), fragmentUrl(fragmentUrl) {}

    // ������ɫ������
    void compile();

    // ʹ����ɫ������
    void use();

    // ֹͣʹ����ɫ������
    void unuse();

    // ����int���͵�uniform����
    void setUniform(const std::string& name, int value);

    // ����float���͵�uniform����
    void setUniform(const std::string& name, float value);

    // ����mat4���͵�uniform����
    void setUniform(const std::string& name, const glm::mat4& matrix);

    // ����vec3���͵�uniform����
    void setUniform(const std::string& name, const glm::vec3& vector);

	// ����vec4���͵�uniform����
    void setUniform(const std::string& name, const glm::vec4& vector);

private:
    // ��ȡ�ļ�����Ϊ�ַ���
    std::string readFile(const char* filePath);

    // ���ַ���������ɫ��
    void compile_string(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);

    // ���ļ�·��������ɫ��
    void compile_path(const char* vShaderFilePath, const char* fShaderFilePath);
};