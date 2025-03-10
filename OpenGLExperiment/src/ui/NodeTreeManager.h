#pragma once
// NodeTreeManager.h
#pragma once
#include "../objects/BaseNode.h"

class NodeTreeManager
{
public:
    NodeTreeManager(BaseNode* root) : rootNode(root), selectedNode(nullptr) {}

    void Render();

    BaseNode* selectedNode;
private:
    BaseNode* rootNode;

    void RenderNodeTree(BaseNode* node);
};