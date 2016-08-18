//13-23861-1 Mim,Shahajadi Sultana
//13-22947-1 Alam, Ariful
//12-22136-3 khan,shahrin

//press 1 car 1 move and press2 car 1 stop 
//press 3 car 2 move and press 4 car 2 stop
//press C cloud start and press E  cloud stop
//press s sun start and press n sun stop

#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>



int carStatus = 0;
int carStatus1 = 0;

int meghStatus = 0;
int sunStatus =  0; 
 

float carX = 0;
float carY = 0;

float carX1 = 0;
float carY1 = 0;

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
		DrawCircle(2000, 600, 500, 2000);//4

	}
	
	void megh(int x){


     //megh1
	glColor3f(1.0, 1.0, 1.0);
	DrawCircle(100, 1300, 60, 2000);//1
	DrawCircle(200,1300, 80, 2000);//2
	DrawCircle(300, 1300, 55, 2000);//3

	//megh2
	DrawCircle(700, 1300, 60, 2000);//1
	DrawCircle(800,1300, 80, 2000);//2
	DrawCircle(900, 1300, 55, 2000);//3

	//megh3
	DrawCircle(1100, 1300, 60, 2000);//1
	DrawCircle(1200,1300, 80, 2000);//2
	DrawCircle(1300, 1300, 55, 2000);//3

	//megh4
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
	void road(){

	glBegin(GL_POLYGON); // road
	glColor3f(98, 131, 110);
	glVertex2i(0, 400);
	glVertex2i(2000, 400);
	glVertex2i(2000, 900);
	glVertex2i(0, 900);
	glEnd();

	glBegin(GL_POLYGON); // road 
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(0, 450);
	glVertex2i(2000, 450);
	glVertex2i(2000, 850);
	glVertex2i(0, 850);
	glEnd();
	



	}
	void house(){

	glBegin(GL_POLYGON); //Middle ground 
	glColor3f(0.0, 0.8, 0.0);
	glVertex2i(0, 0);
	glVertex2i(2000,0);
	glVertex2i(2000, 400);
	glVertex2i(0,400);
    glEnd();

	//house1
	glBegin(GL_POLYGON); //House rec
	glColor3f(0.5, 0.2, 0.1);
	glVertex2i(100, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 670);
	glVertex2i(100, 670);
	glEnd();

    glBegin(GL_POLYGON); //House door
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(200, 100);
	glVertex2i(250, 100);
	glVertex2i(250, 200);
	glVertex2i(200, 200);
	glEnd();

	glBegin(GL_POLYGON); //House vender1l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(125, 200);
	glVertex2i(150, 200);
	glVertex2i(150, 240);
	glVertex2i(125, 240);
	glEnd();
	glBegin(GL_POLYGON); //House vender2l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(125, 300);
	glVertex2i(150, 300);
	glVertex2i(150, 340);
	glVertex2i(125, 340);
	glEnd();

	glBegin(GL_POLYGON); //House vender3l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(125, 400);
	glVertex2i(150, 400);
	glVertex2i(150, 440);
	glVertex2i(125, 440);
	glEnd();

    glBegin(GL_POLYGON); //House vender4l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(125, 500);
	glVertex2i(150, 500);
	glVertex2i(150, 540);
	glVertex2i(125, 540);
	glEnd();
	
	glBegin(GL_POLYGON); //House vender 5l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(125, 600);
	glVertex2i(150, 600);
	glVertex2i(150, 640);
	glVertex2i(125, 640);
	glEnd();



    glBegin(GL_POLYGON); //House vender1r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(300, 200);
	glVertex2i(325, 200);
	glVertex2i(325, 240);
	glVertex2i(300, 240);
	glEnd();

	glBegin(GL_POLYGON); //House vender2r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(300, 300);
	glVertex2i(325, 300);
	glVertex2i(325, 340);
	glVertex2i(300, 340);
	glEnd();

	glBegin(GL_POLYGON); //House vender3r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(300, 400);
	glVertex2i(325, 400);
	glVertex2i(325, 440);
	glVertex2i(300, 440);
	glEnd();


	glBegin(GL_POLYGON); //House vender4r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(300, 500);
	glVertex2i(325, 500);
	glVertex2i(325, 540);
	glVertex2i(300, 540);
	glEnd();
	glBegin(GL_POLYGON); //House vender5r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(300, 600);
	glVertex2i(325, 600);
	glVertex2i(325, 640);
	glVertex2i(300, 640);
	glEnd();

	//house2

	glBegin(GL_POLYGON); //House2 rec
	glColor3f(0.5, 0.2, 0.1);
	glVertex2i(700, 100);
	glVertex2i(950, 100);
	glVertex2i(950, 670);
	glVertex2i(700, 670);
	glEnd();




	 glBegin(GL_POLYGON); //House door
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(800, 100);
	glVertex2i(850, 100);
	glVertex2i(850, 200);
	glVertex2i(800, 200);
	glEnd();

	glBegin(GL_POLYGON); //House vender1l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(725, 200);
	glVertex2i(750, 200);
	glVertex2i(750, 240);
	glVertex2i(725, 240);
	glEnd();
	glBegin(GL_POLYGON); //House vender2l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(725, 300);
	glVertex2i(750, 300);
	glVertex2i(750, 340);
	glVertex2i(725, 340);
	glEnd();
	glBegin(GL_POLYGON); //House vender3l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(725, 400);
	glVertex2i(750, 400);
	glVertex2i(750, 440);
	glVertex2i(725, 440);
	glEnd();
	glBegin(GL_POLYGON); //House vender 4l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(725, 500);
	glVertex2i(750, 500);
	glVertex2i(750, 540);
	glVertex2i(725, 540);
	glEnd();
	glBegin(GL_POLYGON); //House vender5l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(725, 600);
	glVertex2i(750, 600);
	glVertex2i(750, 640);
	glVertex2i(725, 640);
	glEnd();
	


	glBegin(GL_POLYGON); //House vender 1r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(900, 200);
	glVertex2i(925, 200);
	glVertex2i(925, 240);
	glVertex2i(900, 240);
	glEnd();
	glBegin(GL_POLYGON); //House vender2r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(900, 300);
	glVertex2i(925, 300);
	glVertex2i(925, 340);
	glVertex2i(900, 340);
	glEnd();
	glBegin(GL_POLYGON); //House vender3r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(900, 400);
	glVertex2i(925, 400);
	glVertex2i(925, 440);
	glVertex2i(900, 440);
	glEnd();
	glBegin(GL_POLYGON); //House vender4r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(900, 500);
	glVertex2i(925, 500);
	glVertex2i(925, 540);
	glVertex2i(900, 540);
	glEnd();
	glBegin(GL_POLYGON); //House vender5r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(900, 600);
	glVertex2i(925, 600);
	glVertex2i(925, 640);
	glVertex2i(900, 640);
	glEnd();

   
    //house3

	glBegin(GL_POLYGON); //House3 rec
	glColor3f(0.5, 0.2, 0.1);
	glVertex2i(1300, 100);
	glVertex2i(1550, 100);
	glVertex2i(1550, 670);
	glVertex2i(1300, 670);
	glEnd();




	 glBegin(GL_POLYGON); //House door
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(1400, 100);
	glVertex2i(1450, 100);
	glVertex2i(1450, 200);
	glVertex2i(1400, 200);
	glEnd();

	glBegin(GL_POLYGON); //House vender1l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(1325, 200);
	glVertex2i(1350, 200);
	glVertex2i(1350, 240);
	glVertex2i(1325, 240);
	glEnd();
	glBegin(GL_POLYGON); //House vender2l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(1325, 300);
	glVertex2i(1350, 300);
	glVertex2i(1350, 340);
	glVertex2i(1325, 340);
	glEnd();

	glBegin(GL_POLYGON); //House vender3l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(1325, 400);
	glVertex2i(1350, 400);
	glVertex2i(1350, 440);
	glVertex2i(1325, 440);
	glEnd();

	glBegin(GL_POLYGON); //House vender4l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(1325, 500);
	glVertex2i(1350, 500);
	glVertex2i(1350, 540);
	glVertex2i(1325, 540);
	glEnd();

	glBegin(GL_POLYGON); //House vender5l
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(1325, 600);
	glVertex2i(1350, 600);
	glVertex2i(1350, 640);
	glVertex2i(1325, 640);
	glEnd();




	glBegin(GL_POLYGON); //House vender1r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(1500, 200);
	glVertex2i(1525, 200);
	glVertex2i(1525, 240);
	glVertex2i(1500, 240);
	glEnd();
	glBegin(GL_POLYGON); //House vender 2r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(1500, 300);
	glVertex2i(1525, 300);
	glVertex2i(1525, 340);
	glVertex2i(1500, 340);
	glEnd();

	glBegin(GL_POLYGON); //House vender3r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(1500, 400);
	glVertex2i(1525, 400);
	glVertex2i(1525, 440);
	glVertex2i(1500, 440);
	glEnd();

	glBegin(GL_POLYGON); //House vender4r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(1500, 500);
	glVertex2i(1525, 500);
	glVertex2i(1525, 540);
	glVertex2i(1500, 540);
	glEnd();

	glBegin(GL_POLYGON); //House vender5r
	glColor3f(0.2, 0.2, 0.1);
	glVertex2i(1500, 600);
	glVertex2i(1525, 600);
	glVertex2i(1525, 640);
	glVertex2i(1500, 640);
	glEnd();
	
	//tree1

		glBegin(GL_POLYGON); 
		glColor3f(0.4, 0.3, 0.0);
		glVertex2i(450,100);
		glVertex2i(480,100);
		glVertex2i(480, 300);
		glVertex2i(450,300);
		glEnd();


		glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.2, 0.1);
		glVertex2i(380,200);
		glVertex2i(560,200);
		glVertex2i(460,400);
		glEnd();



		
		glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.2, 0.1);
		glVertex2i(380,250);
		glVertex2i(560,250);
		glVertex2i(460,450);
		glEnd();

		glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.2,0.1);
		glVertex2i(380,300);
		glVertex2i(560,300);
		glVertex2i(460,500);
		glEnd();

