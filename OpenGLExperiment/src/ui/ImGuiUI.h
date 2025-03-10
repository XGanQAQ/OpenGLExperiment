#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "NodeTreeManager.h"

class ImGuiUI {
public:
    ImGuiUI(GLFWwindow* window);
    ~ImGuiUI();


    void beginFrame();
    void endFrame();

    void showExampleWindow();
	void createNodeTreeManager(BaseNode* rootNode);
	bool isNodeTreeManagerInitialized();
	void showNodeTreeWindow();
    void showAttributeWindow(); // 新增的方法

	NodeTreeManager* nodeTreeManager;
private:
    float currentFontSize = 20.0f; // 默认字体大小
    ImFont* currentFont = nullptr; // 当前使用的字体

    bool isChecked = false;
    char inputBuffer[256] = "";

    void onClicked();
    void createFont();
};