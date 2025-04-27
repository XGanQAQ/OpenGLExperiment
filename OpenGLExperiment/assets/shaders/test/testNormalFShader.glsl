#version 430

in vec3 fragNormal;
out vec4 varyingColor;

void main(void)
{
    // ������ӳ�䵽 [0, 1] ��Χ����Ϊ��ɫ���
    vec3 normalizedNormal = normalize(fragNormal);
    vec3 color = (normalizedNormal * 0.5) + 0.5; // �� [-1, 1] ӳ�䵽 [0, 1]
    varyingColor = vec4(color, 1.0);
}
