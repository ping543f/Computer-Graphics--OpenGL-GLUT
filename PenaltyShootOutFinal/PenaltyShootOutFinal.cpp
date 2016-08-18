// PenaltyShootOut.cpp : Defines the entry point for the console application.
//

    	/*SUBJECT-COMPUTER GRAPHICS(C)
----------------------------------------
		NAME				ID           PHONE
    --------------------------------------------
	 1)AHAMED SAJIB------(13-24921-3)--01935294900
	 2)ROY,PROTICK-------(13-24956-3)--01861320771
	 3)RAHMAN,MAHBUBUR---(13-25047-3)--01673595182*/





#include "stdafx.h"
#include<stdlib.h>  //random function 
#include <Windows.h> //for Sleep function  
#include <iostream>
#include <GL/glut.h>
#include <ctime>	//time duration 
using namespace std;

static int i=0;
const int sides = 360;  // The number of edges
const double radius = 40; // The radius of the circle (Foot Ball)

static double moveBall=0;
static double kickBall = 0;
double shotPower=0;

static double ballx=0;
static double bally=0;

static double goalKeeperx=700;
static double goalKeepery=832;

static int score=0;
char scoreBuffer[10];

void Field();
void DrawFootball();

//Screen Text
void drawScoreText(char ch[], int xPos, int yPos) //"Score" Text 
{
	int numOfChar = strlen(ch);
	glLoadIdentity();

	glColor3ub(0, 191, 255);
	glRasterPos2i(xPos, yPos);
	for (int i = 0; i <= numOfChar; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ch[i]); //Selects font.
	}
}

void drawScoreNum(int numText, int xPos, int yPos) //Score "Counter"
{
	sprintf_s(scoreBuffer,"%d",numText);
	int k = 0;
	glLoadIdentity();

	glColor3ub(255, 255, 255);
	glRasterPos2i(xPos, yPos);
	for(int i=0;i<strlen(scoreBuffer);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,scoreBuffer[i]);
	}
}

void drawText(char ch[], int xPos, int yPos) //!!!!!!!!!!Goal!!!!!!!!! text
{
	int numOfChar = strlen(ch);
	glLoadIdentity();

	glColor3ub(255, 165, 0);
	glRasterPos2i(xPos, yPos);
	for (int i = 0; i <= numOfChar; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ch[i]); //Selects font.
	}
}
//Screen Text

void Reset()  //Reset function to reset football position
{
				ballx=0;
				bally=0;
				moveBall = 0;
				kickBall = 0;
				DrawFootball();
}

void GoalKeeper()  //goal keeper// random movement along x axis only, y fixed
{
	//int lowv=550;
	//int highv=850;
	//int rvalue1,rvalue2;
	//rvalue1=(rand()%(highv-lowv+1)+lowv);
	//rvalue2=(rand()%(highv-lowv+1)+lowv);
	//


	glPushMatrix();
	glPointSize(10.0);
	//glTranslatef(rvalue1,840,0);
	glBegin(GL_POINTS);

	glColor3ub(234,127,255);
	glVertex2i(700,865);
	
	glColor3ub(255,0,255);
	glVertex2i(680,850);

	glColor3ub(255,0,255);
	glVertex2i(680,842);
	
	glColor3ub(255,0,255);
	glVertex2i(720,850);
	
	glColor3ub(255,0,255);
	glVertex2i(720,842);
	
	glColor3ub(234,127,255);
	glVertex2i(690,834);
	
	glColor3ub(234,127,255);
	glVertex2i(710,834);
	
	glColor3ub(234,127,255);
	glVertex2i(690,832);
	
	glColor3ub(234,127,255);
	glVertex2i(710,832);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glBegin(GL_POLYGON);
	glColor3ub(234,127,255);
	glVertex2i(680,860);
	glVertex2i(680,840);
	glVertex2i(720,840);
	glVertex2i(720,860);
	glEnd();
	
	
	glPopMatrix();
	glEnd();
	glFlush();


}

