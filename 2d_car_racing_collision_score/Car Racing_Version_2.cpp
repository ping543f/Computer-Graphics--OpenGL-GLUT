/*
Monzur,MD.Shohag (14-27883-3)
Hasan,SM Amit (14-27794-3)
Ghose,Amit (12-21250-2)
Rahman,Md Mahmudur (14-26447-1)
*/


#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <GL/glut.h>
#include <stdio.h>
#include<time.h>
#include<iostream>
using namespace std;
#pragma region

static int score=0;


int x1 = 0;
int x2 = 0;
int y1 = 0;
int y2 = 0;
int Cx1 = 0;
int Cy1 = 0;

float move_unit = 140;

int carpos=0;

float rtri = 0;
float rtriC = -700;     //intisl point
float rtriC1 = -700;

float view = 10.0;

char quote[6][80];
int numberOfQuotes = 0, i;


void keyboardown(int key, int x, int y)
{
	switch (key){

	case GLUT_KEY_RIGHT:
	   if(carpos ==0){
		x1 += move_unit;
		glutPostRedisplay();
		carpos=1;
		break;
	   }else{break;}

	case GLUT_KEY_LEFT:
		if(carpos==1){
		   x1 -= move_unit;
		   glutPostRedisplay();
		   carpos=0;
		   break;
		}else{break;}

	default:
		break;

	}
}

void drawOwnCar(float ax1, float ay1)
{

	glBegin(GL_QUADS); //Car front
	glColor3ub(255, 250, 0);
	glVertex2f(ax1 + 110, ay1 + 465);
	glVertex2f(ax1 + 120, ay1 + 455);
	glVertex2f(ax1 + 80, ay1 + 455);
	glVertex2f(ax1 + 90, ay1 + 465);
	glEnd();

	glBegin(GL_QUADS); // Car middle
	glColor3ub(255,180,0);
	glVertex2f(ax1 + 120, ay1 + 380);
	glVertex2f(ax1 + 120, ay1 + 455);
	glVertex2f(ax1 + 80, ay1 + 455);
	glVertex2f(ax1 + 80, ay1 + 380);
	glEnd();

	glBegin(GL_QUADS); // Car back
	glColor3ub(255, 250, 0);
	glVertex2f(ax1 + 110, ay1 + 360);
	glVertex2f(ax1 + 120, ay1 + 380);
	glVertex2f(ax1 + 80, ay1 + 380);
	glVertex2f(ax1 + 90, ay1 + 360);
	glEnd();

}

void drawRoad()
{
    glBegin(GL_POLYGON);
    glColor3ub(128, 128 ,128);
		glVertex3f(350, 0, 0.0);
		glVertex3f(600, 0, 0.0);
		glVertex3f(600, 768, 0.0);
		glVertex3f(350, 768, 0.0);
    glEnd();
}

