#include <vector>
#include "../base/Mesh.h"
class ImportedModel
{
private:
	int numVertices;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normalVecs;
public:
	ImportedModel();
	ImportedModel(const char *filePath);
	int getNumVertices();
	std::vector<glm::vec3> getVertices();
	std::vector<glm::vec2> getTextureCoords();
	std::vector<glm::vec3> getNormals();

	Mesh* getPosMesh();
	Mesh* getNormalMesh();
	Mesh* getTexMesh();
	static float* getVerticesArray(std::vector<glm::vec3> vertices);
	static float* getVerticesArray(std::vector<glm::vec2> vertices);
};

class ModelImporter
{
private:
	std::vector<float> vertVals;
	std::vector<float> triangleVerts;
	std::vector<float> textureCoords;
	std::vector<float> stVals;
	std::vector<float> normals;
	std::vector<float> normVals;
public:
	ModelImporter();
	void parseOBJ(const char *filePath);
	int getNumVertices();
	std::vector<float> getVertices();
	std::vector<float> getTextureCoordinates();
	std::vector<float> getNormals();
};