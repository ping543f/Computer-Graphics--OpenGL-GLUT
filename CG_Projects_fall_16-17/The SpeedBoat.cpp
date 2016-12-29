#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <GL/glut.h>
#include <stdio.h>
#include<time.h>
#include<iostream>
using namespace std;
#pragma region

static float score=10;


int x1 = 0;
int x2 = 0;
int y1 = 0;
int y2 = 0;
int Cx1 = 0;
int Cy1 = 0;
int flag = 0;

float move_unit = 140;

int shipPosition=0;

float rtri = 0;
float rtriC = -700;     //intisl point
float rtriC1 = -700;
float rtriC_p1 = -700;

float p, q=0,s, m=.80 ,o=.15, j=.50, y=0;

float view = 10.0;

char quote[6][80];
int numberOfQuotes = 0, i;

void display(void);
void bitmap_output(int x,int y,char *string,void * font){
	int len,i;
	glRasterPos2f(x,y);
	len=(int)strlen(string);
	for(i=0;i<len;i++){
		glutBitmapCharacter(font,string[i]);
	}
}
void displayInitial(void){
		 glClear(GL_COLOR_BUFFER_BIT);
         glBegin(GL_LINE_LOOP);
		 glColor3f(1,1,1);
		 glVertex2f(30,30);
		 glVertex2f(870,30);
		 glVertex2f(870,720);
		 glVertex2f(30,720);
		 glEnd();

		 glColor3f(1,0,0);
		 bitmap_output(250,120,"THE SPEED BOAT",GLUT_BITMAP_TIMES_ROMAN_24);

		 glColor3f(1,1,1);
		 bitmap_output(138,170,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING",GLUT_BITMAP_TIMES_ROMAN_24);
         glColor3f(1,1,1);
		 bitmap_output(138,210,"AMERICAN INTERNATIONAL UNIVERSITY BANGLADESH",GLUT_BITMAP_TIMES_ROMAN_24);

         glColor3f(102, 51, 0);
		 bitmap_output(170,250,"Submited To: ",GLUT_BITMAP_TIMES_ROMAN_24);
		 glColor3f(38, 38, 38);
		 bitmap_output(170,290,"MD. SAEF ULLAH MIAH",GLUT_BITMAP_TIMES_ROMAN_24);

         glColor3f(38, 38, 38);
		 bitmap_output(170,320,"Course Name: COMPUTER GRAPHICS",GLUT_BITMAP_TIMES_ROMAN_24);

		 glColor3f(38, 38, 38);
		 bitmap_output(170,350,"Sec: C",GLUT_BITMAP_TIMES_ROMAN_24);

		 glColor3f(102, 51, 0);
		 bitmap_output(170,380,"Submited By:",GLUT_BITMAP_TIMES_ROMAN_24);
         glColor3f(255, 102, 0);
		 bitmap_output(210,410,"NAME: ",GLUT_BITMAP_TIMES_ROMAN_24);
         glColor3f(255, 102, 0);
		 bitmap_output(450,410,"ID: ",GLUT_BITMAP_TIMES_ROMAN_24);

		 glColor3f(38, 38, 38);
		 bitmap_output(170,450,"Hossain, Md. Delwar",GLUT_BITMAP_TIMES_ROMAN_24);
		 glColor3f(38, 38, 38);
		 bitmap_output(420,450,"13-25432-3",GLUT_BITMAP_TIMES_ROMAN_24);

		 glColor3f(38, 38, 38);
		 bitmap_output(170,490,"Hossain, Md. Jakir",GLUT_BITMAP_TIMES_ROMAN_24);
		 glColor3f(38, 38, 38);
		 bitmap_output(420,490,"13-25412-3",GLUT_BITMAP_TIMES_ROMAN_24);

		 glColor3f(38, 38, 38);
		 bitmap_output(170,530,"Piash,Kowshick Kumar",GLUT_BITMAP_TIMES_ROMAN_24);
         glColor3f(38, 38, 38);
		 bitmap_output(420,530,"13-25062-3",GLUT_BITMAP_TIMES_ROMAN_24);

		 glColor3f(38, 38, 38);
		 bitmap_output(170,570,"Nafis, Rasidul Hossain",GLUT_BITMAP_TIMES_ROMAN_24);
         glColor3f(38, 38, 38);
		 bitmap_output(420,570,"13-23232-1",GLUT_BITMAP_TIMES_ROMAN_24);

		 glColor3f(1,0,0);
		 bitmap_output(200,650,"Press `ENTER' For `START GAME'  :)",GLUT_BITMAP_TIMES_ROMAN_24);
		 glEnd();
		 glFlush();
		 glutSwapBuffers();
}

void keyboardown(int key, int x, int y)
{
	switch (key){
    case GLUT_KEY_RIGHT:
	   if(shipPosition ==1){
		x1 += move_unit;
		glutPostRedisplay();
		shipPosition=2;
		break;
	   }
	   else if(shipPosition ==0){
		x1 += move_unit;
		glutPostRedisplay();
		shipPosition=1;
		break;
	   }
	   else if(shipPosition ==-1){
		x1 += move_unit;
		glutPostRedisplay();
		shipPosition=0;
		break;
	   }
	   else if(shipPosition ==-2){
		x1 += move_unit;
		glutPostRedisplay();
		shipPosition=-1;
		break;
	   }
	   else{break;}

	case GLUT_KEY_LEFT:
		if(shipPosition==2){
		   x1 -= move_unit;
		   glutPostRedisplay();
		   shipPosition=1;
		   break;
		}
		else if(shipPosition==1){
		   x1 -= move_unit;
		   glutPostRedisplay();
		   shipPosition=0;
		   break;
		}
		else if(shipPosition==0){
		   x1 -= move_unit;
		   glutPostRedisplay();
		   shipPosition=-1;
		   break;
		}
		else if(shipPosition==-1){
		   x1 -= move_unit;
		   glutPostRedisplay();
		   shipPosition=-2;
		   break;
		}
		else{break;}

	default:
		break;

	}
}


void drawSpeedBoat(float ax1, float ay1)
{

    glBegin(GL_QUADS); //SpeedBoat front
	glColor3ub(255, 250, 0);
	glVertex2f(ax1 + 90, ay1 + 465);
	glVertex2f(ax1 + 110, ay1 + 465);
	glVertex2f(ax1 + 120, ay1 + 455);
	glVertex2f(ax1 + 80, ay1 + 455);
	glEnd();

	glBegin(GL_QUADS); // SpeedBoat middle
	glColor3ub(255,180,0);
	glVertex2f(ax1 + 80, ay1 + 380);
	glVertex2f(ax1 + 120, ay1 + 380);
	glVertex2f(ax1 + 120, ay1 + 455);
	glVertex2f(ax1 + 80, ay1 + 455);
	glEnd();

	glBegin(GL_POLYGON);        // SpeedBoat middle polygon
    glColor3ub(1,1,1);
	glVertex2f(ax1 + 80, ay1 + 400);
	glVertex2f(ax1 + 90, ay1 + 390);
	glVertex2f(ax1 + 110, ay1 + 390);
	glVertex2f(ax1 + 120, ay1 + 400);

	glVertex2f(ax1 + 120, ay1 + 435);
	glVertex2f(ax1 + 110, ay1 + 445);
	glVertex2f(ax1 + 90, ay1 + 445);
	glVertex2f(ax1 + 80, ay1 + 435);
	glEnd();

	glBegin(GL_QUADS); // SpeedBoat middle squre
	glColor3ub(255, 250, 0);
	glVertex2f(ax1 + 90, ay1 + 400);
	glVertex2f(ax1 + 110, ay1 + 400);
	glVertex2f(ax1 + 110, ay1 + 435);
	glVertex2f(ax1 + 90, ay1 + 435);
	glEnd();


	glBegin(GL_POLYGON);        // SpeedBoat back polygon
    glColor3ub(255, 250, 0);
	glVertex2f(ax1 + 80, ay1 + 380);
	glVertex2f(ax1 + 120, ay1 + 380);
	glVertex2f(ax1 + 110, ay1 + 360);
	glVertex2f(ax1 + 100, ay1 + 350);
    glVertex2f(ax1 + 90, ay1 + 360);
	glEnd();

}

void drawShip(float cx1, float cy1)
{
    glBegin(GL_QUADS); //ship front
	glColor3ub(0, 0, 204);
	glVertex2f(cx1 + 80, cy1 + 455);
	glVertex2f(cx1 + 120, cy1 + 455);
	glVertex2f(cx1 + 110, cy1 + 465);
	glVertex2f(cx1 + 90, cy1 + 465);
	glEnd();

	glBegin(GL_QUADS); // ship middle
	glColor3ub(204, 255, 51);
	glVertex2f(cx1 + 80, cy1 + 380);
	glVertex2f(cx1 + 120, cy1 + 380);
	glVertex2f(cx1 + 120, cy1 + 455);
	glVertex2f(cx1 + 80, cy1 + 455);
	glEnd();

	glBegin(GL_QUADS); // ship middle piller 1
	glColor3ub(0,0,0);
	glVertex2f(cx1 + 85, cy1 + 390);
	glVertex2f(cx1 + 90, cy1 + 390);
	glVertex2f(cx1 + 90, cy1 + 435);
	glVertex2f(cx1 + 85, cy1 + 435);
	glEnd();

	glBegin(GL_QUADS); // ship middle piller 2
	glColor3ub(0,0,0);
	glVertex2f(cx1 + 95, cy1 + 400);
	glVertex2f(cx1 + 100, cy1 + 400);
	glVertex2f(cx1 + 100, cy1 + 435);
	glVertex2f(cx1 + 95, cy1 + 435);
	glEnd();

	glBegin(GL_QUADS); // ship middle piller 3
	glColor3ub(0,0,0);
	glVertex2f(cx1 + 105, cy1 + 390);
	glVertex2f(cx1 + 110, cy1 + 390);
	glVertex2f(cx1 + 110, cy1 + 435);
	glVertex2f(cx1 + 105, cy1 + 435);
	glEnd();

    glBegin(GL_QUADS); // ship back
	glColor3ub(0, 0, 204);
	glVertex2f(cx1 + 90, cy1 + 360);
	glVertex2f(cx1 + 110, cy1 + 360);
	glVertex2f(cx1 + 120, cy1 + 380);
	glVertex2f(cx1 + 80, cy1 + 380);
	glEnd();

        rtriC+=15;     //speed of ship
		if(rtriC>1400)
		{
			rtriC=-700;
		}
}

void drawIcebar(float cx1, float cy1)
{
	glBegin(GL_POLYGON);
	glColor3ub(77, 121, 255);
	glVertex2f(cx1 - 90, cy1 + 765);        //icebar upper
	glVertex2f(cx1 - 75, cy1 + 780);
	glVertex2f(cx1 - 65, cy1 + 800);
	glVertex2f(cx1 - 50, cy1 + 810);
	glVertex2f(cx1 - 40, cy1 + 820);
    glVertex2f(cx1 - 25, cy1 + 790);
	glVertex2f(cx1 - 10, cy1 + 770);

	glColor3ub(255, 255, 255);
	glVertex2f(cx1 - 15, cy1 + 735);
	glVertex2f(cx1 - 40, cy1 + 720);
	glVertex2f(cx1 - 60, cy1 + 735);
	glVertex2f(cx1 - 67, cy1 + 745);
    glVertex2f(cx1 - 70, cy1 + 752);
	glVertex2f(cx1 - 80, cy1 + 760);

	glEnd();

		rtriC_p1+=15;     //speed of Icebar
		if(rtriC_p1>1400)
		{
			rtriC_p1=-700;
		}
}


void drawBoat(float cx1, float cy1)
{
    glBegin(GL_TRIANGLES);          //Boat Front
    glColor3ub(102, 51, 0);
    glVertex2f(cx1 + 80, cy1 + 440);
	glVertex2f(cx1 + 120, cy1 + 440);
	glVertex2f(cx1 + 100, cy1 + 470);
	glEnd();

    glBegin(GL_QUADS); // Boat middle
	glColor3ub(0, 51, 0);
	glVertex2f(cx1 + 80, cy1 + 380);
	glVertex2f(cx1 + 120, cy1 + 380);
	glVertex2f(cx1 + 120, cy1 + 440);
	glVertex2f(cx1 + 80, cy1 + 440);
	glEnd();

	glBegin(GL_QUADS); // Boat middle middle
	glColor3ub(255, 255, 204);
	glVertex2f(cx1 + 90, cy1 + 390);
	glVertex2f(cx1 + 110, cy1 + 390);
	glVertex2f(cx1 + 110, cy1 + 430);
	glVertex2f(cx1 + 90, cy1 + 430);
	glEnd();

	glBegin(GL_QUADS); // Boat boitha
	glColor3ub(0,0,0);
	glVertex2f(cx1 + 105, cy1 + 425);
	glVertex2f(cx1 + 107, cy1 + 425);
	glVertex2f(cx1 + 130, cy1 + 450);
	glVertex2f(cx1 + 128, cy1 + 450);
	glEnd();

	glBegin(GL_TRIANGLES);              //Boat Back
    glColor3ub(102, 51, 0);
    glVertex2f(cx1 + 80, cy1 + 380);
	glVertex2f(cx1 + 120, cy1 + 380);
	glVertex2f(cx1 + 100, cy1 + 350);
	glEnd();

        rtriC1+=40;				//speed of Boat
		if(rtriC1>1400)
		{
			rtriC1=-700;
		}
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


int gameOver(char a)
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
    if (y1  == Cy1 -(rtriC1+160) && Cy1 -(rtriC1+160) == y1  && shipPosition==-2)
	{
		score = score - 5;
		return true;
	}
    else if (y1  == Cy1 -(rtriC1+160) && Cy1 -(rtriC1+160) == y1  && shipPosition==-1)
	{
		score = score - 5;
		return true;
	}

	else if (y1  == Cy1 -(rtriC1-200) && Cy1 -(rtriC1-200) == y1  && shipPosition==0)
	{
		score = score - 2.5;
		return true;
	}

	else if (y1  == Cy1 -(rtriC1-900) && Cy1 -(rtriC1-900) == y1  && shipPosition==0)
	{
		score = score - 2.5;
		return true;
	}

	else if (y1  == Cy1 -(rtriC1-560) && Cy1 -(rtriC1-560) == y1  && shipPosition==1)
	{
		score = score - 2.5;
		return true;
	}
	else if (y1  == Cy1 -(rtriC1-560) && Cy1 -(rtriC1-560) == y1  && shipPosition==2)
	{
		score = score - 5;
		return true;
	}

	else{

        return false;
	}
}

int scorepoint()
{
    if (y1  == Cy1 -(rtriC1-560) && Cy1 -(rtriC1-560) == y1  && shipPosition==-2)
	{

        score = score + 5;
	}
	else if (y1  == Cy1 -(rtriC1-200) && Cy1 -(rtriC1-200) == y1  && shipPosition==-2)
	{

        score = score + 5;
	}

	else if (y1  == Cy1 -(rtriC1-900) && Cy1 -(rtriC1-900) == y1  && shipPosition==-2)
	{
        score = score + 5;
	}

    else if (y1  == Cy1 -(rtriC1-560) && Cy1 -(rtriC1-560) == y1  && shipPosition==-1)
	{

        score = score + 5;
	}
	else if (y1  == Cy1 -(rtriC1-200) && Cy1 -(rtriC1-200) == y1  && shipPosition==-1)
	{

        score = score + 5;
	}

	else if (y1  == Cy1 -(rtriC1-900) && Cy1 -(rtriC1-900) == y1  && shipPosition==-1)
	{
        score = score + 5;
	}
    else if (y1  == Cy1 -(rtriC1+160) && Cy1 -(rtriC1+160) == y1  && shipPosition==1)
    {

        score = score + 5;
	}
    else if (y1  == Cy1 -(rtriC1-200) && Cy1 -(rtriC1-200) == y1  && shipPosition==1)
	{

        score = score + 5;
	}

	else if (y1  == Cy1 -(rtriC1-900) && Cy1 -(rtriC1-900) == y1  && shipPosition==1)
	{
        score = score + 5;
	}
	else if (y1  == Cy1 -(rtriC1+160) && Cy1 -(rtriC1+160) == y1  && shipPosition==2)
    {

        score = score + 5;
	}
    else if (y1  == Cy1 -(rtriC1-200) && Cy1 -(rtriC1-200) == y1  && shipPosition==2)
	{

        score = score + 5;
	}

	else if (y1  == Cy1 -(rtriC1-900) && Cy1 -(rtriC1-900) == y1  && shipPosition==2)
	{
        score = score + 5;
	}

    else if (y1  == Cy1 -(rtriC1+160) && Cy1 -(rtriC1+160) == y1  && shipPosition==0)
    {

        score = score + 5;
	}
	else if (y1  == Cy1 -(rtriC1-560) && Cy1 -(rtriC1-560) == y1  && shipPosition==0)
	{
        score = score + 5;
	}
	else{
            return 0;

        }
}
void sea()
{
    glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
    glColor3f(0.0,0.50,1.0);
    glVertex2f(0.0,0.0);
    glVertex2f(2000.0,0.0);
    glVertex2f(2000.0,1600.0);
    glVertex2f(0.0,1600.0);
	glEnd();


    glPushMatrix();
    glTranslatef(0,q,0);

	glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    for(p=0;p<20000;p=p+100)
	   for(s=0;s<20000;s=s+50)
		glVertex2f(50.0+s,50.0+p);
		glVertex2f(100.0+s,50.0+p);
	glEnd();


  glPopMatrix();
}


void drawScence()
{
	glPushMatrix();
    glTranslatef(305, 250, 0); //Speed Boat position
	drawSpeedBoat(x1, y1);
	glPopMatrix();

	glPushMatrix();				//Ship -2
	glTranslatef(445,+rtriC-350,0);
    drawShip( Cx1,  Cy1);
	glPopMatrix();

	glPushMatrix();				//Ship -1
	glTranslatef(305,+rtriC,0);
    drawShip( Cx1,  Cy1);
	glPopMatrix();

	glPushMatrix();				//Ship -3
	glTranslatef(25,+rtriC-700,0);
    drawShip( Cx1,  Cy1);
	glPopMatrix();

	glPushMatrix();				//Boat
	glTranslatef(305,+rtriC1-700,0);
    drawBoat( Cx1,  Cy1);
	glPopMatrix();

	glPushMatrix();				//Icebar 1
	glTranslatef(305,+rtriC_p1-700,0);
    drawIcebar( Cx1,  Cy1);
	glPopMatrix();

	glPushMatrix();				//Icebar 2
	glTranslatef(725,+rtriC_p1-350,0);
    drawIcebar( Cx1,  Cy1);
	glPopMatrix();


}

void myDisplay(void)

{
	char a = '1';
	char b = '2';

	glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(0,0,0,0);
	sea();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();



    drawString(GLUT_BITMAP_TIMES_ROMAN_24,score,10,160,100);
    drawString1(GLUT_BITMAP_TIMES_ROMAN_24,"Score : ",100,100);

        collision();
	if(collision() && (score == 0))
    {

            gameOver(a);

    }else{

        scorepoint();

    }

    drawScence();

	glFlush();
}
void myKeyboardFunc( unsigned char key, int x, int y ) {
			if(key==13)
		flag=1;               //break;
			      display();
}
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    if(flag==0)
        displayInitial();
    else if(flag==1)
        myDisplay();


}
/*
void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
		case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN)
			glutIdleFunc(myDisplay);
		break;
		case GLUT_MIDDLE_BUTTON:
		if(state==GLUT_DOWN)
		{
			glutIdleFunc(NULL);
		}
		break;
		case GLUT_RIGHT_BUTTON:
		if(state==GLUT_DOWN)
			glutIdleFunc(NULL);
		break;
		default:
		break;
	}
}*/

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1100, 688);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("The Speed Boat");
	glutDisplayFunc(display);
	myInit();
	glutTimerFunc(60, update, 0); // timer
	glutKeyboardFunc(myKeyboardFunc);
	//glutMouseFunc(mouse);
	glutSpecialFunc(keyboardown);
	glutMainLoop();
	return 0;
}
