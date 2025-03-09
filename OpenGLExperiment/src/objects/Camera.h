#pragma once

#include "BaseNode.h" // ���� BaseNode ��ͷ�ļ�
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera : public BaseNode {
public:
    // ���캯��
    Camera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up,
        float fov, float aspectRatio, float nearPlane, float farPlane);

    // ��ȡ��ͼ����
    glm::mat4 getViewMatrix() const;

    // ��ȡͶӰ����
    glm::mat4 getProjectionMatrix() const;

    // �������λ��
    void setPosition(const glm::vec3& position);

    // �������Ŀ���
    void setTarget(const glm::vec3& target);

    // ���������������
    void setUp(const glm::vec3& up);

    // ������Ұ�Ƕ�
    void setFov(float fov);

    // ���ÿ�߱�
    void setAspectRatio(float aspectRatio);

    // ���ý��ü���
    void setNearPlane(float nearPlane);

    // ����Զ�ü���
    void setFarPlane(float farPlane);

    // ��ȡ���λ��
    glm::vec3 getPosition() const;

    // ��ȡ���Ŀ���
    glm::vec3 getTarget() const;

    // ��ȡ�����������
    glm::vec3 getUp() const;

    // ��ȡ��Ұ�Ƕ�
    float getFov() const;

    // ��ȡ��߱�
    float getAspectRatio() const;

    // ��ȡ���ü���
    float getNearPlane() const;

    // ��ȡԶ�ü���
    float getFarPlane() const;

private:
    glm::vec3 target; // ���Ŀ���
    glm::vec3 up;     // �����������
    float fov;        // ��Ұ�Ƕ�
    float aspectRatio;// ��߱�
    float nearPlane;  // ���ü���
    float farPlane;   // Զ�ü���
};