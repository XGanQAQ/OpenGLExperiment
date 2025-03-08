#pragma once
#include <vector>
#include <glm/glm.hpp>
#include "../base/Mesh.h"

class GeometryGenerator {
public:
    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texCoord;
    };

    struct MeshData {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
    };

    static MeshData createCube(float size = 1.0f);
    static MeshData createSphere(float radius = 1.0f, int sectorCount = 36, int stackCount = 18);
    static MeshData createCone(float radius = 1.0f, float height = 1.0f, int sectorCount = 36);
    static MeshData createTetrahedron(float size = 1.0f);

	//把Vertex的position数据提取出来，返回一个float数组
	static std::vector<float> extractPositionData(const MeshData& meshData);
    //把Vertex的position数据提取出来，返回一个Mesh
	static Mesh* extractPositionMesh(const MeshData& meshData);

private:
    static void buildSphereVertices(MeshData& meshData, float radius, int sectorCount, int stackCount);
};
