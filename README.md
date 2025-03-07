## 概述：
项目目标：可编辑场渲染引擎
Demo目标：林中小屋的室内环境
使用C++和OpenGL编写的小型渲染引擎
## 计划
 - [ ] 渲染功能
	 - [x]  基本抽象封装
		 - [x] VAO,VBO抽象
		 - [x] Shaderprogram抽象
		 - [x] Model、Mesh抽象
		 - [x] Material抽象
		 - [x] Scene、SceneNode抽象
		 - [x] Camera抽象
		 - [x] Renderer抽象
		 - [x] Application抽象
	 - [ ] 便捷几何体
		 - [x] 矩阵栈
		 - [ ] 基本几何体类的封装
	- [ ] 纹理
	- [ ] 模型
	- [ ] 光照
	- [ ] 天空盒
	- [ ] 阴影
- [ ] 交互界面

## 程序架构
### 依赖库
GLFW：窗口管理
GLM：数学运算
Im GUI：UI界面
SOIL：纹理图形加载库

待选：
SDL：功能更强大的多媒体管理库
imGUI：UI界面库

### 项目结构
```
/OpenGLExperiment
	/src
		/base 对opengl的封装
			baseAll.h
			Mesh.cpp
			Mesh.h
			ShaderProgram.cpp
			ShaderProgram.h
			VertexArrayObject.cpp
			VertexArrayObject.h
			VertexBuffer.cpp
			VertexBuffer.h
			VertexBufferElement.h
		/component 组件
			Material.cpp
			Material.h
			Model.cpp
			Model.h
		/core 核心
		    Application.cpp
		    Application.h
		    Renderer.cpp
		    Renderer.h
		    Scene.cpp
		    Scene.h
		/objects 对象
		    Camera.h
		    Camera.cpp
		    SceneNode.cpp
		    SceneNode.cpp
		    Light.h
		    Light.cpp
		    Skybox.h
		    Skybox.cpp
		/resources 资源管理
		    ModelLoader.h
		    ModelLoader.cpp
		    TextureManager.h
		    TextureManager.cpp
		    ShaderManager.h
		    ShaderManager.cpp
		/tools
		    Geometry.h 创建基本几何体
		    Geometry.cpp
			ImportedModel.cpp 读取模型
			ImportedModel.h
			Utils.cpp 老旧工具
			Utils.h
		/advanced
		    ShadowMapping.h
		    ShadowMapping.cpp
		    AdvancedTexturing.h
		    AdvancedTexturing.cpp
		/ui
		    ImGUI.h
		    ImGUI.cpp
	/assets
	    /models
	    /textures
	    /shaders
	/include
	(公共的头文件)
	/lib
    (外部库引用)
    /x64
    (x64的可执行文件)
	    /debug
	/docs
	(可阅读文档)
	/test
	(测试模块)
	

```
### 核心运行逻辑
- main
	- application
		- Scene
			- SceneNode 管理场景中的对象（例如位置、旋转、缩放）				
				- Model 管理多个 Mesh
					- VertexArrayObject VAO封装
					- Mesh 网格 管理顶点数据和顶点属性配置
						- 第一个Mesh固定为顶点坐标网格
						- VertexBuffer VBO封装
						- VretexBufferElement 结构体记录vbo配置信息
				- Material 材质信息
					- ShaderProgram
					- Texture
			- Camera
			- Light
		- Renderer 
			- 从SceneNode的Model和Material得到vao进行绘制
			- MainScene 注入的场景，用于绘制
			- MainCamera 从场景中获得主相机



