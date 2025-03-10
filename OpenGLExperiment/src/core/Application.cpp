#include "Application.h"
#include "Renderer.h"
#include <string>
#include <iostream>
#include <fstream>


Application::Application()
{
}

void Application::initOpenGL(int width, int height) {
	// Initialize the library
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		return;
	}

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::cout << "Failed to create window" << std::endl;
		return;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return;
	}

	// Set the viewport
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
	glViewport(0, 0, screenWidth, screenHeight);

	// Set the clear color
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	// 设置用户指针为当前 Application 实例
	glfwSetWindowUserPointer(window, this);

	// 设置帧缓冲区大小回调
	glfwSetFramebufferSizeCallback(window,framebufferSizeCallback);
}

void Application::createScene()
{
	scene = new Scene();
}

void Application::createRenderer()
{
	renderer = new Renderer();
}

void Application::initSceneRenderer()
{	
	renderer->initialize();
	scene->initialize();
}

void Application::run() {
	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		// Process input
		processInput();

		// Render here
		renderer->render(scene);

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}
}

void Application::processInput() {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void Application::cleanup() {
	// Terminate GLFW
	glfwTerminate();
}

// 静态回调函数，用于桥接 GLFW 回调和成员函数
void Application::framebufferSizeCallback(GLFWwindow* window, int width, int height) 

{
	// 获取存储在窗口中的 Application 实例指针
	Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));
	if (app)
	{
		// 调用成员函数处理窗口大小变化
		app->onResize(width, height);
	}
	else
	{
		std::cerr << "Failed to get Application instance" << std::endl;
	}
}

// 成员函数处理窗口大小变化
void Application::onResize(int newWidth, int newHeight) {
	screenWidth = newWidth;
	screenHeight = newHeight;
	glViewport(0, 0, screenWidth, screenHeight);
	std::cout << "窗口帧缓冲区大小变化为：" << screenWidth << " x " << screenHeight << std::endl;
}