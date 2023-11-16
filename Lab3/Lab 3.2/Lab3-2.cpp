#include <iostream>
#include <fstream>
#include <string>
#include <GL/freeglut.h>
//using namespace std;

void myinit(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set the clear color to black
    glColor3f(0.0, 0.0, 1.0); // Set the drawing color to blue
    glPointSize(10.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

void display(void)
{   
    glFlush();
}

void mouse(int button, int state, int x, int y)
{   
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        
        glBegin(GL_POINTS);
        glVertex2d(x, 480 - y);
        glEnd();
        
    }
    else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        glClearColor(0.0, 0.0, 0.0, 1.0); // Set the clear color to black
        glClear(GL_COLOR_BUFFER_BIT);   
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Arham Sharif EB21102022");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    myinit();
    glutMainLoop();
    return 0;
}
