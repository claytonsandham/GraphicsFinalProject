#include "HalfEdge.h"

HalfEdge::HalfEdge(int xIndex, int zIndex, float rotation = 0.0f, float xScale = 1.0f, float yScale = 1.0f, float zScale = 1.0f)
	: loc(xIndex, zIndex), rotation(rotation), scale(xScale, yScale, zScale) {
		srand(time(NULL));
}

HalfEdge::HalfEdge(char *inputFile, int thing, int xIndex, int zIndex, float rotation = 0.0f, float xScale = 1.0f, float yScale = 1.0f, float zScale = 1.0f)
	: loc(xIndex, zIndex), rotation(rotation), scale(xScale, yScale, zScale) {
		srand(time(NULL));
		load(inputFile);
}

HalfEdge::~HalfEdge() { }
void HalfEdge::load() { }

void HalfEdge::load(char *inputFile) {
	ifstream fin(inputFile);

	if (!fin.is_open()) {
		char error[512];
		strcpy_s(error, inputFile);
		strcat_s(error, " is missing and cannot be loaded.");

		throw exception(error);
	}

//Determine the number of slices
	fin >> slices;

//Determine the number of vertices
	fin >> polylineTotal;

//Gather each of the vertices
	vec4 pt;
	pt.z = 0.0f;

	for(int i = 0; i < polylineTotal; ++i) { 
		fin >> pt.x;
		fin >> pt.y;
		
		polyline.push_back(Vertex(pt.x, pt.y, pt.z));
	}

//Is the last point touching the Y-axis (closing the polyline)?
	if (polyline.back().location.x != 0.0f) {
		pt.x = 0.0f;
		pt.y = polyline.back().location.y;
		pt.z = 0.0f;

		polyline.push_back(Vertex(pt.x, pt.y, pt.z));
		++polylineTotal;
	}
}

