
#include "SceneNode.h"
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "../core/Scene.h"
void SceneNode::initNode()
{
	//��ʼ���ӽڵ�
	for (auto child : children)
	{
		child->initNode();
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
		mMat = getTransform() * parent->getTransform();
		mvMat = vMat * mMat;
		material->shaderProgram->setUniform("mv_matrix", mvMat);
		material->shaderProgram->setUniform("proj_matrix", pMat);
	}
}
