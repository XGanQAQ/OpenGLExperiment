#include "Renderer.h"
#include "../tools/Utils.h"
#include <iostream>

using namespace std;


Renderer::Renderer()
{
}

void Renderer::initialize() {
	// ��ʼ����ɫ������
	shaderProgram = new ShaderProgram();
	shaderProgram->compile_path("assets/shaders/testVertShader.glsl", "assets/shaders/testFragShader.glsl");
	// ��ʼ�������������
	vao = new VertexArrayObject();
    vao->create();
	vao->bind();
	// ��ʼ������
	//loadTexture("textures/container.jpg");
	//loadTexture("textures/awesomeface.png");
	// ��ʼ��֡����
	//frameBuffer = new FrameBuffer();
	// ��ʼ�����
	//camera = new Camera();
	// ��ʼ������
	//light = new Light();
	// ��ʼ��ģ��
	//model = new Model();
	// ��ʼ����պ�
	//skybox = new Skybox();
	// ��ʼ��ˮ��
	//water = new Water();
	// ��ʼ���ݵ�
	//grass = new Grass
}

void Renderer::initialize(ShaderProgram* shaderProgram)
{
	this->shaderProgram = shaderProgram;
	vao = new VertexArrayObject();
	vao->create();
	vao->bind();
}

void Renderer::render(Scene* scene) {
	// ����
	clearScreen();
	// ������ɫ������
	shaderProgram->use();
	// �������
	//shaderProgram->setMat4("view", camera->getViewMatrix());
	//shaderProgram->setMat4("projection", camera->getProjectionMatrix());
	// ���ù���
	//shaderProgram->setVec3("light.position", light->position);
	//shaderProgram->setVec3("light.ambient", light->ambient);
	//shaderProgram->setVec3("light.diffuse", light->diffuse);
	//shaderProgram->setVec3("light.specular", light->specular);
	// ���ò���
	//shaderProgram->setVec3("material.ambient", model->material->ambient);
	//shaderProgram->setVec3("material.diffuse", model->material->diffuse);
	//shaderProgram->setVec3("material.specular", model->material->specular);
	//shaderProgram->setFloat("material.shininess", model->material->shininess);
	// ������պ�
	//shaderProgram->setMat4("view", glm::mat4(glm::mat3(camera->getViewMatrix())));
	//skybox->render(this);
	// ����ˮ��
	//shaderProgram->setMat4("view", camera->getViewMatrix());
	//shaderProgram->setMat4("projection", camera->getProjectionMatrix());
	//water->render(this);
	// ���òݵ�
	//shaderProgram->setMat4("view", camera->getViewMatrix());
	//shaderProgram->setMat4("projection", camera->getProjectionMatrix());
	//grass->render(this);
	// ��Ⱦ����
	scene->rootNode->render(this);
}

void Renderer::render(GLFWwindow* window, double currentTime)
{
	shaderProgram->use();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderer::setShaderProgram(ShaderProgram* shader) {
	shaderProgram = shader;
}

void Renderer::loadTexture(const std::string& path) {
	//Texture* texture = new Texture();
	//texture->load(path);
	//textures.push_back(texture);
}

void Renderer::clearScreen() {
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}


void Renderer::draw(VertexBuffer* vbo) {

	// ��
	vbo->bind();
    // ���ö�������ָ��
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

	// ����
	glDrawArrays(GL_TRIANGLES, 0, vbo->size / 3);
}



