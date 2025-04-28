#pragma once
#include <glm/ext/vector_float4.hpp>
#include <glm/ext/vector_float3.hpp>

using namespace glm;

namespace LightModel {
	struct PositionalLight
	{
		vec4 ambient;
		vec4 diffuse;
		vec4 specular;
		vec3 position;
	};
	struct Material
	{
		vec4 ambient;
		vec4 diffuse;
		vec4 specular;
		float shininess;
	};
}
