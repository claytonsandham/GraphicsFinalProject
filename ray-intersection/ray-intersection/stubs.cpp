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

	float epsilon = 0.001; //fine tune this value

	vec3 E = vec3((inverse(T) * vec4(P0,1))); //Transform the ray origin
	mat4 cMult = mat4(1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1); //Prepare to make C*
	vec3 D = vec3((inverse(matrixCompMult(T,cMult)) * vec4(V0,0))); //Transform the ray direction
	vec3 v1 = p3 - p1; //prep for Normal vector calc
	vec3 v2 = p3 - p2;
	vec3 N = cross(v1,v2); //calculate the normal vector
	vec3 P = E + D; //Calculate a point on the ray
	if (dot(N, P-E) == 0) //t would be undefined
		return -1;
	float t = dot(N, p1 - E)/dot(N, P - E); //Find the value for t
	if (t - epsilon < 0) //the ray is parallel to the plane
		return -1;
	vec3 R = E + t*(P - E);
	//set up matrices for area calculations
	mat3 S01 = mat3(p1.y, p1.z, 1, p2.y, p2.z, 1, p3.y, p3.z, 1);
	mat3 S02 = mat3(p1.z, p1.x, 1, p2.z, p2.x, 1, p3.z, p3.x, 1);
	mat3 S03 = mat3(p1.x, p1.y, 1, p2.x, p2.y, 1, p3.x, p3.y, 1);
	
	mat3 S11 = mat3(R.y, R.z, 1, p2.y, p2.z, 1, p3.y, p3.z, 1);
	mat3 S12 = mat3(R.z, R.x, 1, p2.z, p2.x, 1, p3.z, p3.x, 1);
	mat3 S13 = mat3(R.x, R.y, 1, p2.x, p2.y, 1, p3.x, p3.y, 1);

	mat3 S21 = mat3(R.y, R.z, 1, p3.y, p3.z, 1, p1.y, p1.z, 1);
	mat3 S22 = mat3(R.z, R.x, 1, p3.z, p3.x, 1, p1.z, p1.x, 1);
	mat3 S23 = mat3(R.x, R.y, 1, p3.x, p3.y, 1, p1.x, p1.y, 1);

	mat3 S31 = mat3(R.y, R.z, 1, p1.y, p1.z, 1, p2.y, p2.z, 1);
	mat3 S32 = mat3(R.z, R.x, 1, p1.z, p1.x, 1, p2.z, p2.x, 1);
	mat3 S33 = mat3(R.x, R.y, 1, p1.x, p1.y, 1, p2.x, p2.y, 1);

	//After matrices are set up calculate areas

	float S0 = sqrt(determinant(S01)*determinant(S01) + determinant(S02)*determinant(S02) + determinant(S03)*determinant(S03));
	float S1 = sqrt(determinant(S11)*determinant(S11) + determinant(S12)*determinant(S12) + determinant(S13)*determinant(S13))/S0;
	float S2 = sqrt(determinant(S21)*determinant(S21) + determinant(S22)*determinant(S22) + determinant(S23)*determinant(S23))/S0;
	float S3 = sqrt(determinant(S31)*determinant(S31) + determinant(S32)*determinant(S32) + determinant(S33)*determinant(S33))/S0;
	float testS = S1+S2+S3;
	
	if (testS <= 1 + epsilon && testS >= 1 - epsilon) //Include epsilon value since floating point numbers are not 100% accurate
		return t;
	else
		return -1;
}

double Test_RayCubeIntersect(const vec3& P0, const vec3& V0, const mat4& T) {
	// TODO fill this in.
	// See the documentation of this function in stubs.h.

	return -1;
}