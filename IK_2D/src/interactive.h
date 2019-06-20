#pragma once
#ifndef INTERACTIVE_H
#define INTERACTIVE_H
#include <glut.h>

Bone* root = new Bone();
Bone* bone1 = new Bone(root, 100, 0.25*PI);
Bone* bone2 = new Bone(bone1, 100, 0.25*PI);
Bone* bone3 = new Bone(bone2, 100, 0.25*PI);
Bone* bone4 = new Bone(bone3, 100, 0.25*PI);
Bone* bone5 = new Bone(bone4, 100, 0.25*PI);
Bone* bone6 = new Bone(bone5, 100, 0.25*PI);
Bone* bone7 = new Bone(bone6, 100, 0.25*PI);

Skeleton skeleton(root);
double target_x=bone7->position.x(), target_y=bone7->position.y();

void changePoint(int x, int y)
{
	target_x = x;
	target_y = 700 - y;
	glutPostRedisplay();
}

#endif