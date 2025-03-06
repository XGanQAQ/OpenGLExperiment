#pragma once
#include <GL/glew.h>
#include "ShaderProgram.h"
#include "VertexArrayObject.h"
#include "VertexBufferLayout.h"

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
