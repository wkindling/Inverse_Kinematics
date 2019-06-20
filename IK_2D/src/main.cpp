#include "skeleton.h"
#include "interactive.h"

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2.0);
	skeleton.ccd(bone7, Vector2d(target_x, target_y));
	skeleton.draw();
	glColor3f(0, 0, 1);
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2d(target_x, target_y);
	glEnd();

	glutPostRedisplay();
	glutSwapBuffers();
}


int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(700, 700);
	glutCreateWindow("IK");
	glutMotionFunc(changePoint);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 700.0, 0.0, 700.0);
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}

