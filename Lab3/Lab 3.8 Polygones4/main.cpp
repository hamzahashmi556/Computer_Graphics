
#include <iostream>
#include <fstream>
#include <string>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cmath>

//lab 9 rossete 


const double PI = 3.14159265358979323846;

class Point2 {
public:
    float x, y;

    Point2(float x = 0.0, float y = 0.0) : x(x), y(y) {}
};

void moveTo(const Point2& p) {
    glVertex2f(p.x, p.y);
}

void lineTo(const Point2& p) {
    glVertex2f(p.x, p.y);
}

void Rosette(int N, float radius) {
    // Assuming N is the number of vertices in the rosette
    Point2 pt[N];

    // Generate the vertices of the rosette
    for (int i = 0; i < N; i++) {
        double angle = 2.0 * PI * i / N;//This line calculates the angle for the current vertex.
        double x = radius * cos(angle);//This calculates the x-coordinate of the current vertex
        double y = radius * sin(angle);//This calculates the y-coordinate of the current vertex
        pt[i] = Point2(x, y);
    }

    glBegin(GL_LINES);

    // Draw lines to connect all vertices
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            moveTo(pt[i]);
            lineTo(pt[j]);
        }
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0); // Set color to purple 

    int vertices = 5;      // Number of vertices in the rosette
    double rosetteRadius = 0.5;

    // Call the Rosette function
    Rosette(vertices, rosetteRadius);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rosette Example");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
