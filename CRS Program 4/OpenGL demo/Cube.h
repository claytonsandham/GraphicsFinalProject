/*
	Author:	Clayton Sandham
	Course:	COMP 361, Computer Graphics
	Date:	February 10, 2014
	Description: This file contains the class definition for a Cube, which inherits from Geometry.
*/
#pragma once
#include "geometry.h"
class Cube :
	public Geometry
{
public:
	Cube(glm::vec3 Scale, glm::vec3 Rotate, float RotAngle, glm::vec3 Translate);
    Cube();
	~Cube(void);
    void initialize(unsigned int shaderProgram, unsigned int u_modelMatrix);
    void draw(glm::vec3 Scale, glm::vec3 Rotate, float RotAngle, glm::vec3 Translate);
    void draw(glm::mat4 Matrix, glm::vec3 color);
	void setColor(glm::vec3 color);

private:
	GLuint u_modelMatrix;
	GLuint shaderProgram;

	GLuint vertexBuffer;
	GLuint colorBuffer;
	GLuint normalBuffer;

	GLuint indexBuffer;
	GLuint vLocation;
	GLuint vColor;
	GLuint vNormal;
};

