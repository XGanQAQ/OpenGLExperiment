#pragma once

#include "BaseNode.h" // 包含 BaseNode 的头文件
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera : public BaseNode {
public:
    // 构造函数
    Camera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up,
        float fov, float aspectRatio, float nearPlane, float farPlane);

    // 获取视图矩阵
    glm::mat4 getViewMatrix() const;

    // 获取投影矩阵
    glm::mat4 getProjectionMatrix() const;

    // 设置相机位置
    void setPosition(const glm::vec3& position);

    // 设置相机目标点
    void setTarget(const glm::vec3& target);

    // 设置相机的上向量
    void setUp(const glm::vec3& up);

    // 设置视野角度
    void setFov(float fov);

    // 设置宽高比
    void setAspectRatio(float aspectRatio);

    // 设置近裁剪面
    void setNearPlane(float nearPlane);

    // 设置远裁剪面
    void setFarPlane(float farPlane);

    // 获取相机位置
    glm::vec3 getPosition() const;

    // 获取相机目标点
    glm::vec3 getTarget() const;

    // 获取相机的上向量
    glm::vec3 getUp() const;

    // 获取视野角度
    float getFov() const;

    // 获取宽高比
    float getAspectRatio() const;

    // 获取近裁剪面
    float getNearPlane() const;

    // 获取远裁剪面
    float getFarPlane() const;

private:
    glm::vec3 target; // 相机目标点
    glm::vec3 up;     // 相机的上向量
    float fov;        // 视野角度
    float aspectRatio;// 宽高比
    float nearPlane;  // 近裁剪面
    float farPlane;   // 远裁剪面
};