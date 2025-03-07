#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "src/tools/Utils.h"
#include "src/core/Application.h"
#include <iostream>
#include <string>

using namespace std;

void printTest(Scene* scene) {
	scene->printSceneTree(0, scene->rootNode);
}

void CHECK_GL_ERROR(int a) {
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cerr << "OpenGL error at " << a << ": " << err << std::endl;
	}
}


float vertexPositions[108] = {
	-1.0f,  1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, -1.0f, 1.0f,  1.0f, -1.0f, -1.0f,  1.0f, -1.0f,
	1.0f, -1.0f, -1.0f, 1.0f, -1.0f,  1.0f, 1.0f,  1.0f, -1.0f,
	1.0f, -1.0f,  1.0f, 1.0f,  1.0f,  1.0f, 1.0f,  1.0f, -1.0f,
	1.0f, -1.0f,  1.0f, -1.0f, -1.0f,  1.0f, 1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f,  1.0f, -1.0f,  1.0f,  1.0f, 1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f,  1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f, -1.0f,  1.0f, -1.0f, -1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f,  1.0f,  1.0f, -1.0f,  1.0f,  1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f,
	-1.0f,  1.0f, -1.0f, 1.0f,  1.0f, -1.0f, 1.0f,  1.0f,  1.0f,
	1.0f,  1.0f,  1.0f, -1.0f,  1.0f,  1.0f, -1.0f,  1.0f, -1.0f
};

float trianglePositions[9] = {
	-0.6f, -0.6f, 0.0f,
	0.6f, -0.6f, 0.0f,
	0.0f, 0.6f, 0.0f
};

int main(void) {
	Application app;
	
	Camera camera(glm::vec3(0.5f, 2.0f, 8.0f),  // λ��
		glm::vec3(0.0f, 0.0f, 0.0f),  // Ŀ���
		glm::vec3(0.0f, 1.0f, 0.0f), // ������
		45.0f,                        // ��Ұ�Ƕ�
		800.0f / 600.0f,              // ��߱�
		0.1f,                         // ���ü���
		100.0f);                      // Զ�ü���

	app.initOpenGL(800,600); //���������г�ʼ��֮ǰ������opengl�����ĵ�����
	app.createScene();
	app.createRenderer();

	// ������
	ShaderProgram* shaderProgram = new ShaderProgram("assets/shaders/1vertShader.glsl", "assets/shaders/1fragShader.glsl");
	Material* material = new Material(shaderProgram);
	Mesh* mesh = new Mesh(vertexPositions, 108*sizeof(float), {0,3,GL_FLOAT,GL_FALSE,0,0});
	Model* cubeModel = new Model(mesh,108/3);
	SceneNode* cubeNode = new SceneNode("cubeNode", cubeModel, material);
	cubeNode->transform = glm::translate(glm::mat4(1.0f), glm::vec3(-2, -2, 0));
	app.scene->addNode(cubeNode);
	
	// ������
	//ShaderProgram* shaderProgram2 = new ShaderProgram("assets/shaders/1vertShader.glsl", "assets/shaders/1fragShader.glsl");
	//Material* material2 = new Material(shaderProgram2);
	//Mesh* mesh2 = new Mesh(vertexPositions, 108 * sizeof(float), { 0,3,GL_FLOAT,GL_FALSE,0,0 });
	//Model* cubeModel2 = new Model(mesh, 108 / 3);
	SceneNode* cubeNode2 = new SceneNode("cubeNode2", cubeModel, material);
	cubeNode2->transform = glm::translate(glm::mat4(1.0f), glm::vec3(2, 2, 0));
	//app.scene->addNode(cubeNode2);
	cubeNode->addChild(cubeNode2);


	app.scene->setMainCamera(&camera);

	app.initSceneRenderer();

	printTest(app.scene);

	app.run();
	app.cleanup();

}



