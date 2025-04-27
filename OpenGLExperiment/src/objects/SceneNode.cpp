
#include "SceneNode.h"
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "../core/Scene.h"
void SceneNode::initNode()
{
	//初始化子节点
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

void SceneNode::inject_mvp_uniforms()
{
	if (material != nullptr)
	{
		Camera* camera = Scene::getMainCamera();

		glm::mat4 pMat, vMat, mMat, mvMat;
		pMat = camera->getProjectionMatrix();
		vMat = camera->getViewMatrix();
		mMat = getTransform() * parent->getTransform();
		mvMat = vMat * mMat;
		material->setUniformMat4("mv_matrix", mvMat);
		material->setUniformMat4("proj_matrix", pMat);
		material->setUniformMat4("norm_matrix", glm::transpose(glm::inverse(mvMat)));
	}
}
