#pragma once

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <exception>

#include "HalfEdgeDS.h"
#include "Mesh.h"

using glm::mat4;
using glm::rotate;
using glm::vec3;
using std::exception;
using std::ifstream;

class HalfEdge : Mesh {
// Constructors and destructor
public : 
	HalfEdge(vec3 scale, vec3 rotate, float rotAngle, vec3 translate);
	~HalfEdge();

// Public function interface
public : 
	void import(ifstream& reader);
	void subDivide(int iterations = 1);

//Give public access to the data
public : 
	HE *start;

// Internal "interface" for building the object
private : 
	void bufferStuffer();
	void revolve();

// Physical attributes of object
private : 
	Location loc;
	float rotation;
	Scale scale;
	int slices;

// Edges and vertices
private : 
	vector<HEEdge> edges;
	vector<HEFace> faces;
	vector<HEVertex> verts;

// Polyline information
private : 
	vector<vec4> polyline;
	int polylineTotal;
};