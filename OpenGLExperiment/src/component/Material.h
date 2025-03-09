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
	std::unordered_map<int, Texture> textures; //‘›Œ¥ π”√…œ
	Texture* texture;
	int slot = 0;
	//texture

	void initMaterial();
	void useMaterial();
private:

};
