#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
int flag = 0;

GLuint texture;
void init() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-20, 20, -20, 20, -20, 20);
}
// Function to load BMP file 
GLuint LoadTexture(const char* filename)
{
    int width, height;
    unsigned char* data;

#pragma warning(disable : 4996).
    FILE* file;
    file = fopen(filename, "rb");

    if (file == NULL) return 0;
    width = 512;
    height = 512;
    data = (unsigned char*)malloc(width * height * 3);
    //int size = fseek(file,);
    fread(data, width * height * 3, 1, file);
    fclose(file);

    for (int i = 0; i < width * height; ++i)
    {
        int index = i * 3;
        unsigned char B, R;
        B = data[index];
        R = data[index + 2];

        data[index] = R;
        data[index + 2] = B;
    }

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
    free(data);

    return texture;
}
void display() {
    //DDA Algorithm
    glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(1, 0, 0);
    glEnable(GL_TEXTURE_2D);
    if (flag == 0)
        texture = LoadTexture("img.bmp");

    if (flag == 1)

        texture = LoadTexture("door.bmp");

    if (flag == 2)
        texture = LoadTexture("grass.bmp");
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);

    glVertex2i(-4, -4);
    glTexCoord2f(0, 1);
    glVertex2i(-4, 4);
    glTexCoord2f(1, 1);
    glVertex2i(4, 4);
    glTexCoord2f(1, 0);
    glVertex2i(4, -4);
    glEnd();
    glFlush();
}
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'S':flag = 1;
        break;
    case 'W':flag = 0;
        break;
    case 'A':flag = 2;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(600, 600);
    glutCreateWindow("texture");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}