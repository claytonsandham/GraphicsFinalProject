#include "glm/glm.hpp"
#include <vector>

using glm::vec3;
using glm::vec4;
using std::vector;

struct Face {
public : 
	long ID;
}; // Your face, Clayton, YOUR face

struct HE {
public : 
	Face *face;
	HE *next;
	HE *pair;
	HE *previous;
	Vertex *vertex;
};

struct Location {
	Location() : x(0), y(0), z(0) { }
	Location(int x, int z) : x(x), y(0), z(z) { }
	Location(int x, int y, int z) : x(x), y(y), z(z) { }

	int x;
	int y;
	int z;
};

struct Scale {
	Scale() : x(1.0f), y(1.0f), z(1.0f) { }
	Scale(float x, float y, float z) : x(x), y(y), z(x) { }

	float x;
	float y;
	float z;
};

struct Vertex {
public : 
	Vertex() : ID(rand()) { }
	Vertex(float x, float y, float z) : ID(rand()), location(x, y, z) { }

	vector<Face*> connectedFaces;
	vector<HE*> connectedHEs;
	long ID;
	Location location;
	vec3 normal;
};