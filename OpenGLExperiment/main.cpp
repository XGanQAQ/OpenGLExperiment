#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "src/tools/Utils.h"
#include "src/core/Application.h"
#include "src/tools/GeometryGenerator.h"
#include <iostream>
#include <string>
#include "src/tools/ImportedModel.h"

#include "src/base/LightModelStruct.h"

using namespace std;

#pragma region test

void printTest(Scene* scene) {
	scene->printSceneTree(0, scene->rootNode);
}

void CHECK_GL_ERROR(int a) {
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cerr << "OpenGL error at " << a << ": " << err << std::endl;
	}
}

void TestCreateModelAndAddTexture(Application app) {
	//����������������������������������������ģ��
	//�����ģ��
	ImportedModel model = ImportedModel("assets/models/pyr.obj");
	Mesh* importedPosMesh = model.getPosMesh();
	Mesh* importedNormalMesh = model.getNormalMesh();
	Mesh* importedTexMesh = model.getTexMesh();
	Model* importedModel = new Model(importedPosMesh, importedNormalMesh, importedTexMesh, model.getNumVertices());

	GeometryGenerator::MeshData cubeMeshData = GeometryGenerator::createCube(1.0f);
	Mesh* cubePosMesh = GeometryGenerator::extractPositionMesh(cubeMeshData);
	Mesh* cubeNormalMesh = GeometryGenerator::extractNormalMesh(cubeMeshData);
	Mesh* cubeTexMesh = GeometryGenerator::extractTexMesh(cubeMeshData);
	Model* cubeModel = new Model(cubePosMesh, cubeNormalMesh, cubeTexMesh, cubeMeshData.indices);

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

	//���������������������������������������ò���
	//��������
	ShaderProgram* shaderProgram = new ShaderProgram("assets/shaders/1vertShader.glsl", "assets/shaders/1fragShader.glsl");
	Material* material = new Material(shaderProgram);
	//�������1
	ShaderProgram* shaderProgram_texture = new ShaderProgram("assets/shaders/TexVShader.glsl", "assets/shaders/TexFShader.glsl");
	Texture* texture = new Texture("assets/textures/brick1.jpg");
	Material* material_texture = new Material(shaderProgram_texture, texture);
	//�������2 ͼƬ��1��ͬ
	ShaderProgram* shaderProgram_texture2 = new ShaderProgram("assets/shaders/TexVShader.glsl", "assets/shaders/TexFShader.glsl");
	Texture* texture2 = new Texture("assets/textures/brick1upArrow.jpg");
	Material* material_texture2 = new Material(shaderProgram_texture2, texture2);

	//������������������������������������������ӽڵ�
	SceneNode* importedModelNode = new SceneNode("importedModelNode", importedModel, material_texture);
	importedModelNode->setPosition(glm::vec3(0, 0, 0));
	app.scene->addNode(importedModelNode);

	SceneNode* cubeNode = new SceneNode("cubeNode", cubeModel, material_texture);
	cubeNode->setPosition(glm::vec3(-2, 2, 0));
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
}

#pragma endregion



