#include "GlobalAmbient.h"
using namespace glm;
GlobalAmbient::GlobalAmbient(vec4 energy, vec4 color) :
	BaseNode("GlobalAmbient"), globalAmbient(energy), globalAmbientColor(color)
{

}

GlobalAmbient::~GlobalAmbient()
{
}