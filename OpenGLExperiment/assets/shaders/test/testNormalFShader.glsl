#version 430

in vec3 fragNormal;
out vec4 varyingColor;

void main(void)
{
    // 将法线映射到 [0, 1] 范围并作为颜色输出
    vec3 normalizedNormal = normalize(fragNormal);
    vec3 color = (normalizedNormal * 0.5) + 0.5; // 将 [-1, 1] 映射到 [0, 1]
    varyingColor = vec4(color, 1.0);
}
