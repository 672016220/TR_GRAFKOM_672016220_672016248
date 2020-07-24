#include<windows.h>
#include <gl/glut.h>
#include<math.h>

void init(void);
void display(void);
void tampil(void);
void Lapangan(void);
void posenggggg(void);
void Penonton(void);
void lawang(void);
void atap(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;
int sudut=0, o=0, p=0, q=0;
int i=0; int j=0;

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("672016220 - 672016248");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(1.5f);
}

void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Lapangan();
    Penonton();
    lawang();
    atap();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void hilang(void)
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    Lapangan();
    Penonton();
    lawang();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void Lapangan(void){

    //Base
	glBegin(GL_QUADS);
	glColor3f(1,0.5,0);
	glVertex3f(-100,-64,-0.9);
	glVertex3f(-100,64,-0.9);
	glVertex3f(100,64,-0.9);
    	glVertex3f(100,-64,-0.9);
    	glEnd();
	
	//gawang
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);//kiri
    glColor3f(1,1,1);
    glVertex3f(-50,3.62,2.3);
    glVertex3f(-50,-3.62,2.3);
    glVertex3f(-50,-3.62,0);
    glVertex3f(-50,3.62,0);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);//penyangga 1
    glColor3f(1,1,1);
    glVertex3f(-50,     -3.62,2);
    glVertex3f(-51,     -3.62,2);
    glVertex3f(-51.5,   -3.62,0);
    glVertex3f(-51,     -3.62,2);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);//penyangga 2
    glColor3f(1,1,1);
    glVertex3f(-50,     3.62,2);
    glVertex3f(-51,     3.62,2);
    glVertex3f(-51.5,   3.62,0);
    glVertex3f(-51,     3.62,2);
    glEnd();
    glBegin(GL_LINE_STRIP);//bayangkan jaring
    glColor3f(1,1,1);
    glVertex3f(-51,-3.62,2);
    glVertex3f(-51,3.62,2);
    glEnd();
    glBegin(GL_LINE_STRIP);//bayangkan jaring
    glColor3f(1,1,1);;
    glVertex3f(51,-3.62,2);
    glVertex3f(51,3.62,2);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);//kanan
    glColor3d(1,1,1);
    glVertex3f(50,3.62,2.3);
    glVertex3f(50,-3.62,2.3);
    glVertex3f(50,-3.62,0);
    glVertex3f(50,3.62,0);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);//penyangga 1
    glColor3f(1,1,1);
    glVertex3f(50,-3.62,2);
    glVertex3f(51,-3.62,2);
    glVertex3f(51.5,-3.62,0);
    glVertex3f(51,-3.62,2);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);//penyangga 2
    glColor3f(1,1,1);
    glVertex3f(50,3.62,2);
    glVertex3f(51,3.62,2);
    glVertex3f(51.5,3.62,0);
    glVertex3f(51,3.62,2);
    glEnd();
	
	//Lapangan
	glBegin(GL_QUADS);
	glColor3f(0,0.8,0);
	glVertex3f(-50,-30,0);
	glVertex3f(-50,30,0);
	glVertex3f(50,30,0);
    	glVertex3f(50,-30,0);
    	glEnd();
	
	//Flag
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);//1
    glColor3f(1,1,1);
    glVertex3f(49,29,0);
    glVertex3f(49,29,2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    glVertex3f(49,29,1.9);
    glVertex3f(49,29,1);
    glVertex3f(49.5,29,1.45);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);//2
    glColor3f(1,1,1);
    glVertex3f(49,-29,0);
    glVertex3f(49,-29,2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    glVertex3f(49,-29,1.9);
    glVertex3f(49,-29,1);
    glVertex3f(49.5,-29,1.45);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);//3
    glColor3f(1,1,1);
    glVertex3f(-49,29,0);
    glVertex3f(-49,29,2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    glVertex3f(-49,29,1.9);
    glVertex3f(-49,29,1);
    glVertex3f(-49.5,29,1.45);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);//4
    glColor3f(1,1,1);
    glVertex3f(-49,-29,0);
    glVertex3f(-49,-29,2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    glVertex3f(-49,-29,1.9);
    glVertex3f(-49,-29,1);
    glVertex3f(-49.5,-29,1.45);
    glEnd();
	    //Garis
    	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
	glColor3b(1,1,1);
	glVertex3f(-49,-29,0.1);
	glVertex3f(-49,29,0.1);
	glVertex3f(0,29,0.1);
	glVertex3f(0,-29,0.1);
	glVertex3f(49,-29,0.1);
	glVertex3f(49,29,0.1);
	glVertex3f(-49,29,0.1);
	glVertex3f(-49,-29,0.1);
	glVertex3f(0,-29,0.1);
	glEnd();
	glLineWidth(1);
	
	glBegin(GL_LINE_LOOP);//lingkaran
	glColor3b(0,0,0);
	glVertex3f(2,2,0.1);
	glVertex3f(0,2.5,0.1);
	glVertex3f(-1.8,1.8,0.1);
	glVertex3f(-2.5,0,0.1);
	glVertex3f(-1.8,-1.8,0.1);
	glVertex3f(0,-2.5,0.1);
	glVertex3f(1.8,-1.8,0.1);
	glVertex3f(2.5,0,0.1);
	glEnd();
    	glLineWidth(1);
	
	glLineWidth(1);//Kotak Penalty kiri
	glBegin(GL_LINE_STRIP);
	glColor3b(0,0,0);
	glVertex3f(-49,20,0.1);
	glVertex3f(-41,20,0.1);
	glVertex3f(-41,-20,0.1);
	glVertex3f(-49,-20,0.1);
	glEnd();
	
	glLineWidth(1);//Kotak Penalty kanan
	glBegin(GL_LINE_STRIP);
	glColor3b(0,0,0);
	glVertex3f(49,20,0.1);
	glVertex3f(41,20,0.1);
	glVertex3f(41,-20,0.1);
	glVertex3f(49,-20,0.1);
	glEnd();
	
	glLineWidth(1);//Area Gawang kiri
	glBegin(GL_LINE_STRIP);
	glColor3b(0,0,0);
	glVertex3f(-49,9,0.1);
	glVertex3f(-44,9,0.1);
	glVertex3f(-44,-9,0.1);
	glVertex3f(-49,-9,0.1);
	glEnd();
	
	glLineWidth(1);//Area Gawang kanan
	glBegin(GL_LINE_STRIP);
	glColor3b(0,0,0);
	glVertex3f(49,9,0.1);
	glVertex3f(44,9,0.1);
	glVertex3f(44,-9,0.1);
	glVertex3f(49,-9,0.1);
	glEnd();
	glLineWidth(1);
	glBegin(GL_POLYGON);//Pelatih
	glColor3f(1,0,0);
	glVertex3f(5,-32,0.1);
	glVertex3f(15,-32,0.1);
	glVertex3f(15,-34,0.1);
	glVertex3f(5,-34,0.1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3d(0,0,0);
	glVertex3d(5,-32,0.1);
	glVertex3d(5,-32,2);
	glVertex3d(5,-33.5,1.8);
	glVertex3d(5,-34,0.1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3d(0,0,0);
	glVertex3d(15,-32,0.1);
	glVertex3d(15,-32,2);
	glVertex3d(15,-33.5,1.8);
	glVertex3d(15,-34,0.1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3d(0,0,0);
	glVertex3d(15,-32,2);
	glVertex3d(15,-33.5,1.8);
	glVertex3d(15,-34,0.1);
	glVertex3d(5,-34,0.1);
	glVertex3d(5,-33.5,1.8);
	glVertex3d(5,-32,2);
	glEnd();
	glLineWidth(1);
	glBegin(GL_POLYGON);//Pelatih
	glColor3f(1,0,0);
	glVertex3f(-5,-32,0.1);
	glVertex3f(-15,-32,0.1);
	glVertex3f(-15,-34,0.1);
	glVertex3f(-5,-34,0.1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3d(0,0,0);
	glVertex3d(-5,-32,0.1);
	glVertex3d(-5,-32,2);
	glVertex3d(-5,-33.5,1.8);
	glVertex3d(-5,-34,0.1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3d(0,0,0);
	glVertex3d(-15,-32,0.1);
	glVertex3d(-15,-32,2);
	glVertex3d(-15,-33.5,1.8);
	glVertex3d(-15,-34,0.1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3d(0,0,0);
	glVertex3d(-15,-32,2);
	glVertex3d(-15,-33.5,1.8);
	glVertex3d(-15,-34,0.1);
	glVertex3d(-5,-34,0.1);
	glVertex3d(-5,-33.5,1.8);
	glVertex3d(-5,-32,2);
	glEnd();
	
	//Iklan
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-53,-35,0);
	glVertex3f(-53,-35,1);
	glColor3f(1,0.2,0.5);
	glVertex3f(53,-35,1);
    glVertex3f(53,-35,0);
    glEnd();
    glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-53,35,0);
	glVertex3f(-53,35,1);
	glColor3f(1,0.2,0.5);
	glVertex3f(53,35,1);
    glVertex3f(53,35,0);
    glEnd();
    glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-53,-35,0);
	glVertex3f(-53,-35,1);
	glColor3f(1,0.2,0.5);
	glVertex3f(-53,35,1);
    glVertex3f(-53,35,0);
    glEnd();
    glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(53,-35,0);
	glVertex3f(53,-35,1);
	glColor3f(1,0.2,0.5);
	glVertex3f(53,35,1);
    glVertex3f(53,35,0);
    glEnd();

}

void Penonton(void){

    //Kursi Penonton belakang Gawang 1
    	glBegin(GL_QUADS);//bottom
    	glColor3f(0,0,0.3);
	glVertex3f(-70,-32,0);
	glVertex3f(-55,-32,0);
	glVertex3f(-55,32,0);
	glVertex3f(-70,32,0);
	glEnd();
	
	glBegin(GL_QUADS);//back
    	glColor3d(0.5,0.7,0.6);//
	glVertex3f(-70,-32,0);
	glVertex3f(-70,-32,26);
	//glColor3f(1,1,0);
	glVertex3f(-70,32,26);
	glVertex3f(-70,32,0);
	glEnd();
	glBegin(GL_POLYGON);//side 1
    	glColor3f(0.9,0,0.3);
	glVertex3f(-70,-32,0);
	glVertex3f(-55,-32,0);
	glVertex3f(-55,-32,1);
	glVertex3f(-57,-32,1);
	glVertex3f(-57,-32,2);
	glVertex3f(-65,-32,11);
	glVertex3f(-70,-32,11);
	glEnd();
	glBegin(GL_POLYGON);//side 2
    	glColor3f(0.9,0,0.3);
	glVertex3f(-70,32,0);
	glVertex3f(-55,32,0);
	glVertex3f(-55,32,1);
	glVertex3f(-57,32,1);
	glVertex3f(-57,32,2);
	glVertex3f(-65,32,11);
	glVertex3f(-70,32,11);
	glEnd();
	
	glBegin(GL_QUADS);//kursi lvl 1
        glColor3f(0.5,1,0.6);
	glVertex3f(-55,-32,0);
	glVertex3f(-55,32,0);
	glVertex3f(-55,32,1);
	glVertex3f(-55,-32,1);
	glEnd();
	
	glBegin(GL_QUADS);//Kursi Lvl 1
        glColor3f(0.5,0.6,1);
	glVertex3f(-57,-32,1);
	glVertex3f(-55,-32,1);
	glVertex3f(-55,32,1);
	glVertex3f(-57,32,1);
	glEnd();
	
	glBegin(GL_QUADS);//kursi lvl 2
        glColor3f(0.5,1,0.6);
	glVertex3f(-57,-32,1);
	glVertex3f(-57,32,1);
	glVertex3f(-57,32,2);
	glVertex3f(-57,-32,2);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 2
        glColor3f(0.5,0.6,1);
	glVertex3f(-58,-32,2);
	glVertex3f(-57,-32,2);
	glVertex3f(-57,32,2);
	glVertex3f(-58,32,2);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 3
        glColor3f(0.5,1,0.6);
	glVertex3f(-58,-32,2);
	glVertex3f(-58,32,2);
	glVertex3f(-58,32,3);
	glVertex3f(-58,-32,3);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 3
        glColor3f(0.5,0.6,1);
	glVertex3f(-59,-32,3);
	glVertex3f(-58,-32,3);
	glVertex3f(-58,32,3);
	glVertex3f(-59,32,3);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 4
        glColor3f(0.5,1,0.6);
	glVertex3f(-59,-32,3);
	glVertex3f(-59,32,3);
	glVertex3f(-59,32,4);
	glVertex3f(-59,-32,4);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 4
        glColor3f(0.5,0.6,1);
	glVertex3f(-60,-32,4);
	glVertex3f(-59,-32,4);
	glVertex3f(-59,32,4);
	glVertex3f(-60,32,4);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 5
        glColor3f(0.5,1,0.6);
	glVertex3f(-60,-32,4);
	glVertex3f(-60,32,4);
	glVertex3f(-60,32,5);
	glVertex3f(-60,-32,5);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 5
        glColor3f(0.5,0.6,1);
	glVertex3f(-61,-32,5);
	glVertex3f(-60,-32,5);
	glVertex3f(-60,32,5);
	glVertex3f(-61,32,5);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 6
        glColor3f(0.5,1,0.6);
	glVertex3f(-61,-32,5);
	glVertex3f(-61,32,5);
	glVertex3f(-61,32,6);
	glVertex3f(-61,-32,6);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 6
        glColor3f(0.5,0.6,1);
	glVertex3f(-62,-32,6);
	glVertex3f(-61,-32,6);
	glVertex3f(-61,32,6);
	glVertex3f(-62,32,6);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 7
        glColor3f(0.5,1,0.6);
	glVertex3f(-62,-32,6);
	glVertex3f(-62,32,6);
	glVertex3f(-62,32,7);
	glVertex3f(-62,-32,7);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 7
        glColor3f(0.5,0.6,1);
	glVertex3f(-63,-32,7);
	glVertex3f(-62,-32,7);
	glVertex3f(-62,32,7);
	glVertex3f(-63,32,7);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 8
        glColor3f(0.5,1,0.6);
	glVertex3f(-63,-32,7);
	glVertex3f(-63,32,7);
	glVertex3f(-63,32,8);
	glVertex3f(-63,-32,8);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 8
        glColor3f(0.5,0.6,1);
	glVertex3f(-64,-32,8);
	glVertex3f(-63,-32,8);
	glVertex3f(-63,32,8);
	glVertex3f(-64,32,8);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 9
        glColor3f(0.5,1,0.6);
	glVertex3f(-64,-32,8);
	glVertex3f(-64,32,8);
	glVertex3f(-64,32,9);
	glVertex3f(-64,-32,9);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 9
        glColor3f(0.5,0.6,1);
	glVertex3f(-65,-32,9);
	glVertex3f(-64,-32,9);
	glVertex3f(-64,32,9);
	glVertex3f(-65,32,9);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 10
        glColor3f(0.5,1,0.6);
	glVertex3f(-65,-32,9);
	glVertex3f(-65,32,9);
	glVertex3f(-65,32,10);
	glVertex3f(-65,-32,10);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 10
        glColor3f(0.5,0.6,1);
	glVertex3f(-66,-32,10);
	glVertex3f(-65,-32,10);
	glVertex3f(-65,32,10);
	glVertex3f(-66,32,10);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 11
        glColor3f(0.5,1,0.6);
	glVertex3f(-66,-32,10);
	glVertex3f(-66,32,10);
	glVertex3f(-66,32,11);
	glVertex3f(-66,-32,11);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 11
        glColor3f(0.5,0.6,1);
	glVertex3f(-70,-32,11);
	glVertex3f(-66,-32,11);
	glVertex3f(-66,32,11);
	glVertex3f(-70,32,11);
	glEnd();
	
	//Kursi Penonton belakang Gawang 2
        glBegin(GL_QUADS);//bottom
        glColor3f(1.99,0,3);
	glVertex3f(70,-32,0);
	glVertex3f(55,-32,0);
	glVertex3f(55,32,0);
	glVertex3f(70,32,0);
	glEnd();
	glBegin(GL_QUADS);//back
        glColor3d(0.5,0.7,0.6);
	glVertex3f(70,-32,0);
	glVertex3f(70,-32,26);
	glVertex3f(70,32,26);
	glVertex3f(70,32,0);
	glEnd();
	glBegin(GL_POLYGON);//side 1
        glColor3f(0.9,0,0.3);
	glVertex3f(70,-32,0);
	glVertex3f(55,-32,0);
	glVertex3f(55,-32,1);
	glVertex3f(57,-32,1);
	glVertex3f(57,-32,2);
	glVertex3f(65,-32,11);
	glVertex3f(70,-32,11);
	glEnd();
	glBegin(GL_POLYGON);//side 2
        glColor3f(0.9,0,0.3);
	glVertex3f(70,32,0);
	glVertex3f(55,32,0);
	glVertex3f(55,32,1);
	glVertex3f(57,32,1);
	glVertex3f(57,32,2);
	glVertex3f(65,32,11);
	glVertex3f(70,32,11);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 1
        glColor3f(0.5,1,0.6);
	glVertex3f(55,-32,0);
	glVertex3f(55,32,0);
	glVertex3f(55,32,1);
	glVertex3f(55,-32,1);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 1
        glColor3f(0.5,0.6,1);
	glVertex3f(57,-32,1);
	glVertex3f(55,-32,1);
	glVertex3f(55,32,1);
	glVertex3f(57,32,1);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 2
        glColor3f(0.5,1,0.6);
	glVertex3f(57,-32,1);
	glVertex3f(57,32,1);
	glVertex3f(57,32,2);
	glVertex3f(57,-32,2);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 2
        glColor3f(0.5,0.6,1);
	glVertex3f(58,-32,2);
	glVertex3f(57,-32,2);
	glVertex3f(57,32,2);
	glVertex3f(58,32,2);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 3
        glColor3f(0.5,1,0.6);
	glVertex3f(58,-32,2);
	glVertex3f(58,32,2);
	glVertex3f(58,32,3);
	glVertex3f(58,-32,3);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 3
        glColor3f(0.5,0.6,1);
	glVertex3f(59,-32,3);
	glVertex3f(58,-32,3);
	glVertex3f(58,32,3);
	glVertex3f(59,32,3);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 4
        glColor3f(0.5,1,0.6);
	glVertex3f(59,-32,3);
	glVertex3f(59,32,3);
	glVertex3f(59,32,4);
	glVertex3f(59,-32,4);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 4
        glColor3f(0.5,0.6,1);
	glVertex3f(60,-32,4);
	glVertex3f(59,-32,4);
	glVertex3f(59,32,4);
	glVertex3f(60,32,4);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 5
        glColor3f(0.5,1,0.6);
	glVertex3f(60,-32,4);
	glVertex3f(60,32,4);
	glVertex3f(60,32,5);
	glVertex3f(60,-32,5);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 5
        glColor3f(0.5,0.6,1);
	glVertex3f(61,-32,5);
	glVertex3f(60,-32,5);
	glVertex3f(60,32,5);
	glVertex3f(61,32,5);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 6
        glColor3f(0.5,1,0.6);
	glVertex3f(61,-32,5);
	glVertex3f(61,32,5);
	glVertex3f(61,32,6);
	glVertex3f(61,-32,6);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 6
        glColor3f(0.5,0.6,1);
	glVertex3f(62,-32,6);
	glVertex3f(61,-32,6);
	glVertex3f(61,32,6);
	glVertex3f(62,32,6);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 7
        glColor3f(0.5,1,0.6);
	glVertex3f(62,-32,6);
	glVertex3f(62,32,6);
	glVertex3f(62,32,7);
	glVertex3f(62,-32,7);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 7
        glColor3f(0.5,0.6,1);
	glVertex3f(63,-32,7);
	glVertex3f(62,-32,7);
	glVertex3f(62,32,7);
	glVertex3f(63,32,7);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 8
        glColor3f(0.5,1,0.6);
	glVertex3f(63,-32,7);
	glVertex3f(63,32,7);
	glVertex3f(63,32,8);
	glVertex3f(63,-32,8);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 8
        glColor3f(0.5,0.6,1);
	glVertex3f(64,-32,8);
	glVertex3f(63,-32,8);
	glVertex3f(63,32,8);
	glVertex3f(64,32,8);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 9
        glColor3f(0.5,1,0.6);
	glVertex3f(64,-32,8);
	glVertex3f(64,32,8);
	glVertex3f(64,32,9);
	glVertex3f(64,-32,9);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 9
        glColor3f(0.5,0.6,1);
	glVertex3f(65,-32,9);
	glVertex3f(64,-32,9);
	glVertex3f(64,32,9);
	glVertex3f(65,32,9);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 10
        glColor3f(0.5,1,0.6);
	glVertex3f(65,-32,9);
	glVertex3f(65,32,9);
	glVertex3f(65,32,10);
	glVertex3f(65,-32,10);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 10
        glColor3f(0.5,0.6,1);
	glVertex3f(66,-32,10);
	glVertex3f(65,-32,10);
	glVertex3f(65,32,10);
	glVertex3f(66,32,10);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 11
        glColor3f(0.5,1,0.6);
	glVertex3f(66,-32,10);
	glVertex3f(66,32,10);
	glVertex3f(66,32,11);
	glVertex3f(66,-32,11);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 11
        glColor3f(0.5,0.6,1);
	glVertex3f(70,-32,11);
	glVertex3f(66,-32,11);
	glVertex3f(66,32,11);
	glVertex3f(70,32,11);
	glEnd();
	
	//Kursi Penonton Sayap Kanan:>
	glBegin(GL_QUADS);//bottom
        glColor3f(1.99,0,3);
	glVertex3f(-50,-37,0);
	glVertex3f(50,-37,0);
	glVertex3f(50,-52,0);
	glVertex3f(-50,-52,0);
	glEnd();
	glBegin(GL_QUADS);//back
        glColor3d(0.5,0.7,0.6);
	glVertex3f(-50,-52,0);
	glVertex3f(50,-52,0);
	glVertex3f(50,-52,26);
	glVertex3f(-50,-52,26);
	glEnd();
	glBegin(GL_POLYGON);//side 1
        glColor3f(0.80,0,0);
	glVertex3f(50,-37,0);
	glVertex3f(50,-37,1);
	glVertex3f(50,-39,1);
	glVertex3f(50,-39,2);
	glColor3f(0.60,0,0);
	glVertex3f(50,-47,10);
	glVertex3f(50,-47,11);
	glVertex3f(50,-52,11);
	glVertex3f(50,-52,11);
	glVertex3f(50,-52,0);
	glEnd();
	glBegin(GL_POLYGON);//side 2
        glColor3f(0.80,0,0);
	glVertex3f(-50,-37,0);
	glVertex3f(-50,-37,1);
	glVertex3f(-50,-39,1);
	glVertex3f(-50,-39,2);
	glColor3f(0.60,0,0);
	glVertex3f(-50,-47,10);
	glVertex3f(-50,-47,11);
	glVertex3f(-50,-52,11);
	glVertex3f(-50,-52,11);
	glVertex3f(-50,-52,0);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 1
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,-37,0);
	glVertex3f(50,-37,0);
	glVertex3f(50,-37,1);
	glVertex3f(-50,-37,1);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 1
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,-37,1);
	glVertex3f(50,-37,1);
	glVertex3f(50,-39,1);
	glVertex3f(-50,-39,1);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 2
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,-39,1);
	glVertex3f(50,-39,1);
	glVertex3f(50,-39,2);
	glVertex3f(-50,-39,2);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 2
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,-39,2);
	glVertex3f(50,-39,2);
	glVertex3f(50,-40,2);
	glVertex3f(-50,-40,2);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 3
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,-40,2);
	glVertex3f(50,-40,2);
	glVertex3f(50,-40,3);
	glVertex3f(-50,-40,3);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 3
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,-40,3);
	glVertex3f(50,-40,3);
	glVertex3f(50,-41,3);
	glVertex3f(-50,-41,3);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 4
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,-41,3);
	glVertex3f(50,-41,3);
	glVertex3f(50,-41,4);
	glVertex3f(-50,-41,4);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 4
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,-41,4);
	glVertex3f(50,-41,4);
	glVertex3f(50,-42,4);
	glVertex3f(-50,-42,4);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 5
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,-42,4);
	glVertex3f(50,-42,4);
	glVertex3f(50,-42,5);
	glVertex3f(-50,-42,5);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 5
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,-42,5);
	glVertex3f(50,-42,5);
	glVertex3f(50,-43,5);
	glVertex3f(-50,-43,5);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 6
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,-43,5);
	glVertex3f(50,-43,5);
	glVertex3f(50,-43,6);
	glVertex3f(-50,-43,6);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 6
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,-43,6);
	glVertex3f(50,-43,6);
	glVertex3f(50,-44,6);
	glVertex3f(-50,-44,6);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 7
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,-44,6);
	glVertex3f(50,-44,6);
	glVertex3f(50,-44,7);
	glVertex3f(-50,-44,7);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 7
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,-44,7);
	glVertex3f(50,-44,7);
	glVertex3f(50,-45,7);
	glVertex3f(-50,-45,7);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 8
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,-45,7);
	glVertex3f(50,-45,7);
	glVertex3f(50,-45,8);
	glVertex3f(-50,-45,8);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 8
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,-45,8);
	glVertex3f(50,-45,8);
	glVertex3f(50,-46,8);
	glVertex3f(-50,-46,8);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 9
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,-46,8);
	glVertex3f(50,-46,8);
	glVertex3f(50,-46,9);
	glVertex3f(-50,-46,9);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 9
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,-46,9);
	glVertex3f(50,-46,9);
	glVertex3f(50,-47,9);
	glVertex3f(-50,-47,9);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 10
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,-47,9);
	glVertex3f(50,-47,9);
	glVertex3f(50,-47,10);
	glVertex3f(-50,-47,10);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 10
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,-47,10);
	glVertex3f(50,-47,10);
	glVertex3f(50,-48,10);
	glVertex3f(-50,-48,10);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 11
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,-48,10);
	glVertex3f(50,-48,10);
	glVertex3f(50,-48,11);
	glVertex3f(-50,-48,11);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 11
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,-48,11);
	glVertex3f(50,-48,11);
	glVertex3f(50,-52,11);
	glVertex3f(-50,-52,11);
	glEnd();
	//Kursi Penonton Sayap Kiri:>
	glBegin(GL_QUADS);//bottom
        glColor3f(1.99,0,3);
	glVertex3f(-50,37,0);
	glVertex3f(50,37,0);
	glVertex3f(50,52,0);
	glVertex3f(-50,52,0);
	glEnd();
	glBegin(GL_QUADS);//back
        glColor3d(0.5,0.7,0.6);
	glVertex3f(-50,52,0);
	glVertex3f(50,52,0);
	glVertex3f(50,52,26);
	glVertex3f(-50,52,26);
	glEnd();
	glBegin(GL_POLYGON);//side 1
        glColor3f(0.80,0,0);
	glVertex3f(50,37,0);
	glVertex3f(50,37,1);
	glVertex3f(50,39,1);
	glVertex3f(50,39,2);
	glColor3f(0.60,0,0);
	glVertex3f(50,47,10);
	glVertex3f(50,47,11);
	glVertex3f(50,52,11);
	glVertex3f(50,52,11);
	glVertex3f(50,52,0);
	glEnd();
	glBegin(GL_POLYGON);//side 2
        glColor3f(0.80,0,0);
	glVertex3f(-50,37,0);
	glVertex3f(-50,37,1);
	glVertex3f(-50,39,1);
	glVertex3f(-50,39,2);
	glColor3f(0.60,0,0);
	glVertex3f(-50,47,10);
	glVertex3f(-50,47,11);
	glVertex3f(-50,52,11);
	glVertex3f(-50,52,11);
	glVertex3f(-50,52,0);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 1
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,37,0);
	glVertex3f(50,37,0);
	glVertex3f(50,37,1);
	glVertex3f(-50,37,1);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 1
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,37,1);
	glVertex3f(50,37,1);
	glVertex3f(50,39,1);
	glVertex3f(-50,39,1);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 2
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,39,1);
	glVertex3f(50,39,1);
	glVertex3f(50,39,2);
	glVertex3f(-50,39,2);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 2
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,39,2);
	glVertex3f(50,39,2);
	glVertex3f(50,40,2);
	glVertex3f(-50,40,2);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 3
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,40,2);
	glVertex3f(50,40,2);
	glVertex3f(50,40,3);
	glVertex3f(-50,40,3);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 3
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,40,3);
	glVertex3f(50,40,3);
	glVertex3f(50,41,3);
	glVertex3f(-50,41,3);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 4
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,41,3);
	glVertex3f(50,41,3);
	glVertex3f(50,41,4);
	glVertex3f(-50,41,4);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 4
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,41,4);
	glVertex3f(50,41,4);
	glVertex3f(50,42,4);
	glVertex3f(-50,42,4);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 5
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,42,4);
	glVertex3f(50,42,4);
	glVertex3f(50,42,5);
	glVertex3f(-50,42,5);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 5
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,42,5);
	glVertex3f(50,42,5);
	glVertex3f(50,43,5);
	glVertex3f(-50,43,5);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 6
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,43,5);
	glVertex3f(50,43,5);
	glVertex3f(50,43,6);
	glVertex3f(-50,43,6);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 6
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,43,6);
	glVertex3f(50,43,6);
	glVertex3f(50,44,6);
	glVertex3f(-50,44,6);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 7
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,44,6);
	glVertex3f(50,44,6);
	glVertex3f(50,44,7);
	glVertex3f(-50,44,7);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 7
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,44,7);
	glVertex3f(50,44,7);
	glVertex3f(50,45,7);
	glVertex3f(-50,45,7);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 8
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,45,7);
	glVertex3f(50,45,7);
	glVertex3f(50,45,8);
	glVertex3f(-50,45,8);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 8
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,45,8);
	glVertex3f(50,45,8);
	glVertex3f(50,46,8);
	glVertex3f(-50,46,8);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 9
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,46,8);
	glVertex3f(50,46,8);
	glVertex3f(50,46,9);
	glVertex3f(-50,46,9);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 9
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,46,9);
	glVertex3f(50,46,9);
	glVertex3f(50,47,9);
	glVertex3f(-50,47,9);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 10
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,47,9);
	glVertex3f(50,47,9);
	glVertex3f(50,47,10);
	glVertex3f(-50,47,10);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 10
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,47,10);
	glVertex3f(50,47,10);
	glVertex3f(50,48,10);
	glVertex3f(-50,48,10);
	glEnd();
	glBegin(GL_QUADS);//Kursi Lvl 11
        glColor3f(0.5,1,0.6);
	glVertex3f(-50,48,10);
	glVertex3f(50,48,10);
	glVertex3f(50,48,11);
	glVertex3f(-50,48,11);
	glEnd();
	glBegin(GL_QUADS);//kursi lvl 11
        glColor3f(0.5,0.6,1);
	glVertex3f(-50,48,11);
	glVertex3f(50,48,11);
	glVertex3f(50,52,11);
	glVertex3f(-50,52,11);
	glEnd();
}

