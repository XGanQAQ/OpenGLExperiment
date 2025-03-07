#include "VertexArrayObject.h"
#include <stdexcept>

void VertexArrayObject::create()
{
	glGenVertexArrays(1, &vaoID);
	if (vaoID == 0) {
		throw std::runtime_error("Failed to generate VAO");
	}
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

void VertexArrayObject::addVertexBuffer(VertexBuffer* vbo, VertexBufferElement element)
{
	bind();
	vbo->bind();
	glEnableVertexAttribArray(element.locationPos);
	glVertexAttribPointer(element.locationPos, element.count, element.type, element.normalized, element.stride, (const void*)element.beginPos);
	vbo->unbind();
	unbind();
}
