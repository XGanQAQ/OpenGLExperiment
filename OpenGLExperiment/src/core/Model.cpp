#pragma once
#include "Model.h"
void Model::pushMesh(Mesh* mesh)
{
	meshes.push_back(mesh);
}
void Model::render(Renderer* renderer)
{
	for (int i = 0; i < meshes.size(); i++)
	{
		meshes[i]->render(renderer);
	}
}

//void Model::setMaterial(Material* material)