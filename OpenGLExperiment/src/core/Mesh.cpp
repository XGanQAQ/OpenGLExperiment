#pragma once
#include "VertexBuffer.h"
#include "Renderer.h"
#include "Mesh.h"

void Mesh::render(Renderer* renderer)
{
    if (vertexBuffer)
    {
        renderer->draw(vertexBuffer);
    }
}

void Mesh::setMeshData(float* vertices, unsigned int numVertices)
{
	if (vertexBuffer)
	{
	    vertexBuffer->create(vertices, numVertices);
	}
}
