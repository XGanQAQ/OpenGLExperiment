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
	// ���붥����ɫ��
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexShaderSourceCStr = vertexShaderSource.c_str();
	glShaderSource(vertexShader, 1, &vertexShaderSourceCStr, nullptr);
	glCompileShader(vertexShader);

	// ��鶥����ɫ���������
	GLint success;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// ����Ƭ����ɫ��
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentShaderSourceCStr = fragmentShaderSource.c_str();
	glShaderSource(fragmentShader, 1, &fragmentShaderSourceCStr, nullptr);
	glCompileShader(fragmentShader);

	// ���Ƭ����ɫ���������
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// ������ɫ������
	programID = glCreateProgram();
	glAttachShader(programID, vertexShader);
	glAttachShader(programID, fragmentShader);
	glLinkProgram(programID);

	// �����ɫ���������Ӵ���
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(programID, 512, nullptr, infoLog);
		std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// ɾ����ɫ������
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

GLuint ShaderProgram::createShaderProgram(const char* vShaderFilePath, const char* fShaderFilePath)
{
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	GLuint vfprogram = glCreateProgram();

	std::string vertShaderStr = readFile(vShaderFilePath);
	std::string fragShaderStr = readFile(fShaderFilePath);
	const char* vertShaderSrc = vertShaderStr.c_str();
	const char* fragShaderSrc = fragShaderStr.c_str();

	glShaderSource(vShader, 1, &vertShaderSrc, NULL);
	glShaderSource(fShader, 1, &fragShaderSrc, NULL);
	glCompileShader(vShader);
	glCompileShader(fShader);

	glAttachShader(vfprogram, vShader);
	glAttachShader(vfprogram, fShader);
	glLinkProgram(vfprogram);

	return vfprogram;
}

void ShaderProgram::use() {
	if (programID != 0) {
		glUseProgram(programID);
	}
	else {
		std::cerr << "ERROR: Shader program not compiled or linked!" << std::endl;
	}
}

void ShaderProgram::setUniform(const std::string& name, const glm::mat4& matrix)
{
	GLint location = uniformLocations[name];
	if (location == 0) {
		location = glGetUniformLocation(programID, name.c_str());
		uniformLocations[name] = location;
	}
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::setUniform(const std::string& name, const glm::vec3& vector)
{
	GLint location = uniformLocations[name];
	if (location == 0) {
		location = glGetUniformLocation(programID, name.c_str());
		uniformLocations[name] = location;
	}
	glUniform3fv(location, 1, glm::value_ptr(vector));
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
