#include "Renderer.h"
#include "../tools/Utils.h"
#include <iostream>


using namespace std;

Renderer::Renderer()
{
}

void Renderer::initialize() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

}

void checkShaderAtrrib(GLint shaderID) {
	GLint posAttrib = glGetAttribLocation(shaderID, "position");
	if (posAttrib == -1) {
		std::cerr << "Failed to find attribute location for 'position'" << "In: " << shaderID << std::endl;
	}
}

//渲染一个模型，使用模型和材质，采用顶点数组直接渲染
void Renderer::render_Array(Model* model, Material* material)
{
	material->useMaterial();
	model->vao->bind();

	//std::cout << "Draw count: " << model->drewCount << std::endl;
	glDrawArrays(GL_TRIANGLES, 0, model->drewCount);

	model->vao->unbind();

	material->unuseMaterial();

	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cerr << "OpenGL error at " << "render" << ": " << err << std::endl;
	}
}

//渲染一个模型，使用模型自己包含，采用索引渲染
void Renderer::render_Element(Model* model)
{
	if (model->shaderProgram==nullptr)
	{
		std::cerr <<"The model shaderProgram is null" << std::endl;
		return;
	}
	model->shaderProgram->use();
	model->vao->bind();
	glDrawElements(GL_TRIANGLES, model->drewCount, GL_UNSIGNED_INT, 0);
	model->vao->unbind();
	model->shaderProgram->unuse();
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cerr << "OpenGL error at " << "render" << ": " << err << std::endl;
	}
}

//渲染一个模型,使用模型和材质，采用索引渲染
void Renderer::render_Element(Model* model, Material* material)
{
	material->useMaterial();
	model->vao->bind();
	//checkShaderAtrrib(material->shaderProgram->programID); //检查是否有position属性

	glDrawElements(GL_TRIANGLES, model->drewCount, GL_UNSIGNED_INT, 0);

	model->vao->unbind();
	material->unuseMaterial();

	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cerr << "OpenGL error at " << "render" << ": " << err << std::endl;
	}
}

void Renderer::render(BaseNode* sceneNode)
{
	// 递归渲染子节点
	for (BaseNode* child : sceneNode->children) {
		render(child);
	}

	// 渲染当前节点
	SceneNode* node = dynamic_cast<SceneNode*>(sceneNode);
	if (node != nullptr) {
		node->initUniforms();
		if(!node->model->indices.empty())
			render_Element(node->model, node->material);
		else
			render_Array(node->model, node->material);
	}
}

void Renderer::render(Scene* scene) {
	// 清屏
	clearScreen();
	render(scene->rootNode);
}

void Renderer::clearScreen() {
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}




