/*Nabil,MD.Tanjilur Rahaman 12-21151-1
Khan,Asif Ahmed  12-21158-1*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include<time.h>
using namespace std;
#define PI 3.1416
float posX=10,posY=0,posZ=0;
float missileX=0,missileY=300,missileZ=0;
bool missilestat= false,dropped=false,game=false;
int score =0;
char buffer[10];
float xx;
void scene();
void ship();
void reset();
void initmissile(int max ,int min)
{
    static bool first = true;
    if (first)
        {
            srand (time(NULL));
                first=false;
        }

	missileX= min+ rand()%(max-min);
}

void DrawCircle(float cirx, float ciry, float r, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

		float x = r * cosf(theta); 
		float y = r * sinf(theta);

		glVertex2f(x + cirx, y + ciry);

	}
	glEnd();
}

void drawoval(GLfloat x, GLfloat y, GLfloat radius)
{
    int triangleAmount = 2000; 
    float twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius/6 * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)));
            }
    glEnd();
}
void drawoval2(GLfloat x, GLfloat y, GLfloat radius)
{
    int triangleAmount = 2000; 
    float twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius/4 * sin(i * twicePi / triangleAmount)));
            }
    glEnd();
}
void drawString (void * font, char *s, float x, float y){
     glRasterPos2f(x, y);
	 glColor3f(0, 0, 1);
     for (int i = 0; i < strlen (s); i++)
          glutBitmapCharacter (font, s[i]);
}
void myInit(void)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1200.0, 0.0, 800.0);
}
void ship()
{	glPushMatrix();
	for(int i=0;i<10;i++)
	{
	glTranslatef(posX,posY,posZ);
	}
	
	glBegin(GL_POLYGON);//base
	glColor3f(.07,.45,.89);
	glVertex2i(800,300);
	glVertex2i(1000,300);
	glVertex2i(1100,400);
	glVertex2i(700,400);
	glEnd();

	glBegin(GL_POLYGON);//c1
	glColor3f(1,1,1);
	glVertex2i(800,400);
	glVertex2i(830,400);
	glVertex2i(830,470);
	glVertex2i(800,470);
	glEnd();

	glBegin(GL_POLYGON);//c11
	glColor3f(.44,.45,.43);
	glVertex2i(800,470);
	glVertex2i(830,470);
	glVertex2i(830,500);
	glVertex2i(800,500);
	glEnd();

	glBegin(GL_POLYGON);//c2
	glColor3f(1,1,1);
	glVertex2i(900,400);
	glVertex2i(930,400);
	glVertex2i(930,470);
	glVertex2i(900,470);
	glEnd();

	glBegin(GL_POLYGON);//c22
	glColor3f(.44,.45,.43);
	glVertex2i(900,470);
	glVertex2i(930,470);
	glVertex2i(930,500);
	glVertex2i(900,500);
	glEnd();

	glBegin(GL_POLYGON);//c3
	glColor3f(1,1,1);
	glVertex2i(1000,400);
	glVertex2i(1030,400);
	glVertex2i(1030,470);
	glVertex2i(1000,470);
	glEnd();

	glBegin(GL_POLYGON);//c33
	glColor3f(.44,.45,.43);
	glVertex2i(1000,470);
	glVertex2i(1030,470);
	glVertex2i(1030,500);
	glVertex2i(1000,500);
	glEnd();

	/*glBegin(GL_POLYGON);//p1
	glColor3f(1,1,1);
	glVertex2i(750,400);
	glVertex2i(1050,400);
	glVertex2i(1050,450);
	glVertex2i(750,450);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2,0.5,0.6);
	glVertex2i(740,400);
	glVertex2i(750,400);
	glVertex2i(750,450);
	glVertex2i(740,455);
	glEnd();*/
	glPopMatrix();
}

void scene()
{
	glPushMatrix();

	glBegin(GL_POLYGON); //Sky  
	glColor3f(0.4, 0.5, 1.0);
	glVertex2i(0, 800);
	glVertex2i(1200, 800);
	glColor3f(0.7, 0.7, 1.0);
	glVertex2i(1200, 0);
	glVertex2i(0, 0);
	glEnd();

	glBegin(GL_POLYGON);//sand
	glColor3f(0.94, 0.94, 0.03);
	glVertex2i(0,0);
	glVertex2i(1200,0);
	glColor3f(0.89, 0.89, 0.46);
	glVertex2i(1200,50);
	glVertex2i(0,150);
	glEnd();

	glBegin(GL_POLYGON);//ocean
	glColor3f(0.35, 0.78, .96);
	glVertex2i(0,150);
	glVertex2i(1200,50);
	glVertex2i(1200,350);
	glVertex2i(0,350);
	glEnd();

	



	glPopMatrix();

}
void drawSun()
{
	glPushMatrix();

	glColor3f(.98, .61, 0.01);
	DrawCircle(900, 700, 40, 1000);
	glPopMatrix();
}

/*void drawmissilehorizontal()
{
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);//upper
	glVertex2i(470,400);
	glVertex2i(520,400);
	glVertex2i(470,450);
	glEnd();
	drawoval2(500,400,80);
	glBegin(GL_POLYGON);//upper
	glVertex2i(470,400);
	glVertex2i(520,400);
	glVertex2i(470,350);
	glEnd();

	drawoval(700,600,80);
	glPopMatrix();
}*/
void drawmissilevertical()
{
	glPushMatrix();
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(690,630);
	glVertex2i(690,580);
	glVertex2i(640,630);
	glVertex2i(710,630);
	glVertex2i(710,580);
	glVertex2i(760,630);
	glEnd();
	glColor3f(.04,.32,0);
	drawoval(700,600,80);
	
	
	
	
	glPopMatrix();
}
void drawcloud()
{
	glPushMatrix();
	glColor3f(1,1,1);
	DrawCircle(600,700,60,1000);
	DrawCircle(530,700,40,1000);
	DrawCircle(670,700,40,1000);
	DrawCircle(200,700,45,1000);
	DrawCircle(150,700,30,1000);
	DrawCircle(250,700,30,1000);
	glPopMatrix();


}
void mouse (int button, int state, int x,int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
		missilestat = true;
		game=true;
}
}

void missile()
{
	
	if (missilestat==true)
	{
		
		missileY-=.8;
		
	}
	while (missileY<=-300)
	{
		
		missileY=300;
		initmissile(200,-600);
		dropped=true;
		
	}
	
	
	glPushMatrix();
	glTranslatef(missileX, missileY, missileZ);
	drawmissilevertical();
	glPopMatrix();
	cout<<"Y: "<<missileY<<endl;
}
void reset()
{
	posX =10;
	
}

void myDisplay(void)
{
	drawcloud();
	scene();
	drawSun();
	
	ship();
	if(posX==-110)
	{
	
	reset();
	score+=1;
	}
	missile();
	drawcloud();
	drawString(GLUT_BITMAP_9_BY_15,"Score:  ",1100,750);
	 sprintf_s(buffer,"%d", score);
	 drawString(GLUT_BITMAP_9_BY_15,buffer,1150,750);
	cout << "POSX: "<<posX<<endl;

	

	glFlush();

	glutPostRedisplay();
	glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
	if(game==true)
	{
	if(key == 'a')
	{
		posX--;
	}
	else if(key == 'd')
	{
		posX++;
	}
	}
	
	glutPostRedisplay();
}

void main(int argc, char** argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1350, 700);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Escape");
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}