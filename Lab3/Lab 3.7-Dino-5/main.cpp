#include <iostream>
#include <fstream>
#include <GL/freeglut.h>

using std::cout;
using std::fstream;
using std::ios;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//DINO 5
//Make a Viewport Dynamic.( Output is attached) i.e Roaming a.k.a Panning (To move the view in a specific direction ).

const int screenWidth = 640;
const int screenHeight = 480;
int ViewportXmin = 0;
int ViewportXmax = screenWidth;
int ViewportYmin = 0;
int ViewportYmax = screenHeight;
int ReferenceX = 0;
int ReferenceY = 0;

//---------------- setViewport ------------------
void setViewport()
{
    glViewport(ViewportXmin, ViewportYmin, ViewportXmax - ViewportXmin, ViewportYmax - ViewportYmin);
}

void myMouse(int button, int state, int x, int y)
{
    // Remember the location of the mouse when the button was pressed
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        ReferenceX = x;
        ReferenceY = y;
    }
}

void myMotion(int x, int y)
{
    // Translate the Viewport according to the distance from the reference
    int dx = x - ReferenceX;
    int dy = y - ReferenceY; // because the y axis is down

    ViewportXmin += dx;
    ViewportXmax += dx;
    ViewportYmin -= dy;
    ViewportYmax -= dy;
    setViewport();

    ReferenceX = x;
    ReferenceY = y;

    glutPostRedisplay();
}

void mykeys(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'u':
            // Adjust the viewport by increasing the Y values
            ViewportYmin += 2;
            ViewportYmax += 2;
            setViewport();
            glutPostRedisplay();
            break;
    }
}

void myInit(void)
{
    glClearColor(0.9, 0.9, 0.9, 0.0); // the color is a very light gray
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}

void drawPolyLineFile(const char *fileName)
{
    std::fstream inStream;
    inStream.open(fileName, std::ios::in);
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
    drawPolyLineFile("dino.dat");
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Dinosaur Banao");
    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);
    glutKeyboardFunc(mykeys);
    myInit();
    glutMainLoop();
    return 0;
}
