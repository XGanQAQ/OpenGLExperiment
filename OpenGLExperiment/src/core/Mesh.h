#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
class Renderer;

class Mesh
{
public:
	VertexBuffer* vertexBuffer;
	VertexBufferElement layout;
	//IndexBuffer* indexBuffer;
	//Texture* texture;

	Mesh(float* vertices, unsigned int bufferSize,VertexBufferElement layout) {
		vertexBuffer = new VertexBuffer(vertices,bufferSize);
		this->layout = layout;
	}
private:
};