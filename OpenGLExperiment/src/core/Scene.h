#pragma once
#include "../objects/SceneNode.h"
#include "../objects/Camera.h"
#include <vector>
class Scene
{
public:
	BaseNode* rootNode;
	static Camera* mainCamera;
	
	Scene() {
		rootNode = new BaseNode("rootNode");
	}
	Scene(BaseNode* rootNode) :rootNode(rootNode) {}
	void initialize();

	void update(float deltaTime);
	void addNode(BaseNode* node); //给rootNode添加子节点
	void removeNode(BaseNode* node);
	//void addLight(Light* light);
	void setMainCamera(Camera* camera);
	static Camera* getMainCamera();
	void printSceneTree(int depth, BaseNode* node);
private:

};
