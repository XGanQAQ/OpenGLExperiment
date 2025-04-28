#pragma once
#include "SceneNode.h"
class LightModelNode : public SceneNode
{
public:
	LightModelNode();
	~LightModelNode();

	void inject_uniforms() override;
};