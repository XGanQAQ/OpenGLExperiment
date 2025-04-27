#pragma once
#include "BaseNode.h"
#include "GL/glew.h"
using namespace glm;
class DirLight: public BaseNode
{
public:
	DirLight();
	DirLight(vec4 ambient,vec4 diffuse,vec4 specular);
	~DirLight();

	vec4 getDirLightAmbient() { return dirLightAmbient; }
	vec4 getDirLightDiffuse() { return dirLightDiffuse; }
	vec4 getDirLightSpecular() { return dirLightSpecular; }
	vec3 getDirLightPosition() { return getPosition(); } // λ�ü�Ϊλ��
	vec3 getDirLightDirection() { return getRotation(); } // ����Ϊ��ת�Ƕ�

private:
	vec4 dirLightAmbient = vec4(0.1f, 0.1f, 0.1f, 1.0f);
	vec4 dirLightDiffuse = vec4(0.6f, 0.6f, 0.6f, 1.0f);
	vec4 dirLightSpecular = vec4(0.6f, 0.6f, 0.6f, 1.0f);
};
