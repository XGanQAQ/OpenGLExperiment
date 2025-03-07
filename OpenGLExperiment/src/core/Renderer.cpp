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

void Renderer::render(Model* model, Material* material)
{
	material->shaderProgram->use();

	model->vao->bind();
	checkShaderAtrrib(material->shaderProgram->programID);

	//std::cout << "Draw count: " << model->drewCount << std::endl;
	glDrawArrays(GL_TRIANGLES, 0, model->drewCount);

	model->vao->unbind();

	material->shaderProgram->unuse();

	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cerr << "OpenGL error at " << "render" << ": " << err << std::endl;
	}
}

void Renderer::render(SceneNode* sceneNode)
{
	// 递归渲染子节点
	for (SceneNode* child : sceneNode->children) {
		render(child);
	}
	// 渲染当前节点
	if (sceneNode->model != nullptr && sceneNode->material!=nullptr) {
		sceneNode->initUniforms();
		render(sceneNode->model, sceneNode->material);
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




