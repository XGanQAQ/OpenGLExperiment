#include "NodeTreeManager.h"
#include "imgui/imgui.h"

void NodeTreeManager::Render()
{
    ImGui::Begin("Node Tree");
    RenderNodeTree(rootNode);
    ImGui::End();
}

void NodeTreeManager::RenderNodeTree(BaseNode* node)
{
    if (!node)
        return;

    ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick;
    if (selectedNode == node)
        flags |= ImGuiTreeNodeFlags_Selected;

    bool nodeOpen = ImGui::TreeNodeEx((void*)(intptr_t)node->id, flags, node->nodeName.c_str());

    if (ImGui::IsItemClicked())
    {
        selectedNode = node;
    }

    if (nodeOpen)
    {
        for (BaseNode* child : node->children)
        {
            RenderNodeTree(child);
        }
        ImGui::TreePop();
    }
}