//tree2

		glBegin(GL_POLYGON); 
		glColor3f(0.4, 0.3, 0.0);
		glVertex2i(1070,100);
		glVertex2i(1100,100);
		glVertex2i(1100, 300);
		glVertex2i(1070,300);
		glEnd();


		glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.2, 0.1);
		glVertex2i(1000,200);
		glVertex2i(1180,200);
		glVertex2i(1080,400);
		glEnd();



		
		glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.2, 0.1);
		glVertex2i(1000,250);
		glVertex2i(1180,250);
		glVertex2i(1080,450);
		glEnd();
	


		glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.2, 0.1);
		glVertex2i(1000,300);
		glVertex2i(1180,300);
		glVertex2i(1080,500);
		glEnd();
	





//tree3

		glBegin(GL_POLYGON); 
		glColor3f(0.4, 0.3, 0.0);
		glVertex2i(1680,100);
		glVertex2i(1710,100);
		glVertex2i(1710, 300);
		glVertex2i(1680,300);
		glEnd();


		glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.2, 0.1);
		glVertex2i(1610,200);
		glVertex2i(1790,200);
		glVertex2i(1690,400);
		glEnd();



		
		glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.2, 0.1);
		glVertex2i(1610,250);
		glVertex2i(1790,250);
		glVertex2i(1690,450);
		glEnd();
	


		glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.2, 0.1);
		glVertex2i(1610,300);
		glVertex2i(1790,300);
		glVertex2i(1690,500);
		glEnd();
	


