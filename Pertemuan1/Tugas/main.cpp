#include <GL/glut.h>

void Roket(void) {
    glClear(GL_COLOR_BUFFER_BIT); 
    glLineWidth(2.5f);

    // 1. MONCONG ROKET menggunakan GL_TRIANGLE_FAN
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.9f, 0.1f, 0.1f); // Warna Merah
        glVertex2f(0.0f, 0.7f);      // Titik pusat (Puncak moncong)
        glVertex2f(-0.2f, 0.4f);     
        glVertex2f(0.0f, 0.45f);     // Lengkungan bawah moncong
        glVertex2f(0.2f, 0.4f);      
    glEnd();

    // Outline Moncong
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.7f);
        glVertex2f(-0.2f, 0.4f);
        glVertex2f(0.2f, 0.4f);
    glEnd();

    // 2. BADAN ROKET menggunakan GL_QUAD_STRIP
    glBegin(GL_QUAD_STRIP);
        glColor3f(0.8f, 0.8f, 0.8f); // Warna Abu-abu terang
        glVertex2f(-0.2f, 0.4f);     // Atas kiri
        glVertex2f( 0.2f, 0.4f);     // Atas kanan
        glVertex2f(-0.2f, -0.3f);    // Bawah kiri
        glVertex2f( 0.2f, -0.3f);    // Bawah kanan
    glEnd();

    // Outline Badan Roket
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.2f, 0.4f);
        glVertex2f( 0.2f, 0.4f);
        glVertex2f( 0.2f, -0.3f);
        glVertex2f(-0.2f, -0.3f);
    glEnd();

    // 3. JENDELA KACA menggunakan GL_QUADS
    glBegin(GL_QUADS);
        glColor3f(0.2f, 0.6f, 1.0f); // Warna Biru Kaca
        glVertex2f(-0.1f, 0.2f);
        glVertex2f( 0.1f, 0.2f);
        glVertex2f( 0.1f, 0.0f);
        glVertex2f(-0.1f, 0.0f);
    glEnd();

    // Outline Jendela
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.1f, 0.2f);
        glVertex2f( 0.1f, 0.2f);
        glVertex2f( 0.1f, 0.0f);
        glVertex2f(-0.1f, 0.0f);
    glEnd();

    // 4. SAYAP KIRI & KANAN menggunakan GL_QUADS
    glBegin(GL_QUADS);
        glColor3f(0.9f, 0.1f, 0.1f); // Warna Merah
        // Sayap Kiri
        glVertex2f(-0.2f, 0.0f);
        glVertex2f(-0.2f, -0.3f);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f(-0.4f, -0.1f);
        
        // Sayap Kanan
        glVertex2f( 0.2f, 0.0f);
        glVertex2f( 0.2f, -0.3f);
        glVertex2f( 0.4f, -0.4f);
        glVertex2f( 0.4f, -0.1f);
    glEnd();

    // 5. MESIN BAWAH (Thruster) menggunakan GL_QUADS
    glBegin(GL_QUADS);
        glColor3f(0.3f, 0.3f, 0.3f); // Warna Abu-abu gelap
        glVertex2f(-0.15f, -0.3f);
        glVertex2f( 0.15f, -0.3f);
        glVertex2f( 0.2f, -0.45f);
        glVertex2f(-0.2f, -0.45f);
    glEnd();

    // 6. SEMBURAN API menggunakan GL_TRIANGLE_STRIP
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1.0f, 0.5f, 0.0f); // Warna Oranye/Api
        glVertex2f(-0.15f, -0.45f); // 1
        glVertex2f(-0.1f, -0.7f);   // 2 (Ujung api kiri)
        glVertex2f(-0.05f, -0.45f); // 3
        glVertex2f( 0.0f, -0.8f);   // 4 (Ujung api tengah memanjang)
        glVertex2f( 0.05f, -0.45f); // 5
        glVertex2f( 0.1f, -0.7f);   // 6 (Ujung api kanan)
        glVertex2f( 0.15f, -0.45f); // 7
    glEnd();

    // 7. ANTENA ZIG-ZAG DI ATAS menggunakan GL_LINE_STRIP
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.7f);      // Mulai dari pucuk moncong
        glVertex2f(0.05f, 0.75f);
        glVertex2f(-0.05f, 0.8f);
        glVertex2f(0.05f, 0.85f);
        glVertex2f(0.0f, 0.9f);      // Ujung antena
    glEnd();

    glFlush(); 
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);  
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas OpenGL - Objek Roket"); 
    glutDisplayFunc(Roket); 
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    glutMainLoop();
    return 0;
}
