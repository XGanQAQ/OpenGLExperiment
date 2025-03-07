#pragma once
#include "../include/GL/glew.h"
#include "../base/ShaderProgram.h"
#include "Scene.h"
#include "../component/Material.h"
#include "../component/Model.h"
#include "../objects/Camera.h"
#include "../objects/SceneNode.h"

class Renderer {
public:
	Renderer();
    //std::vector<Texture*> textures
    //FrameBuffer* frameBuffer;
    Scene* mainScene;
    Camera* mainCamera;


    void initialize();
	void render(Model* model,Material* material);
    void render(SceneNode* sceneNode);
    void render(Scene* scene);
    //void bindFrameBuffer(FrameBuffer* fb)
	void clearScreen();

private:
};
