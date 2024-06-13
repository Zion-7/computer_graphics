#include <GL/glut.h>
float rotx = 0.0;
void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 0.01, 1000);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 50, 0, 0, 0, 0, 1, 0);
    //glOrtho(-20, 20, -20, 20, -20, 20

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat position[] = { 0.0,0.0 ,50.0, 1.0 };
    GLfloat ambientLight[] = { 0.1,0.1,0.1,1.0 };
    GLfloat diffuseLight[] = { 0.8,0.,0.,1.0 };
    GLfloat specularLight[] = { 1.0,0.0,0.0,1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);


}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   // glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(rotx, 0, 1, 0);
    glBegin(GL_QUADS);
    //FRONT SURFACE
    glNormal3f(0, 0, 1);
    glVertex3f(-5, -5, 5);
    glNormal3f(0, 0, 1);
    glVertex3f(-5, 5, 5);
    glNormal3f(0, 0, 1);
    glVertex3f(5, 5, 5);
    glNormal3f(0, 0, 1);
    glVertex3f(5, -5, 5);

    //back surface
    glNormal3f(0, 0, -1);
    glVertex3f(-5, -5, -5);
    glNormal3f(0, 0, -1);
    glVertex3f(-5, 5, -5);
    glNormal3f(0, 0, -1);
    glVertex3f(5, 5, -5);
    glNormal3f(0, 0, -1);
    glVertex3f(5, -5, -5);

    //left surface
    glNormal3f(-1, 0, 0);
    glVertex3f(-5, -5, 5);
    glNormal3f(-1, 0, 0);
    glVertex3f(-5, -5, -5);
    glNormal3f(-1, 0, 0);
    glVertex3f(-5, 5, -5);
    glNormal3f(-1, 0, 0);
    glVertex3f(-5, 5, 5);

    //right surface
    glNormal3f(1, 0, 0);
    glVertex3f(5, -5, 5);
    glNormal3f(1, 0, 0);
    glVertex3f(5, -5, -5);
    glNormal3f(1, 0, 0);
    glVertex3f(5, 5, -5);
    glNormal3f(1, 0, 0);
    glVertex3f(5, 5, 5);

    //top surface
    glNormal3f(0, 1, 0);
    glVertex3f(-5, 5, 5);
    glNormal3f(0, 1, 0);
    glVertex3f(-5, 5, -5);
    glNormal3f(0, 1, 0);
    glVertex3f(5, 5, -5);
    glNormal3f(0, 1, 0);
    glVertex3f(5, 5, 5);

    //bottom surface
    glNormal3f(0, -1, 0);
    glVertex3f(-5, -5, 5);
    glNormal3f(0, -1, 0);
    glVertex3f(-5, -5, -5);
    glNormal3f(0, -1, 0);
    glVertex3f(5, -5, -5);
    glNormal3f(0, -1, 0);
    glVertex3f(5, -5, 5);

    glEnd();
    glPopMatrix();
    glFlush();

}

void idle()
{
    rotx += 0.01;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(600, 600);
    glutCreateWindow("light");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
}