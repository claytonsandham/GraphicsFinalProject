#include "HEExtrusion.h"


HEExtrusion::HEExtrusion(void)
{
	
}

HEExtrusion::HEExtrusion(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate) :
	HalfEdge(Scale, Rotate, RotAngle, Translate)
{
	height = 1;
}

HEExtrusion::~HEExtrusion(void)
{
}

void HEExtrusion::extrude(VertLine base)
{
	//This assumes the vertices from base have not been added to the mesh.
	for(int i=0; i<base.points.size(); ++i)
	{
		addHEVert(base.points[i]);
	}

	//Create top verts.
	VertLine top;
	for(int i = 0; i < base.points.size(); ++i)
	{
		top.addVertex(base.points[i]->position + vec4(0, height, 0, 0));
		addHEVert(top.points[i]);
	}

//Create base edges
	vector<HEEdge*> baseEdges;
	HEEdge* first;
	HEEdge* last, *current;
	HEFace* baseFace = new HEFace();
	addHEFace(baseFace);
	baseFace->edge = first;
	baseEdges.resize(base.points.size());
	for(int i = base.points.size()-1; i >= 0; --i)
	{
		if(i == base.points.size()-1)
		{
			first = new HEEdge();
			addHEEdge(first);
			baseEdges[i] = first;
			first->vertex = base.points[i];
			
			baseFace->edge = first;

			first->face = baseFace;
			first->pair = NULL;
			last = first;
		}
		else
		{
			current = new HEEdge();
			addHEEdge(current);
			baseEdges[i] = current;
			last->next = current;
			current->vertex = base.points[i];
			baseFace->edge = current;
			current->face = baseFace;
			current->pair = NULL;
			last = current;

			if(i==0)
			{
				current->next = first;
			}
		}
	}

	for(int i = 0; i < base.points.size(); ++i)
	{
		if(i==0)
		{
			base.points[i]->edge = baseEdges[baseEdges.size()-1];
		}
		else
		{
			base.points[i]->edge = baseEdges[i-1];
		}
	}

//Create side edges
	HEEdge* firstPost;
	HEEdge* left;
	HEEdge* right;
	vector<HEEdge*> topEdges;
	for(int i = 0; i < base.points.size(); ++i)
	{
		HEFace* sideFace = new HEFace();
		addHEFace(sideFace);

		//Left
		left = new HEEdge();
		addHEEdge(left);
		left->vertex = base.points[i];
		left->face = sideFace;
		left->next = NULL;
		if(i==0)
		{
			left->pair = NULL;
			firstPost = left;
		}
		else
		{
			//This works because of the "left = right;" expression below.
			left->pair = right;
			right->pair = left;
		}
		
		//bottom
		HEEdge* bottom = new HEEdge();
		addHEEdge(bottom);
		left->next = bottom;
		bottom->face = sideFace;
		bottom->vertex = base.points[(i+1)%base.points.size()];
		bottom->pair = baseEdges[i];
		baseEdges[i]->pair = bottom;
		
		//right
		right = new HEEdge();
		addHEEdge(right);
		bottom->next = right;
		right->face = sideFace;
		right->vertex = top.points[(i+1)%top.points.size()];
		sideFace->edge = right;
		if(i == base.points.size()-1)
		{
			right->pair = firstPost;
			firstPost->pair = right;
		}

		//top
		HEEdge* topEdge = new HEEdge();
		addHEEdge(topEdge);
		right->next = topEdge;
		topEdge->face = sideFace;
		topEdge->vertex = top.points[i];
		topEdge->next = left;

		//Creates topEdge;
		topEdge->pair = new HEEdge();
		topEdge->pair->pair = topEdge;
		topEdge->pair->vertex = top.points[(i+1)%top.points.size()];
		topEdges.push_back(topEdge->pair);	
		addHEEdge(topEdge->pair);

		//see comment above.
		left = right;
	}

//Create top edges.
	HEFace* topFace = new HEFace();
	addHEFace(topFace);
	topFace->edge = topEdges[0];
	for(int i = 0; i < top.points.size(); ++i)
	{
		topEdges[i]->next = topEdges[(i+1)%top.points.size()];
		topEdges[i]->face = topFace;
	}

	
	for(int i = 0; i < top.points.size(); ++i)
	{
		top.points[i]->edge = topEdges[i];
	}
}