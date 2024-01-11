#include <iostream>
#include <fstream>
#include <GL/freeglut.h>

using std::cout;
using std::fstream;
using std::ios;

//Tiling the display with copies of the dinosaur.
//Multiple Dino

const int screenWidth = 640; // width of screen window in pixels
const int screenHeight = 480; // height of screen window in pixels

//--------------- setWindow ---------------------
void setWindow(float left, float right, float bottom, float top)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left, right, bottom, top);
}
//---------------- setViewport ------------------
void setViewport(float left, float right, float bottom, float top)
{
    glViewport(left, bottom, right - left, top - bottom);
}

void myInit(void)
{
    glClearColor(0.9, 0.9, 0.9, 0.0); // background color is light gray
    glMatrixMode(GL_PROJECTION); // set "camera shape"
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}
void drawPolyLineFile(const char* fileName)
{
    std::ifstream inStream;
    inStream.open(fileName, std::ios::in);// open the file
    if (inStream.fail())
        return;
    GLint numpolys, numLines, x, y;
    inStream >> numpolys; //read the number of polylines 
    for (int j = 0; j < numpolys; j++) // read each polyline
    {
        inStream >> numLines;
        glBegin(GL_LINE_STRIP); // draw the next polyline
        for (int i = 0; i < numLines; i++)
        {
            inStream >> x >> y; // read the next x,y pair
            glVertex2i(x, y);
        }
        glEnd();
    }
    inStream.close();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    
    setWindow(0, 640.0, 0, 480.0);
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 2; j++) {
             //glViewport(i * 64, j * 44, 64, 44);
            if ((i + j) % 2 == 0) {

                setWindow(0, 640.0, 0, 480.0);
            }
            else {
                setWindow(0, 640.0, 480.0, 0);
            }
            glViewport(j * 64, i * 44, 64, 44);
            drawPolyLineFile("dino.dat");//purpose is to draw a set of polylines based on the data stored in the "dino.dat" file.
        }
    }
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Dinosaur Grid");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}
