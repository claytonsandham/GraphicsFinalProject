#include "stubs.h"

using namespace glm;

double Test_RaySphereIntersect(const vec3& P0, const vec3& V0, const mat4& T) {
//Transform the ray to local space
	mat4 PTrans = inverse(T);
	mat4 VTrans = T;
	VTrans[0].w = 0;
	VTrans[1].w = 0;
	VTrans[2].w = 0;
	VTrans = inverse(VTrans);

	vec4 P1 = vec4(P0, 0) * PTrans;
	vec4 V1 = vec4(V0, 0) * VTrans;
	vec3 P = vec3(P1);
	vec3 V = vec3(V1);

//Generate infomation about the sphere
	float radius = 1.0f;
	vec3 translate(T[3].x, T[3].y, T[3].z);
	vec3 TwoV(2 * V.x, 2 * V.y, 2 * V.z);

//Find out the T value
	int a = 1;
	float b = dot(TwoV, P - translate);
	float c = pow(length(P - translate), 2) - pow(radius, 2);

	float t1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	float t2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

//Which value should return?
	if (t1 < 0 && t2 < 0) { // 0 solutions
		return -1;
	} else if (t1 >= 0 && t2 < 0) { // 1 solution
		return t1;
	} else if (t1 < 0 && t2 >= 0) { // 1 solution
		return t2;
	} else { // 2 solutions
		return t1 < t2 ? t1 : t2;
	}	
}

double Test_RayPolyIntersect(const vec3& P0, const vec3& V0, const vec3& p1, const vec3& p2, const vec3& p3, const mat4& T) {
	// TODO fill this in.
	// See the documentation of this function in stubs.h.

	return -1;
}

double Test_RayCubeIntersect(const vec3& P0, const vec3& V0, const mat4& T) {
	// TODO fill this in.
	// See the documentation of this function in stubs.h.

	return -1;
}