//grass0
	glBegin(GL_POLYGON); //Grass
	glColor3f(0.0, 0.6, 0.3);
	glVertex2i(50, 110);
	glVertex2i(45, 130);
	glVertex2i(25, 140);
	glVertex2i(45, 130);
	glVertex2i(35, 160);
	glVertex2i(45, 130);
	glVertex2i(50, 180);
	glColor3f(0.8, 0.8, 0.1);
	glVertex2i(55, 140);
	glVertex2i(75, 160);
	glVertex2i(65, 130);
	glVertex2i(75, 140);
	glVertex2i(65, 130);
	glVertex2i(60, 110);
	glEnd();

//grass1
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
	glBegin(GL_POLYGON); //Grass2 
	glColor3f(0.0, 0.6, 0.1);
	glVertex2i(935, 100);
	glVertex2i(920, 120);
	glVertex2i(910, 130);
	glVertex2i(930, 120);
	glVertex2i(920, 150);
	glVertex2i(940, 130);
	glVertex2i(945, 170);
	glColor3f(0.8, 0.8, 0.1);
	glVertex2i(950, 130);
	glVertex2i(970, 150);
	glVertex2i(960, 120);
	glVertex2i(980, 130);
	glVertex2i(970, 120);
	glVertex2i(955, 100);
	glEnd();
	
    glBegin(GL_POLYGON); //Grass2 
	glColor3f(0.0, 0.6, 0.1);
	glVertex2i(1135, 100);
	glVertex2i(1120, 120);
	glVertex2i(1110, 130);
	glVertex2i(1130, 120);
	glVertex2i(1120, 150);
	glVertex2i(1140, 130);
	glVertex2i(1145, 170);
	glColor3f(0.8, 0.8, 0.1);
	glVertex2i(1150, 130);
	glVertex2i(1170, 150);
	glVertex2i(1160, 120);
	glVertex2i(1180, 130);
	glVertex2i(1170, 120);
	glVertex2i(1155, 100);
	glEnd();
	glBegin(GL_POLYGON); //Grass3
	glColor3f(0.0, 0.6, 0.1);
	glVertex2i(1835, 100);
	glVertex2i(1820, 120);
	glVertex2i(1810, 130);
	glVertex2i(1830, 120);
	glVertex2i(1820, 150);
	glVertex2i(1840, 130);
	glVertex2i(1845, 170);
	glColor3f(0.8, 0.8, 0.1);
	glVertex2i(1850, 130);
	glVertex2i(1870, 150);
	glVertex2i(1860, 120);
	glVertex2i(1880, 130);
	glVertex2i(1870, 120);
	glVertex2i(1855, 100);
	glEnd();

    glBegin(GL_POLYGON); //Grass3
	glColor3f(0.0, 0.6, 0.1);
	glVertex2i(1935, 100);
	glVertex2i(1920, 120);
	glVertex2i(1910, 130);
	glVertex2i(1930, 120);
	glVertex2i(1920, 150);
	glVertex2i(1940, 130);
	glVertex2i(1945, 170);
	glColor3f(0.8, 0.8, 0.1);
	glVertex2i(1950, 130);
	glVertex2i(1970, 150);
	glVertex2i(1960, 120);
	glVertex2i(1980, 130);
	glVertex2i(1970, 120);
	glVertex2i(1955, 100);
	glEnd();

}

