#pragma once
#include "Mesh.h"
#include <vector>
class Renderer;
class Mesh;

class Model
{
public:
	std::vector<Mesh*> meshes;
	//Material* material;

	void pushMesh(Mesh* mesh);
	void render(Renderer* renderer);
	//void setMaterial(Material* material);
private:

};