#pragma once
#include "..\include\glm\glm.hpp"
#include "..\include\glm\gtc\matrix_transform.hpp"

class Camera {
public:
    // 构造函数
    Camera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up,
        float fov, float aspectRatio, float nearPlane, float farPlane)
        : position(position), target(target), up(up),
        fov(fov), aspectRatio(aspectRatio),
        nearPlane(nearPlane), farPlane(farPlane) {}

    // 获取视图矩阵
    glm::mat4 getViewMatrix() const {
        return glm::lookAt(position, target, up);
    }

    // 获取投影矩阵
    glm::mat4 getProjectionMatrix() const {
        return glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
    }

    // 设置相机位置
    void setPosition(const glm::vec3& position) {
        this->position = position;
    }

    // 设置相机目标点
    void setTarget(const glm::vec3& target) {
        this->target = target;
    }

    // 设置相机的上向量
    void setUp(const glm::vec3& up) {
        this->up = up;
    }

    // 设置视野角度
    void setFov(float fov) {
        this->fov = fov;
    }

    // 设置宽高比
    void setAspectRatio(float aspectRatio) {
        this->aspectRatio = aspectRatio;
    }

    // 设置近裁剪面
    void setNearPlane(float nearPlane) {
        this->nearPlane = nearPlane;
    }

    // 设置远裁剪面
    void setFarPlane(float farPlane) {
        this->farPlane = farPlane;
    }

    // 获取相机位置
    glm::vec3 getPosition() const {
        return position;
    }

    // 获取相机目标点
    glm::vec3 getTarget() const {
        return target;
    }

    // 获取相机的上向量
    glm::vec3 getUp() const {
        return up;
    }

    // 获取视野角度
    float getFov() const {
        return fov;
    }

    // 获取宽高比
    float getAspectRatio() const {
        return aspectRatio;
    }

    // 获取近裁剪面
    float getNearPlane() const {
        return nearPlane;
    }

    // 获取远裁剪面
    float getFarPlane() const {
        return farPlane;
    }

private:
    glm::vec3 position;  // 相机位置
    glm::vec3 target;    // 相机目标点
    glm::vec3 up;        // 相机的上向量
    float fov;           // 视野角度
    float aspectRatio;   // 宽高比
    float nearPlane;     // 近裁剪面
    float farPlane;      // 远裁剪面
};