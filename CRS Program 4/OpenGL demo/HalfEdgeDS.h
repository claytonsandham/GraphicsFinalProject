#include "glm/glm.hpp"

using glm::vec4;

struct HEEdge {
public : 
	HEFace *face;
	HEEdge *next;
	HEEdge *pair;
	HEVertex *vertex;
};

struct HEFace {
	HEEdge *edge; 
};

struct HEVertex {
public : 
	HEEdge *edge;
	vec4 location;
};