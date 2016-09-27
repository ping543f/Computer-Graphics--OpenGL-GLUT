
//Kabir ,Nusrat Farzana   12-21557-2
//Rashid,Rezwana 12-21461-2
//press 1 boat 1 move and press2 boat 1 stop 
//press 3 boat 2 move and press 4 boat 2 stop
//press C cloud start and press E  cloud stop
//press s sun start and press n sun stop
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>



int boatStatus = 0;
int boatStatus1 = 0;

int meghStatus = 0;
int sunStatus =  0; 
 

float boatX = 0;
float boatY = 0;

float boatX1 = 0;
float boatY1 = 0;

float sunX = 0;
float sunY = 0;

float meghX = 0;
float meghY = 0;


float move, angle;

		void DrawCircle(float cx, float cy, float r, int num_segments){

		 glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i < num_segments; i++)
		{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 

		}
		glEnd();
	}

	void drawSun(int x)
	{	
		glColor3f(3.0, 1.0, 0.5);
		DrawCircle(800, 1000, 70, 1000);	
	}



	void hills(){

		glColor3f(0.4, 0.4, 0.2);
		DrawCircle(200, 600, 500, 2000); //1
		glColor3f(0.4, 0.4, 0.2);
		DrawCircle(800,600,500, 2000);//2
		glColor3f(0.4, 0.4, 0.2);
		DrawCircle(1400, 600, 500, 2000);//3
		glColor3f(0.4, 0.4, 0.2);
		DrawCircle(2000, 600, 500, 2000);//3

	}
	void tree()
	{
	

	glBegin(GL_POLYGON); //Tree 
	glColor3f(.6, 0.3, 0.1);
	glVertex2i(395, 50);
	glVertex2i(430, 50);
	glVertex2i(430, 250);
	glVertex2i(395, 250);
	
	glVertex2i(345, 30);
	glVertex2i(480, 30);
	glVertex2i(430, 50);
	glVertex2i(395, 50);


	
	glVertex2i(395, 250);
	glVertex2i(430, 250);
	glVertex2i(460, 360);
	
	glVertex2i(430, 360);
	glVertex2i(390, 290);
	glVertex2i(360, 360);
	glVertex2i(320, 360);
	glEnd();





	glColor3f(0.0, 0.6, 0.1);
	DrawCircle(370, 370, 60, 2000); //4
	glColor3f(0.0, 0.6, 0.1);
	DrawCircle(450,480,80, 2000);//2
	glColor3f(0.0, 0.6, 0.1);
	DrawCircle(320, 460, 80, 2000);//1
	glColor3f(0.0, 0.6, 0.1); 
        DrawCircle(450, 380, 70, 1000);//3
	glColor3f(0.0, 0.6, 0.1); 
	DrawCircle(370, 550,80, 1000);//5

	}
	void megh(int x){




	glColor3f(1.0, 1.0, 1.0);
	DrawCircle(100, 1300, 60, 2000);//1
	DrawCircle(200,1300, 80, 2000);//2
	DrawCircle(300, 1300, 55, 2000);//3


	DrawCircle(700, 1300, 60, 2000);//1
	DrawCircle(800,1300, 80, 2000);//2
	DrawCircle(900, 1300, 55, 2000);//3

	DrawCircle(1100, 1300, 60, 2000);//1
	DrawCircle(1200,1300, 80, 2000);//2
	DrawCircle(1300, 1300, 55, 2000);//3

	DrawCircle(1700, 1300, 60, 2000);//1
	DrawCircle(1800,1300, 80, 2000);//2
	DrawCircle(1900, 1300, 55, 2000);//3


	}

	void movemegh()

	{
		if (meghStatus == 1)
		{
			meghX +=.5;
		}
		if (meghX>2000)
		{
			meghX = -200;
		}
		glPushMatrix();
		glTranslatef(meghX, meghY, 0);
		megh(1);
		glPopMatrix();


	}

	void moveSun()
	{

	
		 if(sunStatus == 1)
		  {
				 if (sunY>=350)
				 sunY=350;
				 else
					sunY += .5;
		  }		
         
			  glPushMatrix();
		 
			 glTranslatef(sunX, sunY, 0);
		 
     		 drawSun(1);
			 glPopMatrix();
		
		     
	}

	void sky(){

	glBegin(GL_POLYGON); //Sky  
	glColor3f(0.4, 0.5, 1.0);
	glVertex2i(0, 1500);
	glVertex2i(2000, 1500);
	glColor3f(0.7, 0.7, 1.0);
	glVertex2i(2000, 0);
	glVertex2i(0, 0);
	glEnd();
	  


	}
	void river(){

	glBegin(GL_POLYGON); // River
	glColor3f(0.2, 0.3, 1.1);
	glVertex2i(0, 500);
	glVertex2i(550, 300);
	glVertex2i(2000, 200);
	glVertex2i(2000, 950);
	glVertex2i(0, 950);
	glEnd();


	}
	void house(){

	glBegin(GL_POLYGON); //Middle ground 
	glColor3f(0.0, 0.8, 0.0);
	glVertex2i(0, 0);
	glVertex2i(2000,0);
	glVertex2i(2000, 200);
	glVertex2i(1000,0);
	glColor3f(0.1, 0.9, 0.1);
	glVertex2i(0,0);
	glVertex2i(2000, 200);
	glVertex2i(550, 300);
	glVertex2i(0, 500);
	glEnd();


	glBegin(GL_POLYGON); //House rec
	glColor3f(0.5, 0.2, 0.1);
	glVertex2i(100, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 250);
	glVertex2i(100, 250);
	glEnd();




	glBegin(GL_POLYGON); //House rec border
	glColor3f(1.0, 0.3, 0.2);
	glVertex2i(90, 80);
	glVertex2i(355, 80);
	glVertex2i(350, 100);
	glVertex2i(100, 100);
	glEnd();

	glBegin(GL_POLYGON); //House door
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(200, 100);
	glVertex2i(250, 100);
	glVertex2i(250, 200);
	glVertex2i(200, 200);
	glEnd();


	glBegin(GL_POLYGON); //House tin
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(100, 250);
	glVertex2i(350, 250);
	glVertex2i(300, 400);
	glVertex2i(50, 400);
	glEnd();



	glBegin(GL_POLYGON); //House tri
	glColor3f(0.6, 0.3, 0.1);
	glVertex2i(25, 275);
	glVertex2i(100, 250);
	glVertex2i(50, 400);
	
	glEnd();




	glBegin(GL_POLYGON); //House tri down rec
	glColor3f(0.9, 0.2, 0.16);
	glVertex2i(25, 150);
	glVertex2i(100, 100);
	glVertex2i(100, 250);
	glVertex2i(25, 275);
	glEnd();




	glBegin(GL_POLYGON); //House tri down rec bor
	glColor3f(0.3, 0.3, 0.1);
	glVertex2i(20, 130);
	glVertex2i(90,80 );
	glVertex2i(100, 100);
	glVertex2i(25, 150);
	glEnd();



	glBegin(GL_POLYGON); //House tri down rec ven
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(50, 210);
	glVertex2i(75, 200);
	glVertex2i(75, 240);
	glVertex2i(50, 250);
	glEnd();




	glBegin(GL_POLYGON); //House vender
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(125, 200);
	glVertex2i(150, 200);
	glVertex2i(150, 240);
	glVertex2i(125, 240);
	glEnd();

	glBegin(GL_POLYGON); //House vender
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(300, 200);
	glVertex2i(325, 200);
	glVertex2i(325, 240);
	glVertex2i(300, 240);
	glEnd();
	 glBegin(GL_POLYGON); //Grass
	glColor3f(0.0, 0.6, 0.3);
	glVertex2i(495, 110);
	glVertex2i(480, 130);
	glVertex2i(470, 140);
	glVertex2i(490, 130);
	glVertex2i(480, 160);
	glVertex2i(500, 130);
	glVertex2i(505, 180);
	glColor3f(0.8, 0.8, 0.1);
	glVertex2i(510, 140);
	glVertex2i(530, 160);
	glVertex2i(520, 130);
	glVertex2i(540, 140);
	glVertex2i(530, 130);
	glVertex2i(515, 110);
	glEnd();

	glBegin(GL_POLYGON); //Grass 
	glColor3f(0.0, 0.6, 0.1);
	glVertex2i(635, 100);
	glVertex2i(620, 120);
	glVertex2i(610, 130);
	glVertex2i(630, 120);
	glVertex2i(620, 150);
	glVertex2i(640, 130);
	glVertex2i(645, 170);
	glColor3f(0.8, 0.8, 0.1);
	glVertex2i(650, 130);
	glVertex2i(670, 150);
	glVertex2i(660, 120);
	glVertex2i(680, 130);
	glVertex2i(670, 120);
	glVertex2i(655, 100);
	glEnd();
	}
