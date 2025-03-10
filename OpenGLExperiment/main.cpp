#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "src/tools/Utils.h"
#include "src/core/Application.h"
#include "src/tools/GeometryGenerator.h"
#include <iostream>
#include <string>
#include "src/tools/ImportedModel.h"

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

void window_size_callback(GLFWwindow* win, int newWidth, int newHeight) {
}

int main(void) {
	Application app;
	
	Camera camera(glm::vec3(0.5f, 2.0f, 8.0f),  // 位置
		glm::vec3(0.0f, 0.0f, 0.0f),  // 目标点
		glm::vec3(0.0f, 1.0f, 0.0f), // 上向量
		45.0f,                        // 视野角度
		800.0f / 600.0f,              // 宽高比
		0.1f,                         // 近裁剪面
		100.0f);                      // 远裁剪面


	app.initOpenGL(1000,800); //必须在所有初始化之前，包含opengl上下文的设置

	app.createScene();
	app.createRenderer();
	//——————————————————生成模型
	//导入的模型
	ImportedModel model = ImportedModel("assets/models/pyr.obj");
	Mesh* importedPosMesh = model.getPosMesh();
	Mesh* importedNormalMesh = model.getNormalMesh();
	Mesh* importedTexMesh = model.getTexMesh();
	Model* importedModel = new Model(importedPosMesh, importedNormalMesh, importedTexMesh, model.getNumVertices());

	GeometryGenerator::MeshData cubeMeshData = GeometryGenerator::createCube(1.0f);
	Mesh* cubePosMesh = GeometryGenerator::extractPositionMesh(cubeMeshData);
	Mesh* cubeNormalMesh = GeometryGenerator::extractNormalMesh(cubeMeshData);
	Mesh* cubeTexMesh = GeometryGenerator::extractTexMesh(cubeMeshData);
	Model* cubeModel = new Model(cubePosMesh, cubeNormalMesh,cubeTexMesh,cubeMeshData.indices);

	GeometryGenerator::MeshData sphereMeshData = GeometryGenerator::createSphere(1.0f, 36, 18);
	Mesh* spherePosMesh = GeometryGenerator::extractPositionMesh(sphereMeshData);
	Mesh* sphereNormalMesh = GeometryGenerator::extractNormalMesh(sphereMeshData);
	Mesh* sphereTexMesh = GeometryGenerator::extractTexMesh(sphereMeshData);
	Model* sphereModel = new Model(spherePosMesh, sphereNormalMesh, sphereTexMesh, sphereMeshData.indices);

	GeometryGenerator::MeshData coneMeshData = GeometryGenerator::createCone(1.0f, 2.0f, 36);
	Mesh* conePosMesh = GeometryGenerator::extractPositionMesh(coneMeshData);
	Mesh* coneNormalMesh = GeometryGenerator::extractNormalMesh(coneMeshData);
	Mesh* coneTexMesh = GeometryGenerator::extractTexMesh(coneMeshData);
	Model* coneModel = new Model(conePosMesh, coneNormalMesh, coneTexMesh, coneMeshData.indices);

	GeometryGenerator::MeshData tetrahedronMeshData = GeometryGenerator::createTetrahedron(2.0f);
	Mesh* tetrahedronPosMesh = GeometryGenerator::extractPositionMesh(tetrahedronMeshData);
	Mesh* tetrahedronNormalMesh = GeometryGenerator::extractNormalMesh(tetrahedronMeshData);
	Mesh* tetrahedronTexMesh = GeometryGenerator::extractTexMesh(tetrahedronMeshData);
	Model* tetrahedronModel = new Model(tetrahedronPosMesh, tetrahedronNormalMesh, tetrahedronTexMesh, tetrahedronMeshData.indices);

	//——————————————————设置材质
	//基础材质
	ShaderProgram* shaderProgram = new ShaderProgram("assets/shaders/1vertShader.glsl", "assets/shaders/1fragShader.glsl");
	Material* material = new Material(shaderProgram);
	//纹理材质1
	ShaderProgram* shaderProgram_texture = new ShaderProgram("assets/shaders/TexVShader.glsl", "assets/shaders/TexFShader.glsl");
	Texture* texture = new Texture("assets/textures/brick1.jpg");
	Material* material_texture = new Material(shaderProgram_texture, texture);
	//纹理材质2 图片和1不同
	ShaderProgram* shaderProgram_texture2 = new ShaderProgram("assets/shaders/TexVShader.glsl", "assets/shaders/TexFShader.glsl");
	Texture* texture2 = new Texture("assets/textures/brick1upArrow.jpg");
	Material* material_texture2 = new Material(shaderProgram_texture2, texture2);

	//——————————————————构造添加节点
	SceneNode* importedModelNode = new SceneNode("importedModelNode", importedModel, material_texture);
	importedModelNode->setPosition(glm::vec3(0, 0, 0));
	app.scene->addNode(importedModelNode);

	SceneNode* cubeNode = new SceneNode("cubeNode", cubeModel, material_texture);
	cubeNode->setPosition(glm::vec3(-2,2,0));
	app.scene->addNode(cubeNode);

	SceneNode* sphereNode = new SceneNode("sphereNode", sphereModel, material_texture2);
	sphereNode->setPosition(glm::vec3(2, 2, 0));
	app.scene->addNode(sphereNode);

	SceneNode* coneNode = new SceneNode("coneNode", coneModel, material_texture);
	coneNode->setPosition(glm::vec3(-2, -2, 0));
	app.scene->addNode(coneNode);

	SceneNode* tetrahedronNode = new SceneNode("tetrahedronNode", tetrahedronModel, material_texture2);
	tetrahedronNode->setPosition(glm::vec3(2, -2, 0));
	app.scene->addNode(tetrahedronNode);

	//——————————————————设置相机
	app.scene->setMainCamera(&camera);
	app.scene->addNode(&camera);

	//——————————————————初始化渲染器
	app.initSceneRenderer();

	//——————————————————打印场景树
	printTest(app.scene);

	//——————————————————运行
	app.run();
	app.cleanup();

}



