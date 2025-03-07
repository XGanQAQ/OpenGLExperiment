#pragma once
#include "Model.h"
Model::Model()
{
	vao = new VertexArrayObject();
	vao->create();
}
Model::Model(Mesh* mesh, int drewCount)
{
	vao = new VertexArrayObject();
	vao->create();
	pushMesh(mesh);
	this->drewCount = drewCount;
}

void Model::pushMesh(Mesh* mesh)
{
	meshes.push_back(mesh);
	vao->addVertexBuffer(mesh->vertexBuffer, mesh->layout);
}

void Model::initModel()
{

}

//void Model::setMaterial(Material* material)