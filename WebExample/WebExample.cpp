#include <iostream>
#include <SDL.h>
#include <GL/glut.h>

void F() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    glVertex2f(-0.9f, -0.9f);
    glColor3f(1, 0, 0);
    glVertex2f(0, 0.9f);
    glColor3f(0, 1, 0);
    glVertex2f(0.9f, -0.9f);
    glColor3f(0, 0, 1);

    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);

    glutCreateWindow("GLUT Test");

    glutDisplayFunc(F);

    glutMainLoop();
}

