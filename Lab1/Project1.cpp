#include <GL/freeglut.h>
#include <iostream>
#include <GL/glut.h>

// START OF LAB # 01
//* Lab # 01

// Function to initialize OpenGL settings and create a window
void setupWindow() {
	// Set the display mode to single buffer and RGB color
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    // Set the initial window size to 640x480 pixels
    glutInitWindowSize(640, 480); 
    // Set the initial window position on the screen
    glutInitWindowPosition(800, 200); 
    // Create a window with the specified title
    glutCreateWindow("Simple Window"); 
}

// Function to handle the display
void display() {
	// Set the clear color to white (RGB: 1.0, 1.0, 1.0)
    glClearColor(1.0, 1.0, 1.0, 0.0); 
    // Clear the color buffer (background)
    glClear(GL_COLOR_BUFFER_BIT); 
    // gluOrtho2D(0.0, 100.0, 0, 100.0); // This line is commented out; it's used to set the coordinate system
    // Flush the rendering pipeline to display the changes
    glFlush(); 
}

// Main function
int main(int argc, char **argv) {
	// Initialize the GLUT library
    glutInit(&argc, argv);
	// Call the setup Window function to configure the window options 
    setupWindow();
    // Register the display function to be called when the window needs to be redrawn
    glutDisplayFunc(display); 
    // Enter the GLUT event processing loop
    glutMainLoop();

    return 0; // Return 0 to indicate successful execution
}

// End OF LAB # 01

