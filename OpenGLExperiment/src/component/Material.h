#pragma once
#include "../base/ShaderProgram.h"

class Material
{
public:
	Material(ShaderProgram* shader):shaderProgram(shader){}
	~Material();
	ShaderProgram* shaderProgram;
	//texture

	void initMaterial();
private:

};
