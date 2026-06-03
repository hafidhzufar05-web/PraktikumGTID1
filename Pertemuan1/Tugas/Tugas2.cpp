#include <GL/glut.h>

// Fungsi modular untuk menggambar satu kotak beserta garis tepinya
// Parameter: koordinat titik tengah (x, y), ukuran sisi (size), dan warna RGB (r, g, b)
void drawBox(float x, float y, float size, float r, float g, float b) {
    float half = size / 2.0f;

    // 1. Gambar warna solid di dalam kotak
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x - half, y - half);
        glVertex2f(x + half, y - half);
        glVertex2f(x + half, y + half);
        glVertex2f(x - half, y + half);
    glEnd();

    // 2. Gambar garis tepi (Outline) agar batas antar kubus terlihat jelas
    glColor3f(0.2f, 0.3f, 0.4f); // Warna biru gelap untuk outline (mirip contoh)
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x - half, y - half);
        glVertex2f(x + half, y - half);
        glVertex2f(x + half, y + half);
        glVertex2f(x - half, y + half);
    glEnd();
}

void SusunanKubus(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Konfigurasi ukuran dan jarak antar kubus
    float size = 0.25f;        // Ukuran sisi kubus
    float gap = 0.02f;         // Celah kecil antar kubus
    float offset = size + gap; // Jarak total pergeseran

    // BARIS BAWAH (3 Kubus) - Warna biru tua
    drawBox(-offset, -offset, size, 0.30f, 0.55f, 0.80f); // Kiri
    drawBox(0.0f,    -offset, size, 0.30f, 0.55f, 0.80f); // Tengah
    drawBox(offset,  -offset, size, 0.30f, 0.55f, 0.80f); // Kanan

    // BARIS TENGAH (2 Kubus) - Warna biru sedikit lebih cerah
    drawBox(-offset / 2.0f, 0.0f, size, 0.40f, 0.65f, 0.90f); // Kiri Tengah
    drawBox(offset / 2.0f,  0.0f, size, 0.40f, 0.65f, 0.90f); // Kanan Tengah

    // BARIS ATAS (1 Kubus) - Warna biru paling terang 
    // (Total 6 kubus, memenuhi syarat "minimal 5")
    drawBox(0.0f, offset, size, 0.50f, 0.75f, 1.00f);     // Puncak

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);  
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas 3 - Susunan Kubus Bertingkat"); 
    glutDisplayFunc(SusunanKubus); 
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Background putih
    glutMainLoop();
    return 0;
}
