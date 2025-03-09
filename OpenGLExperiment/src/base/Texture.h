#pragma once
#include "..\include\GL\glew.h"
#include <string>
#include <iostream>
#include "SOIL2/SOIL2.h" // ����SOIL2��

class Texture {
public:
    // ���캯�������������ļ�·��
    Texture(const std::string& filePath);

    // ���ÿ������캯���͸�ֵ������
    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;

    // �ƶ����캯�����ƶ���ֵ������
    Texture(Texture&& other) noexcept;
    Texture& operator=(Texture&& other) noexcept;

    // �����������ͷ�������Դ
    ~Texture();

    // ������ָ��������Ԫ
    void bind(unsigned int slot = 0) const;

    // �������
    void unbind() const;

    // ��ȡ����ID
    GLuint getID() const { return m_RendererID; }

private:
    // ������ȾID
    GLuint m_RendererID;
    // �����ļ�·��
    std::string m_FilePath;
};