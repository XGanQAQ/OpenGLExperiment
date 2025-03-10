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
    void showAttributeWindow(); // �����ķ���

	NodeTreeManager* nodeTreeManager;
private:
    float currentFontSize = 20.0f; // Ĭ�������С
    ImFont* currentFont = nullptr; // ��ǰʹ�õ�����

    bool isChecked = false;
    char inputBuffer[256] = "";

    void onClicked();
    void createFont();
};