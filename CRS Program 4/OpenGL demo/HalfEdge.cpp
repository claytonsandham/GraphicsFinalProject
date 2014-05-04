#include "HalfEdge.h"

HalfEdge::HalfEdge(vec3 scale, vec3 rotate, float rotAngle, vec3 translate) : 
	Mesh(scale, rotate, rotAngle, translate) { }

HalfEdge::~HalfEdge() { }

void HalfEdge::import(ifstream& reader) {
//Clear all the things!
	edges.clear();
	faces.clear();
	verts.clear();
	polylineTotal = 0;
	slices = 0;

//Determine the number of slices
	reader >> slices;

//Determine the number of vertices
	reader >> polylineTotal;

//Gather each of the vertices
	vec4 pt;
	pt.z = 0.0f;
	pt.w = 1.0f;

	for(int i = 0; i < polylineTotal; ++i) { 
		reader >> pt.x;
		reader >> pt.y;
		
		polyline.push_back(pt);
	}

//Is the last point touching the Y-axis (closing the polyline)?
	//if (polyline.back().x != 0.0f) {
	//	pt.x = 0.0f;
	//	pt.y = polyline.back().y;
	//
	//	polyline.push_back(pt);
	//	++polylineTotal;
	//}

//Now revolve!
	revolve();
}

void HalfEdge::revolve() {
//Keep track of points touching the y-axis
	vector<HEVertex*> yVec;

//Calculate the rotation matrix based on the number of slices
	float degrees = 360.0f / slices;
	mat4 rotNowMatrix = mat4(1.0f);
	mat4 rotNextMatrix = mat4(1.0f);

//The FIRST iteration will handle plotting the y-points
	rotNextMatrix = rotate(rotNextMatrix, degrees, vec3(0, 1, 0));

	for(int i = 0; i < polylineTotal - 1; ++i) {
		HEVertex vNow;
		HEVertex vNext;
		HEVertex vNnext;
		HEVertex vNnnext;

		HEEdge eNow;
		HEEdge eNext;
		HEEdge eNnext;
		HEEdge eNnnext;

		HEFace face;

	//Case 1: triangle, tip side down
		if (polyline[i].y == 0.0f) {
		//
		//        b
		// 3  +-------+   2
		//     \     /
		//   c  \   /  a
		//       \ /
		//        V
		//        1
		//

		//Create the vertices
			vNow.location = polyline[i];                      // 1
			vNext.location = polyline[i + 1] * rotNextMatrix; // 2
			vNnext.location = polyline[i + 1];                // 3

		//Create the edges
			eNow.face = &face;                                // a
			eNow.next = &eNext;
			eNow.vertex = &vNext;

			eNext.face = &face;                               // b
			eNext.next = &eNnext;
			eNext.vertex = &vNnext;

			eNnext.face = &face;                              // c
			eNnext.next = &eNow;
			eNnext.vertex = &vNow;

		//Add to the face
			face.edge = &eNow;

		//Keep track of everything
			verts.push_back(vNow);
			verts.push_back(vNext);
			verts.push_back(vNnext);

			edges.push_back(eNow);
			edges.push_back(eNext);
			edges.push_back(eNnext);

			faces.push_back(face);

		//This vertex is on the y-axis
			yVec[i] = &vNow;
	//Case 2: quad, no vertices touch
		} else if (polyline[i].y != 0.0f && polyline[i + 1].y != 0.0f) {
		//
		//    3   b   2
		//    +-------+
		//    |       |
		//  c |       |  a
		//    |       |
		//    +-------+
		//    4   d   1
		//
			
	//Case 3: triangle, tip side up
		} else if (polyline[i + 1].y == 0.0f) {
			
	//Case 4: line on y-axis
		} else {
			
		}

		now = polyline[i];
		next = polyline
	}

//Create the vertices for each rotation slice
	for(int i = 0; i < slices; ++i) {
		rotNextMatrix = rotate(rotNextMatrix, degrees, vec3(0, 1, 0));


	}
}