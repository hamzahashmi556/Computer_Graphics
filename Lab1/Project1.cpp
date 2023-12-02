#include <GL/freeglut.h>
#include <iostream>
#include <GL/glut.h>

// START OF LAB # 01
//* Lab # 01

// Function to initialize OpenGL settings and create a window
void setupWindow() {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode to single buffer and RGB color
    glutInitWindowSize(640, 480); // Set the initial window size to 640x480 pixels
    glutInitWindowPosition(800, 200); // Set the initial window position on the screen
    glutCreateWindow("Simple Window"); // Create a window with the specified title
}

// Function to handle the display
void display() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set the clear color to white (RGB: 1.0, 1.0, 1.0)
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    // gluOrtho2D(0.0, 100.0, 0, 100.0); // This line is commented out; it's used to set the coordinate system
    glFlush(); // Flush the rendering pipeline to display the changes
}

// Main function
int main(int argc, char **argv) {
    glutInit(&argc, argv); // Initialize the GLUT library
    setupWindow(); // Call the setup Window function to configure the window options
    glutDisplayFunc(display); // Register the display function to be called when the window needs to be redrawn
    glutMainLoop(); // Enter the GLUT event processing loop

    return 0; // Return 0 to indicate successful execution
}

// End OF LAB # 01

