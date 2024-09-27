
#include<windows.h>
#include<GL/freeglut.h>

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
    glBegin(GL_TRIANGLES);
        glVertex2f(0.5, 0.0);
        glVertex2f(0.0,0.5);
        glVertex2f(-0.5, 0.0);
    glEnd();

    glFlush();
}

void colorize(void){
    switch(){
        case 'r': case 'R':
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(1.0, 0.0, 0.0);
        case 'g': case 'G':
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(0.0, 1.0, 0.0);
        case 'b': case 'B':
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(0.0, 0.0, 1.0);
    }
}

void special(void){

}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("n vertex shape");

    glutSpecialFunc(special);

    glutKeyboardFunc(keyboard);

    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    //glutKeyboardFunc(keyboard);

    glClearColor(1, 1, 1, 1);
    glutMainLoop();

    return EXIT_SUCCESS;
}
