#pragma once
#include "..\include\GL\glew.h"
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <vector>
#include "VertexArrayObject.h"
#include "VertexBufferLayout.h"
#include "Model.h"
#include "Renderer.h"
#include "Material.h"

// ǰ������
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
	SceneNode* parent;
	glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

	Model* model;
	Material* material;

	void update(float deltaTime);
	void addChild(SceneNode* child);
	void removeChild(SceneNode* child);
	void setTransform(const glm::mat4& transform);
	
	void initialize(); // ��ʼ�������ڵ㣬������ʼ���ӽڵ㡢ģ�͡����ʵ�
	void initUniforms(); // ��ʼ��uniform������������Ⱦǰ��׼������
private:

};