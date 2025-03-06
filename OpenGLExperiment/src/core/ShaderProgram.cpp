#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <unordered_map>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <iostream>
#include "ShaderProgram.h"
#include <fstream>

void ShaderProgram::compile_path(const char* vShaderFilePath, const char* fShaderFilePath)
{
	std::string vertShaderStr = readFile(vShaderFilePath);
	std::string fragShaderStr = readFile(fShaderFilePath);
	compile_string(vertShaderStr, fragShaderStr);
}

void ShaderProgram::compile_string(const std::string& vertexShaderSource, const std::string& fragmentShaderSource)
{
	// 编译顶点着色器
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexShaderSourceCStr = vertexShaderSource.c_str();
	glShaderSource(vertexShader, 1, &vertexShaderSourceCStr, nullptr);
	glCompileShader(vertexShader);

	// 检查顶点着色器编译错误
	GLint success;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// 编译片段着色器
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentShaderSourceCStr = fragmentShaderSource.c_str();
	glShaderSource(fragmentShader, 1, &fragmentShaderSourceCStr, nullptr);
	glCompileShader(fragmentShader);

	// 检查片段着色器编译错误
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// 链接着色器程序
	programID = glCreateProgram();
	glAttachShader(programID, vertexShader);
	glAttachShader(programID, fragmentShader);
	glLinkProgram(programID);

	// 检查着色器程序链接错误
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(programID, 512, nullptr, infoLog);
		std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// 删除着色器对象
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void ShaderProgram::compile()
{
	if (isCompiled)
	{
		return;
	}
	else
	{
		compile_path(vertexUrl.c_str(), fragmentUrl.c_str());
	}
}

void ShaderProgram::use() {
	if (programID != 0) {
		glUseProgram(programID);
	}
	else {
		std::cerr << "ERROR: Shader program not compiled or linked!" << std::endl;
	}
}

void ShaderProgram::unuse()
{
	glUseProgram(0);
}

void ShaderProgram::setUniform(const std::string& name, int value)
{
	GLint location = uniformLocations[name];
	if (location == 0) {
		location = glGetUniformLocation(programID, name.c_str());
		uniformLocations[name] = location;
	}
	glProgramUniform1i(programID,location, value);
}

void ShaderProgram::setUniform(const std::string& name, float value)
{
	GLint location = uniformLocations[name];
	if (location == 0) {
		location = glGetUniformLocation(programID, name.c_str());
		uniformLocations[name] = location;
	}
	glProgramUniform1f(programID,location, value);
}

void ShaderProgram::setUniform(const std::string& name, const glm::mat4& matrix)
{
	GLint location = uniformLocations[name];
	if (location == 0) {
		location = glGetUniformLocation(programID, name.c_str());
		uniformLocations[name] = location;
	}
	glProgramUniformMatrix4fv(programID, location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::setUniform(const std::string& name, const glm::vec3& vector)
{
	GLint location = uniformLocations[name];
	if (location == 0) {
		location = glGetUniformLocation(programID, name.c_str());
		uniformLocations[name] = location;
	}
	glProgramUniform3fv(programID, location, 1, glm::value_ptr(vector));
}

std::string ShaderProgram::readFile(const char* filePath)
{
	std::string content;
	std::ifstream fileStream(filePath, std::ios::in);
	std::string line = "";
	while (!fileStream.eof()) {
		getline(fileStream, line);
		content.append(line + "\n");
	}
	fileStream.close();
	return content;
}
