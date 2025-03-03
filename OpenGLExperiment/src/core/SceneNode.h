#pragma once
#include "..\include\GL\glew.h"
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <vector>
#include "Model.h"
#include "Renderer.h"

// Ç°ÏòÉùÃ÷
class Model;
class Renderer;

class SceneNode
{
public:
	SceneNode(){};
	SceneNode(Model* model):model(model){}
	std::vector<SceneNode*> children;
	SceneNode* parent;
	glm::mat4 transform;
	Model* model;

	void update(float deltaTime);
	void render(Renderer* renderer);
	void addChild(SceneNode* child);
	void removeChild(SceneNode* child);
	void setTransform(const glm::mat4& transform);
private:

};