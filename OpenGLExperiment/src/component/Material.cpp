#include "Material.h"

Material::~Material()
{
}

void Material::initMaterial()
{
	shaderProgram->compile();
}
