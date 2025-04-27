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

	// ÉèÖÃ uniforms
    for (const auto& uniform : uniformInt)
    {
		shaderProgram->setUniform(uniform.first, uniform.second);
    }
	for (const auto& uniform : uniformFloat)
	{
		shaderProgram->setUniform(uniform.first, uniform.second);
	}
	for (const auto& uniform : uniformVec3)
	{
		shaderProgram->setUniform(uniform.first, uniform.second);
	}
	for (const auto& uniform : uniformVec4)
	{
		shaderProgram->setUniform(uniform.first, uniform.second);
	}
	for (const auto& uniform : uniformMat4)
	{
		shaderProgram->setUniform(uniform.first, uniform.second);
	}
}

void Material::unuseMaterial()
{
	shaderProgram->unuse();
	if (texture != nullptr)
	{
		texture->unbind();
	}
}

void Material::setUniformInt(const std::string& name, int value)
{
	uniformInt[name]=value;
}

void Material::setUniformFloat(const std::string& name, float value)
{
	uniformFloat[name] = value;
}

void Material::setUniformVec3(const std::string& name, const glm::vec3& value) {
	uniformVec3[name] = value;
}

void Material::setUniformVec4(const std::string& name, const glm::vec4& value)
{
	uniformVec4[name] = value;
}

void Material::setUniformMat4(const std::string& name, const glm::mat4& value){
	uniformMat4[name] = value;
}