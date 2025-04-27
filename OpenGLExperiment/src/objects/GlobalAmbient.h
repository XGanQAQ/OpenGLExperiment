#pragma once
#include "BaseNode.h"
#include "GL/glew.h"
class GlobalAmbient : BaseNode
{
public:
	GlobalAmbient(glm::vec4 energy, glm::vec4 color);
	~GlobalAmbient();
	void setAmbientColor(glm::vec4 color) { globalAmbientColor = color; }
	void setAmbientEnergy(glm::vec4 energy) { globalAmbient = energy; }
	glm::vec4 getAmbientColor() { return globalAmbientColor; }
	glm::vec4 getAmbientEnergy() { return globalAmbient; }
private:
	glm::vec4 globalAmbientColor = glm::vec4(0.1f, 0.1f, 0.1f,1.0f);
	glm::vec4 globalAmbient = glm::vec4(0.6f, 0.6f, 0.6f, 1.0f);

};
