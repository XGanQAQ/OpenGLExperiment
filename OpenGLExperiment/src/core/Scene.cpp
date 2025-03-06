#include "Scene.h"
#include <iostream>

// ���徲̬��Ա����
Camera* Scene::mainCamera = nullptr; // ��ʼ��Ϊ nullptr ���������ʵ�ֵ

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
		Scene::mainCamera = new Camera(glm::vec3(0.0f, 2.0f, -8.0f),  // λ��
			glm::vec3(0.0f, 0.0f, 0.0f),  // Ŀ���
			glm::vec3(0.0f, 1.0f, 0.0f), // ������
			45.0f,                        // ��Ұ�Ƕ�
			800.0f / 600.0f,              // ��߱�
			0.1f,                         // ���ü���
			100.0f);                      // Զ�ü���;	Camera camera
		return Scene::mainCamera;
	}
}

//�ݹ������ӡ�������ڵ�
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
