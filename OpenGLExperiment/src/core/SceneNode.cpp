#include "..\include\GL\glew.h"
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <vector>

#include "Model.h"
#include "Renderer.h"
#include "SceneNode.h"

void SceneNode::update(float deltaTime)
{
	//for (auto child : children)
	//{
	//	child->update(deltaTime);
	//}
}


void SceneNode::addChild(SceneNode* child)
{
	children.push_back(child);
	child->parent = this;
}

void SceneNode::removeChild(SceneNode* child)
{
	children.erase(std::remove(children.begin(), children.end(), child), children.end());
	child->parent = nullptr;
}

void SceneNode::setTransform(const glm::mat4& transform)
{
	this->transform = transform;
}

void SceneNode::initialize()
{
	//初始化子节点
	for (auto child : children)
	{
		child->initialize();
	}

	if (model != nullptr)
	{
		model->initModel();
	}
	if (material!=nullptr)
	{
		material->initMaterial();
	}
}

void SceneNode::initUniforms()
{
	if (material != nullptr)
	{
		Camera* camera = Scene::getMainCamera();

		glm::mat4 pMat, vMat, mMat, mvMat;
		pMat = camera->getProjectionMatrix();
		vMat = camera->getViewMatrix();
		mMat = transform * parent->transform;
		mvMat = vMat * mMat;
		material->shaderProgram->setUniform("mv_matrix", mvMat);
		material->shaderProgram->setUniform("proj_matrix", pMat);
	}
}
