#pragma once
#define GLEW_STATIC
#include "glew.h"
#include "../glm/glm.hpp"
#include <stdlib.h>
#include "../glm/gtc/matrix_transform.hpp"
#include <vector>
using std::vector;
using glm::vec3;
using glm::vec4;
using glm::mat4;
class Face
{
public:
	Face(void);
	~Face(void);
	void addVertex(vec4 pos);
	bool isConvex();
	int size();
	vector<vec4> getVertices();
	vector<vec3> getColors();
	void setColors(vec3 color);
	vector<vec4> getNormals();
	void setNormals(vec4 normal);
	vector<int> getIndices(int startIndex);
	vector<Face> triangulate();
private:
	vector<vec4> points;
	vector<vec3> colors;
	vector<vec4> normals;
};

