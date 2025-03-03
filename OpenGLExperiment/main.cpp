#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <SOIL2\soil2.h>
#include <string>
#include <iostream>
#include <fstream>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "src\objects\Torus.h"
#include "src\tools\Utils.h"
#include "src\resources\ImportedModel.h"
#include "src/core/Application.h"
using namespace std;

float vertices[] = {
	-0.5f, -0.5f, 1.0f,  // 左下角
	 0.5f, -0.5f, 1.0f,  // 右下角
	 0.0f,  0.5f, 1.0f   // 顶部
};


int main(void) {

	Renderer* renderer = new Renderer();
	Scene* scene = new Scene();
	ShaderProgram* shaderProgram = new ShaderProgram();
	Application app;

	app.initialize(800,600,renderer,scene); //必须在所有初始化之前

	shaderProgram->compile_path("assets/shaders/testVertShader.glsl", "assets/shaders/testFragShader.glsl");
	renderer->initialize(shaderProgram); //注入着色器程序
	scene->initialize();

	//Scene* scenePtr = app.scene;
	//SceneNode* cubeNode = new SceneNode();
	//Model* cubeModel = new Model();
	//Mesh* cubeMesh = new Mesh();
	//
	//scenePtr->addNode(cubeNode); //根节点添加子节点
	//
	//cubeNode->model = cubeModel; // 节点添加模型
	//cubeModel->meshes.push_back(cubeMesh); //模型添加网格
	//cubeMesh->setMeshData(vertices,9); // 网格绑定vbo

	app.run();
	app.cleanup();

}
