#include "DirLight.h"
DirLight::DirLight() :BaseNode("DirLight")
{
}
DirLight::DirLight(vec4 ambient, vec4 diffuse, vec4 specular) :BaseNode("DirLight")
{
	dirLightAmbient = ambient;
	dirLightDiffuse = diffuse;
	dirLightSpecular = specular;
}

DirLight::~DirLight()
{
}