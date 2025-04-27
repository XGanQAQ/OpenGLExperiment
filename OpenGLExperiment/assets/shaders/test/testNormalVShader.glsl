#version 430

layout (location = 0) in vec3 vertPos;
layout (location = 1) in vec3 vertNormal;


uniform mat4 mv_matrix;
uniform mat4 proj_matrix;

out vec3 fragNormal;

void main(void)
{
    // �����ߴ��ݵ�Ƭ����ɫ��
    fragNormal = vertNormal;

    // ���ö���λ��,����任��
    gl_Position = proj_matrix * mv_matrix * vec4(vertPos,1.0);
}