#include "Material.h"

Material::~Material()
{
}

void Material::initMaterial()
{
	shaderProgram->compile();
}

void Material::useMaterial()
{
	shaderProgram->use();
	if (texture != nullptr)
	{
		texture->bind(slot);
	}
}

