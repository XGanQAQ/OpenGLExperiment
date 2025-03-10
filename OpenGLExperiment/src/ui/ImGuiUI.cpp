#include "ImGuiUI.h"
#include <iostream>

ImGuiUI::ImGuiUI(GLFWwindow* window) {
    // ��ʼ�� ImGUI ������
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // ���ü��̿���

    // ���� ImGUI ��ʽ
    ImGui::StyleColorsDark();

    // ��ʼ�� ImGUI ����Ⱦ���
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 430");

    // ������ʼ����
    createFont();
}

ImGuiUI::~ImGuiUI() {
    // ���� ImGUI
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiUI::createFont() {
    if (currentFont) {
        // ����Ѿ��������壬�����پɵ�����
        ImGui::GetIO().Fonts->ClearTexData(); // �����������
        // ImGui::GetIO().Fonts->RemoveFont(currentFont); // �Ƴ�������
    }

    ImFontAtlas* fontAtlas = ImGui::GetIO().Fonts;
    currentFont = fontAtlas->AddFontFromFileTTF("assets/font/FiraCode-VariableFont_wght.ttf", currentFontSize);
    if (!currentFont) {
        // �������ʧ�ܣ�����ʹ��Ĭ������
        currentFont = ImGui::GetFont(); // ʹ��Ĭ������
    }

    // ������������
    ImGui::GetIO().Fonts->Build();
}

void ImGuiUI::beginFrame() {
    // ��ʼ�µ�һ֡
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImGuiUI::endFrame() {
    // ��Ⱦ ImGUI
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


// �� showExampleWindow ����Ӱ�ť�����������С
void ImGuiUI::showExampleWindow() {
    // ʾ������
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
    // �ڵ�������
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
    ImGui::PushID("name"); // ����ؼ�ID��ͻ
    ImGui::PopID();

    // ��ʾ�ͱ༭λ����Ϣ
    ImGui::Text("Position");
    ImGui::PushID("position"); // ����ؼ�ID��ͻ
    ImGui::DragFloat3("##Position", &selected->position.x, 0.1f);
    ImGui::PopID();

    // ��ʾ�ͱ༭��ת��Ϣ�������Ҫ��
    ImGui::Text("Rotation");
    ImGui::PushID("rotation");
    ImGui::DragFloat3("##Rotation", &selected->rotation.x, 0.1f);
    ImGui::PopID();

    // ��ʾ�ͱ༭������Ϣ�������Ҫ��
    ImGui::Text("Scale");
    ImGui::PushID("scale");
    ImGui::DragFloat3("##Scale", &selected->scale.x, 0.1f);
    ImGui::PopID();

    // ����Ը�����Ҫ��Ӹ�������

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
    // ��ť����¼�����
    isChecked = !isChecked;
}