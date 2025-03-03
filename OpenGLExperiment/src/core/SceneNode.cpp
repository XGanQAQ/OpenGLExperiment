#include "..\include\GL\glew.h"
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <vector>

#include "Model.h"
#include "Renderer.h"
#include "SceneNode.h"

void SceneNode::update(float deltaTime)
{
	//for (auto child : children)
	//{
	//	child->update(deltaTime);
	//}
}

void SceneNode::render(Renderer* renderer)
{
	if (model)
	{
		model->render(renderer);
	}
	for (auto child : children)
	{
		child->render(renderer);
	}
}


void SceneNode::addChild(SceneNode* child)
{
	children.push_back(child);
	child->parent = this;
}

void SceneNode::removeChild(SceneNode* child)
{
	children.erase(std::remove(children.begin(), children.end(), child), children.end());
	child->parent = nullptr;
}

void SceneNode::setTransform(const glm::mat4& transform)
{
	this->transform = transform;
}