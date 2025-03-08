#pragma once
#include "..\include\GL\glew.h"
#include "VertexBuffer.h"
#include "VertexBufferElement.h"
#include "ElementBuffer.h"
#include "ElementBuffer.h"

class VertexArrayObject
{
public:
	GLuint vaoID;
	void create();
	void bind();
	void unbind();
	void addVertexBuffer(VertexBuffer* vbo,VertexBufferElement element);
	void addElementBuffer(ElementBuffer* ebo);
private:

};