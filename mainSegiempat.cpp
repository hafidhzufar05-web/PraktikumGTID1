#include <windows.h>
#include <GL/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(-0.50f,-0.50f,0.0f);

        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(0.50f,-0.50f,0.0f);

        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f(0.50f,0.50f,0.0f);

        glColor3f(1.0f,1.0f,0.0f);
        glVertex3f(-0.50f,0.50f,0.0f);

    glEnd();

    glFlush();
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Segiempat");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}

