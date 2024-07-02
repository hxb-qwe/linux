#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();  // Reset the modelview matrix

    // Set up the camera position and orientation
    gluLookAt(2.0, 2.0, 2.0,  // eye position
              0.0, 0.0, 0.0,  // look-at position
              0.0, 1.0, 0.0); // up direction

    glBegin(GL_QUADS);
    // Front face
    glColor3f(1.0, 0.0, 0.0);  // Red
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    // Back face
    glColor3f(0.0, 1.0, 0.0);  // Green
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    // Top face
    glColor3f(0.0, 0.0, 1.0);  // Blue
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    // Bottom face
    glColor3f(1.0, 1.0, 0.0);  // Yellow
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    // Right face
    glColor3f(1.0, 0.0, 1.0);  // Magenta
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    // Left face
    glColor3f(0.0, 1.0, 1.0);  // Cyan
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simple Cube Example");
    glEnable(GL_DEPTH_TEST);

    // Set up the perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 800.0/600.0, 0.1, 100.0); // (fovy, aspect, zNear, zFar)

    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
