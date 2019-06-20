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

void Skeleton::ccd(Bone* opBone, Vector3d target)
{
	int count = 0;
	while (opBone->position != target)
	{
		count++;
		opBone->ccd(opBone, target);
		if (count > 1000)
		{
			break;
		}
	}
}

void Skeleton::draw()
{
	root->draw();
}

void Skeleton::updatePosition()
{
	root->updatePosition();
}