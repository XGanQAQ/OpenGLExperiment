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
	-0.5f, -0.5f, 1.0f,  // ���½�
	 0.5f, -0.5f, 1.0f,  // ���½�
	 0.0f,  0.5f, 1.0f   // ����
};


int main(void) {

	Renderer* renderer = new Renderer();
	Scene* scene = new Scene();
	ShaderProgram* shaderProgram = new ShaderProgram();
	Application app;

	app.initialize(800,600,renderer,scene); //���������г�ʼ��֮ǰ

	shaderProgram->compile_path("assets/shaders/testVertShader.glsl", "assets/shaders/testFragShader.glsl");
	renderer->initialize(shaderProgram); //ע����ɫ������
	scene->initialize();

	//Scene* scenePtr = app.scene;
	//SceneNode* cubeNode = new SceneNode();
	//Model* cubeModel = new Model();
	//Mesh* cubeMesh = new Mesh();
	//
	//scenePtr->addNode(cubeNode); //���ڵ�����ӽڵ�
	//
	//cubeNode->model = cubeModel; // �ڵ����ģ��
	//cubeModel->meshes.push_back(cubeMesh); //ģ���������
	//cubeMesh->setMeshData(vertices,9); // �����vbo

	app.run();
	app.cleanup();

}
