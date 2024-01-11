#include <iostream>
#include <fstream>
#include <string>
#include <GL/freeglut.h>
//using namespace std;

void myinit(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set the clear color to black
    glColor3f(0.0, 0.0, 1.0); // Set the drawing color to blue
    gluOrtho2D(0, 640, 0, 480);
}

void display(void)
{   
    glFlush();
}

void myMovedMouse(int mouseX, int mouseY)
{
	
  int x = mouseX; //grab the mouse position
  int y = 480 - mouseY; // flip it as usual
  int brushSize = 10;
  glRecti(x,y, x + brushSize, y + brushSize);
  glFlush();
  
  
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Paint Brush: Hamza Alam Hashmi EB21102031");
    glutMotionFunc(myMovedMouse);
    glutDisplayFunc(display);
    
    myinit();
    glutMainLoop();
    return 0;
}
