#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Objek 1: Garis menggunakan Stack pertama
    glPushMatrix();
        glLineWidth(2.0f);
        glBegin(GL_LINES);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex3f(0.00, 0.20, 0.0);
            glVertex3f(0.00, -0.20, 0.0);
        glEnd();
    glPopMatrix();

    // Objek 2: Titik (Point) menggunakan Stack kedua
    glPushMatrix();
        glPointSize(5.0f);
        glTranslatef(0.35, 0.35, 0.0); 
        glBegin(GL_POINTS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex3f(0.25, 0.25, 0.0);
        glEnd();
    glPopMatrix();

    // Objek 3: Segitiga (Triangle Strip) menggunakan Stack ketiga
    glPushMatrix();
        glTranslatef(0.50, 0.50, 0.00);
        glBegin(GL_TRIANGLE_STRIP); 
            glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.05, -0.05, 0.00);
            glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.15, -0.05, 0.00);
            glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(-0.05, 0.05, 0.00);
            glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(0.15, 0.05, 0.00);
        glEnd();
    glPopMatrix();

    // Objek 4: Lingkaran (Line Loop) menggunakan Stack keempat
    glPushMatrix();
        glBegin(GL_LINE_LOOP); 
        GLint circle_points = 100; 
        int i;
        float angle;
        for (i = 0; i < circle_points; i++) {
            angle = 2 * PI * i / circle_points;
            glVertex2f(cos(angle), sin(angle));
        }
        glEnd();
    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
    glutCreateWindow("Simple");
    glutDisplayFunc(RenderScene);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
