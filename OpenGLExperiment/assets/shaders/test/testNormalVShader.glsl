#version 430

layout (location = 0) in vec3 vertPos;
layout (location = 1) in vec3 vertNormal;


uniform mat4 mv_matrix;
uniform mat4 proj_matrix;

out vec3 fragNormal;

void main(void)
{
    // 将法线传递到片段着色器
    fragNormal = vertNormal;

    // 设置顶点位置,矩阵变换后
    gl_Position = proj_matrix * mv_matrix * vec4(vertPos,1.0);
}