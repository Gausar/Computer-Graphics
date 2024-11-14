#include <GL/glut.h>
#include <cmath>

// Constants
const int NUM_POINTS = 240;
float u[NUM_POINTS];
float v[NUM_POINTS];
const float damping = 0.99f;
void initWater() {
    for (int i = 0; i < NUM_POINTS; i++) {
        u[i] = sinf(i * 0.1f);
        v[i] = 0.0f;
    }
}

void updateWater(int value) {
    for (int i = 1; i < NUM_POINTS - 1; i++) {
        v[i] += (u[i-1] + u[i+1] - 2 * u[i]) * 0.99f;
        v[i] *= damping;
    }

    for (int i = 0; i < NUM_POINTS; i++) {
        u[i] += v[i];
    }
    glutPostRedisplay();
	glutTimerFunc(33, updateWater, 0);
}

void drawWater() {
    glColor3f(0.0, 0.4, 1.0);

	glBegin(GL_POLYGON);
	float xStart = 0.0f;
	float xEnd = 1200.0f;
	float waterLevel = 100.0f;

	for (float x = xStart; x <= xEnd; x += 5.0f) {
		float y = waterLevel + sinf((x));
		glVertex2f(x, y);
	}

	glVertex2f(xEnd, 0.0f);
	glVertex2f(xStart, 0.0f);

	glEnd();
}

// Render function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawWater();

    glutSwapBuffers();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 600);
    glutCreateWindow("Water Simulation");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1200.0, 0.0, 600.0);

    initWater();

    glutDisplayFunc(display);
    //glutIdleFunc(display);
    glutTimerFunc(0, updateWater, 0);

    glutMainLoop();

    return 0;
}
