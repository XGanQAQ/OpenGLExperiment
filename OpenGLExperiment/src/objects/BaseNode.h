#pragma once
#include "../include/GL/glew.h"
#include <glm\gtc\matrix_transform.hpp>
#include <vector>
#include <string>

class BaseNode
{
public:
	BaseNode() : nodeName("UnnamedNode") {}
	BaseNode(std::string nodeName = "UnnamedNode") : nodeName(nodeName) {}

	std::string nodeName;
	std::vector<BaseNode*> children;
	BaseNode* parent = nullptr;

	glm::vec3 position = glm::vec3(0, 0, 0);
	glm::vec3 rotation = glm::vec3(0, 0, 0);
	glm::vec3 scale = glm::vec3(1, 1, 1);

	glm::mat4 getTransform();
	glm::vec3 getPosition() { return position; }
	glm::vec3 getRotation() { return rotation; }
	glm::vec3 getScale() { return scale; }
	void setTransform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	void setPosition(glm::vec3 position) { this->position = position; }
	void setRotation(glm::vec3 rotation) { this->rotation = rotation; }
	void setScale(glm::vec3 scale) { this->scale = scale; }
	void update(float deltaTime);
	void addChild(BaseNode* child);
	void removeChild(BaseNode* child);
	virtual void initNode(); 
private:

};