void movecar(int x)
	{
	glBegin(GL_QUADS); //car chaka
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(110,790);
	glVertex2i(120,790);
	glVertex2i(120,800);
	glVertex2i(110,800);
	
    glEnd();

	glBegin(GL_QUADS); //car chaka
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(180,790);
	glVertex2i(190,790);
	glVertex2i(190,800);
	glVertex2i(180,800);
	
    glEnd();

    glBegin(GL_QUADS); //car upper
	glColor3f(1.9, 0.0, 0.0);
	glVertex2i(100,800);
	glVertex2i(200, 800);
	glVertex2i(200,850);
	glVertex2i(100,850);
	
    glEnd();

	glBegin(GL_POLYGON); //car  
	glColor3f(0.0, 1.8, 0.5);
	glVertex2i(120,850);
	glVertex2i(180, 850);
	glVertex2i(180,890);
	glVertex2i(120,890);
	glEnd();

	
	
	
	
	}

void movecar1(int x){

	//2nd car


	glBegin(GL_QUADS); //car chaka
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(110,690);
	glVertex2i(120,690);
	glVertex2i(120,700);
	glVertex2i(110,700);
	
    glEnd();

	glBegin(GL_QUADS); //car chaka
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(180,690);
	glVertex2i(190,690);
	glVertex2i(190,700);
	glVertex2i(180,700);
	
    glEnd();

    glBegin(GL_QUADS); //car 
	glColor3f(1.9, 0.0, 0.0);
	glVertex2i(100,700);
	glVertex2i(200, 700);
	glVertex2i(200,750);
	glVertex2i(100,750);
	
    glEnd();

	glBegin(GL_POLYGON); //car  
	glColor3f(0.0, 1.8, 0.5);
	glVertex2i(120,750);
	glVertex2i(180, 750);
	glVertex2i(180,790);
	glVertex2i(120,790);
	glEnd();





}



	void car()
	{
		if (carStatus == 1)
		{
			carX +=1;
		}
		if (carX>2000)
		{
			carX = -600;
		}
		glPushMatrix();
		glTranslatef(carX, carY, 0);
		movecar(1);
		glPopMatrix();
	}

	void car1()
	{
		if (carStatus1 == 1)
		{
			carX1 +=.5;
		}
	if (carX1>2000)
	{
		carX1 = -600;
	}
		glPushMatrix();
		glTranslatef(carX1, carY1, 0);
		movecar1(1);
		glPopMatrix();
	}
	


	void keyboard(unsigned char key,int x,int y)
	
	{

		if(key=='1')
	   {		               //car start
	    carStatus = 1;

		}

			
		else if(key== '2')
			//car stop
		{
			carStatus = 0;
	
		}



		else if(key== '3')		//car1 start
		
		 {	 carStatus1 = 1;

		}

		else if(key=='4')	
			//car1 stop
		{ 
			carStatus1 = 0;
		
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
			 road();
			 car();
			 car1();
			 house();
			 movemegh();
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

	glutCreateWindow("city view");
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}