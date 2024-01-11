#include <iostream>
#include <fstream>
#include <GL/freeglut.h>

using std::cout;
using std::fstream;
using std::ios;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Zooming in and Zooming out on a figure


const int screenWidth = 640;
const int screenHeight = 480;
GLfloat zoomFactor = 1.0; // Initial zoom factor

void myInit(void)
{
    glClearColor(0.9, 0.9, 0.9, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}

void drawPolyLineFile(const char* fileName)
{
    fstream inStream;
    inStream.open(fileName, ios::in);
    if (inStream.fail())
        return;
    glClear(GL_COLOR_BUFFER_BIT);
    GLint numpolys, numLines, x, y;
    inStream >> numpolys;
    for (int j = 0; j < numpolys; j++)
    {
        inStream >> numLines;
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < numLines; i++)
        {
            inStream >> x >> y;
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

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(zoomFactor, zoomFactor, 1.0); // Apply the zoom factor

    drawPolyLineFile("dino.dat");

    glFlush();
}

void myKeyboard(unsigned char key, int x, int y)
{
    if (key == '+')
    {
        zoomFactor *= 1.1; // Zoom in by increasing the zoom factor
    }
    else if (key == '-')
    {
        zoomFactor /= 1.1; // Zoom out by decreasing the zoom factor
    }
    glutPostRedisplay(); // Redraw the scene with the updated zoom factor
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Dinosaur Zoom in-out");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(myKeyboard); // Register the keyboard function
    myInit();
    glutMainLoop();
    return 0;

}
