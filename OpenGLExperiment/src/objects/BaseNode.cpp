#include "BaseNode.h"
unsigned int BaseNode::nodeCounter = 0;

glm::mat4 BaseNode::getTransform()
{
	glm::mat4 posMat = glm::translate(glm::mat4(1.0f), position);
	glm::mat4 rotMat = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x), glm::vec3(1, 0, 0));
	rotMat = glm::rotate(rotMat, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	rotMat = glm::rotate(rotMat, glm::radians(rotation.z), glm::vec3(0, 0, 1));
	glm::mat4 scaleMat = glm::scale(glm::mat4(1.0f), scale);

	return posMat * rotMat * scaleMat;
}


void BaseNode::setTransform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}

void BaseNode::update(float deltaTime)
{
	for (auto child : children)
	{
		child->update(deltaTime);
	}
}

void BaseNode::addChild(BaseNode* child)
{
	children.push_back(child);
	child->parent = this;
}

void BaseNode::removeChild(BaseNode* child)
{
	children.erase(std::remove(children.begin(), children.end(), child), children.end());
	child->parent = nullptr;
}

void BaseNode::initNode()
{
	for (auto child : children)
	{
		child->initNode();
	}
}
