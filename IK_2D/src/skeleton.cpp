#include "skeleton.h"


Skeleton::Skeleton()
{
	root = nullptr;
}

Skeleton::Skeleton(Bone* _root)
{
	root = _root;
}

Skeleton::~Skeleton() {}

void Skeleton::ccd(Bone* opBone, Vector2d target)
{
	int count = 0;
	while (opBone->position != target)
	{
		count++;
		opBone->ccd(opBone, target);
		if (count == 80) break;
	}

}

void Skeleton::draw()
{
	root->draw2D();
}

void Skeleton::updatePosition()
{
	root->updatePosition();
}