#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898 // [cite: 107]

// Fungsi untuk membuat objek Lingkaran (Digunakan untuk Roda)
void drawCircle(float radius, float r, float g, float b) {
    glColor3f(r, g, b); // 
    glBegin(GL_POLYGON); // 
    int circle_points = 100; // [cite: 109, 110]
    for (int i = 0; i < circle_points; i++) { // [cite: 112]
        float angle = 2 * PI * i / circle_points; // [cite: 114]
        glVertex2f(radius * cos(angle), radius * sin(angle)); // [cite: 115]
    }
    glEnd(); // 
}

// Fungsi menggambar satu Roda lengkap dengan Velg
void drawWheel() {
    // 1. Ban Utama (Hitam)
    drawCircle(0.12f, 0.15f, 0.15f, 0.15f); 
    
    // 2. Velg Ban (Abu-abu)
    drawCircle(0.07f, 0.7f, 0.7f, 0.7f);

    // 3. Jari-jari Velg (untuk menunjukkan rotasi dengan jelas)
    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(3.0f);
    glBegin(GL_LINES); // 
        glVertex2f(-0.07f, 0.0f); glVertex2f(0.07f, 0.0f); // Garis horizontal
        glVertex2f(0.0f, -0.07f); glVertex2f(0.0f, 0.07f); // Garis vertikal
    glEnd();
}

void Mobil2D(void) {
    glClear(GL_COLOR_BUFFER_BIT); // [cite: 21, 77]

    // --- MENGGAMBAR MOBIL (Gunakan Stack agar rapi) ---
    glPushMatrix(); // [cite: 70]
        
        // Memindahkan seluruh posisi mobil agak ke atas dari jalan raya 
        glTranslatef(0.0f, 0.1f, 0.0f); // 

        // 1. Badan Bawah Mobil
        glPushMatrix();
            glColor3f(0.8f, 0.1f, 0.1f); // Warna Merah
            glBegin(GL_QUADS); // 
                glVertex2f(-0.5f, -0.05f);
                glVertex2f( 0.5f, -0.05f);
                glVertex2f( 0.5f,  0.15f);
                glVertex2f(-0.5f,  0.15f);
            glEnd();
        glPopMatrix(); // [cite: 70]

        // 2. Kabin Atas Mobil
        glPushMatrix();
            glColor3f(0.8f, 0.1f, 0.1f); 
            glTranslatef(0.0f, 0.15f, 0.0f); // Geser titik sumbu ke atas bodi bawah
            glBegin(GL_QUADS);
                glVertex2f(-0.25f, 0.0f);
                glVertex2f( 0.25f, 0.0f);
                glVertex2f( 0.15f, 0.2f);
                glVertex2f(-0.15f, 0.2f);
            glEnd();
        glPopMatrix();

        // 3. Jendela Mobil (Kaca)
        glPushMatrix();
            glColor3f(0.4f, 0.7f, 1.0f); // Biru muda
            glTranslatef(0.0f, 0.15f, 0.0f); 
            
            // Jendela Kiri
            glBegin(GL_QUADS);
                glVertex2f(-0.22f, 0.02f);
                glVertex2f(-0.02f, 0.02f);
                glVertex2f(-0.02f, 0.17f);
                glVertex2f(-0.13f, 0.17f);
            glEnd();
            
            // Jendela Kanan
            glBegin(GL_QUADS);
                glVertex2f(0.02f, 0.02f);
                glVertex2f(0.22f, 0.02f);
                glVertex2f(0.13f, 0.17f);
                glVertex2f(0.02f, 0.17f);
            glEnd();
        glPopMatrix();

        // 4. Lampu Depan
        glPushMatrix();
            glColor3f(1.0f, 1.0f, 0.0f); // Kuning
            glTranslatef(0.48f, 0.08f, 0.0f); // Posisi moncong mobil kanan
            drawCircle(0.04f, 1.0f, 1.0f, 0.0f); // Menggunakan fungsi lingkaran
        glPopMatrix();

        // 5. Roda Belakang (Kiri)
        glPushMatrix();
            glTranslatef(-0.3f, -0.05f, 0.0f); // Geser titik pusat ke kiri bawah mobil
            glRotated(45.0, 0.0, 0.0, 1.0);    // Implementasi Rotasi sebesar 45 Derajat [cite: 40, 68]
            drawWheel();
        glPopMatrix();

        // 6. Roda Depan (Kanan)
        glPushMatrix();
            glTranslatef(0.3f, -0.05f, 0.0f); // Geser ke kanan bawah
            glRotated(45.0, 0.0, 0.0, 1.0);   // Rotasi velg 45 derajat [cite: 40, 68]
            drawWheel();
        glPopMatrix();

    glPopMatrix(); // Akhir stack objek mobil

    // --- OBJEK TAMBAHAN (Jalan Raya di belakang/bawah) ---
    glPushMatrix();
        glColor3f(0.3f, 0.3f, 0.3f); // Warna aspal gelap
        glBegin(GL_QUADS);
            glVertex2f(-1.0f, -0.07f);
            glVertex2f( 1.0f, -0.07f);
            glVertex2f( 1.0f, -0.5f);
            glVertex2f(-1.0f, -0.5f);
        glEnd();
        
        // Garis marka jalan (Putus-putus)
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
            glVertex2f(-0.8f, -0.28f); glVertex2f(-0.5f, -0.28f);
            glVertex2f(-0.5f, -0.32f); glVertex2f(-0.8f, -0.32f);
            
            glVertex2f(-0.1f, -0.28f); glVertex2f(0.2f, -0.28f);
            glVertex2f(0.2f, -0.32f);  glVertex2f(-0.1f, -0.32f);
            
            glVertex2f(0.6f, -0.28f);  glVertex2f(0.9f, -0.28f);
            glVertex2f(0.9f, -0.32f);  glVertex2f(0.6f, -0.32f);
        glEnd();
    glPopMatrix();

    glFlush(); // [cite: 118]
}

int main(int argc, char* argv[]) { // [cite: 119]
    glutInit(&argc, argv); // [cite: 120]
    glutInitWindowSize(800, 600); // Ukuran window dilebarkan agar muat objek jalanan [cite: 121]
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // [cite: 122, 123]
    glutCreateWindow("Praktikum Modul 3 - Mobil 2D"); // [cite: 123]
    glutDisplayFunc(Mobil2D); // [cite: 124]
    glClearColor(0.6f, 0.8f, 1.0f, 1.0f); // Latar belakang warna langit biru muda [cite: 125]
    glutMainLoop(); // [cite: 126]
    return 0; // [cite: 127]
} // [cite: 128]