void trafficline()
{
		glTranslatef(60,+rtri,0);

		glBegin(GL_POLYGON);
		    glColor3f(0,0,0);
			glVertex2f(100,-280);
			glVertex2f(110, -280);
			glVertex2f(110, -180);
			glVertex2f(100, -180);
		glEnd();

	        glBegin(GL_POLYGON);
			glVertex2f(100,-400);
			glVertex2f(110, -400);
			glVertex2f(110, -300);
			glVertex2f(100, -300);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(100,-520);
			glVertex2f(110, -520);
			glVertex2f(110, -420);
			glVertex2f(100, -420);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(100,-640);
			glVertex2f(110, -640);
			glVertex2f(110, -540);
			glVertex2f(100, -540);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(100,-680);
			glVertex2f(110, -680);
			glVertex2f(110, -780);
			glVertex2f(100, -780);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(100,-60);
			glVertex2f(110, -60);
			glVertex2f(110, -160);
			glVertex2f(100, -160);
		glEnd();

		//.........................................................

		glBegin(GL_POLYGON);
			glVertex2f(100,-40);
			glVertex2f(110, -40);
			glVertex2f(110, 60);
			glVertex2f(100, 60);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(100,80);
			glVertex2f(110, 80);
			glVertex2f(110, 180);
			glVertex2f(100, 180);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(100,200);
			glVertex2f(110, 200);
			glVertex2f(110, 300);
			glVertex2f(100, 300);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(100,320);
			glVertex2f(110, 320);
			glVertex2f(110, 420);
			glVertex2f(100, 420);
		glEnd();

		glBegin(GL_POLYGON);
			glVertex2f(100,440);
			glVertex2f(110, 440);
			glVertex2f(110, 540);
			glVertex2f(100, 540);
		glEnd();

		rtri+=18;   //speed
		if(rtri>100)
		{
			rtri=-1;
		}
}
void opCar1(float cx1, float cy1)
{
	//glTranslatef(135,+rtriC,0);
	glBegin(GL_QUADS); //Car front
	glColor3ub(230, 0, 0);
	glVertex2f(cx1 + 110, cy1 + 465);
	glVertex2f(cx1 + 120, cy1 + 455);
	glVertex2f(cx1 + 80, cy1 + 455);
	glVertex2f(cx1 + 90, cy1 + 465);
	glEnd();

	glBegin(GL_QUADS); // Car middle
	glColor3ub(1, 1, 1);
	glVertex2f(cx1 + 120, cy1 + 380);
	glVertex2f(cx1 + 120, cy1 + 455);
	glVertex2f(cx1 + 80, cy1 + 455);
	glVertex2f(cx1 + 80, cy1 + 380);
	glEnd();

	glBegin(GL_QUADS); // Car back
	glColor3ub(230, 0, 0);
	glVertex2f(cx1 + 110, cy1 + 360);
	glVertex2f(cx1 + 120, cy1 + 380);
	glVertex2f(cx1 + 80, cy1 + 380);
	glVertex2f(cx1 + 90, cy1 + 360);
	glEnd();

		rtriC+=10;     //speed car
		if(rtriC>1400)
		{
			rtriC=-700;
		}
}

void opCar2(float cx1, float cy1)
{

	glBegin(GL_QUADS); //Car front
	glColor3ub(230,0,0);
	glVertex2f(cx1 + 110, cy1 + 465);
	glVertex2f(cx1 + 120, cy1 + 455);
	glVertex2f(cx1 + 80, cy1 + 455);
	glVertex2f(cx1 + 90, cy1 + 465);
	glEnd();

	glBegin(GL_QUADS); // Car middle
	glColor3ub(1,1,1);
	glVertex2f(cx1 + 120, cy1 + 380);
	glVertex2f(cx1 + 120, cy1 + 455);
	glVertex2f(cx1 + 80, cy1 + 455);
	glVertex2f(cx1 + 80, cy1 + 380);
	glEnd();

	glBegin(GL_QUADS); // Car back
	glColor3ub(230, 0, 0);
	glVertex2f(cx1 + 110, cy1 + 360);
	glVertex2f(cx1 + 120, cy1 + 380);
	glVertex2f(cx1 + 80, cy1 + 380);
	glVertex2f(cx1 + 90, cy1 + 360);
	glEnd();

		rtriC1+=20;
		if(rtriC1>1400)
		{
			rtriC1=-700;
		}
}
void roadBoarder()
{
	glBegin(GL_POLYGON);
		    glColor3ub(59,61,63);
			glVertex2f(30,-280);
			glVertex2f(40, -280);
			glVertex2f(40, 500);
			glVertex2f(30, 500);
	glEnd();

	glBegin(GL_POLYGON);
		    glColor3ub(59,61,63);
			glVertex2f(300,-280);
			glVertex2f(290, -280);
			glVertex2f(290, 500);
			glVertex2f(300, 500);
	glEnd();
}


void myInit(void)
{
	glClearColor(0, .6, 1, 1);


	glColor3f(1, 1, 1);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 900, 750, 0.0);
}

void update(int value)
{
	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 1.0, 3200);
	glMatrixMode(GL_MODELVIEW);
}

GLfloat UpwardsScrollVelocity = -10.0;

void timeTick(void)
{
	if (UpwardsScrollVelocity< -600)
		view -= 0.000011;
	if (view < 0) { view = 20; UpwardsScrollVelocity = -10.0; }
	//  exit(0);
	UpwardsScrollVelocity -= 0.1;
	glutPostRedisplay();
}


