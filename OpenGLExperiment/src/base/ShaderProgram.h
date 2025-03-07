#pragma once
#include "..\include\GL\glew.h"
#include <unordered_map>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <string>

class ShaderProgram
{
public:
	GLuint programID = 0;
	std::string vertexUrl;
	std::string fragmentUrl;
	std::unordered_map<std::string, GLint> uniformLocations;
	bool isCompiled = false;

	ShaderProgram(std::string vertexUrl, std::string fragmentUrl) :vertexUrl(vertexUrl), fragmentUrl(fragmentUrl) {}
	void compile();
	void use();
	void unuse();
	void setUniform(const std::string& name, int value);
	void setUniform(const std::string& name, float value);
	void setUniform(const std::string& name, const glm::mat4& matrix);
	void setUniform(const std::string& name, const glm::vec3& vector);
private:
	std::string readFile(const char* filePath);
	void compile_string(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
	void compile_path(const char* vShaderFilePath, const char* fShaderFilePath);

};