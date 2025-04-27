#include "Scene.h"
#include <iostream>


// 定义静态成员变量
Camera* Scene::mainCamera = nullptr; // 初始化为 nullptr 或其他合适的值
GlobalAmbient* Scene::globalAmbient = nullptr; // 新增的定义
DirLight* Scene::dirLight = nullptr; // 新增的定义

void Scene::initialize()
{
	rootNode->initNode();
}

void Scene::update(float deltaTime)
{
	rootNode->update(deltaTime);
}

void Scene::addNode(BaseNode* node)
{
	rootNode->addChild(node);
}

void Scene::removeNode(BaseNode* node)
{
	node->parent = nullptr;
}

void Scene::setMainCamera(Camera* camera)
{
	mainCamera = camera;
}

void Scene::setGlobalAmbient(GlobalAmbient* globalAmbient)
{
	Scene::globalAmbient = globalAmbient;
}

void Scene::setDirLight(DirLight* dirLight)
{
	Scene::dirLight = dirLight;
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

GlobalAmbient* Scene::getGlobalAmbient()
{
	if (Scene::globalAmbient != nullptr)
	{
		return Scene::globalAmbient;
	}
	else
	{
		Scene::globalAmbient = new GlobalAmbient(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f), glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
		return Scene::globalAmbient;
	}
}

DirLight* Scene::getDirLight()
{
	if (Scene::dirLight != nullptr)
	{
		return Scene::dirLight;
	}
	else
	{
		Scene::dirLight = new DirLight(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f), glm::vec4(0.6f, 0.6f, 0.6f, 1.0f), glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
		return Scene::dirLight;
	}
}

//递归遍历打印根场景节点
void Scene::printSceneTree(int depth, BaseNode* node)
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