void lawang(void){
    glBegin(GL_POLYGON);//pojok kiri bawah
    glColor3d(0.5,0.7,0.6);
    glVertex3d(-70,-32,26);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(-66,-40,26);
    glVertex3d(-66,-40,0);
    glVertex3d(-70,-32,0);
    glEnd();
    glBegin(GL_POLYGON);//tengah
    glColor3d(0.5,0.7,0.6);
    glVertex3d(-66,-40,26);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(-58,-48,26);
    glVertex3d(-58,-48,5);
    glVertex3d(-66,-40,5);
    glEnd();
    glBegin(GL_POLYGON);//kanan
    glColor3d(0.5,0.7,0.6);
    glVertex3d(-58,-48,26);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(-50,-52,26);
    glVertex3d(-50,-52,0);
    glVertex3d(-58,-48,0);
    glEnd();
    glBegin(GL_LINE_STRIP);//garis pintu
    glColor3d(0,0,0);//
    glVertex3d(-58,-48,0);
    glVertex3d(-58,-48,5);
    glVertex3d(-66,-40,5);
    glVertex3d(-66,-40,0);
    glEnd();

    glBegin(GL_POLYGON);//pojok kanan bawah
    glColor3d(0.5,0.7,0.6);
    glVertex3d(70,-32,26);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(66,-40,26);
    glVertex3d(66,-40,0);
    glVertex3d(70,-32,0);
    glEnd();
    glBegin(GL_POLYGON);//pintu tengah
    glColor3d(0.5,0.7,0.6);
    glVertex3d(66,-40,26);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(58,-48,26);
    glVertex3d(58,-48,5);
    glVertex3d(66,-40,5);
    glEnd();
    glBegin(GL_POLYGON);//kiri
    glColor3d(0.5,0.7,0.6);
    glVertex3d(58,-48,26);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(50,-52,26);
    glVertex3d(50,-52,0);
    glVertex3d(58,-48,0);
    glEnd();
    glBegin(GL_LINE_STRIP);//garis pintu
    glColor3d(0,0,0);
    glVertex3d(58,-48,0);
    glVertex3d(58,-48,5);
    glVertex3d(66,-40,5);
    glVertex3d(66,-40,0);
    glEnd();
	
    glBegin(GL_POLYGON);//pojok kiri atas
    glColor3d(0.5,0.7,0.6);
    glVertex3d(-70,32,26);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(-66,40,26);
    glVertex3d(-66,40,0);
    glVertex3d(-70,32,0);
    glEnd();
    glBegin(GL_POLYGON);//pintu tengah
    glColor3d(0.5,0.7,0.6);
    glVertex3d(-66,40,26);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(-58,48,26);
    glVertex3d(-58,48,5);
    glVertex3d(-66,40,5);
    glEnd();
    glBegin(GL_POLYGON);//kanan
    glColor3d(0.5,0.7,0.6);
    glVertex3d(-58,48,26);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(-50,52,26);
    glVertex3d(-50,52,0);
    glVertex3d(-58,48,0);
    glEnd();
    glBegin(GL_LINE_STRIP);//garis pintu
    glColor3d(0,0,0);
    glVertex3d(-58,48,0);
    glVertex3d(-58,48,5);
    glVertex3d(-66,40,5);
    glVertex3d(-66,40,0);
    glEnd();
	
    glBegin(GL_POLYGON);//pojok kanan atas
    glColor3d(0.5,0.7,0.6);
    glVertex3d(70,32,26);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(66,40,26);
    glVertex3d(66,40,0);
    glVertex3d(70,32,0);
    glEnd();
    glBegin(GL_POLYGON);//pintu tengah
    glColor3d(0.5,0.7,0.6);
    glVertex3d(66,40,26);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(58,48,26);
    glVertex3d(58,48,5);
    glVertex3d(66,40,5);
    glEnd();
    glBegin(GL_POLYGON);//kiri
    glColor3d(0.5,0.7,0.6);
    glVertex3d(58,48,26);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(50,52,26);
    glVertex3d(50,52,0);
    glVertex3d(58,48,0);
    glEnd();
    glBegin(GL_LINE_STRIP);//garis pintu
    glColor3d(0,0,0);
    glVertex3d(58,48,0);
    glVertex3d(58,48,5);
    glVertex3d(66,40,5);
    glVertex3d(66,40,0);
    glEnd();

}

