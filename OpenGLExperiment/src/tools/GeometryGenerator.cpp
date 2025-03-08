#include "GeometryGenerator.h"
#include <cmath>
#define M_PI 3.1415926

GeometryGenerator::MeshData GeometryGenerator::createCube(float size) {
    MeshData meshData;

    float halfSize = size / 2.0f;

    // 定义立方体的8个顶点
    std::vector<glm::vec3> positions = {
        {-halfSize, -halfSize, -halfSize},
        { halfSize, -halfSize, -halfSize},
        { halfSize,  halfSize, -halfSize},
        {-halfSize,  halfSize, -halfSize},
        {-halfSize, -halfSize,  halfSize},
        { halfSize, -halfSize,  halfSize},
        { halfSize,  halfSize,  halfSize},
        {-halfSize,  halfSize,  halfSize}
    };

    // 定义立方体的6个面
    std::vector<unsigned int> indices = {
        0, 1, 2, 2, 3, 0, // 前
        4, 5, 6, 6, 7, 4, // 后
        0, 3, 7, 7, 4, 0, // 左
        1, 2, 6, 6, 5, 1, // 右
        0, 1, 5, 5, 4, 0, // 下
        2, 3, 7, 7, 6, 2  // 上
    };

    // 定义法线
    std::vector<glm::vec3> normals = {
        { 0.0f,  0.0f, -1.0f}, // 前
        { 0.0f,  0.0f,  1.0f}, // 后
        {-1.0f,  0.0f,  0.0f}, // 左
        { 1.0f,  0.0f,  0.0f}, // 右
        { 0.0f, -1.0f,  0.0f}, // 下
        { 0.0f,  1.0f,  0.0f}  // 上
    };

    // 定义纹理坐标
    std::vector<glm::vec2> texCoords = {
        {0.0f, 0.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 1.0f}
    };

    // 构建顶点数据
    for (unsigned int i = 0; i < indices.size(); ++i) {
        Vertex vertex;
        vertex.position = positions[indices[i]];
        vertex.normal = normals[i / 6];
        vertex.texCoord = texCoords[i % 4];
        meshData.vertices.push_back(vertex);
        meshData.indices.push_back(i);
    }

    return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::createSphere(float radius, int sectorCount, int stackCount) {
    MeshData meshData;
    buildSphereVertices(meshData, radius, sectorCount, stackCount);
    return meshData;
}

void GeometryGenerator::buildSphereVertices(MeshData& meshData, float radius, int sectorCount, int stackCount) {
    float x, y, z, xy;
    float nx, ny, nz, lengthInv = 1.0f / radius;
    float s, t;

    float sectorStep = 2 * M_PI / sectorCount;
    float stackStep = M_PI / stackCount;
    float sectorAngle, stackAngle;

    for (int i = 0; i <= stackCount; ++i) {
        stackAngle = M_PI / 2 - i * stackStep;
        xy = radius * cosf(stackAngle);
        z = radius * sinf(stackAngle);

        for (int j = 0; j <= sectorCount; ++j) {
            sectorAngle = j * sectorStep;

            x = xy * cosf(sectorAngle);
            y = xy * sinf(sectorAngle);

            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;

            s = (float)j / sectorCount;
            t = (float)i / stackCount;

            Vertex vertex;
            vertex.position = glm::vec3(x, y, z);
            vertex.normal = glm::vec3(nx, ny, nz);
            vertex.texCoord = glm::vec2(s, t);
            meshData.vertices.push_back(vertex);
        }
    }

    int k1, k2;
    for (int i = 0; i < stackCount; ++i) {
        k1 = i * (sectorCount + 1);
        k2 = k1 + sectorCount + 1;

        for (int j = 0; j < sectorCount; ++j, ++k1, ++k2) {
            if (i != 0) {
                meshData.indices.push_back(k1);
                meshData.indices.push_back(k2);
                meshData.indices.push_back(k1 + 1);
            }

            if (i != (stackCount - 1)) {
                meshData.indices.push_back(k1 + 1);
                meshData.indices.push_back(k2);
                meshData.indices.push_back(k2 + 1);
            }
        }
    }
}

GeometryGenerator::MeshData GeometryGenerator::createCone(float radius, float height, int sectorCount) {
    MeshData meshData;

    float sectorStep = 2 * M_PI / sectorCount;
    float sectorAngle;

    // 顶点
    Vertex vertex;
    vertex.position = glm::vec3(0.0f, height / 2.0f, 0.0f);
    vertex.normal = glm::vec3(0.0f, 1.0f, 0.0f);
    vertex.texCoord = glm::vec2(0.5f, 0.5f);
    meshData.vertices.push_back(vertex);

    for (int i = 0; i <= sectorCount; ++i) {
        sectorAngle = i * sectorStep;
        vertex.position = glm::vec3(radius * cosf(sectorAngle), -height / 2.0f, radius * sinf(sectorAngle));
        vertex.normal = glm::vec3(cosf(sectorAngle), 0.0f, sinf(sectorAngle));
        vertex.texCoord = glm::vec2(cosf(sectorAngle) * 0.5f + 0.5f, sinf(sectorAngle) * 0.5f + 0.5f);
        meshData.vertices.push_back(vertex);
    }

    // 索引
    for (int i = 1; i <= sectorCount; ++i) {
        meshData.indices.push_back(0);
        meshData.indices.push_back(i);
        meshData.indices.push_back(i + 1);
    }

    return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::createTetrahedron(float size) {
    MeshData meshData;

    float halfSize = size / 2.0f;

    // 定义四面体的4个顶点
    std::vector<glm::vec3> positions = {
        { 0.0f,  halfSize,  0.0f},
        { 0.0f, -halfSize,  halfSize},
        {-halfSize, -halfSize, -halfSize},
        { halfSize, -halfSize, -halfSize}
    };

    // 定义四面体的4个面
    std::vector<unsigned int> indices = {
        0, 1, 2,
        0, 2, 3,
        0, 3, 1,
        1, 3, 2
    };

    // 定义法线
    std::vector<glm::vec3> normals = {
        { 0.0f,  0.707f, -0.707f},
        {-0.816f,  0.408f,  0.408f},
        { 0.816f,  0.408f,  0.408f},
        { 0.0f, -0.707f, -0.707f}
    };

    // 构建顶点数据
    for (unsigned int i = 0; i < indices.size(); ++i) {
        Vertex vertex;
        vertex.position = positions[indices[i]];
        vertex.normal = normals[i / 3];
        vertex.texCoord = glm::vec2(0.0f, 0.0f); // 四面体通常不需要纹理坐标
        meshData.vertices.push_back(vertex);
        meshData.indices.push_back(i);
    }

    return meshData;
}

std::vector<float> GeometryGenerator::extractPositionData(const MeshData& meshData)
{
	std::vector<float> positionData;
	for (const Vertex& vertex : meshData.vertices) {
		positionData.push_back(vertex.position.x);
		positionData.push_back(vertex.position.y);
		positionData.push_back(vertex.position.z);
	}
	return positionData;
}

Mesh* GeometryGenerator::extractPositionMesh(const MeshData& meshData)
{
	std::vector<float> positionData;
	for (const Vertex& vertex : meshData.vertices) {
		positionData.push_back(vertex.position.x);
		positionData.push_back(vertex.position.y);
		positionData.push_back(vertex.position.z);
	}
	Mesh* mesh = new Mesh(positionData.data(), positionData.size() * sizeof(float), { 0,3,GL_FLOAT,GL_FALSE,0,0 });
	return mesh;
}
