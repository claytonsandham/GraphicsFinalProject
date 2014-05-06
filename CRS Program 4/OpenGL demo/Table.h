#pragma once
#include "geometry.h"
#include "Node.h"
#include "Utility.h"
class Table :
	public Geometry
{
public:
	Table(glm::vec3 Scale, glm::vec3 Rotate, float RotAngle, glm::vec3 Translate);
    Table();
	~Table(void);
    void initialize(unsigned int, unsigned int);
    void draw(glm::vec3 Scale, glm::vec3 Rotate, float RotAngle, glm::vec3 Translate);
    void draw(glm::mat4 Matrix, glm::vec3 color);
	void setColor(glm::vec3 color);
	Geometry* cube;
	void setCube(Geometry* _cube);
	bool collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity);
private:
	Node* subGeometry;
};

