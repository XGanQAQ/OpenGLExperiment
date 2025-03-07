#pragma once
#include "../base/VertexBuffer.h"
#include "../base/VertexBufferElement.h"

//This class is used to store the mesh data
//It contains a vertex buffer and a layout
//The layout is used to tell the renderer how to interpret the vertex buffer data
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