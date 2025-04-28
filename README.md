# OpenGLExperiment

## 项目简介

**OpenGLExperiment** 是一个基于 **C++** 和 **OpenGL** 的 3D 渲染学习项目。  
项目专注于模块化封装与核心原理实现，旨在帮助开发者系统学习计算机图形学，理解 3D 渲染引擎的基本构建流程，并为进一步扩展高级渲染效果（如光照、阴影、PBR 材质等）打下基础。

本项目采用了清晰的分层架构设计，涵盖模型管理、材质系统、摄像机与场景管理、渲染器封装、资源加载与 UI 支持等模块，适合作为学习 OpenGL 渲染流程或搭建个人渲染引擎的起点。

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

关于项目的详细设计说明、模块功能、开发计划等内容，请参阅 [docs/](docs/) 目录中的文档。

---

## 许可证

本项目采用 [MIT License](LICENSE) 开源，欢迎学习与使用。

---