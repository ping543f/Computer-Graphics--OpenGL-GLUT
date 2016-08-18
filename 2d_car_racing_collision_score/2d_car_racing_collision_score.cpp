/*Name:                          ID:
1. Sagore,Niloy Saha            13-24066-2
2. Hasan,Md.Mehedy              13-24119-2
3. Hassan,Mehadi                13-23985-2
4. Sakian, Mohius Sunnah Noor   11-19874-3
*/
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;

bool LeftKeyPressed = false,RightKeyPressed = false;
float posX=0,posY=0,posZ=0;


float oponentX=0,oponentY=1600,oponentZ=0;
bool oponentstat= true,dropped=false;

int score =   0;
char buffer[10];


bool gameFlag=false;
bool GOFlag=false;


void drawString (void * font, char *s, float x, float y){ 
     glRasterPos2f(x, y);
	 glColor3f(0, 0, 20);
     for (int i = 0; i < strlen (s); i++)
          glutBitmapCharacter (font, s[i]);
}


void randomOponent(int max ,int min)
{
    static bool first = true;
    if (first)
        {
            srand (time(NULL));
                first=false;
        }
	
	oponentX= min+ rand()%(max-min);
}




void backGround()
	{

		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(0,0);
		glVertex2i(2000, 0);
		glVertex2i(2000, 1500);
		glVertex2i(0,1500);
		glEnd();



	  
	}

void Car() //Main Car
	{
		{	
			glPushMatrix();
		for(int i=0;i<10;i++)
		{
			glTranslatef(posX,posY,posZ);
		}

		glBegin(GL_POLYGON); //outer box
		glColor3ub(0, 0, 153);
		glVertex2i(800,300);
		glVertex2i(900,300);
		glVertex2i(900, 400);
		glVertex2i(800,400);
		glEnd();

		
		glBegin(GL_POLYGON); //back part
		glColor3ub(0, 0, 153);
		glVertex2i(810, 270);
		glVertex2i(890,270);
		glVertex2i(900, 300);
		glVertex2i(800,300);
		
		glEnd();



		glBegin(GL_POLYGON); 
		glColor3ub(140, 140, 140);///middle box  back part
		glVertex2i(800,300);
		glVertex2i(900,300);
		glVertex2i(880, 330);
		glVertex2i(820,330);
		glEnd();

		
		glBegin(GL_POLYGON); //middle box
		glColor3ub(0, 0, 51);
		
		glVertex2i(820, 330);
		glVertex2i(880,330);
		glVertex2i(880,370);
		glVertex2i(820,370);

		glEnd();

			glBegin(GL_POLYGON); 
		glColor3ub(140, 140, 140);///middle box fornt part
		
		glVertex2i(820, 370);
		glVertex2i(880,370);
		glVertex2i(900,400);
		glVertex2i(800,400);

		glEnd();

		glBegin(GL_POLYGON); 
		glColor3ub(0, 0, 153);//front part
		
		glVertex2i(800,400);  
		glVertex2i(900,400);
		glVertex2i(890,430);
		glVertex2i(810,430);
		glEnd();

		glPopMatrix();




		}
	  
	}

	

void oponent()
	{
	  glBegin(GL_POLYGON); //out box
		glColor3ub(153, 102, 0);
		glVertex2i(1000,500);
		glVertex2i(1100,500);
		glVertex2i(1100, 600);
		glVertex2i(1000,600);
		glEnd();

		
		glBegin(GL_POLYGON); //back part
		glColor3ub(153, 102, 0);
		glVertex2i(1010, 470);
		glVertex2i(1090,470);
		glVertex2i(1100, 500);
		glVertex2i(1000,500);
		
		glEnd();



		glBegin(GL_POLYGON); 
		glColor3ub(140, 140, 140);///middle box  back part
		glVertex2i(1000,500);
		glVertex2i(1100,500);
		glVertex2i(1080, 530);
		glVertex2i(1020,530);
		glEnd();

		
		glBegin(GL_POLYGON); //middle box
		glColor3ub(51, 34, 0);
		
		glVertex2i(1020, 530);
		glVertex2i(1080,530);
		glVertex2i(1080,570);
		glVertex2i(1020,570);

		glEnd();

			glBegin(GL_POLYGON); 
		glColor3ub(140, 140, 140);///middle box fornt part
		
		glVertex2i(1020, 570);
		glVertex2i(1080,570);
		glVertex2i(1100,600);
		glVertex2i(1000,600);

		glEnd();

		glBegin(GL_POLYGON); 
		glColor3ub(153, 102, 0);//front part
		
		glVertex2i(1000,600);
		glVertex2i(1100,600);
		glVertex2i(1090,630);
		glVertex2i(1010,630);
		glEnd();

		glPopMatrix();




    }
	  
	
	