void DrawFootball(void) //Drawing Football and Translation into middle of screen
{
	glPushMatrix();
	glColor3ub(102, 140, 255);
	glTranslatef(700+moveBall, 250+kickBall, 0); //to center and along y axis 
	
	glBegin(GL_POLYGON);
	for (int a = 0; a < 360; a += 360 / sides)
	{
		double heading = a * 3.1415926535897932384626433832795 / 180;
		glVertex2f(cos(heading) * radius, sin(heading) * radius);
	}
	glEnd();
	glPopMatrix();

	//collision detection between Football and Goal Post//
	if((ballx>680 &&ballx <720) && bally>=832)
	{
				drawText("!!!!!!!!!!!!!!!!Nice Save!!!!!!!!!!!!!!!!", 500, 450);//with goal keeper
	}

	if(((ballx> 570 && ballx < 680 ) || ( ballx>720 && ballx <850 )) && bally>=850 )
	{
		drawText("!!!!!!!!!!!!!!!!GOAL!!!!!!!!!!!!!!!!", 500, 450); //with goal post
	}

	glutSwapBuffers();
	glutPostRedisplay();
} 



void MousePress(int button,int state, int x, int y)//Mouse Interaction
{
	if (button == GLUT_LEFT_BUTTON && state==GLUT_DOWN) 
	{
		for (i = 0; i <= 60; i++)
		{
			kickBall=kickBall+10;
			Field();//too much important , just to remove older balls // :p
			GoalKeeper();
			DrawFootball();
			ballx=700+moveBall;
			bally=250+kickBall;
			glutPostRedisplay();
			Sleep(20);
			
			glutSwapBuffers();
		}
		//glutPostRedisplay();
	}
		if(button == GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
			{
			if(bally >= 850 && ((ballx > 570 && ballx < 680 ) || ( ballx > 720 && ballx < 850 )) )
				{
					score++;
				}
				Reset();
				cout<<"Score: "<<score<<endl;
			}
}

//keyBoard interaction
void KeyboardPress(int key,int x,int y)
{
	if(key==27)
            exit(0);
    if(key==GLUT_KEY_RIGHT)
    	{
		moveBall += 10;
		DrawFootball();
		glutPostRedisplay();
	}
    if(key==GLUT_KEY_LEFT)
      	{
		moveBall -= 10;
		DrawFootball();
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_UP)
	 {
	/*shotPower += 10;*/
	 }
	if (key == GLUT_KEY_DOWN)
            shotPower -= 10;
}

//Drawing Field along with post and lines
void Field() 
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	//entire Field
	glBegin(GL_QUADS);
	glColor3ub(0,100,0);
	glVertex2i(0,0);
	glVertex2i(1360,0);
	glVertex2i(1360,930);
	glVertex2i(0,930);
	glEnd();

	//whole white Boundary
	glBegin(GL_LINE_LOOP);
	glLineWidth(10);
	glColor3ub(255,255,255);
	glVertex2i(200,10);
	glVertex2i(1200,10);
	glVertex2i(1200,870);
	glVertex2i(200,870);
	glVertex2i(200,10);
	glEnd();

	//half circle middle of the field
	glPushMatrix(); //push here mid circle
	glColor3ub(255,255,255);
	glLineWidth(3);
	glTranslatef(700,-20,0);
	glBegin(GL_LINE_STRIP);
	int radius1=150;
	  for (int a = 0; a < 360; a += 360 / sides)
	  {
		double heading = a * 3.1415926535897932384626433832795 / 180;
		glVertex2f(cos(heading) * radius1, sin(heading) * radius1);
	  }
	glEnd();
	glPopMatrix();//pop after mid circle

	//goal Post
	glBegin(GL_POLYGON);
	glPointSize(1);
	glColor3ub(192,192,192);
	glVertex2i(570,870);
	glVertex2i(830,870);
	glVertex2i(830,920);
	glVertex2i(570,920);
	glEnd();
	glFlush();

	//DBOX
	glColor3ub(225,225,225);
	glBegin(GL_LINE_STRIP);
	glVertex2i(550,870);
	glVertex2i(550,700);
	glVertex2i(850,700);
	glVertex2i(850,870);
	glEnd();
	drawScoreText("Score", 1220,800);
	drawScoreNum(score, 1300,800);
	glFlush();
}

void MyDisplay() //********Display Function********Starting point**********Display********
{
	Field();
	GoalKeeper();
	DrawFootball(); //Football drawing
	glFlush();
}


void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(10);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1368.0, 0.0, 940.0); //measure of field , in pixels 
}

void main(int argc, char** argv) //Main Function //
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize (1108, 940);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Penalty Shoot Out");

	glutDisplayFunc(MyDisplay);
	glutMouseFunc(MousePress);
	glutSpecialFunc(KeyboardPress);
	
	myInit ();
	glutMainLoop();
}


