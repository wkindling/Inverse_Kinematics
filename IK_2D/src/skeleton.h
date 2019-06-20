#pragma once
#ifndef SKELETON_H
#define SKELETON_H

#include "bone.h"


class Skeleton
{
public :
	Skeleton();
	Skeleton(Bone* _root);
	~Skeleton();

	void ccd(Bone* opBone, Vector2d target);
	void draw();
	void updatePosition();

public :

	Bone* root;


};















#endif