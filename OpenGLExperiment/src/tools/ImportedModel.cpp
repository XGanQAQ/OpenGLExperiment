#include <fstream>
#include <sstream>
#include <glm\glm.hpp>
#include "ImportedModel.h"
using namespace std;

ImportedModel::ImportedModel() {}

ImportedModel::ImportedModel(const char *filePath) {
	ModelImporter modelImporter = ModelImporter();
	modelImporter.parseOBJ(filePath);
	numVertices = modelImporter.getNumVertices();
	std::vector<float> verts = modelImporter.getVertices();
	std::vector<float> tcs = modelImporter.getTextureCoordinates();
	std::vector<float> normals = modelImporter.getNormals();

	for (int i = 0; i < numVertices; i++) {
		vertices.push_back(glm::vec3(verts[i*3], verts[i*3+1], verts[i*3+2]));
		texCoords.push_back(glm::vec2(tcs[i*2], tcs[i*2+1]));
		normalVecs.push_back(glm::vec3(normals[i*3], normals[i*3+1], normals[i*3+2]));
	}
}

int ImportedModel::getNumVertices() { return numVertices; }
std::vector<glm::vec3> ImportedModel::getVertices() { return vertices; }
std::vector<glm::vec2> ImportedModel::getTextureCoords() { return texCoords; }
std::vector<glm::vec3> ImportedModel::getNormals() { return normalVecs; }

Mesh* ImportedModel::getPosMesh()
{
	if (vertices.size() > 0) {
		float* verts = getVerticesArray(vertices);
		return new Mesh(verts, vertices.size() * 3 * sizeof(float), { 0, 3, GL_FLOAT, GL_FALSE, 0, 0 });
	}
	else return nullptr;
}

Mesh* ImportedModel::getNormalMesh()
{
	if (normalVecs.size() > 0) {
		float* norms = getVerticesArray(normalVecs);
		return new Mesh(norms, normalVecs.size() * 3 * sizeof(float), { 1, 3, GL_FLOAT, GL_FALSE, 0, 0 });
	}
	else return nullptr;
}

Mesh* ImportedModel::getTexMesh()
{
	if (texCoords.size() > 0) {
		float* tcs = getVerticesArray(texCoords);
		return new Mesh(tcs, texCoords.size() * 2 * sizeof(float), { 2, 2, GL_FLOAT, GL_FALSE, 0, 0 });
	}
	else
	return nullptr;
}

float* ImportedModel::getVerticesArray(std::vector<glm::vec3> vertices)
{
	if (vertices.size() > 0) {
		float* verts = new float[vertices.size() * 3];
		for (int i = 0; i < vertices.size(); i++) {
			verts[i * 3] = vertices[i].x;
			verts[i * 3 + 1] = vertices[i].y;
			verts[i * 3 + 2] = vertices[i].z;
		}
		return verts;
	}
	else {
		return nullptr;
	}
}

float* ImportedModel::getVerticesArray(std::vector<glm::vec2> vertices) {
	if (vertices.size() > 0) {
		float* verts = new float[vertices.size() * 2];
		for (int i = 0; i < vertices.size(); i++) {
			verts[i * 2] = vertices[i].x;
			verts[i * 2 + 1] = vertices[i].y;
		}
		return verts;
	}
	else {
		return nullptr;
	}
}
// ---------------------------------------------------------------

ModelImporter::ModelImporter() {}

void ModelImporter::parseOBJ(const char *filePath) {
	float x, y, z;
	string content;
	ifstream fileStream(filePath, ios::in);
	string line = "";
	while (!fileStream.eof()) {
		getline(fileStream, line);
		if (line.compare(0, 2, "v ") == 0) {
			stringstream ss(line.erase(0, 1));
			ss >> x; ss >> y; ss >> z;
			vertVals.push_back(x);
			vertVals.push_back(y);
			vertVals.push_back(z);
		}
		if (line.compare(0, 2, "vt") == 0) {
			stringstream ss(line.erase(0, 2));
			ss >> x; ss >> y;
			stVals.push_back(x);
			stVals.push_back(y);
		}
		if (line.compare(0, 2, "vn") == 0) {
			stringstream ss(line.erase(0, 2));
			ss >> x; ss >> y; ss >> z;
			normVals.push_back(x);
			normVals.push_back(y);
			normVals.push_back(z);
		}
		if (line.compare(0, 2, "f ") == 0) {
			string oneCorner, v, t, n;
			stringstream ss(line.erase(0, 2));
			for (int i = 0; i < 3; i++) {
				getline(ss, oneCorner, ' ');
				stringstream oneCornerSS(oneCorner);
				getline(oneCornerSS, v, '/');
				getline(oneCornerSS, t, '/');
				getline(oneCornerSS, n, '/');

				int vertRef = (stoi(v) - 1) * 3;
				int tcRef = (stoi(t) - 1) * 2;
				int normRef = (stoi(n) - 1) * 3;

				triangleVerts.push_back(vertVals[vertRef]);
				triangleVerts.push_back(vertVals[vertRef + 1]);
				triangleVerts.push_back(vertVals[vertRef + 2]);

				textureCoords.push_back(stVals[tcRef]);
				textureCoords.push_back(stVals[tcRef + 1]);

				normals.push_back(normVals[normRef]);
				normals.push_back(normVals[normRef + 1]);
				normals.push_back(normVals[normRef + 2]);
			}
		}
	}
}
int ModelImporter::getNumVertices() { return (triangleVerts.size()/3); }
std::vector<float> ModelImporter::getVertices() { return triangleVerts; }
std::vector<float> ModelImporter::getTextureCoordinates() { return textureCoords; }
std::vector<float> ModelImporter::getNormals() { return normals; }