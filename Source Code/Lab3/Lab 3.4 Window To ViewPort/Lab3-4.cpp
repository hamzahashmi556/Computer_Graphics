#include <iostream>
#include <fstream>
#include <string>
#include <GL/freeglut.h>
using namespace std;

float minX = -10 ,minY = -10, maxX = 10, maxY = 10;
int VP_left = 0,VP_bottom = 0, VPwidth = 640 , VPHeight = 480;

void drawAxis()
{
	glBegin(GL_LINES);
	glVertex2f(minX,0);
	glVertex2f(maxX,0);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2f(0,minY);
	glVertex2f(0,maxY);
	glEnd();
	
}
void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(VP_left,VP_bottom,VPwidth,VPHeight);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(minX,maxX,minY,maxY);
    drawAxis();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Window To View Port ");
    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;
}
