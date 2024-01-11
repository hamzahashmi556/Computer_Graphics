#include <iostream>
#include <fstream>
#include <string>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cmath>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const double PI = 3.14159265358979323846;//This line defines a constant PI with the value of p.

class Point2 {  // simple class representing a 2D point with x and y coordinates.
public: //members can be accessed from outside the class.
    float x, y;

    Point2(float x = 0.0, float y = 0.0) : x(x), y(y) {} //constructor 
};
// The purpose of this function is to draw
// a point on the screen at the coordinates specified by the Point2 object p.
void moveTo(const Point2& p) { //constant reference to a Point2 object named p
    glVertex2f(p.x, p.y);
}

void lineTo(const Point2& p) {
    glVertex2f(p.x, p.y);
}
//ngon is a function that draws an ngon (polygon with n sides) centered at (cx, cy) with a given radius. It also allows for rotation (rotAngle) of the ngon.
//It first checks if the number of sides n is less than 3 (a polygon must have at least 3 sides).
void ngon(int n, double cx, double cy, double radius, double rotAngle) {
    if (n < 3) {
        return;
    }

    glBegin(GL_LINE_LOOP);

    double angle = rotAngle * PI / 180;
    double angleInc = 2 * PI / n;

    Point2 startPoint(cx + radius * cos(angle), cy + radius * sin(angle));
    //The moveTo function is used to set the starting point,
	
    moveTo(startPoint);

    for (int i = 0; i < n; ++i) {
        angle += angleInc;
        Point2 vertex(cx + radius * cos(angle), cy + radius * sin(angle));
        //lineTo function is used to draw lines to the subsequent vertices.
        lineTo(vertex);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); // Set color to red

    int sides = 15;          // N Number of sides in the polygon
    double centerX = 0.0;   // X-coordinate of the center
    double centerY = 0.0;   // Y-coordinate of the center
    double radius = 0.5;    // Radius of the polygon
    double rotation = 30.0; // Rotation angle in degrees

    ngon(sides, centerX, centerY, radius, rotation);

    glFlush();
}

int main(int argc, char** argv) 
{
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ngon");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glutDisplayFunc(display);
    glutMainLoop();
}
