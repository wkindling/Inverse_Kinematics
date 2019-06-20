#include "skeleton.h"

Bone* root = new Bone(Vector3d(0, 0, 0));
Bone* bone1 = new Bone(root, 2.5, 0.5*PI, 0.5*PI);
Bone* bone2 = new Bone(bone1, 2.5, 0.5*PI, 0.5*PI);
Bone* bone3 = new Bone(bone2, 2.5, 0.5*PI, 0.5*PI);
Bone* bone4 = new Bone(bone3, 2.5, 0.5*PI, 0.5*PI);
Bone* bone5 = new Bone(bone4, 2.5, 0.5*PI, 0.5*PI);
Bone* bone6 = new Bone(bone5, 2.5, 0.5*PI, 0.5*PI);
Bone* bone7 = new Bone(bone6, 2.5, 0.5*PI, 0.5*PI);


Skeleton skeleton(root);

double target_x = bone7->position.x(); 
double target_y = bone7->position.y();
double target_z = bone7->position.z();


void display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(20, 20, 20, 0, 0, 0, 0, 0, 1);
	glPushMatrix();
	
	glColor3f(0, 0, 1);
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex3d(target_x, target_y, target_z);
	glEnd();

	glColor3d(0, 0, 0);
	glLineWidth(2.0f);
	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(20, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 20, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 20);
	glEnd();

	skeleton.ccd(bone7, Vector3d(target_x, target_y, target_z));
	skeleton.draw();

	glPopMatrix();
	glutPostRedisplay();
	glutSwapBuffers();
}

void mykeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w': target_x += 0.1; break;
		case 's': target_x -= 0.1; break;
		case 'a': target_y += 0.1; break;
		case 'd': target_y -= 0.1; break;
		case 'q': target_z += 0.1; break;
		case 'e': target_z -= 0.1; break;
	}
	glutPostRedisplay();
}

void reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 0.5f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("IK_3D");
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(mykeyboard);
	glutMainLoop();
}