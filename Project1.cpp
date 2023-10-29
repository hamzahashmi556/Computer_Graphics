#include<GL/freeglut.h>
#include <iostream>
#include <GL/glut.h>


// START OF LAB # 01
/* Lab # 01
void init(){
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	//Line C
	glutInitWindowSize(640,480);
	glutInitWindowPosition(1000,200);
	glutCreateWindow("Simple Window");
}

void display()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	// gluOrtho2D(0.0,100.0,0,100.0);
	glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);			//Line A
	init();					//Line B
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
*/
// End OF LAB # 01


// START OF LAB # 02 
// Home Scenery

void drawSky() {
	
	glBegin(GL_QUADS);
	glColor3d(0.1, 0.1, 0.5); // Blue Color for the Sky
	glVertex2f(2, 15); // top left
	glVertex2f(14, 15); // top right
	glVertex2f(14,4); // bottom right
	glVertex2f(2, 4); // bottom left
	glEnd();
	
}

void drawMountains() {
    glBegin(GL_TRIANGLES);
    glColor3d(0.545, 0.270, 0.074); // Brown color for mountains

    // First mountain
    glVertex2f(2, 6);
    glVertex2f(5, 4);
    glVertex2f(7, 6);

    // Second mountain
    glVertex2f(5, 6);
    glVertex2f(7, 4);
    glVertex2f(9, 6);

    // Third mountain
    glVertex2f(7, 6);
    glVertex2f(9, 4);
    glVertex2f(11, 6);

    // Fourth mountain
    glVertex2f(9, 6);
    glVertex2f(11, 4);
    glVertex2f(14, 6);

    glEnd();
}



void drawHouse() {
	
    // House Top Rectangle (roof)
    // chat ke code
    glColor3d(1.0, 1.0, 1.0); // White color for the house roof
    glBegin(GL_QUADS);
    glVertex2f(5, 8.5); // bottom left corner
    glVertex2f(11, 8.5); // bottom right corner
    glVertex2f(8, 6); // top right
    glVertex2f(8, 6); // top left
    glEnd();
    
    // House Chimney
    /*
    glColor3d(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2f(9, 8); // top left
    glVertex2f(9.3, 8); // top right
    glVertex2f(9.3, 7.2); // bottom right
    glVertex2f(9, 7.2); // bottom left
	*/
	
    // House Base
    // ground floor
    glColor3d(0.0, 0.0, 1.0); // Blue color for the square
    glBegin(GL_QUADS);
    glVertex2f(6, 8.5);   // Top left
    glVertex2f(10, 8.5);  // Top right
    glVertex2f(10, 12); // Bottom right
    glVertex2f(6, 12);  // Bottom left
    glEnd();

    // House Door
    glColor3d(0.0, 0.0, 0.0); // Black color for the house door
    glBegin(GL_QUADS);
    glVertex2f(7, 9.5); // top left
    glVertex2f(9, 9.5); // top right
    glVertex2f(9, 12); // bottom right
    glVertex2f(7, 12); // bottom left
    glEnd();
    
    // Double Door Line
    glColor3d(1.0, 1.0, 1.0); // White color for the mid door
    glBegin(GL_QUADS);
    glVertex2f(7.95, 9.5);
    glVertex2f(8.05, 9.5);
    glVertex2f(8.05, 12);
    glVertex2f(7.95, 12);
    glEnd();
}

void drawGreenery() {
	
    glColor3d(0.0, 0.5, 0.0); // Green color for greenery
    glBegin(GL_QUADS);
    glVertex2f(2, 12); // top left
    glVertex2f(14, 12); // top right
    glVertex2f(14, 15); // bottom right
    glVertex2f(2, 15); // bottom left
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawSky();
    
//    glMatrixMode(GL_MODELVIEW);
    // Draw mountains
    drawMountains();
    
    // Draw the house
    drawHouse();

    // Draw greenery
    drawGreenery();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Scenery with GLUT");
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	gluOrtho2D(2,14,15,4);//range
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

// HOME SCENERY
// END OF LAB # 02