void collision()
{
	if ((oponentstat==true) && (gameFlag==true))
	{
		
		if(oponentY<=-40)
		{
			
			if((posX==-30) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision 1"<<endl;
				gameFlag=false;
			}
			else if((posX==-30) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision 2"<<endl;
				gameFlag=false;
			}

			else if((posX==-25) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision 3"<<endl;
				gameFlag=false;
			}
			else if((posX==-25) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision 4"<<endl;
				gameFlag=false;
			}

			else if((posX==-20) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision 5 "<<endl;
				gameFlag=false;
			}
			else if((posX==-15) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision 6 "<<endl;
				gameFlag=false;
			}
			else if((posX==-10) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision 7 "<<endl;
				gameFlag=false;
			}
			else if((posX==-5) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision 8 "<<endl;
				gameFlag=false;

			}
			
			else if((posX==0) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision 9 "<<endl;
				gameFlag=false;
			}
			else if((posX==5) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision 10 "<<endl;
				gameFlag=false;
			}
			else if((posX==10) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision 11 "<<endl;
				gameFlag=false;
				
			}
			else if((posX==15) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision 12 "<<endl;
				gameFlag=false;
				
			}
			else if((posX==20) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision 13 "<<endl;
				gameFlag=false;
			}
			else if((posX==25) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision 14 "<<endl;
				gameFlag=false;
			}
			else if((posX==30) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision 15 "<<endl;
				gameFlag=false;
			}
			else if((posX==35) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision 16 "<<endl;
				gameFlag=false;
			}
			else if((posX==40) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision 17 "<<endl;
				gameFlag=false;
			}
			else if((posX==45) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision 18 "<<endl;
				gameFlag=false;
			}
			else if((posX==50) && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision 19 "<<endl;
				gameFlag=false;
			}
			
			
		}
		else if(oponentY<=10)
		{

		if(((posX==-30) && (posY==5)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision 20"<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==5)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision 21"<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==5)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision 22"<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==5)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision 23"<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==5)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision 24 "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==5)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision 25 "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==5)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision 26 "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==5)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision 27 "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==5)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision 28 "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==5)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision 29 "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==5)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision 30 "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==5)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision 31 "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==5)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision 32 "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==5)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision 33 "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==5)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision 34 "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==5)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision 35 "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==5)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision 36 "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==5)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision 37 "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==5))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision 38 "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=60)
		{

		if(((posX==-30) && (posY==10)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision 39"<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==10)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision 40"<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==10)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision 41"<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==10)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision 42"<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==10)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision 43 "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==10)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision 44 "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==10)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision 45 "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==10)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision 46 "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==10)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision 47 "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==10)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision 48 "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==10)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision 49 "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==10)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision 50 "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==10)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision 51 "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==10)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision 52 "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==10)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision 53 "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==10)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision 54 "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==10)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision 55 "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==10)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision 56 "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==10))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision 57 "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=110)
		{

		if(((posX==-30) && (posY==15)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision 58"<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==15)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision 59"<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==15)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision 60"<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==15)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision 61"<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==15)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision 62 "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==15)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision 63 "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==15)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision 64 "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==15)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision 65 "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==15)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision 66 "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==15)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision 67 "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==15)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision 68 "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==15)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision 69 "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==15)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision 70 "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==15)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision 71 "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==15)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision 72 "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==15)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision 73 "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==15)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision 74 "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==15)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision 75 "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==15))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision 76 "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=160)
		{

		if(((posX==-30) && (posY==20)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision 77"<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==20)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision 78"<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==20)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision 79"<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==20)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision 80"<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==20)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision 81 "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==20)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision 82 "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==20)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision 83 "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==20)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision 84 "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==20)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision 85 "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==20)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision 86 "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==20)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision 87 "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==20)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision 88 "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==20)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision 89 "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==20)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision 90 "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==20)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision 91 "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==20)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision 92 "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==20)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision 93 "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==20)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision 94 "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==20))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision 95 "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=210)
		{

		if(((posX==-30) && (posY==25)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision 96"<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==25)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision 97"<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==25)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision 98"<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==25)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision 99"<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==25)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision 100 "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==25)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==25)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==25)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==25)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==25)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==25)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==25)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==25)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==25)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==25)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==25)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==25)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==25)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==25))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=260)
		{

		if(((posX==-30) && (posY==30)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==30)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==30)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==30)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==30)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==30)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==30)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==30)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==30)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==30)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==30)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==30)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==30)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==30)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==30)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==30)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==30)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==30)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==30))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=310)
		{

		if(((posX==-30) && (posY==35)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==35)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==35)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==35)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==35)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==35)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==35)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==35)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==35)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==35)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==35)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==35)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==35)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==35)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==35)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==35)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==35)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==35)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==35))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=360)
		{

		if(((posX==-30) && (posY==40)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==40)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==40)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==40)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==40)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==40)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==40)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==40)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==40)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==40)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==40)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==40)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==40)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==40)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==40)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==40)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==40)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==40)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==40))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=410)
		{

		if(((posX==-30) && (posY==45)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==45)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==45)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==45)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==45)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==45)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==45)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==45)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==45)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==45)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==45)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==45)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==45)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==45)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==45)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==45)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==45)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==45)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==45))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=460)
		{

		if(((posX==-30) && (posY==50)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==50)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==50)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==50)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==50)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==50)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==50)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==50)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==50)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==50)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==50)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==50)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==50)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==50)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==50)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==50)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==50)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==50)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==50))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

        else if(oponentY<=510)
		{

		if(((posX==-30) && (posY==55)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==55)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==55)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==55)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==55)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==55)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==55)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==55)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==55)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==55)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==55)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==55)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==55)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==55)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==55)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==55)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==55)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==55)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==55))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=560)
		{

		if(((posX==-30) && (posY==60)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==60)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==60)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==60)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==60)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==60)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==60)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==60)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==60)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==60)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==60)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==60)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==60)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==60)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==60)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==60)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==60)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==60)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==60))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=610)
		{

		if(((posX==-30) && (posY==65)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==65)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==65)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==65)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==65)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==65)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==65)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==65)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==65)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==65)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==65)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==65)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==65)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==65)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==65)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==65)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==65)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==65)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==65))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=660)
		{

		if(((posX==-30) && (posY==70)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==70)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==70)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==70)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==70)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==70)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==70)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==70)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==70)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==70)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==70)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==70)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==70)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==70)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==70)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==70)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==70)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==70)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==70))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=710)
		{

		if(((posX==-30) && (posY==75)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==75)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==75)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==75)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==75)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==75)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==75)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==75)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==75)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==75)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==75)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==75)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==75)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==75)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==75)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==75)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==75)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==75)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==75))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=760)
		{

		if(((posX==-30) && (posY==80)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==80)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==80)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==80)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==80)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==80)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==80)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==80)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==80)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==80)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==80)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==80)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==80)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==80)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==80)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==80)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==80)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==80)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==80))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=810)
		{

		if(((posX==-30) && (posY==85)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==85)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==85)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==85)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==85)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==85)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==85)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==85)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==85)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==85)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==85)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==85)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==85)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==85)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==85)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==85)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==85)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==85)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==85))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=860)
		{

		if(((posX==-30) && (posY==90)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==90)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==90)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==90)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==90)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==90)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==90)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==90)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==90)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==90)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==90)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==90)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==90)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==90)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==90)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==90)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==90)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==90)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==90))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

		else if(oponentY<=910)
		{

		if(((posX==-30) && (posY==95)) && ((oponentX>=-500) && (oponentX<=-400)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-30) && (posY==95)) && ((oponentX>=-475) && (oponentX<=-375)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-25) && (posY==95)) && ((oponentX>=-450) && (oponentX<=-350)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}
			else if(((posX==-25) && (posY==95)) && ((oponentX>=-425) && (oponentX<=-325)))
			{
				cout<<"Collision "<<endl;
				gameFlag=false;
			}

			else if(((posX==-20) && (posY==95)) && ((oponentX>=-400) && (oponentX<=-300)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-15) && (posY==95)) && ((oponentX>=-350) && (oponentX<=-250)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-10) && (posY==95)) && ((oponentX>=-300) && (oponentX<=-200)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==-5) && (posY==95)) && ((oponentX>=-250) && (oponentX<=-150)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;

			}
			
			else if(((posX==0) && (posY==95)) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==5) && (posY==95)) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==10) && (posY==95)) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==15) && (posY==95)) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
				
			}
			else if(((posX==20) && (posY==95)) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==25) && (posY==95)) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==30) && (posY==95)) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==35) && (posY==95)) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==40) && (posY==95)) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==45) && (posY==95)) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			else if(((posX==50) && (posY==95))  && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision  "<<endl;
				gameFlag=false;
			}
			
        }

		

	
		if(gameFlag==true)
		{
			oponentY-=1;
			if(oponentY==posY){
			score+=1;
			}
			
			
		}
}

	while (oponentY<=-600)
	{
		
		oponentY=1600;

		randomOponent(200,-500);
		dropped=true;
		
	}
			
			
			
	glPushMatrix();
	glTranslatef(oponentX, oponentY, oponentZ);
	
	oponent();
	glPopMatrix();
	
}







	
void road()
	{
	
		glBegin(GL_POLYGON); 
		glColor3f(1.0, 1.0, 1.0);//line 1
		glVertex2i(450, 0);
		glVertex2i(500, 0);
		glVertex2i(500, 1500);
		glVertex2i(450,1500);
		glEnd();



	
		glBegin(GL_POLYGON); 
	//road
		glColor3ub(51, 51, 51);
		glVertex2i(500, 0);
		glVertex2i(1400, 0);
		glVertex2i(1400, 1500);
		glVertex2i(500,1500);
		glEnd();


		glBegin(GL_POLYGON); 
	//line2
		glColor3f(1.0, 1.0, 1.0);
		glVertex2i(1400, 0);
		glVertex2i(1450, 0);
		glVertex2i(1450, 1500);
		glVertex2i(1400,1500);
		glEnd();


	
		glBegin(GL_POLYGON); 
		
	   
	}





	
