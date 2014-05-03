/*
	Author:	Clayton Sandham
	Course:	COMP 361, Computer Graphics
	Date:	February 10, 2014
	Description: This file contains the function definitions for the Cube class.
*/
#include "Cube.h"


Cube::Cube(glm::vec3 Scale, glm::vec3 Rotate, float RotAngle, glm::vec3 Translate)
{
    //Start with identity matrix
	modelMatrix = glm::mat4(1.0f);
	
	localMatrix = glm::scale(localMatrix, Scale);
	localMatrix = glm::rotate(localMatrix, RotAngle, Rotate);
	localMatrix = glm::translate(localMatrix, Translate);

	u_modelMatrix = 0;
	shaderProgram = 0;
	vertexBuffer = 0;
	colorBuffer = 0;
	normalBuffer = 0;
	indexBuffer = 0;
	vLocation = 0;
	vColor = 0;
	vNormal = 0;
}
Cube::Cube()
{
	modelMatrix = glm::mat4(1.0f);

    localMatrix = glm::mat4(1.0f);
	localMatrix = glm::scale(localMatrix, glm::vec3(1, 1, 1));
	localMatrix = glm::rotate(localMatrix, 0.0f, glm::vec3(1, 1, 1));
	localMatrix = glm::translate(localMatrix, glm::vec3(0, 0, 0));

	u_modelMatrix = 0;
	shaderProgram = 0;
	vertexBuffer = 0;
	colorBuffer = 0;
	normalBuffer = 0;
	indexBuffer = 0;
	vLocation = 0;
	vColor = 0;
	vNormal = 0;
}


Cube::~Cube(void)
{
}

typedef glm::vec3 color3;
typedef glm::vec4 point4;
typedef glm::vec4 normal4;

const int NumVertices = 24;

point4 points[NumVertices];
color3 colors[NumVertices];
normal4 normals[NumVertices];
int indices[36];

point4 vertices[8] = {
	point4(-0.5, -0.5, 0.5, 1.0),	//0 //Front //Bottom Left
	point4(-0.5, 0.5, 0.5, 1.0),	//1 //Front //Top Left
	point4(0.5, 0.5, 0.5, 1.0),		//2 //Front //Top right
	point4(0.5, -0.5, 0.5, 1.0),	//3 //Front //Bottom right

	point4(-0.5, -0.5, -0.5, 1.0),	//4 //Back //Bottom Left
	point4(-0.5, 0.5, -0.5, 1.0),	//5 //Back //Top Left
	point4(0.5, 0.5, -0.5, 1.0),	//6 //Back //Top right
	point4(0.5, -0.5, -0.5, 1.0)	//7 //Back //Bottom right
};



color3 vertex_colors[8] = {
	color3(0.5, 0.5, 0.5), //gray
	color3(1.0, 0.0, 0.0), //red
	color3(1.0, 1.0, 0.0), //yellow
	color3(0.0, 1.0, 1.0), //cyan
	color3(0.0, 1.0, 0.0), //green
	color3(1.0, 0.0, 1.0), //magenta
	color3(0.0, 0.0, 1.0), //blue
	color3(0.0, 0.0, 0.0)  //Black
};

void quad(int a, int b, int c, int d, int color, normal4 normal);

void colorcube( void )
{
	quad(1, 0, 3, 2, 1, normal4(0.0, 0.0, 1.0, 0.0)); //Front
	quad(2, 3, 7, 6, 1, normal4(1.0, 0.0, 0.0, 0.0)); //Right
	quad(0, 4, 7, 3, 1, normal4(0.0, -1.0, 0.0, 0.0)); //bottom

	quad(5, 1, 2, 6, 1, normal4(0.0, 1.0, 0.0, 0.0)); //top
	quad(4, 5, 6, 7, 1, normal4(0.0, 0.0, -1.0, 0.0)); //back
	quad(5, 4, 0, 1, 1, normal4(-1.0, 0.0, 0.0, 0.0)); //left
}

