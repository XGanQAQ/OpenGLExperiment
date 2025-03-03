#pragma once
#include "..\include\GL\glew.h"
#include <unordered_map>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <string>

class ShaderProgram
{
public:
	GLuint programID;
	std::unordered_map<std::string, GLint> uniformLocations;
	void compile_path(const char* vShaderFilePath, const char* fShaderFilePath);
	void compile_string(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
	GLuint createShaderProgram(const char* vShaderFilePath, const char* fShaderFilePath);
	void use();
	void setUniform(const std::string& name, const glm::mat4& matrix);
	void setUniform(const std::string& name, const glm::vec3& vector);
private:
	std::string readFile(const char* filePath);

};