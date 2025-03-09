#pragma once
#include "../include/GL/glew.h"
#include <vector>
#include "../base/VertexArrayObject.h"
#include "../base/VertexBufferElement.h"
#include "../component/Model.h"
#include "../component/Material.h"
#include "BaseNode.h"

// ǰ������
class Model;
class Renderer;

class SceneNode : public BaseNode
{
public:
	SceneNode(std::string nodeName, Model* model,Material* material) :BaseNode(nodeName), model(model),material(material) {}
	
	Model* model = nullptr;
	Material* material = nullptr;
	
	void initNode() override; // ��ʼ���ڵ㣬������Ⱦǰ��׼������
	void initUniforms(); // ��ʼ��uniform������������Ⱦǰ��׼������
private:

};