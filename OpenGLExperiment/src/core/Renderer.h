#pragma once
#include <GL/glew.h>
#include <vector>
#include<string>
#include "VertexArrayObject.h"
#include "ShaderProgram.h"
#include "Scene.h"
#include "..\include\GLFW\glfw3.h"
#include "Material.h"
#include "Camera.h"
#include "SceneNode.h"

class SceneNode;
class Scene;

class Renderer {
public:
	Renderer();
    //std::vector<Texture*> textures
    //FrameBuffer* frameBuffer;
    Scene* mainScene;
    Camera* mainCamera;


    void initialize();
    void render(ShaderProgram* shaderProgram, VertexArrayObject* vao);
	void render(Model* model,Material* material);
    void render(SceneNode* sceneNode);
    void render(Scene* scene);
    void render(GLFWwindow* window, double currentTime);
    //void bindFrameBuffer(FrameBuffer* fb)
	void clearScreen();

private:
};
