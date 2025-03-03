#pragma once
#include "SceneNode.h"
#include "Model.h"
#include <vector>
class Scene
{
public:
	SceneNode* rootNode;
	std::vector<Model*>models;

	void initialize();
	void initialize(SceneNode* rootNode);
	void update(float deltaTime);
	void addNode(SceneNode* node); //��rootNode����ӽڵ�
	void removeNode(SceneNode* node);
	//void addLight(Light* light);
	//void setMainCamera(Camera* camera);
private:

};
