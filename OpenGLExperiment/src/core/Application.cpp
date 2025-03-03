#include "Application.h"
#include "Renderer.h"
#include <string>
#include <iostream>
#include <fstream>


Application::Application()
{
}

void Application::initialize() {
	// Initialize the library
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		return;
	}

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
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

	// Enable depth test
	//glEnable(GL_DEPTH_TEST);

	// Enable blending
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Enable face culling
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glFrontFace(GL_CCW);

	// Set the clear color
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	// Create a renderer
	renderer = new Renderer();
	renderer->initialize();

	// Create a scene
	scene = new Scene();
	scene->initialize();
}

void Application::initialize(int width, int height, Renderer* renderer, Scene* scene)
{	
	screenWidth = width;
	screenHeight = height;

	// Initialize the library
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		return;
	}

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(screenWidth, screenHeight, "Hello World", NULL, NULL);
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

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	this->renderer = renderer;
	this->scene = scene;
}

void Application::run() {
	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		// Process input
		processInput();

		// Render here
		renderer->render(window,glfwGetTime());

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