#include "Camera.h"

// 构造函数
Camera::Camera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up,
    float fov, float aspectRatio, float nearPlane, float farPlane)
    : BaseNode("Camera"), // 调用 BaseNode 的构造函数，设置节点名称
    fov(fov), aspectRatio(aspectRatio),
    nearPlane(nearPlane), farPlane(farPlane)
{
    // 初始化相机的位置和目标点
    setPosition(position);
    setTarget(target);
    setUp(up);
}

// 获取视图矩阵
glm::mat4 Camera::getViewMatrix() const {
    glm::mat4 vMat_T = glm::translate(glm::mat4(1.0f), -getPosition());
    glm::mat4 vMat_R = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x), glm::vec3(1, 0, 0));
	vMat_R *= glm::rotate(vMat_R, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	vMat_R *= glm::rotate(vMat_R, glm::radians(rotation.z), glm::vec3(0, 0, 1));
    return vMat_R * vMat_T;
}

// 获取投影矩阵
glm::mat4 Camera::getProjectionMatrix() const {
    return glm::perspective(glm::radians(getFov()), getAspectRatio(), getNearPlane(), getFarPlane());
}

// 设置相机位置
void Camera::setPosition(const glm::vec3& position) {
    BaseNode::setPosition(position); // 调用 BaseNode 的方法
}

// 设置相机目标点
void Camera::setTarget(const glm::vec3& target) {
    this->target = target;
}

// 设置相机的上向量
void Camera::setUp(const glm::vec3& up) {
    this->up = up;
}

// 设置视野角度
void Camera::setFov(float fov) {
    this->fov = fov;
}

// 设置宽高比
void Camera::setAspectRatio(float aspectRatio) {
    this->aspectRatio = aspectRatio;
}

// 设置近裁剪面
void Camera::setNearPlane(float nearPlane) {
    this->nearPlane = nearPlane;
}

// 设置远裁剪面
void Camera::setFarPlane(float farPlane) {
    this->farPlane = farPlane;
}

// 获取相机位置
glm::vec3 Camera::getPosition() const {
    return position; // BaseNode 中的 position 变量
}

// 获取相机目标点
glm::vec3 Camera::getTarget() const {
    return target;
}

// 获取相机的上向量
glm::vec3 Camera::getUp() const {
    return up;
}

// 获取视野角度
float Camera::getFov() const {
    return fov;
}

// 获取宽高比
float Camera::getAspectRatio() const {
    return aspectRatio;
}

// 获取近裁剪面
float Camera::getNearPlane() const {
    return nearPlane;
}

// 获取远裁剪面
float Camera::getFarPlane() const {
    return farPlane;
}