int main(void) {
	Application app;

	Camera camera(glm::vec3(0.0f, 0.0f, 8.0f),  // λ��
		glm::vec3(0.0f, 0.0f, 0.0f),  // Ŀ���
		glm::vec3(0.0f, 1.0f, 0.0f), // ������
		45.0f,                        // ��Ұ�Ƕ�
		800.0f / 600.0f,              // ��߱�
		0.1f,                         // ���ü���
		100.0f);                      // Զ�ü���


	app.initOpenGL(1920, 1080); //���������г�ʼ��֮ǰ������opengl�����ĵ�����

	app.createScene();
	app.createRenderer();
	app.createUI();
	app.createNodeTreeManager(app.scene->rootNode);

	//����������������������������������������ģ��

	GeometryGenerator::MeshData sphereMeshData = GeometryGenerator::createSphere(1.0f, 36, 18);
	Mesh* spherePosMesh = GeometryGenerator::extractPositionMesh(sphereMeshData);
	Mesh* sphereNormalMesh = GeometryGenerator::extractNormalMesh(sphereMeshData);
	Mesh* sphereTexMesh = GeometryGenerator::extractTexMesh(sphereMeshData);
	Model* sphereModel = new Model(spherePosMesh, sphereNormalMesh, sphereTexMesh, sphereMeshData.indices);

	//���������������������������������������ò���
	//��������
	ShaderProgram* baseShaderProgram = new ShaderProgram(
		"assets/shaders/1vertShader.glsl", 
		"assets/shaders/1fragShader.glsl");
	Material* baseMaterial = new Material(baseShaderProgram);
	//�������
	// 
	//���ղ���
	// Gouraud Shader
	ShaderProgram* gouraudShaderProgram = new ShaderProgram(
		"assets/shaders/GouraudShaders/vertShader.glsl", 
		"assets/shaders/GouraudShaders/fragShader.glsl");
	Material* gouraudMaterial = new Material(gouraudShaderProgram);
	// Phong Shader
	ShaderProgram* phongShaderProgram = new ShaderProgram(
		"assets/shaders/PhongShaders/vertShader.glsl",
		"assets/shaders/PhongShaders/fragShader.glsl");
	Material* phongMaterial = new Material(phongShaderProgram);
	// Blinn-Phong Shader
	ShaderProgram* blinnPhongShaderProgram = new ShaderProgram(
		"assets/shaders/BlinnPhongShaders/vertShader.glsl",
		"assets/shaders/BlinnPhongShaders/fragShader.glsl");
	Material* blinnPhongMaterial = new Material(blinnPhongShaderProgram);


	//������������������������������������������ӽڵ�

	SceneNode* sphereNode = new SceneNode("gouraudSphere", sphereModel, gouraudMaterial);
	sphereNode->setPosition(glm::vec3(2, 2, 0));
	app.scene->addNode(sphereNode);

	SceneNode* sphereNode2 = new SceneNode("phongSphere", sphereModel, phongMaterial);
	sphereNode2->setPosition(glm::vec3(-2, -2, 0));
	app.scene->addNode(sphereNode2);

	SceneNode* spherNode3 = new SceneNode("BlinePhongSphere", sphereModel, blinnPhongMaterial);
	spherNode3->setPosition(glm::vec3(-2, 2, 0));
	app.scene->addNode(spherNode3);


	//�������������������������������������������
	app.scene->setMainCamera(&camera);
	app.scene->addNode(&camera);


	//���������������������������������������ù���
	//ȫ�ֻ�����
	GlobalAmbient* globalAmbient = new GlobalAmbient(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f), glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
	app.scene->setGlobalAmbient(globalAmbient);
	//ƽ�й�
	DirLight* dirLight = new DirLight(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f), glm::vec4(0.8f, 0.8f, 0.8f, 1.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	dirLight->setPosition(glm::vec3(10.0, 10.0, 10.0)); // ���ù�Դλ��
	app.scene->setDirLight(dirLight);
	app.scene->addNode(dirLight);

	//��������ģ�Ͳ���
	LightModel::Material lightModelMaterial = {
		glm::vec4(0.1f, 0.1f, 0.1f, 1.0f), // ������
		glm::vec4(0.6f, 0.6f, 0.6f, 1.0f), // �������
		glm::vec4(0.6f, 0.6f, 0.6f, 1.0f), // �����
		32.0f // �߹�ϵ��
	};

	// ���ù�����Ϣ
	gouraudMaterial->setUniformVec4("globalAmbient", globalAmbient->getAmbientEnergy());

	gouraudMaterial->setUniformVec4("light.ambient", dirLight->getDirLightAmbient());
	gouraudMaterial->setUniformVec4("light.diffuse", dirLight->getDirLightDiffuse());
	gouraudMaterial->setUniformVec4("light.specular", dirLight->getDirLightSpecular());
	gouraudMaterial->setUniformVec3("light.position", dirLight->getDirLightPosition());

	// ���ò�����Ϣ
	gouraudMaterial->setUniformVec4("material.ambient", glm::vec4(lightModelMaterial.ambient));
	gouraudMaterial->setUniformVec4("material.diffuse", glm::vec4(lightModelMaterial.diffuse));
	gouraudMaterial->setUniformVec4("material.specular", glm::vec4(lightModelMaterial.specular));
	gouraudMaterial->setUniformFloat("material.shininess", 32.0f);
	
	// ���ù�����Ϣ - Phong Shader
	phongMaterial->setUniformVec4("globalAmbient", globalAmbient->getAmbientEnergy());

	phongMaterial->setUniformVec4("light.ambient", dirLight->getDirLightAmbient());
	phongMaterial->setUniformVec4("light.diffuse", dirLight->getDirLightDiffuse());
	phongMaterial->setUniformVec4("light.specular", dirLight->getDirLightSpecular());
	phongMaterial->setUniformVec3("light.position", dirLight->getDirLightPosition());

	// ���ò�����Ϣ - Phong Shader
	phongMaterial->setUniformVec4("material.ambient", glm::vec4(lightModelMaterial.ambient));
	phongMaterial->setUniformVec4("material.diffuse", glm::vec4(lightModelMaterial.diffuse));
	phongMaterial->setUniformVec4("material.specular", glm::vec4(lightModelMaterial.specular));
	phongMaterial->setUniformFloat("material.shininess", 32.0f);

	// ���ù�����Ϣ - Blinn-Phong Shader
	blinnPhongMaterial->setUniformVec4("globalAmbient", globalAmbient->getAmbientEnergy());

	blinnPhongMaterial->setUniformVec4("light.ambient", dirLight->getDirLightAmbient());
	blinnPhongMaterial->setUniformVec4("light.diffuse", dirLight->getDirLightDiffuse());
	blinnPhongMaterial->setUniformVec4("light.specular", dirLight->getDirLightSpecular());
	blinnPhongMaterial->setUniformVec3("light.position", dirLight->getDirLightPosition());

	// ���ò�����Ϣ - Blinn-Phong Shader
	blinnPhongMaterial->setUniformVec4("material.ambient", glm::vec4(lightModelMaterial.ambient));
	blinnPhongMaterial->setUniformVec4("material.diffuse", glm::vec4(lightModelMaterial.diffuse));
	blinnPhongMaterial->setUniformVec4("material.specular", glm::vec4(lightModelMaterial.specular));
	blinnPhongMaterial->setUniformFloat("material.shininess", 32.0f);


	//��������������������������������������ʼ����Ⱦ��
	app.initSceneRenderer();

	//��������������������������������������ӡ������
	printTest(app.scene);

	//����������������������������������������
	app.run();
	app.cleanup();

}



