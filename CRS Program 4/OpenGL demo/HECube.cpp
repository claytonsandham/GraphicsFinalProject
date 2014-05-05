#include "HECube.h"


HECube::HECube(void)
{
}

HECube::HECube(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate) : HEExtrusion(Scale, Rotate, RotAngle, Translate)
{
	VertLine base;
	base.addVertex(vec4(-0.5, 0, -0.5, 0));
	base.addVertex(vec4(-0.5, 0, 0.5, 0));
	base.addVertex(vec4(0.5, 0, 0.5, 0));
	base.addVertex(vec4(0.5, 0, -0.5, 0));

	extrude(base);
}

void HECube::initialize(unsigned int shaderProgram, unsigned int u_modelMatrix)
{
	HalfEdge::initialize(shaderProgram, u_modelMatrix);
}


HECube::~HECube(void)
{
}
