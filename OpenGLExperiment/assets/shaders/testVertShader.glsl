#version 430

layout (location=0) in vec3 position;

uniform float offset;
uniform mat4 m_matrix;
uniform mat4 mv_matrix;
uniform mat4 proj_matrix;

void main(void)
{ 
	gl_Position = vec4(position,1.0);
}