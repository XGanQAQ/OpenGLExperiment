#include "Scene.h"


void Scene::initialize()
{
	rootNode = new SceneNode();
}

void Scene::initialize(SceneNode* rootNode)
{
	this->rootNode = rootNode;
}

void Scene::update(float deltaTime)
{
	rootNode->update(deltaTime);
}

void Scene::addNode(SceneNode* node)
{
	rootNode->addChild(node);
}

void Scene::removeNode(SceneNode* node)
{
	node->parent = nullptr;
}
