#include <GL/glut.h>
#include <stdlib.h>

// Ubah menjadi float agar pergerakan animasinya lebih halus
static float shoulder = 0.0, elbow = 0.0, palm = 0.0, finger = 0.0;

// Variabel untuk arah animasi otomatis (1 = maju/naik, -1 = mundur/turun)
static int dirShoulder = 1;
static int dirElbow = 1;
static int dirFinger = 1;

// Status apakah animasi otomatis menyala atau tidak
bool isAuto = true; 

void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void display (void) {
    glClear (GL_COLOR_BUFFER_BIT); 
    glPushMatrix(); 
    
        // 1. BAHU
        glTranslatef (-1.0, 0.0, 0.0);
        glRotatef (shoulder, 0.0, 0.0, 1.0);
        glTranslatef (1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef (2.0, 0.4, 1.0);
            glutWireCube (1.0);
        glPopMatrix();
        
        // 2. SIKU
        glTranslatef (1.0, 0.0, 0.0);
        glRotatef (elbow, 0.0, 0.0, 1.0);
        glTranslatef (1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef (2.0, 0.4, 1.0);
            glutWireCube (1.0);
        glPopMatrix();
        
        // 3. TELAPAK TANGAN
        glTranslatef (1.0, 0.0, 0.0);
        glRotatef (palm, 0.0, 0.0, 1.0);
        glTranslatef (0.5, 0.0, 0.0); 
        glPushMatrix();
            glScalef (1.0, 0.6, 1.0); 
            glutWireCube (1.0);
        glPopMatrix();
        
        // 4. JARI-JARI
        // Telunjuk
        glPushMatrix();
            glTranslatef (0.5, 0.2, 0.0);
            glRotatef (finger, 0.0, 0.0, 1.0);
            glTranslatef (0.25, 0.0, 0.0);
            glPushMatrix();
                glScalef (0.5, 0.15, 0.3);
                glutWireCube (1.0);
            glPopMatrix();
        glPopMatrix();
        
        // Jari Tengah
        glPushMatrix();
            glTranslatef (0.5, 0.0, 0.0);
            glRotatef (finger, 0.0, 0.0, 1.0);
            glTranslatef (0.3, 0.0, 0.0);
            glPushMatrix();
                glScalef (0.6, 0.15, 0.3);
                glutWireCube (1.0);
            glPopMatrix();
        glPopMatrix();
        
        // Jempol 
        glPushMatrix();
            glTranslatef (0.5, -0.2, 0.0);
            glRotatef (-finger, 0.0, 0.0, 1.0); 
            glTranslatef (0.25, 0.0, 0.0);
            glPushMatrix();
                glScalef (0.5, 0.15, 0.3);
                glutWireCube (1.0);
            glPopMatrix();
        glPopMatrix();
        
    glPopMatrix(); 
    glutSwapBuffers();
}

// Fungsi Idle untuk Animasi Otomatis
void idle(void) {
    // Jika isAuto bernilai false (mati), maka hentikan fungsi ini
    if (!isAuto) return; 

    // Kecepatan gerak (ubah angka ini jika dirasa terlalu cepat/lambat)
    float speed = 0.05f; 

    // Animasi Bahu (Naik turun secara terbatas)
    shoulder += dirShoulder * (speed * 1.5f);
    if (shoulder > 30.0f || shoulder < -20.0f) dirShoulder = -dirShoulder;

    // Animasi Siku (Mengayun)
    elbow += dirElbow * (speed * 2.5f);
    if (elbow > 60.0f || elbow < 0.0f) dirElbow = -dirElbow;

    // Animasi Jari (Membuka dan Mengepal)
    finger += dirFinger * (speed * 5.0f);
    if (finger > 90.0f || finger < 0.0f) dirFinger = -dirFinger;

    // Render ulang layar secara terus menerus
    glutPostRedisplay();
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -8.0);
}

void keyboard (unsigned char key, int x, int y) {
    switch (key) {
        // Tombol saklar (ON/OFF) untuk Animasi Otomatis
        case 'a': 
        case 'A':
            isAuto = !isAuto; 
            break;

        // Kontrol Manual (Bisa dipakai saat mode otomatis dimatikan)
        case 's': shoulder += 5.0f; if (shoulder > 360) shoulder -= 360; glutPostRedisplay(); break;
        case 'S': shoulder -= 5.0f; if (shoulder < 0) shoulder += 360; glutPostRedisplay(); break;
        
        case 'e': elbow += 5.0f; if (elbow > 360) elbow -= 360; glutPostRedisplay(); break;
        case 'E': elbow -= 5.0f; if (elbow < 0) elbow += 360; glutPostRedisplay(); break;
        
        case 'p': palm += 5.0f; if (palm > 360) palm -= 360; glutPostRedisplay(); break;
        case 'P': palm -= 5.0f; if (palm < 0) palm += 360; glutPostRedisplay(); break;
        
        case 'j': if (finger < 90) finger += 5.0f; glutPostRedisplay(); break;
        case 'J': if (finger > -10) finger -= 5.0f; glutPostRedisplay(); break;
            
        case 27: exit(0); break;
        default: break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (900, 600); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Animasi Otomatis - Lengan, Telapak, dan Jari");
    
    init();
    glutDisplayFunc (display);
    glutReshapeFunc (reshape);
    glutKeyboardFunc (keyboard);
    
    // Daftarkan fungsi idle agar bisa bergerak otomatis
    glutIdleFunc(idle); 
    
    glutMainLoop();
    return 0;
}