void moveboat(int x)
	{
    glBegin(GL_QUADS); //BOAT 
	glColor3f(1.9, 0.0, 0.0);
	glVertex2i(100,600);
	glVertex2i(400, 600);
	glVertex2i(480,700);
	glVertex2i(50,700);
	glVertex2i(100,600);
    glEnd();

	glBegin(GL_POLYGON); //BOAT  
	glColor3f(0.0, 1.8, 0.5);
	glVertex2i(120,700);
	glVertex2i(240, 700);
	glVertex2i(190,760);
	glEnd();

	glBegin(GL_QUADS); //BOAT 
	glColor3f(1.0, 1.7, 0.0);
	glVertex2i(240,700);
	glVertex2i(420, 700);
	glVertex2i(350,760);
	glVertex2i(190,760);
	glVertex2i(240,700);
    glEnd();
	
	}



	void moveboat1(int x)
	{
    glBegin(GL_QUADS); //BOAT 
	glColor3f(1.9, 0.0, 0.0);
	glVertex2i(100,800);
	glVertex2i(400, 800);
	glVertex2i(480,900);
	glVertex2i(50,900);
	glVertex2i(100,800);
    glEnd();

	glBegin(GL_POLYGON); //BOAT  
	glColor3f(0.0, 1.8, 0.5);
	glVertex2i(120,900);
	glVertex2i(240, 900);
	glVertex2i(190,960);
	glEnd();

	glBegin(GL_QUADS); //BOAT 
	glColor3f(1.0, 1.7, 0.0);
	glVertex2i(240,900);
	glVertex2i(420, 900);
	glVertex2i(350,960);
	glVertex2i(190,960);
	glVertex2i(240,900);
    glEnd();
	
	}





	void boat()
	{
		if (boatStatus == 1)
		{
			boatX +=1;
		}
		if (boatX>2000)
		{
			boatX = -600;
		}
		glPushMatrix();
		glTranslatef(boatX, boatY, 0);
		moveboat(1);
		glPopMatrix();
	}

	void boat1()
	{
		if (boatStatus1 == 1)
		{
			boatX1 +=.5;
		}
	if (boatX1>2000)
	{
		boatX1 = -600;
	}
		glPushMatrix();
		glTranslatef(boatX1, boatY1, 0);
		moveboat1(1);
		glPopMatrix();
	}
	


	void keyboard(unsigned char key,int x,int y)
	
	{

		if(key=='1')
	   {		               //boat start
	    boatStatus = 1;

		}

			
		else if(key== '2')
			//boat stop
		{
			boatStatus = 0;
	
		}



		else if(key== '3')		//boat1 start
		
		 {	 boatStatus1 = 1;

		}

		else if(key=='4')	
			//boat1 stop
		{ 
			boatStatus1 = 0;
		
		}

		else if( key =='S'|| key=='s')		//sun start
		{   
			sunStatus = 1;
	    }

		else if( key =='N'|| key=='n')		//sun  start
		{   
			sunStatus = 0;
		}

		else if( key =='C'|| key=='c')	
			//megh start
		{   
			meghStatus = 1;
		}
		else if( key =='e'|| key=='N')	
			//megh start
		{   
			meghStatus = 0;
	}
		else{

		}
	

	
	}


   void myDisplay(void)
	{     
			 sky();
			 moveSun();
			
			 hills();
			 house();
			 river();
			 movemegh();
			 boat();
			 boat1();
			 tree();
			 glFlush();
			 glutPostRedisplay();
			 glutSwapBuffers();
}

void myInit(void)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 2000.0, 0.0, 1500.0);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(2000, 1500);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("project");
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}