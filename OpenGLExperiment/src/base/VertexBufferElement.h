#pragma once
struct VertexBufferElement {
	unsigned int locationPos; // 顶点属性位置
    unsigned int count;  // 分量数（例如 3 表示 vec3）
    unsigned int type;   // 数据类型（例如 GL_FLOAT）
    unsigned char normalized; // 是否归一化
	unsigned int stride; // 偏移量
	unsigned int beginPos; // 起始位置

    static unsigned int GetSizeOfType(unsigned int type);
};