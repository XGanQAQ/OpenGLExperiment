#include "..\include\GL\glew.h"
#include "VertexBuffer.h"
#include "VertexArrayObject.h"


void VertexArrayObject::create()
{
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);
}

void VertexArrayObject::bind()
{
	glBindVertexArray(vaoID);
}

void VertexArrayObject::unbind()
{
	glBindVertexArray(0);
}

void VertexArrayObject::addVertexBuffer(VertexBuffer* vbo)
{
	vbo->bind();
}