void atap(void){
	
    glBegin(GL_POLYGON);//Pojok kiri bawah,tengah atas
    glColor3d(0.5,0.7,0.6);
    glVertex3d(-54,-32,30);
    glVertex3d(-50,-36,30);
    glVertex3d(-50,-44,30);
    glVertex3d(-62,-32,30);
    glEnd();
    glBegin(GL_TRIANGLES);//Pojok kiri,kiri
    glColor3d(0.5,0.7,0.6);
    glVertex3d(-70,-32,26);
    glVertex3d(-66,-40,26);
    glVertex3d(-62,-32,30);
    glEnd();
    glBegin(GL_TRIANGLES);//Pojok kiri,kanan
    glColor3d(0.5,0.7,0.6);
    glVertex3d(-50,-52,26);
    glVertex3d(-58,-48,26);
    glVertex3d(-50,-44,30);
    glEnd();
    glBegin(GL_POLYGON);//Pojok kiri,tengah bawah
    glColor3d(0.5,0.7,0.6);
    glVertex3d(-62,-32,30);
    glVertex3d(-50,-44,30);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(-58,-48,26);
    glVertex3d(-66,-40,26);
    glEnd();
	
    glBegin(GL_POLYGON);//Pojok kiri atas,tengah atas
    glColor3d(0.5,0.7,0.6);
    glVertex3d(-54,32,30);
    glVertex3d(-50,36,30);
    glVertex3d(-50,44,30);
    glVertex3d(-62,32,30);
    glEnd();
    glBegin(GL_TRIANGLES);//Pojok kiri,kiri
    glColor3d(0.5,0.7,0.6);
    glVertex3d(-70,32,26);
    glVertex3d(-66,40,26);
    glVertex3d(-62,32,30);
    glEnd();
    glBegin(GL_TRIANGLES);//Pojok kiri,kanan
    glColor3d(0.5,0.7,0.6);
    glVertex3d(-50,52,26);
    glVertex3d(-58,48,26);
    glVertex3d(-50,44,30);
    glEnd();
    glBegin(GL_POLYGON);//Pojok kiri,tengah bawah
    glColor3d(0.5,0.7,0.6);
    glVertex3d(-62,32,30);
    glVertex3d(-50,44,30);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(-58,48,26);
    glVertex3d(-66,40,26);
    glEnd();
	
    glBegin(GL_POLYGON);//Pojok kanan bawah,tengah atas
    glColor3d(0.5,0.7,0.6);
    glVertex3d(54,-32,30);
    glVertex3d(50,-36,30);
    glVertex3d(50,-44,30);
    glVertex3d(62,-32,30);
    glEnd();
    glBegin(GL_TRIANGLES);//Pojok kanan,kanan
    glColor3d(0.5,0.7,0.6);
    glVertex3d(70,-32,26);
    glVertex3d(66,-40,26);
    glVertex3d(62,-32,30);
    glEnd();
    glBegin(GL_TRIANGLES);//Pojok kanan,kiri
    glColor3d(0.5,0.7,0.6);
    glVertex3d(50,-52,26);
    glVertex3d(58,-48,26);
    glVertex3d(50,-44,30);
    glEnd();
    glBegin(GL_POLYGON);//Pojok kanan,tengah bawah
    glColor3d(0.5,0.7,0.6);
    glVertex3d(62,-32,30);
    glVertex3d(50,-44,30);
    glColor3d(0.5,0.8,0.7);
    glVertex3d(58,-48,26);
    glVertex3d(66,-40,26);
    glEnd();	
	
}

