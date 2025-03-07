#pragma once
#include "..\include\glm\glm.hpp"
#include "..\include\glm\gtc\matrix_transform.hpp"

class Camera {
public:
    // ���캯��
    Camera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up,
        float fov, float aspectRatio, float nearPlane, float farPlane)
        : position(position), target(target), up(up),
        fov(fov), aspectRatio(aspectRatio),
        nearPlane(nearPlane), farPlane(farPlane) {}

    // ��ȡ��ͼ����
    glm::mat4 getViewMatrix() const {
        return glm::lookAt(position, target, up);
    }

    // ��ȡͶӰ����
    glm::mat4 getProjectionMatrix() const {
        return glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
    }

    // �������λ��
    void setPosition(const glm::vec3& position) {
        this->position = position;
    }

    // �������Ŀ���
    void setTarget(const glm::vec3& target) {
        this->target = target;
    }

    // ���������������
    void setUp(const glm::vec3& up) {
        this->up = up;
    }

    // ������Ұ�Ƕ�
    void setFov(float fov) {
        this->fov = fov;
    }

    // ���ÿ�߱�
    void setAspectRatio(float aspectRatio) {
        this->aspectRatio = aspectRatio;
    }

    // ���ý��ü���
    void setNearPlane(float nearPlane) {
        this->nearPlane = nearPlane;
    }

    // ����Զ�ü���
    void setFarPlane(float farPlane) {
        this->farPlane = farPlane;
    }

    // ��ȡ���λ��
    glm::vec3 getPosition() const {
        return position;
    }

    // ��ȡ���Ŀ���
    glm::vec3 getTarget() const {
        return target;
    }

    // ��ȡ�����������
    glm::vec3 getUp() const {
        return up;
    }

    // ��ȡ��Ұ�Ƕ�
    float getFov() const {
        return fov;
    }

    // ��ȡ��߱�
    float getAspectRatio() const {
        return aspectRatio;
    }

    // ��ȡ���ü���
    float getNearPlane() const {
        return nearPlane;
    }

    // ��ȡԶ�ü���
    float getFarPlane() const {
        return farPlane;
    }

private:
    glm::vec3 position;  // ���λ��
    glm::vec3 target;    // ���Ŀ���
    glm::vec3 up;        // �����������
    float fov;           // ��Ұ�Ƕ�
    float aspectRatio;   // ��߱�
    float nearPlane;     // ���ü���
    float farPlane;      // Զ�ü���
};