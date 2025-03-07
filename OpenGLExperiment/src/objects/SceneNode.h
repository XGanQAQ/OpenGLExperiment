#pragma once
#include "../include/GL/glew.h"
#include <vector>
#include "../base/VertexArrayObject.h"
#include "../base/VertexBufferElement.h"
#include "../component/Model.h"
#include "../component/Material.h"

// 前向声明
class Model;
class Renderer;

class SceneNode
{
public:
	SceneNode(std::string nodeName):nodeName(nodeName){}
	SceneNode(std::string nodeName, Model* model) :nodeName(nodeName), model(model) {}
	SceneNode(std::string nodeName, Model* model,Material* material) :nodeName(nodeName), model(model),material(material) {}

	std::string nodeName;
	std::vector<SceneNode*> children;
	SceneNode* parent = nullptr;
	glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

	Model* model = nullptr;
	Material* material = nullptr;

	void update(float deltaTime);
	void addChild(SceneNode* child);
	void removeChild(SceneNode* child);
	void setTransform(const glm::mat4& transform);
	
	void initialize(); // 初始化场景节点，包括初始化子节点、模型、材质等
	void initUniforms(); // 初始化uniform变量，用于渲染前的准备工作
private:

};