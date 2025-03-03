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

//- **Application(Ӧ�ò�) * *
//- �����ʼ��OpenGL�����ġ����ڹ�����ѭ���ȡ�
//- �����û����루��ꡢ���̵ȣ���
//- ��������ģ��ĸ��º���Ⱦ��
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
