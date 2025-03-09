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
    void render(Scene* scene);
    void render(BaseNode* sceneNode);
	void render_Array(Model* model,Material* material);
    void render_Element(Model* model);
    void render_Element(Model* model, Material* material);
    //void bindFrameBuffer(FrameBuffer* fb)
	void clearScreen();

private:
};
