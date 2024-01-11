#include <iostream>
#include <fstream>
#include <string>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cmath>

//Rose Petal

const double PI = 3.14159265358979323846;
const int numPoints = 50; // You can adjust the number of points for smoother or rougher curves
const int n = 2; // Change 'n' to control the number of petals

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Set color to black

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= numPoints; i++) {
        double theta = 2.0 * PI * i / numPoints;
        double x = cos(n * theta) * cos(theta);
        double y = cos(n * theta) * sin(theta);
        glVertex2d(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rose Curve");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

