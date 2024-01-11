#include <iostream>
#include <fstream>
#include <string>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cmath>

//LAB 7 Arc

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

void drawArc(Point2 center, float radius, float startAngle, float sweep) {
    // StartAngle and sweep are in degrees
    glBegin(GL_LINE_STRIP);
    const int n = 30; // Number of intermediate segments in the arc
    float angle = startAngle * PI / 180; // Initial angle in radians
    float angleInc = sweep * PI / (180 * n); // Angle increment
    float cx = center.x, cy = center.y;
    
    Point2 startPoint(cx + radius * cos(angle), cy + radius * sin(angle));
    //The moveTo function is used to set the starting point,
    moveTo(startPoint);

    //moveTo(Point2(cx + radius * cos(angle), cy + radius * sin(angle)));

    for (int k = 1; k < n; k++, angle += angleInc) {
        Point2 vertex(cx + radius * cos(angle), cy + radius * sin(angle));
        //lineTo function is used to draw lines to the subsequent vertices.
        lineTo(vertex);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); // Set color to black

    // Define the parameters for the arc
    int sides = 30; // Number of sides in the arc
    double centerX = 0.0; //  X-coordinate of the center c
    double centerY = 0.0; // Y-coordinate of the center c
    double radius = 0.5; // R Radius of the arc
    double startAngle = 30.0; // a Starting angle in degrees
    double sweepAngle = 120.0; // b Sweep angle in degrees

    // Call the drawArc function
    drawArc(Point2(centerX, centerY), radius, startAngle, sweepAngle);

    glFlush();
}

int main(int argc, char** argv) {
    // Initialize OpenGL and create a window
    // Set up callbacks and other necessary setup

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Arc Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glutDisplayFunc(display);
    glutMainLoop();

}