int Index = 0;
int indices_index = 0;
void quad(int a, int b, int c, int d, int color, normal4 normal)
{
	colors[Index] = vertex_colors[color]; 
	points[Index] = vertices[a];
	normals[Index] = normal;
	a = Index;
	Index++;

	colors[Index] = vertex_colors[color]; 
	points[Index] = vertices[b]; 
	normals[Index] = normal;
	b = Index;
	Index++;

	colors[Index] = vertex_colors[color]; 
	points[Index] = vertices[c]; 
	normals[Index] = normal;
	c = Index;
	Index++;

	colors[Index] = vertex_colors[color]; 
	points[Index] = vertices[d]; 
	normals[Index] = normal;
	d = Index;
	Index++;
	
	
	indices[indices_index] = a; indices_index++;
	indices[indices_index] = b; indices_index++;
	indices[indices_index] = d; indices_index++;
	indices[indices_index] = b; indices_index++;
	indices[indices_index] = c; indices_index++;
	indices[indices_index] = d; indices_index++;



	//colors[Index] = vertex_colors[a]; 
	//points[Index] = vertices[a]; 
	//Index++;

	//colors[Index] = vertex_colors[a]; 
	//points[Index] = vertices[b]; 
	//Index++;

	//colors[Index] = vertex_colors[a]; 
	//points[Index] = vertices[c]; 
	//Index++;

	//colors[Index] = vertex_colors[a]; 
	//points[Index] = vertices[a]; 
	//Index++;

	//colors[Index] = vertex_colors[a]; 
	//points[Index] = vertices[c]; 
	//Index++;

	//colors[Index] = vertex_colors[a]; 
	//points[Index] = vertices[d]; 
	//Index++;
}




void Cube::initialize(unsigned int shaderProgram, unsigned int modelMatrix)
{
    colorcube();
    u_modelMatrix = modelMatrix;
	this->shaderProgram = shaderProgram;

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, 24*sizeof(point4), points, GL_STATIC_DRAW);
	this->vertexBuffer = vertexBuffer;

	vLocation = glGetAttribLocation(shaderProgram, "vs_position");
	glEnableVertexAttribArray(vLocation);
	glVertexAttribPointer(vLocation, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, 24*sizeof(color3), colors, GL_STATIC_DRAW);
	this->colorBuffer = colorBuffer;

	vColor = glGetAttribLocation(shaderProgram, "vs_color");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, 0);
	this->vColor = vColor;

	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, 24*sizeof(normal4), normals, GL_STATIC_DRAW);
	this->normalBuffer = normalBuffer;

	vNormal = glGetAttribLocation(shaderProgram, "vs_normal");
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal, 4, GL_FLOAT, GL_FALSE, 0, 0);
	
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36*sizeof(GLuint), indices, GL_STATIC_DRAW);
	this->indexBuffer = indexBuffer;
	
}

void Cube::draw(glm::vec3 Scale, glm::vec3 Rotate, float RotAngle, glm::vec3 Translate)
{
	//Start with identity matrix
	modelMatrix = glm::mat4(1.0f);
	
	modelMatrix = glm::scale(modelMatrix, Scale);
	modelMatrix = glm::rotate(modelMatrix, RotAngle, Rotate);
	modelMatrix = glm::translate(modelMatrix, Translate);

	draw(modelMatrix, color3(1.0f, 0, 0));

}
void Cube::draw(glm::mat4 Matrix, glm::vec3 color)
{
	setColor(color);

	modelMatrix = Matrix * localMatrix;
    glUniformMatrix4fv(u_modelMatrix, 1, GL_FALSE, &modelMatrix[0][0]);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, 24*sizeof(point4), points, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, 24*sizeof(normal4), normals, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36*sizeof(GLuint), indices, GL_STATIC_DRAW);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glFlush();
}

void Cube::setColor(glm::vec3 color)
{
	for (int i = 0; i < 24; ++i)
	{
		colors[i] = color3(color.x, color.y, color.z);
	}

	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, 24*sizeof(color3), colors, GL_STATIC_DRAW);

	//GLuint vColor = glGetAttribLocation(shaderProgram, "vs_color");
	//glEnableVertexAttribArray(vColor);
	//glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, 0);
}