void display(void)
{
    if (is_depth)
        tampil();
    else
        hilang();
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{


{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}
tampil();
}

void posenggggg()
{
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f,0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}

void mouseMotion(int x, int y)
{
    posenggggg();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();

    }
}

void keyboard(unsigned char key, int x, int y)
{

    switch(key)
    {
        case 'w':
        case 'W':
            glTranslated(0,0,3);
            break;
        case 'd':
        case 'D':
            glTranslated(3,0,0);
            break;
        case 's':
        case 'S':
            glTranslated(0,0,-3);
            break;
        case 'a':
        case 'A':
            glTranslated(-3,0,0);
            break;
        case '7':
            glTranslated(0,3,0);
            break;
        case '9':
            glTranslated(0,-3,0);
            break;
        case '2':
            glRotated(2,1,0,0);
            break;
        case '8':
            glRotated(-2,1,0,0);
            break;
        case '6':
            glRotated(2,0,1,0);
            break;
        case '4':
            glRotated(-2,1,0,0);
            break;
        case '1':
            glRotated(2,0,0,1);
            break;
        case '3':
            glRotated(-2,0,0,1);
            break;
        case '5':
            if (is_depth)
            {
                is_depth = 0;
                tampil();
            }
            else
            {
                is_depth = 1;
                hilang();
            }
    }
    display();
}

void ukuran(int lebar, int tinggi)
{
    if(tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(-3.5, -15.0, -100.0);
    glMatrixMode(GL_MODELVIEW);
}
