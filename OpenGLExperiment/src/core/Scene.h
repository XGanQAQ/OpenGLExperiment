#pragma once
#include "../objects/SceneNode.h"
#include "../objects/Camera.h"
#include "../objects/GlobalAmbient.h"
#include "../objects/DirLight.h"
#include <vector>
class Scene
{
public:
	BaseNode* rootNode;
	static Camera* mainCamera;
	static GlobalAmbient* globalAmbient;;
	static DirLight* dirLight;

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
	void setGlobalAmbient(GlobalAmbient* globalAmbient);
	void setDirLight(DirLight* dirLight);
	static Camera* getMainCamera();
	static GlobalAmbient* getGlobalAmbient();
	static DirLight* getDirLight();
	void printSceneTree(int depth, BaseNode* node);
private:

};
