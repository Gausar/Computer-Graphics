#include<windows.h>
#include<GL/freeglut.h>
//glutPostRedisplay


void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);

    glPointSize(5.0);
    glBegin(GL_POINTS);
        glVertex2f(0.5, 0.0);
        glVertex2f(0.0,0.5);
        glVertex2f(-0.5, 0.0);
    glEnd();

    glFlush();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Circle");

    glutDisplayFunc(display);
    glutReshapeFunc(resize);

    glClearColor(1, 1, 1, 1);
    glutMainLoop();

    return EXIT_SUCCESS;
}

