#include "Scene.h"
#include <iostream>

// 定义静态成员变量
Camera* Scene::mainCamera = nullptr; // 初始化为 nullptr 或其他合适的值

void Scene::initialize()
{
	rootNode->initialize();
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

void Scene::setMainCamera(Camera* camera)
{
	mainCamera = camera;
}

Camera* Scene::getMainCamera()
{
	if (Scene::mainCamera!=nullptr)
	{
		return Scene::mainCamera;
	}
	else
	{
		Scene::mainCamera = new Camera(glm::vec3(0.0f, 2.0f, -8.0f),  // 位置
			glm::vec3(0.0f, 0.0f, 0.0f),  // 目标点
			glm::vec3(0.0f, 1.0f, 0.0f), // 上向量
			45.0f,                        // 视野角度
			800.0f / 600.0f,              // 宽高比
			0.1f,                         // 近裁剪面
			100.0f);                      // 远裁剪面;	Camera camera
		return Scene::mainCamera;
	}
}

//递归遍历打印根场景节点
void Scene::printSceneTree(int depth, SceneNode* node)
{
	if (node!=nullptr)
	{
		for (int i = 0; i < depth; i++)
		{
			std::cout << "  ";
		}
		std::cout << node->nodeName << std::endl;
		for (int i = 0; i < node->children.size(); i++)
		{
			printSceneTree(depth + 1, node->children[i]);
		}
	}
	else
	{
		std::cout << "null" << std::endl;
	}
}
