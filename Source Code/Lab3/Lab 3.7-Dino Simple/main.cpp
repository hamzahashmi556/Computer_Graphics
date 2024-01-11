#include <iostream>
#include <fstream>
#include <GL/freeglut.h>

using std::cout;
using std::fstream;
using std::ios;

const int screenWidth = 640;
const int screenHeight = 480;

void myInit(void)
{
    glClearColor(0.9, 0.9, 0.9, 0.0);//the color is a very light gray
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);// Sets the matrix mode for projection transformations, enabling you to configure how the 3D scene is projected onto a 2D screen or viewport.
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}

void drawPolyLineFile(const char* fileName)
{
	fstream inStream;
    inStream.open(fileName, ios ::in); // open the file
    if(inStream.fail())
	    return;
    glClear(GL_COLOR_BUFFER_BIT); // clear the screen
    GLint numpolys, numLines, x ,y;
    inStream >> numpolys; // read the number of polylines
   for(int j = 0; j < numpolys; j++) // read each polyline
    {
    inStream >> numLines;
    glBegin(GL_LINE_STRIP); // draw the next polyline
    for (int i = 0; i < numLines; i++)
    {
    inStream >> x >> y; // read the next x, y pair
    glVertex2i(x, y);
    }
    glEnd();
    }
    glFlush();
    inStream.close(); 

}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_MODELVIEW);//Sets the matrix mode for modeling transformations, allowing you to control the view and position of objects in 3D space.
    glLoadIdentity();
    drawPolyLineFile("dino.dat");

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Dinosaur :(");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;

} 
