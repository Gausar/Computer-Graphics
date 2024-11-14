#include <GL/glut.h>
#include <stdio.h>

void printMatrix() {
    GLdouble matrix[16];
    glGetDoublev(GL_MODELVIEW_MATRIX, matrix);
    printf("Transformation Matrix:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%f ", matrix[j * 4 + i]);
        }
        printf("\n");
    }
    printf("\n");
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(1.0f, 0.0f, 0.0f);
    printf("glTranslatef(1, 0, 0):\n");
    printMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    printf("glRotatef(90, 1, 0, 0):\n");
    printMatrix();
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    printf("glRotatef(90, 0, 1, 0):\n");
    printMatrix();

    glBegin(GL_POINTS);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glEnd();

    glFlush();
}

void init() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Transformation Matrix");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
