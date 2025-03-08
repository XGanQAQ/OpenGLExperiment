#pragma once
#include "../include/GL/glew.h"
#include <vector>
#include <string>

class BaseNode
{
public:
	BaseNode(std::string nodeName) :nodeName(nodeName) {}

	std::string nodeName;
	std::vector<BaseNode*> children;
	BaseNode* parent = nullptr;

	void update(float deltaTime);
	void addChild(BaseNode* child);
	void removeChild(BaseNode* child);

private:

};
