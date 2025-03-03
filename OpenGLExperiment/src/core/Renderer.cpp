#include "Renderer.h"
#include "../tools/Utils.h"
#include <iostream>

using namespace std;


Renderer::Renderer()
{
}

void Renderer::initialize() {
	// 初始化着色器程序
	shaderProgram = new ShaderProgram();
	shaderProgram->compile_path("assets/shaders/testVertShader.glsl", "assets/shaders/testFragShader.glsl");
	// 初始化顶点数组对象
	vao = new VertexArrayObject();
    vao->create();
	vao->bind();
	// 初始化纹理
	//loadTexture("textures/container.jpg");
	//loadTexture("textures/awesomeface.png");
	// 初始化帧缓冲
	//frameBuffer = new FrameBuffer();
	// 初始化相机
	//camera = new Camera();
	// 初始化光照
	//light = new Light();
	// 初始化模型
	//model = new Model();
	// 初始化天空盒
	//skybox = new Skybox();
	// 初始化水面
	//water = new Water();
	// 初始化草地
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
	// 清屏
	clearScreen();
	// 设置着色器程序
	shaderProgram->use();
	// 设置相机
	//shaderProgram->setMat4("view", camera->getViewMatrix());
	//shaderProgram->setMat4("projection", camera->getProjectionMatrix());
	// 设置光照
	//shaderProgram->setVec3("light.position", light->position);
	//shaderProgram->setVec3("light.ambient", light->ambient);
	//shaderProgram->setVec3("light.diffuse", light->diffuse);
	//shaderProgram->setVec3("light.specular", light->specular);
	// 设置材质
	//shaderProgram->setVec3("material.ambient", model->material->ambient);
	//shaderProgram->setVec3("material.diffuse", model->material->diffuse);
	//shaderProgram->setVec3("material.specular", model->material->specular);
	//shaderProgram->setFloat("material.shininess", model->material->shininess);
	// 设置天空盒
	//shaderProgram->setMat4("view", glm::mat4(glm::mat3(camera->getViewMatrix())));
	//skybox->render(this);
	// 设置水面
	//shaderProgram->setMat4("view", camera->getViewMatrix());
	//shaderProgram->setMat4("projection", camera->getProjectionMatrix());
	//water->render(this);
	// 设置草地
	//shaderProgram->setMat4("view", camera->getViewMatrix());
	//shaderProgram->setMat4("projection", camera->getProjectionMatrix());
	//grass->render(this);
	// 渲染场景
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

	// 绑定
	vbo->bind();
    // 设置顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

	// 绘制
	glDrawArrays(GL_TRIANGLES, 0, vbo->size / 3);
}



