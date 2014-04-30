/*
	Author:	Clayton Sandham
	Course:	COMP 361, Computer Graphics
	Date:	February 10, 2014
	Description: This file contains the implementation of a node in a scene graph.
*/

#include "Node.h"


Node::Node(glm::mat4 matrix, Geometry* model)
{
	transform = matrix;
	geometry = model;
	this->x = x;
	this->y = y;
	this->color = glm::vec3(0, 0, 1); //Default Red
}


Node::~Node(void)
{
}

void Node::visitChildren(glm::mat4 xform)
{
    if (geometry != NULL)
	{
		geometry->draw(xform * transform, color);
	}
	for (int i=0; i<children.size(); ++i)
	{
		children.at(i)->visitChildren(xform * transform);
	}
}

void Node::setColor(glm::vec3 color)
{
	this->color = color;
}