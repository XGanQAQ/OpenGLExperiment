#pragma once
struct VertexBufferElement {
	unsigned int locationPos; // ��������λ��
    unsigned int count;  // ������������ 3 ��ʾ vec3��
    unsigned int type;   // �������ͣ����� GL_FLOAT��
    unsigned char normalized; // �Ƿ��һ��
	unsigned int stride; // ƫ����
	unsigned int beginPos; // ��ʼλ��

    static unsigned int GetSizeOfType(unsigned int type);
};