#include "ImGuiUI.h"
#include <iostream>

ImGuiUI::ImGuiUI(GLFWwindow* window) {
    // 初始化 ImGUI 上下文
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // 启用键盘控制

    // 设置 ImGUI 样式
    ImGui::StyleColorsDark();

    // 初始化 ImGUI 的渲染后端
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 430");

    // 创建初始字体
    createFont();
}

ImGuiUI::~ImGuiUI() {
    // 清理 ImGUI
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiUI::createFont() {
    if (currentFont) {
        // 如果已经存在字体，先销毁旧的字体
        ImGui::GetIO().Fonts->ClearTexData(); // 清除纹理数据
        // ImGui::GetIO().Fonts->RemoveFont(currentFont); // 移除旧字体
    }

    ImFontAtlas* fontAtlas = ImGui::GetIO().Fonts;
    currentFont = fontAtlas->AddFontFromFileTTF("assets/font/FiraCode-VariableFont_wght.ttf", currentFontSize);
    if (!currentFont) {
        // 如果加载失败，可以使用默认字体
        currentFont = ImGui::GetFont(); // 使用默认字体
    }

    // 构建字体纹理
    ImGui::GetIO().Fonts->Build();
}

void ImGuiUI::beginFrame() {
    // 开始新的一帧
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImGuiUI::endFrame() {
    // 渲染 ImGUI
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


// 在 showExampleWindow 中添加按钮来调整字体大小
void ImGuiUI::showExampleWindow() {
    // 示例窗口
    ImGui::Begin("Example Window");
    ImGui::Text("Hello, world!");
    ImGui::Checkbox("Check me", &isChecked);
    ImGui::InputText("Input", inputBuffer, IM_ARRAYSIZE(inputBuffer));
    if (ImGui::Button("Click Me")) {
        onClicked();
    }

    ImGui::End();
}

void ImGuiUI::showNodeTreeWindow()
{
    if (nodeTreeManager == nullptr)
    {
        std::cout << "Node Tree Manager is not initialized" << std::endl;
        return;
    }
    // 节点树窗口
    ImGui::Begin("Node Tree");
    nodeTreeManager->Render();
    ImGui::End();
}

void ImGuiUI::showAttributeWindow()
{
    if (nodeTreeManager == nullptr || nodeTreeManager->selectedNode == nullptr)
    {
        return;
    }

    BaseNode* selected = nodeTreeManager->selectedNode;

    ImGui::Begin("AttributeWindow");

    ImGui::Text(("Name: " + selected->nodeName).c_str());
    ImGui::PushID("name"); // 避免控件ID冲突
    ImGui::PopID();

    // 显示和编辑位置信息
    ImGui::Text("Position");
    ImGui::PushID("position"); // 避免控件ID冲突
    ImGui::DragFloat3("##Position", &selected->position.x, 0.1f);
    ImGui::PopID();

    // 显示和编辑旋转信息（如果需要）
    ImGui::Text("Rotation");
    ImGui::PushID("rotation");
    ImGui::DragFloat3("##Rotation", &selected->rotation.x, 0.1f);
    ImGui::PopID();

    // 显示和编辑缩放信息（如果需要）
    ImGui::Text("Scale");
    ImGui::PushID("scale");
    ImGui::DragFloat3("##Scale", &selected->scale.x, 0.1f);
    ImGui::PopID();

    // 你可以根据需要添加更多属性

    ImGui::End();
}

void ImGuiUI::createNodeTreeManager(BaseNode* rootNode)
{
	nodeTreeManager = new NodeTreeManager(rootNode);
}

bool ImGuiUI::isNodeTreeManagerInitialized()
{
	return nodeTreeManager != nullptr;
}

void ImGuiUI::onClicked() {
    // 按钮点击事件处理
    isChecked = !isChecked;
}