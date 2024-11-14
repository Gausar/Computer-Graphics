#include"GL/freeglut.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTICES 1400000
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

typedef struct {
    float x, y, z;
} Vertex;

Vertex vertices[MAX_VERTICES];
int vertexCount = 0;

void loadOBJ(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file %s\n", filename);
        exit(1);
    }
    char line[128];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "v ", 2) == 0) {
            Vertex vertex;
            sscanf(line, "v %f %f %f", &vertex.x, &vertex.y, &vertex.z);

            if (vertexCount < MAX_VERTICES) {
                vertices[vertexCount++] = vertex;
            } else {
                printf("Maximum vertex limit reached!\n");
                break;
            }
        }
    }
    fclose(file);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0, -0.2, -5.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);
    glRotatef(xRot, 1.0, 0.0, 0.0);

    glPointSize(3.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < vertexCount; i++) {
        glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
    }
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}
void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    //glOrtho(-30, 30, -30, 30, 4.0, 40.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
void ChangeSize(int w, int h) {
    GLfloat fAspect;
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    fAspect = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) {
        glOrtho(-10.0, 10.0, -10.0 * (GLfloat)h / (GLfloat)w,
                10.0 * (GLfloat)h / (GLfloat)w, 1.0, 100.0);
    } else {
        glOrtho(-10.0 * (GLfloat)w / (GLfloat)h,
                10.0 * (GLfloat)w / (GLfloat)h, -10.0, 10.0, 1.0, 100.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void SpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_UP) xRot -= 5.0f;
    if (key == GLUT_KEY_DOWN) xRot += 5.0f;
    if (key == GLUT_KEY_LEFT) yRot -= 5.0f;
    if (key == GLUT_KEY_RIGHT) yRot += 5.0f;

    xRot = (GLfloat)((const int)xRot % 360);
    yRot = (GLfloat)((const int)yRot % 360);
    glutPostRedisplay();
}
void SetupRC() {
    GLfloat whiteLight[] = {0.05f, 0.05f, 0.05f, 1.0f};
    GLfloat sourceLight[] = {0.25f, 0.25f, 0.25f, 1.0f};
    GLfloat lightPos[] = {-10.f, 5.0f, 5.0f, 1.0f};

    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
    glLightfv(GL_LIGHT0, GL_AMBIENT, sourceLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sourceLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glClearColor(0.25f, 0.25f, 0.50f, 1.0f);
}
int main(int argc, char *argv[]) {
    loadOBJ("C:\\Users\\Gausar\\OneDrive\\Documents\\CGLabs\\first\\lab10\\dragon.obj");
    //bunny.obj object file tuulai
    //dragon.obj file luu
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Object");
    initGL();
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(display);
    SetupRC();
    glutMainLoop();
    return 0;
}

