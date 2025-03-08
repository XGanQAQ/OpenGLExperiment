#pragma once
#include "Model.h"
#include "../base/ElementBuffer.h"
Model::Model()
{
	vao = new VertexArrayObject();
	vao->create();
}

Model::Model(Mesh* posMesh, std::vector<unsigned int> indices)
{
	vao = new VertexArrayObject();
	vao->create();
	ElementBuffer* ebo = new ElementBuffer(indices.data(), indices.size());
	vao->addElementBuffer(ebo);
	this->positionMesh = posMesh;
	vao->addVertexBuffer(posMesh->vertexBuffer,posMesh->layout);
	this->indices = indices;
	this->drewCount = ebo->getCount();
}

Model::Model(Mesh* posMesh, Mesh* normalMesh, Mesh* texMesh, std::vector<unsigned int> indices)
{
	vao = new VertexArrayObject();
	vao->create();
	ElementBuffer* ebo = new ElementBuffer(indices.data(), indices.size());
	vao->addElementBuffer(ebo);
	this->positionMesh = posMesh;
	this->normalMesh = normalMesh;
	this->texMesh = texMesh;
	vao->addVertexBuffer(posMesh->vertexBuffer, posMesh->layout);
	vao->addVertexBuffer(normalMesh->vertexBuffer, normalMesh->layout);
	vao->addVertexBuffer(texMesh->vertexBuffer, texMesh->layout);
	this->indices = indices;
	this->drewCount = ebo->getCount();
}

void Model::pushOtherMesh(Mesh* mesh)
{
	otherMeshes.push_back(mesh);
	vao->addVertexBuffer(mesh->vertexBuffer, mesh->layout);
}

void Model::initModel()
{

}

//void Model::setMaterial(Material* material)