#pragma once

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <exception>

#include "HalfEdgeDS.h"
#include "Geometry.h"

using std::exception;
using std::ifstream;

class HalfEdge : Geometry {
// Constructors and destructor
public : 
	HalfEdge(int xIndex, int zIndex, float rotation, float xScale, float yScale, float zScale);
	HalfEdge(char *inputFile, int thing, int xIndex, int zIndex, float rotation, float xScale, float yScale, float zScale);
	~HalfEdge();

// Public function interface
public : 
	void load();
	void load(char *inputFile);
	void subDivide(int iterations = 1);

//Give public access to the data
public : 
	HE *start;

// Internal "interface" for building the object
	void bufferStuffer();
	void build();

// Physical attributes of object
private : 
	Location loc;
	float rotation;
	Scale scale;
	int slices;

// Polyline information
private : 
	vector<Vertex> polyline;
	int polylineTotal;
};