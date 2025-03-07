#pragma once
#include "../objects/SceneNode.h"
#include "../objects/Camera.h"
#include <vector>
class Scene
{
public:
	SceneNode* rootNode;
	static Camera* mainCamera;
	
	Scene() {
		rootNode = new SceneNode("rootNode");
	}
	Scene(SceneNode* rootNode) :rootNode(rootNode) {}
	void initialize();

	void update(float deltaTime);
	void addNode(SceneNode* node); //给rootNode添加子节点
	void removeNode(SceneNode* node);
	//void addLight(Light* light);
	void setMainCamera(Camera* camera);
	static Camera* getMainCamera();
	void printSceneTree(int depth,SceneNode* node);
private:

};