void middleline1()
	{
		glBegin(GL_QUADS);  //1
		glColor3f(1.0, 1.0, 1.0);
		glVertex2i(900,50);
		glVertex2i(950, 50);
		glVertex2i(950,350);
		glVertex2i(900,350);
		glEnd();
	

	}
void middleline2()
	{
		glBegin(GL_QUADS);  //2
		glColor3f(1.0, 1.0, 1.0);
		glVertex2i(900,550);
		glVertex2i(950, 550);
		glVertex2i(950,850);
		glVertex2i(900,850);
		glEnd();
	}
void middleline3()
	{
		glBegin(GL_QUADS);  //3
		glColor3f(1.0, 1.0, 1.0);
		glVertex2i(900,1050);
		glVertex2i(950, 1050);
		glVertex2i(950,1350);
		glVertex2i(900,1350);
	 glEnd();

}




	



void myDisplay(void)

	{     
		backGround();
		road();
			
		middleline1();
		middleline2();
		middleline3();
		
        collision();
		Car();// car
		drawString(GLUT_BITMAP_TIMES_ROMAN_24,"Score:  ",1050,1450);
		sprintf_s(buffer,"%d", score);
		drawString(GLUT_BITMAP_TIMES_ROMAN_24,buffer,1200,1450);
		
		

	glFlush();
	if(gameFlag==false && GOFlag==true)
	{
		drawString(GLUT_BITMAP_TIMES_ROMAN_24,"OPPS!!! GAME OVER :(",650,950);
		sprintf_s(buffer,"%d", score);
		drawString(GLUT_BITMAP_TIMES_ROMAN_24,"Press ESC to to exit ",700,870);
		
	}
	

		
		
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

void keyboard(unsigned char key,int x,int y)
	
	{

		if(key==(char)13)
	   {		               //game start
		 gameFlag =true;
		 GOFlag = true;

		}

		if(key == 27) //27 is escape
        {
         exit(0);
        }
	}

void handleSpecialKeypress(int key, int x, int y) {
	switch (key)
	{
       case GLUT_KEY_LEFT:

	   LeftKeyPressed = true;
	   if (!RightKeyPressed)
	   {
			if( (posX>-30))
			   {
					posX-=5;
					
			   }
        }
        break;
        case GLUT_KEY_RIGHT:
	    RightKeyPressed = true;
	 
	
        if (!LeftKeyPressed) 
		{
	        if( (posX<50))
	            {
			         posX+=5;
			
	            }
        }
	 
        break;
		case GLUT_KEY_UP:
	    if (GLUT_KEY_UP) 
		{
	        if( (posY<105))
	            {
			         posY+=5;
			
	            }
        }
	 
        break;
        case GLUT_KEY_DOWN:
	    if (GLUT_KEY_DOWN) 
		{
	        if( (posY>0))
	            {
			         posY-=5;
			
	            }
        }
	 
        break;
		

		 
		
	 }
	
}

void handleSpecialKeyReleased(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_LEFT:
			LeftKeyPressed = false;
		break;
		case GLUT_KEY_RIGHT:
			 RightKeyPressed = false;
		break;
 }

	glutPostRedisplay();
}

void main(int argc, char** argv)
	
	{	
			glutInit(&argc, argv);
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
			glutInitWindowSize(900, 1200);
			glutInitWindowPosition(0, 0);
	
			glutCreateWindow("Graphics Final Project");
			
			glutKeyboardFunc(keyboard);
			glutSpecialFunc(handleSpecialKeypress);
            glutSpecialUpFunc(handleSpecialKeyReleased);
		    glutDisplayFunc(myDisplay);
			myInit();
			glutMainLoop();
	}