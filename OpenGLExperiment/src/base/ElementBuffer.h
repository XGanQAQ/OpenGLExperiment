#pragma once
#include "..\include\GL\glew.h"

//索引缓冲对象
//用于存储顶点的索引
class ElementBuffer
{
public:
	ElementBuffer(const unsigned int* data, unsigned int count);
	~ElementBuffer();

	void bind();
	void unbind();
	void updateData(const unsigned int* data, unsigned int count);
	unsigned int getCount() const { return count; }
	
	// 获取 EBO ID
	GLuint getID() const { return eboID; }
	// 获取缓冲区大小
	GLsizeiptr getSize() const { return size; };

private:
	GLuint eboID = 0;       // VBO ID
	int count; // 顶点数量
	GLsizeiptr size = 0;     // 缓冲区大小
};