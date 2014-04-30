#pragma once
#include "mesh.h"
class SurfRev :
	public Mesh
{
public:
	SurfRev(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate);
	~SurfRev(void);
	void import(ifstream& reader);
	vector<Face> rotate(Face polygon);
private:
	int slices;
};

