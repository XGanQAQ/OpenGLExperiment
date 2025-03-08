#pragma once
#include "../base/Mesh.h"
#include "../base/VertexArrayObject.h"
#include <vector>
#include <string>
class Renderer;
class Mesh;

class Model
{
public:
	Model();
	Model(Mesh* posMesh, std::vector<unsigned int> indices);
	Model(Mesh* posMesh, Mesh* normalMesh, Mesh* texMesh, std::vector<unsigned int> indices);
	VertexArrayObject* vao;
	Mesh* positionMesh;
	Mesh* normalMesh;
	Mesh* texMesh;
	std::vector<unsigned int> indices;
	std::vector<Mesh*> otherMeshes;
	int drewCount = 0;

	
	void pushOtherMesh(Mesh* mesh);
	void initModel();//initialize the model

private:

};