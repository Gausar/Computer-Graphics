/*
#include <GL/glut.h>
#include <math.h>

float water = 0.0f;
float hair = 45.0f;
float boat = 0.0f;

void drawBoat()
{
	glPushMatrix();
    //zavi
	glBegin(GL_POLYGON);
	glColor3f(0.65, 0.5, 0.16);
	glVertex2i(400, 250);
	glVertex2i(650, 300);
	glVertex2i(650, 250);
	glVertex2i(580, 120);
	glVertex2i(500, 100);
	glVertex2i(300, 100);
	glVertex2i(220, 120);
	glVertex2i(150, 250);
	glVertex2i(150, 300);
	glEnd();

	// hol
	glBegin(GL_POLYGON);
	glColor3f(0.82, 0.71, 0.55);
	glVertex2i(430, 250);
	glVertex2i(440, 250);
	glVertex2i(430, 320);
	glVertex2i(440, 320);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.82, 0.71, 0.55);
	glVertex2i(400, 250);
	glVertex2i(410, 250);
	glVertex2i(400, 320);
	glVertex2i(410, 320);
	glEnd();

	// ohinii ih bie
	glBegin(GL_QUADS);
	glColor3f(0.82, 0.0, 0.0);
	glVertex2i(380, 320);
	glVertex2i(460, 320);
	glVertex2i(400, 450);
	glVertex2i(440, 450);
	glEnd();

	// Tolgoi
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.82, 0.71, 0.55);
	float radius = 30.0f;
	float centerX = 420.0f;
	float centerY = 450.0f + radius;

	for (int i = 0; i < 36; i++) {
		float angle = 2.0 * 3.1415926f * float(i) / 36.0;
		float x = cosf(angle) * radius + centerX;
		float y = sinf(angle) * radius + centerY;
		glVertex2f(x, y);
	}
	glEnd();

	// 2 nud
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	float rad = 3.0f;
	float cenX = 430.0f;
	float cenY = 480.0f + rad;

	for (int i = 0; i < 36; i++) {
		float a = 2.0 * 3.1415926f * float(i) / 36.0;
		float x = cosf(a) * rad + cenX;
		float y = sinf(a) * rad + cenY;
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	float cX = 410.0f;
	float cY = 480.0f + rad;

	for (int i = 0; i < 36; i++) {
		float a = 2.0 * 3.1415926f * float(i) / 36.0;
		float x = cosf(a) * rad + cX;
		float y = sinf(a) * rad + cY;
		glVertex2f(x, y);
	}
	glEnd();

	//ohinii us
	int numHairs = 16;
	float hairLength = 60.0f;

	for (int i = 0; i < numHairs; i++) {

		float angle = 3.1415926f * float(i) / (numHairs - 1);

		float startX = cosf(angle) * radius + centerX;
		float startY = sinf(angle) * radius + centerY;

		float endX = cosf(angle) * (radius + hairLength) + centerX + hair;
		float endY = sinf(angle) * (radius + hairLength) + centerY;


		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(startX, startY);
		glVertex2f(startX - 5.0f, startY);
		glVertex2f(endX - 5.0f, endY);
		glVertex2f(endX, endY);
		glEnd();
	}

	// 2 gar
	glBegin(GL_POLYGON);
	glColor3f(0.82, 0.71, 0.55);
	glVertex2i(410, 440);
	glVertex2i(410, 430);
	glVertex2i(330, 430);
	glVertex2i(330, 420);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.82, 0.71, 0.55);
	glVertex2i(420, 420);
	glVertex2i(420, 410);
	glVertex2i(330, 420);
	glVertex2i(330, 410);
	glEnd();


	glPopMatrix();
}
//P[i] = (1 - t)A[i] + B[i];

float startUmbrellaX = 330.0f;
float startUmbrellaY = 600.0f;

float endUmbrellaX = 395.0f;
float endUmbrellaY = 550.0f;

float t = 0.0f;
float tweenSpeed = 0.01f;

bool tweening = true;

void drawUmbrella() {

    float currentUmbrellaX = (1 - t) * startUmbrellaX + t * endUmbrellaX;
    float currentUmbrellaY = (1 - t) * startUmbrellaY + t * endUmbrellaY;

    glPushMatrix();
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(currentUmbrellaX, currentUmbrellaY);
    glVertex2f(startUmbrellaX, 420);
    glEnd();

    glPushMatrix();
    glTranslatef(currentUmbrellaX, currentUmbrellaY, 0);
    glColor3f(0.5, 0.5, 0.5);

    float Radius = 80.0f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0);
    for (int i = 0; i <= 180; i++) {
        float angle = 3.1415926f * float(i) / 180.0f;
        float x = cosf(angle) * Radius ;
        float y = sinf(angle) * Radius ;
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}
void timer(int value) {
    if (tweening) {
        t += tweenSpeed;
        if (t >= 1.0f) {
            t = 1.0f;
            tweening = false;
        }
    } else {
        t -= tweenSpeed;
        if (t <= 0.0f) {
            t = 0.0f;
            tweening = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(33, timer, 0);
}
void drawWater() {
	glColor3f(0.0, 0.4, 1.0);

	glBegin(GL_POLYGON);

	float waveHeight = 15.0f;
	float waveFrequency = 0.05f;
	float xStart = 0.0f;
	float xEnd = 1200.0f;
	float waterLevel = 100.0f;

	for (float x = xStart; x <= xEnd; x += 5.0f) {
		float y = waterLevel + sinf((x + water) * waveFrequency) * waveHeight;
		glVertex2f(x, y);
	}

	glVertex2f(xEnd, 0.0f);
	glVertex2f(xStart, 0.0f);

	glEnd();
}
void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
    drawUmbrella();
	drawBoat();
	drawWater();
	glutSwapBuffers();
}

void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1200.0, 0.0, 800.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("Girl on the boat");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutTimerFunc(0, timer, 0);

	glutMainLoop();
	return 0;
}
*/
