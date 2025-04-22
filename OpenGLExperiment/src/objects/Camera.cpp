#include "Camera.h"

// ���캯��
Camera::Camera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up,
    float fov, float aspectRatio, float nearPlane, float farPlane)
    : BaseNode("Camera"), // ���� BaseNode �Ĺ��캯�������ýڵ�����
    fov(fov), aspectRatio(aspectRatio),
    nearPlane(nearPlane), farPlane(farPlane)
{
    // ��ʼ�������λ�ú�Ŀ���
    setPosition(position);
    setTarget(target);
    setUp(up);
}

// ��ȡ��ͼ����
glm::mat4 Camera::getViewMatrix() const {
    glm::mat4 vMat_T = glm::translate(glm::mat4(1.0f), -getPosition());
    glm::mat4 vMat_R = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x), glm::vec3(1, 0, 0));
	vMat_R *= glm::rotate(vMat_R, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	vMat_R *= glm::rotate(vMat_R, glm::radians(rotation.z), glm::vec3(0, 0, 1));
    return vMat_R * vMat_T;
}

// ��ȡͶӰ����
glm::mat4 Camera::getProjectionMatrix() const {
    return glm::perspective(glm::radians(getFov()), getAspectRatio(), getNearPlane(), getFarPlane());
}

// �������λ��
void Camera::setPosition(const glm::vec3& position) {
    BaseNode::setPosition(position); // ���� BaseNode �ķ���
}

// �������Ŀ���
void Camera::setTarget(const glm::vec3& target) {
    this->target = target;
}

// ���������������
void Camera::setUp(const glm::vec3& up) {
    this->up = up;
}

// ������Ұ�Ƕ�
void Camera::setFov(float fov) {
    this->fov = fov;
}

// ���ÿ�߱�
void Camera::setAspectRatio(float aspectRatio) {
    this->aspectRatio = aspectRatio;
}

// ���ý��ü���
void Camera::setNearPlane(float nearPlane) {
    this->nearPlane = nearPlane;
}

// ����Զ�ü���
void Camera::setFarPlane(float farPlane) {
    this->farPlane = farPlane;
}

// ��ȡ���λ��
glm::vec3 Camera::getPosition() const {
    return position; // BaseNode �е� position ����
}

// ��ȡ���Ŀ���
glm::vec3 Camera::getTarget() const {
    return target;
}

// ��ȡ�����������
glm::vec3 Camera::getUp() const {
    return up;
}

// ��ȡ��Ұ�Ƕ�
float Camera::getFov() const {
    return fov;
}

// ��ȡ��߱�
float Camera::getAspectRatio() const {
    return aspectRatio;
}

// ��ȡ���ü���
float Camera::getNearPlane() const {
    return nearPlane;
}

// ��ȡԶ�ü���
float Camera::getFarPlane() const {
    return farPlane;
}