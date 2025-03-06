#pragma once
#include "Mesh.h"
#include "VertexArrayObject.h"
#include <vector>
#include <string>
class Renderer;
class Mesh;

class Model
{
public:
	Model();
	Model(Mesh* mesh,int drewCount);
	VertexArrayObject* vao;
	std::vector<Mesh*> meshes;
	int drewCount = 0;

	void pushMesh(Mesh* mesh);
	void initModel();//initialize the model

private:

};