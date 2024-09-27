#include<windows.h>
#include<GL/freeglut.h>
#include<math.h>

void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

float r = 0.0, g = 1.0, b = 0.0;
int n = 3;

void colorize(unsigned char key, int x, int y){
    switch(key){
        case 'r': case 'R':
            r = 1.0; g = 0.0; b = 0.0;
            break;
        case 'g': case 'G':
            r = 0.0; g = 1.0; b = 0.0;
            break;
        case 'b': case 'B':
            r = 0.0; g = 0.0; b = 1.0;
            break;
        default:
            return;
    }
    glutPostRedisplay();
}

void add_vertex(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            n++;
            if (n > 72) n = 72;
            break;
        case GLUT_KEY_DOWN:
            n--;
            if (n < 3) n = 3;
            break;
        default:
            return;
    }
    glutPostRedisplay();
}

void circle(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(r, g, b);

    glPointSize(5.0);
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i < n; i++){
        float a = 2.0 * 3.14 * float(i) / float(n);
        float x = cosf(a);
        float y = sinf(a);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("n shape");

    glutReshapeFunc(resize);
    glutDisplayFunc(circle);


    glutKeyboardFunc(colorize);
    glutSpecialFunc(add_vertex);

    glClearColor(1, 1, 1, 1);
    glutMainLoop();

    return EXIT_SUCCESS;
}
