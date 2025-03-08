#pragma once
#include "..\include\GL\glew.h"

//�����������
//���ڴ洢���������
class ElementBuffer
{
public:
	ElementBuffer(const unsigned int* data, unsigned int count);
	~ElementBuffer();

	void bind();
	void unbind();
	void updateData(const unsigned int* data, unsigned int count);
	unsigned int getCount() const { return count; }
	
	// ��ȡ EBO ID
	GLuint getID() const { return eboID; }
	// ��ȡ��������С
	GLsizeiptr getSize() const { return size; };

private:
	GLuint eboID = 0;       // VBO ID
	int count; // ��������
	GLsizeiptr size = 0;     // ��������С
};