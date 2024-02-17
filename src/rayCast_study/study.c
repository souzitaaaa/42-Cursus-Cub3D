#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>
#include <GLUT/glut.h>

#define WIDTH 1024
#define HEIGHT 512

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}

void init()
{
    glClearColor(0.3, 0.3, 0.3, 0);
    glOrtho(0, 1024, 512, 0, -1, 1);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Test");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
