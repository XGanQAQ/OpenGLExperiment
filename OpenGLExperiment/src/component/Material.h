#pragma once
#include "../base/ShaderProgram.h"
#include "../base/Texture.h"
#include <unordered_map>
class Material
{
public:
	Material(ShaderProgram* shader):shaderProgram(shader){}
	Material(ShaderProgram* shader, Texture* texture) :shaderProgram(shader),texture(texture) {}
	~Material();
	ShaderProgram* shaderProgram;
	std::unordered_map<int, Texture> textures; //��δʹ����
	Texture* texture;
	int slot = 0;
	//texture
	std::unordered_map<std::string, int> uniformInt; // �洢 uniform int ֵ
	std::unordered_map<std::string, float> uniformFloat; // �洢 uniform float ֵ
	std::unordered_map<std::string, glm::vec3> uniformVec3; // �洢 uniform vec3 ֵ
	std::unordered_map<std::string, glm::vec4> uniformVec4; // �洢 uniform vec4 ֵ
	std::unordered_map<std::string, glm::mat4> uniformMat4; // �洢 uniform mat4 ֵ

	void initMaterial();
	void useMaterial();
	void unuseMaterial();
	void setUniformInt(const std::string& name, int value);
	void setUniformFloat(const std::string& name, float value);
	void setUniformVec3(const std::string& name, const glm::vec3& value);
	void setUniformVec4(const std::string& name, const glm::vec4& value);
	void setUniformMat4(const std::string& name, const glm::mat4& value);

private:

};


