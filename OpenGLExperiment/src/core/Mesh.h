#pragma once
#include "VertexBuffer.h"
class Renderer;

class Mesh
{
public:
	VertexBuffer* vertexBuffer;
	//IndexBuffer* indexBuffer;
	//Texture* texture;
	Mesh()
	{
		vertexBuffer = new VertexBuffer();
	}
	Mesh(float* vertices, unsigned int numVertices) {
		setMeshData(vertices, numVertices);
	}
	void setMeshData(float* vertices, unsigned int numVertices);
	void render(Renderer* renderer);
private:

};