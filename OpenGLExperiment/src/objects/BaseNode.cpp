#include "BaseNode.h"
void BaseNode::update(float deltaTime)
{
	//for (auto child : children)
	//{
	//	child->update(deltaTime);
	//}
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