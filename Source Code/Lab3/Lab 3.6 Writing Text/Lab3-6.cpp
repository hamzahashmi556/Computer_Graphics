#include <iostream>
#include <fstream>
#include <string>
#include <GL/freeglut.h>
using namespace std;

 void bitmap_output(int x,int y,string s,void*font)
 {
 	int len,i;
 	glRasterPos2i(x,y); //Specifies the raster position for pixel operations OR specifies the location at which the text will be drawn on the screen.
 	len = s.length();
 	for (i = 0;i<len;i++)
 	{
 		glutBitmapCharacter(font,s[i]);//Inside the loop, this function is called to draw each character from the input string s at the current raster position using the specified font.
	}
 }
 void mydisplay()
{
	glColor3f(1,0,0);//resulting in a pure red color.
	bitmap_output(40,230,"This is written in a GLUT bitmap font.",GLUT_BITMAP_TIMES_ROMAN_24);
	
	glColor3f(1,0,0);//resulting in a pure red color.
	bitmap_output(30,210,"More bitmap test is a fixed 9 by 15 font.",GLUT_BITMAP_9_BY_15);
	
	glColor3f(0,1,0);//, resulting in a solid green color.
	bitmap_output(70,35,"Helvetica is yet another bitmap font.",GLUT_BITMAP_HELVETICA_18);		
	glFlush();
	
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Writing text to the screen ");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,640,0,480);
    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;
}

