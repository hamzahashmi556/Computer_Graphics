#include <iostream>
#include <fstream>
#include <string>
#include <GL/freeglut.h>
using namespace std;

int screenWidth = 640;
int screenHeight = 480;

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void myMouse(int button, int state, int mx , int my)
{
	if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		glutPostRedisplay();
	}
	if ( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		glClear(GL_COLOR_BUFFER_BIT);//function to clear the color buffer of the OpenGL rendering context.
		glFlush();
	}
}

void myinit()
{
	glClearColor(0.9f,0.9f,0.9f,0.0);//background
	glColor3f(1,0,0); // Foreground
}

void myReshape(int w ,int h)
{
	int screenwidth = w;
 	int screenHeight = h;
   
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)screenwidth,0.0,(GLdouble)screenHeight);
    
//    glMatrixModel(GL_MODELVIEW)
//    glLoadIdentity();
   
}
void mouseMove(int x , int y)
{
	glutPostRedisplay();
}

void myKeys(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 'q':exit(0);
		case 's': break;
	}
	glutPostRedisplay();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Hamza Alam Hashmi EB21102031");  
    myinit();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(myKeys);
    glutMouseFunc(myMouse);
    glutMotionFunc(mouseMove);
    glutMainLoop();
    return 0;
}