void RenderToDisplay()
{
	int l, lenghOfQuote, i;

	glTranslatef(0.0, -100, UpwardsScrollVelocity);
	glRotatef(-20, 1.0, 0.0, 0.0);
	glScalef(0.1, 0.1, 0.1);

	for (l = 0; l<numberOfQuotes; l++)
	{
		lenghOfQuote = (int)strlen(quote[l]);
		glPushMatrix();
		glTranslatef(-(lenghOfQuote * 37), -(l * 200), 0.0);
		for (i = 0; i < lenghOfQuote; i++)
		{
			glColor3f((UpwardsScrollVelocity / 10) + 300 + (l * 10), (UpwardsScrollVelocity / 10) + 300 + (l * 10), 0.0);
			glutStrokeCharacter(GLUT_STROKE_ROMAN, quote[l][i]);
		}
		glPopMatrix();
	}
}




void myDisplayFunction(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 30.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	RenderToDisplay();
	glutSwapBuffers();
}

void drawString1 (void * font, char *s, float x, float y){ //score word
     glRasterPos2f(x, y);
	 glColor3f(255, 0, 0);
     for (int i = 0; i < strlen (s); i++)
          glutBitmapCharacter (font, s[i]);
}

void drawString (void * font, int s,int spc, float x, float y){ //scoreFunction
     glRasterPos2f(x, y);
	 glColor3f(255, 0, 0);
	  int k=0,j=0;
     while(s>9){

            k=s%10;
        glRasterPos2f((x-(j*spc)), y);
        glutBitmapCharacter (font, 48+k);
        j++;
        s=s/10;

     }
        glRasterPos2f((x-(j*spc)), y);
        glutBitmapCharacter (font, 48+s);
     }


int winner(char a)
{


	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1360, 750);
	glutCreateWindow("GAME OVER");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glLineWidth(3);
	char c=char(score);
	strcpy(quote[0], "Game Over");
	numberOfQuotes = 5;
	glutDisplayFunc(myDisplayFunction);
	glutReshapeFunc(reshape);
	glutIdleFunc(timeTick);
	glutMainLoop();

	return 0;
}

bool collision()
{

	if (y1  == Cy1 -(rtriC1-200) && Cy1 -(rtriC1-200) == y1  && carpos==0)
	{
		return true;
	}

	else if (y1  == Cy1 -(rtriC1-900) && Cy1 -(rtriC1-900) == y1  && carpos==0)
	{
		return true;
	}

	else if (y1  == Cy1 -(rtriC1-560) && Cy1 -(rtriC1-560) == y1  && carpos==1)
	{
		return true;
	}

	else{

        return false;
	}
}

int scorepoint()
{

    if (y1  == Cy1 -(rtriC1-200) && Cy1 -(rtriC1-200) == y1  && carpos==1)
	{

        score++;
	}

	else if (y1  == Cy1 -(rtriC1-900) && Cy1 -(rtriC1-900) == y1  && carpos==1)
	{
    score++;
	}


	else if (y1  == Cy1 -(rtriC1-560) && Cy1 -(rtriC1-560) == y1  && carpos==0)
	{
    score++;
	}
	else{
            return 0;

        }
}


void drawScence()
{
	glPushMatrix();
    glTranslatef(305, 250, 0); //Initial car position
	drawOwnCar(x1, y1);
	glPopMatrix();

	glPushMatrix();				//Road Lane Line
	glTranslatef(310, 250, 0); //Lane position
    trafficline();
	glPopMatrix();

	glPushMatrix();				//Road Boarder
	glTranslatef(310, 250, 0); //Road Boarder Lane position
    roadBoarder();
	glPopMatrix();

	glPushMatrix();				//2nd Car *
	glTranslatef(445,+rtriC-350,0);
    opCar1( Cx1,  Cy1);
	glPopMatrix();

	glPushMatrix();				//1st Car *
	glTranslatef(305,+rtriC,0);
    opCar1( Cx1,  Cy1);
	glPopMatrix();

	glPushMatrix();				//3rd Car
	glTranslatef(305,+rtriC1-700,0);
    opCar2( Cx1,  Cy1);
	glPopMatrix();
}

void myDisplay(void)

{
	char a = '1';
	char b = '2';

	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    drawString(GLUT_BITMAP_TIMES_ROMAN_24,score,10,160,100);
    drawString1(GLUT_BITMAP_TIMES_ROMAN_24,"Score :",100,100);

        collision();
	if(collision())
    {
        winner(a);
    }else{

        scorepoint();

    }

    drawRoad();
    drawScence();

	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1600, 688);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Final Project");
	glutDisplayFunc(myDisplay);
	myInit();
	glutTimerFunc(60, update, 0); // timer
	glutSpecialFunc(keyboardown);
	glutMainLoop();
	return 0;
}