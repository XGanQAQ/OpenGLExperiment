# OpenGLExperiment

## 项目简介

**OpenGLExperiment** 是一个基于 **C++** 和 **OpenGL** 的 3D 渲染学习项目。  
项目专注于模块化封装与核心原理实现，旨在帮助开发者系统学习计算机图形学，理解 3D 渲染引擎的基本构建流程，并为进一步扩展高级渲染效果（如光照、阴影、PBR 材质等）打下基础。

本项目采用了清晰的分层架构设计，涵盖模型管理、材质系统、摄像机与场景管理、渲染器封装、资源加载与 UI 支持等模块，适合作为学习 OpenGL 渲染流程或搭建个人渲染引擎的起点。

---

## 项目状态

> ⚠️ **暂停开发（2025/4/28）**

由于开发过程中对 C++ 系统设计理解尚浅，导致封装和耦合结构不够合理，后续扩展变得较为复杂。  
加之学习目标的调整，目前决定暂停本项目的进一步开发。

暂停原因总结如下：

- 本项目封装较多，不利于专注学习图形学原理，理解 OpenGL 基础 API 更为直接高效。
- 个人目标更倾向于理解图形学原理，而非从零手动开发一套引擎。
- 当前架构设计存在缺陷，后期维护和功能扩展成本较高。
- 考虑未来技术方向，计划转向学习更新的图形 API，如 Vulkan。

尽管如此，本项目仍保留作为早期图形开发学习的记录与参考。

---

## 特性概览

- 简洁的 OpenGL 抽象封装（VAO、VBO、Shader、Mesh、Material）
- 场景管理与节点系统（Scene、SceneNode）
- 简单易用的界面编辑器（基于 ImGUI）
- OBJ 模型导入与纹理加载
- 光照系统与材质扩展预留
- 良好的模块化与可扩展性设计

---

## 快速开始

### 环境要求

- C++17 及以上编译器
- Visual Studio 2022
- OpenGL 4.5 或更高版本

### 克隆与构建

```bash
git clone https://github.com/your-repo/OpenGLExperiment.git
```

使用 Visual Studio 2022 打开 `OpenGLExperiment.sln`，配置相关依赖后即可编译运行。

---

## 文档与资料

关于项目的详细设计说明、模块功能、开发计划等内容，请参阅 [/OpenGLExperiment/docs/](/OpenGLExperiment/docs/) 目录中的文档。

---

## 许可证

本项目采用 [MIT License](LICENSE) 开源，欢迎学习与参考。
