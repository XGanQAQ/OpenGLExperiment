#pragma once
#include "..\include\GL\glew.h"
#include "..\include\GLFW\glfw3.h"
#include "..\include\SOIL2\soil2.h"
#include "..\include\glm\gtc\type_ptr.hpp"
#include "..\include\glm\gtc\matrix_transform.hpp"
#include "Renderer.h"
#include "Scene.h"
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

	void initialize();
	void initialize(int width, int height, Renderer* renderer, Scene* scene);
	void run();
	void processInput();
	void cleanup();
	void onResize(GLFWwindow* win, int newWidth, int newHeight);

private:
	double currentTime;
};
