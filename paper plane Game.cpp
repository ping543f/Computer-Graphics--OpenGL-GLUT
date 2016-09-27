/*  1.Faize, Md.Sadik(12-20636-1)
    2.Hedayet,Tahmida(12-20368-1)
    3.Abedin, Md. Rashedul(12-20142-1)*/



#include<iostream>
#include <stdio.h>
#include<string>
#include<math.h>
//#include<windows.h>
#include <GL/glut.h>
using namespace std;


void init();
void myDisplay();
void myInit();

void plane();
void box();

std::string scoring;
int score=0;

int count_r=0;

int x=0;
int y=0;


int px=0;
int px1=0;
int px2=0;
int px3=0;
int py=0;
int pyvmax=0;
int pyvmin=0;
int py1=0;
int py2=0;
int py3=0;


int bx=0;
int bxmax=0;
int bxmin=0;
int by=0;
int bymax=0;
int bymin=0;

void init() {
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 1350, 0, 650);
}

void drawScore(const char *text ){


	int x = 280, y = 380;

	glColor3f(1, 0, 0);
	glRasterPos2f(x, y);
	while (*text) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
		text++;
	}

}

void drawGameOverText(){
	
	glColor3f(255, 0, 0);
	/*glBegin(GL_POLYGON);
		glVertex2i(30, 70);
		glVertex2i(220, 70 );
		glVertex2i(220, 150);
		glVertex2i(30, 150);
	glEnd();*/


	std::string str;

	str = "Game Over!!  Press R to Retry";

	const char *text = str.data();
	int length = str.size();
	int x =200 , y = 200;

	//reference : nehe.gamedev.net/tutorial/bitmap_fonts/17002/
	glColor3f(1, 0, 0);
	glRasterPos2f(x, y);
	while (*text) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
		text++;
	}
	//glEnd();

        //glFlush ();



}

void keyboard(unsigned char key, int x, int y)
{

	if(key=='w')
	{
		 
		if(py1>bymin && py1<bymax && px1>bxmin && px1<bxmax )
		{
			bx=bx;
			by=by;
			count_r++;
			//drawGameOverText();
		}
		else if(py2>bymin && py2<bymax && px2>bxmin && px2<bxmax )
		{
			bx=bx;
			by=by;
			count_r++;
			//drawGameOverText();
		}
		else if(py3>bymin && py3<bymax && px3>bxmin && px3<bxmax )
		{
			bx=bx;
			by=by;
			count_r++;
			//drawGameOverText();
		}
		else if(pyvmax<365)
		{
			py=py+2;
			bx=bx-8;
			if(bx<-600)
		{
			bx=0;
			score++;
			by=rand()%365;
		}
		}

		else if(bx<-600)
		{
			bx=0;
			score++;
			by=rand()%365;
		}
		
		else{
		bx=bx-8;
		}

		
		glutPostRedisplay();
	}
	else if(key=='s')
	{
        if(py1>bymin && py1<bymax && px1>bxmin && px1<bxmax )
		{
			bx=bx;
			by=by;
			count_r++;
			//drawGameOverText();

		}
		else if(py2>bymin && py2<bymax && px2>bxmin && px2<bxmax )
		{
			bx=bx;
			by=by;
			count_r++;
			//drawGameOverText();
			
		}
		else if(py3>bymin && py3<bymax && px3>bxmin && px3<bxmax )
		{
			bx=bx;
			by=by;
			count_r++;
			//drawGameOverText();
		
		}
		else if(pyvmin>0)
		{
			py=py-2;
			bx=bx-8;
		if(bx<-600)
		{
			bx=0;
			score++;
			by=rand()%365;
		}
		}
		else if(bx<-600)
		{
			bx=0;
			score++;
			by=rand()%365;
		}
		else{
		bx=bx-8;
		}
		glutPostRedisplay();
	}
	else if(key=='r')
	{
		py=0;
		bx=0;
		by=0;
		score=0;
		glutPostRedisplay();
	}
	
	
}

void plane()
{
	px1=250+px;
	py1=340+py;
	pyvmax=py1;
	pyvmin=310+py;
	px2=165+px;
    py2=pyvmin;
	px3=170+px;
	py3=py1;
    glColor3f (0.747,0.747,0.747);
    glBegin(GL_POLYGON);
	glVertex2i(px2,pyvmin);
	glVertex2i(px1,py1);
	glVertex2i(170+px,340+py);
    glEnd();
	glColor3f (0.847,0.847,0.847);
	glBegin(GL_POLYGON);
	glVertex2i(160+px,330+py);
	glVertex2i(250+px,340+py);
	glVertex2i(px3,340+py);
    glEnd();
	
}
void box()
{
	bxmax = 600+bx;
	bxmin = 550+bx;
	bymax = 200+by;
    bymin = 0+by;

    glColor3f (0.165,0.012,0.411);
    glBegin(GL_POLYGON); 
	glVertex2i(bxmin,bymin);		
	glVertex2i(bxmax,bymin);
	glVertex2i(600+bx,bymax);
	glVertex2i(550+bx,bymax);
    glEnd();

	/*glColor3f (0.015,0.047,0.121);
    glBegin(GL_POLYGON); 
	glVertex2i(550+bx,-200+by);		
	glVertex2i(600+bx,-200+by);
	glVertex2i(600+bx,-100+by);
	glVertex2i(550+bx,-100+by);
    glEnd();*/
	
	/*glColor3f (0.015,0.047,0.121);
    glBegin(GL_POLYGON); 
	glVertex2i(550+bx,200+by);		
	glVertex2i(600+bx,200+by);
	glVertex2i(600+bx,300+by);
	glVertex2i(550+bx,300+by);
    glEnd();*/
	
	
}


void myDisplay(void)
{
        glClear (GL_COLOR_BUFFER_BIT);

        plane();
        box();
		/*glColor3f (1,1,1);
        glBegin(GL_POLYGON); 
	    glVertex2i(10,367);		
	    glVertex2i(590,367);
	    glVertex2i(590,400);
	    glVertex2i(10,400);*/
		scoring = " Score: " + std::to_string(score);

		drawScore(scoring.data());
		
        glEnd();
		if(count_r>0){
		drawGameOverText();
		count_r=0;
		}

        glFlush ();
}


void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,600.0,0.0,400.0);
}



int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (700, 500);
glutInitWindowPosition (10, 10);
glutCreateWindow ("paper plane");
glutDisplayFunc(myDisplay);
glutKeyboardFunc(keyboard);
myInit ();
glutMainLoop();
}

