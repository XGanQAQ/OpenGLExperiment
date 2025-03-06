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

void Application::onResize(GLFWwindow* win, int newWidth, int newHeight) {
	screenWidth = newWidth;
	screenHeight = newHeight;
	glViewport(0, 0, screenWidth, screenHeight);
}