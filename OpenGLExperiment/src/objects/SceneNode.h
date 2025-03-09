#pragma once
#include "../include/GL/glew.h"
#include <vector>
#include "../base/VertexArrayObject.h"
#include "../base/VertexBufferElement.h"
#include "../component/Model.h"
#include "../component/Material.h"
#include "BaseNode.h"

// 前向声明
class Model;
class Renderer;

class SceneNode : public BaseNode
{
public:
	SceneNode(std::string nodeName, Model* model,Material* material) :BaseNode(nodeName), model(model),material(material) {}
	
	Model* model = nullptr;
	Material* material = nullptr;
	
	void initNode() override; // 初始化节点，用于渲染前的准备工作
	void initUniforms(); // 初始化uniform变量，用于渲染前的准备工作
private:

};