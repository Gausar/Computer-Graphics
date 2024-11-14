#include"GL/freeglut.h"

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void ChangeSize(int w, int h)
{
    GLfloat fAspect;

    // Prevent a divide by zero
    if(h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w/(GLfloat)h;

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Produce the perspective projection
    gluPerspective(35.0f, fAspect, 1.0, 40.0);
    //glOrtho(-5.0, 5.0, -5.0, 5.0, 5.0, -5.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// This function does any needed initialization on the rendering
// context.  Here it sets up and initializes the lighting for
// the scene.
void SetupRC()
    {
    // Light values and coordinates
    GLfloat  whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };
    GLfloat  sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
    GLfloat lightPos[] = { -10.f, 5.0f, 5.0f, 1.0f };

    glEnable(GL_DEPTH_TEST);// Hidden surface removal
    glFrontFace(GL_CCW);    // Counter clock-wise polygons face out
    glEnable(GL_CULL_FACE); // Do not calculate inside

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup and enable light 0
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);
    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Black blue background
    glClearColor(0.25f, 0.25f, 0.50f, 1.0f );
    }

// Respond to arrow keys
void SpecialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_UP)
        xRot-= 5.0f;

    if(key == GLUT_KEY_DOWN)
        xRot += 5.0f;

    if(key == GLUT_KEY_LEFT)
        yRot -= 5.0f;

    if(key == GLUT_KEY_RIGHT)
        yRot += 5.0f;

        xRot = (GLfloat)((const int)xRot % 360);
        yRot = (GLfloat)((const int)yRot % 360);

    glutPostRedisplay();
}

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLUquadricObj *pObj;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0, -0.2, -5.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);
    glRotatef(xRot, 1.0, 0.0, 0.0);
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    //hazaisan malgai
    glPushMatrix();
        glTranslatef(-0.3, 0.4, 0.2);
        glRotatef(-75, 1.0, 1.0, 1.0);
        glColor3f(1, 0.0, 0.0);
        gluCylinder(pObj ,0.3, 0.06, 0.93, 30, 30 );
    glPopMatrix();

    //hazaisan malgainii deed heseg
    glPushMatrix();
        glTranslatef(-0.6, 1.185, 0.68);
        //glRotatef(-75, 1.0, 1.0, 1.0);
        glColor3f(0, 0.0, 1.0);
        gluSphere(pObj , 0.1 , 15 ,15);
    glPopMatrix();

    // tegsh malgai
    glPushMatrix();
        glTranslatef(-0.2, 0.5, 0.2);
        glRotatef(-90, 1.0, 0.0, 0.0);
        glColor3f(1, 0.0, 0.0);
        gluCylinder(pObj ,0.3, 0.06, 0.93, 30, 30 );
    glPopMatrix();

    //tegsh malgainii deed heseg
    glPushMatrix();
        glTranslatef(-0.2, 1.5, 0.2);
        glColor3f(0, 0.0, 1.0);
        gluSphere(pObj , 0.1 , 15 ,15);
    glPopMatrix();

    //tsagaan sphere tolgoi
    glPushMatrix();
        glTranslatef(-0.2, 0.15, 0.2);
        glColor3f(0.7, 0.7, 0.3);
        gluSphere(pObj , 0.5 , 25 ,25);
    glPopMatrix();

    //ih bie
    glPushMatrix();
        glTranslatef(-0.2, -0.8, 0.2);
        glColor3f(1.0, 0.0, 0.0);
        gluSphere(pObj , 0.7 , 25 ,25);
    glPopMatrix();

    //hamar
    glPushMatrix();
        glTranslatef(-0.2, 0.1, 0.7);
        glColor3f(0.0, 0.0, 1.0);
        gluSphere(pObj , 0.07 , 15 ,15);
    glPopMatrix();

    //nud
    glPushMatrix();
        glTranslatef(-0.05, 0.3, 0.64);
        glColor3f(0.0, 0.0, 0.0);
        gluSphere(pObj , 0.05 , 15 ,15);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.35, 0.3, 0.64);
        glColor3f(0.0, 0.0, 0.0);
        gluSphere(pObj , 0.05 , 15 ,15);
    glPopMatrix();

    //chih
    glPushMatrix();
        glTranslatef(0.2, 0.3, 0.4);
        glColor3f(0.7, 0.7, 0.3);
        gluSphere(pObj , 0.1 , 15 ,15);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.6, 0.3, 0.4);
        glColor3f(0.7, 0.7, 0.3);
        gluSphere(pObj , 0.1 , 15 ,15);
    glPopMatrix();

    //hol
    glPushMatrix();
        glTranslatef(0.2, -1.2, 0.64);
        glColor3f(0.7, 0.7, 0.3);
        gluSphere(pObj , 0.2 , 25 ,25);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.55, -1.2, 0.64);
        glColor3f(0.7, 0.7, 0.3);
        gluSphere(pObj , 0.2 , 25 ,25);
    glPopMatrix();

    //gar
    glPushMatrix();
        glTranslatef(0.28, -0.4, 0.5);
        glColor3f(0.7, 0.7, 0.3);
        gluSphere(pObj , 0.2 , 25 ,25);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.65, -0.4, 0.5);
        glColor3f(0.7, 0.7, 0.3);
        gluSphere(pObj , 0.2 , 25 ,25);
    glPopMatrix();

    //ar tal ni
    glPushMatrix();
        glTranslatef(-0.2, -1.2, -0.4);
        glColor3f(0.7, 0.7, 0.3);
        gluSphere(pObj , 0.2 , 25 ,25);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 700);
    glutCreateWindow("Modeling with Quadrics");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
    SetupRC();
    glutMainLoop();

    return 0;
}
