#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "SOIL2/soil2.h"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Renderer.h"
#include "Scene.h"
#include "../ui/ImGuiUI.h"
#include <string>
#include <iostream>
#include <fstream>

//- **Application(应用层) * *
//- 负责初始化OpenGL上下文、窗口管理、主循环等。
//- 处理用户输入（鼠标、键盘等）。
//- 调度其他模块的更新和渲染。
class Application
{
public:
	Application();
	GLFWwindow* window;
	int screenWidth, screenHeight;
	bool isRunning;
	Renderer* renderer;
	Scene* scene;
	ImGuiUI* ui;

	void initOpenGL(int width, int height);
	void createScene();
	void createRenderer();
	void createUI();
	void createNodeTreeManager(BaseNode* rootNode);
	void initSceneRenderer();
	void run();
	void processInput();
	void cleanup();
	static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
	void onResize(int newWidth, int newHeight);

private:
	double currentTime;
};
