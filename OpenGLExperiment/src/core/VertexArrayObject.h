#pragma once
#include "..\include\GL\glew.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include <map>

class VertexArrayObject
{
public:
	GLuint vaoID;
	void create();
	void bind();
	void unbind();
	void addVertexBuffer(VertexBuffer* vbo,VertexBufferElement element);

private:

};