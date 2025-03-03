#pragma once
#include <GL/glew.h>
#include <vector>
#include<string>
#include "VertexArrayObject.h"
#include "ShaderProgram.h"
#include "Scene.h"
#include "..\include\GLFW\glfw3.h"

class Scene;

class Renderer {
public:
	Renderer();
    void initialize();
	void initialize(ShaderProgram* shaderProgram);
    void render(Scene* scene);
    void render(GLFWwindow* window, double currentTime);
    void setShaderProgram(ShaderProgram* shader);
    void loadTexture(const std::string& path);
    //void bindFrameBuffer(FrameBuffer* fb)
	void clearScreen();
    void draw(VertexBuffer* vbo);

private:
    ShaderProgram* shaderProgram;
    //std::vector<Texture*> textures
	//FrameBuffer* frameBuffer;
    VertexArrayObject* vao;
    //Camera* camera

};
