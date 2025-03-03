#pragma once
#include "..\include\GL\glew.h"
#include "VertexBuffer.h"

class VertexArrayObject
{
public:
	GLuint vaoID;
	void create();
	void bind();
	void unbind();
	void addVertexBuffer(VertexBuffer* vbo);//const VertexBufferLayout& layout

private:

};