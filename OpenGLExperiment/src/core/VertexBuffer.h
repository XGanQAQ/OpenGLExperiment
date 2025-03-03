#pragma once
#include "..\include\GL\glew.h"

class VertexBuffer
{
public:
	GLuint vboID;
	int size;
	void create(const float* data, GLsizei size);
	void bind();
	void unbind();

private:

};