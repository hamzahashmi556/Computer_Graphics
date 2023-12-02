#include <iostream>
#include <fstream>
#include <string>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cmath>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// For Circle Curves 

const double PI = 3.14159265358979323846;
const int numSegments = 100; // You can adjust this for the circle's smoothness
float radius = 0.8; // Radius of the circle
float centerX = 0.0; // X-coordinate of the circle's center
float centerY = 0.0; // Y-coordinate of the circle's center

void drawCircle() {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; i++) {
        double angle = 2.0 * PI * i / numSegments;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 1.0); // Set color to pink

    // Call the function to draw the circle
    drawCircle();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Circle Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
