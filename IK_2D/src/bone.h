#pragma once
#ifndef BONE_H
#define BONE_H

#include <Eigen/Dense>
#include <vector>
#include <cassert>
#include <glut.h>
#include <iostream>
#include <cmath>

#define PI 3.1415926535


using namespace std;
using namespace Eigen;



class Bone
{
public:
	Bone();
	Bone(Bone* _father, double _length, double _angle);
	~Bone();

	void updatePosition();
	void draw2D();
	void addChildren(Bone* child);
	void ccd(Bone* opBone, Vector2d target);

public:
	double length;
	double angle;
	Vector2d position;
	Bone* father;
	vector<Bone*> children;

	EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};








#endif