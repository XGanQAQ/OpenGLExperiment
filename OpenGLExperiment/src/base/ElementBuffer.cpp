#include "ElementBuffer.h"

ElementBuffer::ElementBuffer(const unsigned int* data, unsigned int count)
{
	this->count = count;
	glGenBuffers(1, &eboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

ElementBuffer::~ElementBuffer()
{
	if (eboID != 0) {
		glDeleteBuffers(1, &eboID);
		eboID = 0;
	}
}

void ElementBuffer::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
}

void ElementBuffer::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementBuffer::updateData(const unsigned int* data, unsigned int count)
{
	this->count = count;
	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}
