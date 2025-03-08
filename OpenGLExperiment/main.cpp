#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "src/tools/Utils.h"
#include "src/core/Application.h"
#include "src/tools/GeometryGenerator.h"
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

	GeometryGenerator::MeshData cubeMeshData = GeometryGenerator::createCube(1.0f);
	Mesh* cubePosMesh = GeometryGenerator::extractPositionMesh(cubeMeshData);
	Model* cubeModel = new Model(cubePosMesh, cubeMeshData.indices);

	GeometryGenerator::MeshData sphereMeshData = GeometryGenerator::createSphere(1.0f, 36, 18);
	Mesh* spherePosMesh = GeometryGenerator::extractPositionMesh(sphereMeshData);
	Model* sphereModel = new Model(spherePosMesh, sphereMeshData.indices);
	GeometryGenerator::MeshData coneMeshData = GeometryGenerator::createCone(1.0f, 2.0f, 36);
	Mesh* conePosMesh = GeometryGenerator::extractPositionMesh(coneMeshData);
	Model* coneModel = new Model(conePosMesh, coneMeshData.indices);
	GeometryGenerator::MeshData tetrahedronMeshData = GeometryGenerator::createTetrahedron(1.0f);
	Mesh* tetrahedronPosMesh = GeometryGenerator::extractPositionMesh(tetrahedronMeshData);
	Model* tetrahedronModel = new Model(tetrahedronPosMesh, tetrahedronMeshData.indices);

	// ������
	ShaderProgram* shaderProgram = new ShaderProgram("assets/shaders/1vertShader.glsl", "assets/shaders/1fragShader.glsl");
	Material* material = new Material(shaderProgram);
	SceneNode* cubeNode = new SceneNode("cubeNode", cubeModel, material);
	cubeNode->transform = glm::translate(glm::mat4(1.0f), glm::vec3(-2, -2, 0));
	app.scene->addNode(cubeNode);

	SceneNode* sphereNode = new SceneNode("sphereNode", sphereModel, material);
	sphereNode->transform = glm::translate(glm::mat4(1.0f), glm::vec3(2, 2, 0));
	app.scene->addNode(sphereNode);

	SceneNode* coneNode = new SceneNode("coneNode", coneModel, material);
	coneNode->transform = glm::translate(glm::mat4(1.0f), glm::vec3(-2, 2, 0));
	app.scene->addNode(coneNode);

	SceneNode* tetrahedronNode = new SceneNode("tetrahedronNode", tetrahedronModel, material);
	tetrahedronNode->transform = glm::translate(glm::mat4(1.0f), glm::vec3(2, -2, 0));
	app.scene->addNode(tetrahedronNode);


	app.scene->setMainCamera(&camera);

	app.initSceneRenderer();

	printTest(app.scene);

	app.run();
	app.cleanup();

}



