#include<windows.h>
#include<GL/freeglut.h>
#include<math.h>

float angle = 0.0f;
float r = 0.0, g = 0.0, b = 0.0;
int n = 6;
int rows = 4, cols = 5;

void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-0.5, 0.5, -0.5, 0.5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawHexagon(float scale, float angleOffset)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 6; i++) {
        float a = 2.0 * 3.1415926f * float(i) / 6.0;

        float x = cosf(a) * scale;
        float y = sinf(a) * scale;

        float rotatedX = x * cos(angleOffset) - y * sin(angleOffset);
        float rotatedY = x * sin(angleOffset) + y * cos(angleOffset);
        glVertex2f(rotatedX, rotatedY);
    }
    glEnd();
}

void renderHexagons()
{
    glColor3f(r, g, b);
    for (int i = 0; i < 30; i++) {
        float scale = 1.0f - (float)i / 30.0;
        float angleOffset = angle + i * 4;
        drawHexagon(scale, angleOffset);
    }
}


void hexagon(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    int viewportWidth = windowWidth / cols;
    int viewportHeight = windowHeight / rows;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            glViewport(j * viewportWidth, i * viewportHeight, viewportWidth, viewportHeight);

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            if(i%2==1&&j%2==1){
                gluOrtho2D(-0.5, 0.5, -0.5, 0.5);
            }
            else if(i%2==1&&j%2==0){
                gluOrtho2D(0.5, -0.5, -0.5, 0.5);
            }
            else if(i%2==0&&j%2==1){ //mur n tegsh, bagana ni sondgoi
                gluOrtho2D(-0.5, 0.5, 0.5, -0.5);
            }
            else{ //hoyulaa tegsh
                gluOrtho2D(-0.5, 0.5, -0.5, 0.5);
            }
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            renderHexagons();
        }
    }
    glFlush();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600, 480);

    glutCreateWindow("Hexagons in Pattern");

    glutReshapeFunc(resize);
    glutDisplayFunc(hexagon);

    glClearColor(1, 1, 1, 1);

    glutMainLoop();
    return EXIT_SUCCESS;
}
