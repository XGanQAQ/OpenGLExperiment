#include "ShaderProgram.h"
#include <iostream>
#include <fstream>
#include <filesystem> // �޸�Ϊ std::experimental::filesystem

void ShaderProgram::compile_path(const char* vShaderFilePath, const char* fShaderFilePath)
{
    // ��鶥����ɫ���ļ��Ƿ����
    if (!std::filesystem::exists(vShaderFilePath)) { // �޸�Ϊ std::experimental::filesystem
        std::cerr << "ERROR: Vertex shader file does not exist: " << vShaderFilePath << std::endl;
        return;
    }

    // ���Ƭ����ɫ���ļ��Ƿ����
    if (!std::filesystem::exists(fShaderFilePath)) { // �޸�Ϊ std::experimental::filesystem
        std::cerr << "ERROR: Fragment shader file does not exist: " << fShaderFilePath << std::endl;
        return;
    }

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
	GLint location;
	auto it = uniformLocations.find(name);
	if (it == uniformLocations.end()) {
		location = glGetUniformLocation(programID, name.c_str());
		uniformLocations[name] = location;
	}
	else {
		location = it->second;
	}
	if (location != -1) {
		glProgramUniform1i(programID, location, value);
	}
}


void ShaderProgram::setUniform(const std::string& name, float value)
{
	GLint location;
	auto it = uniformLocations.find(name);
	if (it == uniformLocations.end()) {
		location = glGetUniformLocation(programID, name.c_str());
		uniformLocations[name] = location;
	}
	else {
		location = it->second;
	}
	if (location != -1) {
		glProgramUniform1f(programID, location, value);
	}
}


void ShaderProgram::setUniform(const std::string& name, const glm::mat4& matrix)
{
	GLint location;
	auto it = uniformLocations.find(name);
	if (it == uniformLocations.end()) {
		location = glGetUniformLocation(programID, name.c_str());
		uniformLocations[name] = location;
	}
	else {
		location = it->second;
	}
	if (location != -1) {
		glProgramUniformMatrix4fv(programID, location, 1, GL_FALSE, glm::value_ptr(matrix));
	}
}

void ShaderProgram::setUniform(const std::string& name, const glm::vec3& vector)
{
	GLint location;
	auto it = uniformLocations.find(name);
	if (it == uniformLocations.end()) {
		location = glGetUniformLocation(programID, name.c_str());
		uniformLocations[name] = location;
	}
	else {
		location = it->second;
	}
	if (location != -1) {
		glProgramUniform3fv(programID, location, 1, glm::value_ptr(vector));
	}
}


void ShaderProgram::setUniform(const std::string& name, const glm::vec4& vector)
{
	GLint location;
	auto it = uniformLocations.find(name);
	if (it == uniformLocations.end()) {
		location = glGetUniformLocation(programID, name.c_str());
		uniformLocations[name] = location;
	}
	else {
		location = it->second;
	}
	if (location != -1) {
		glProgramUniform4fv(programID, location, 1, glm::value_ptr(vector));
	}
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
