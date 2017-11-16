/**
@AUTHER 1:
NAME: AHAMED,TAJDIK
ID: 15-28612-1

@AUTHER 2:
NAME: HASAN, SHAH MD. NAHID
ID: 14-27959-3

@AUTHER 3:
NAME: HAIDER,DOLLON
ID: 15-28614-1

*/

#include <GL/gl.h>
#include <iostream>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
#include "game.h"

extern bool food;
float cloudX=0.0;
bool food3=true;
float roadY3=-10;
float roadY=-10;
float roadY1=-10;
int roadMax=300;
bool food1=true;
int score=0;
extern int index;
extern bool startEnvirnment;
extern float objPosX;
bool gameOver=false;
bool obstrac1=true;
float obj1Y=-10;
int obIndex=0;
void createCointwo();
bool obstrac=false;
float objY=-10;


void drawEnvirnment()
{
    glPushMatrix();



	/// draw water
	glPushMatrix();
    drawWater();
	glPopMatrix();
	glPushMatrix();
	glPopMatrix();

	/// draw left boarder
	glPushMatrix();
    leftBoarder();
	glPopMatrix();

	///create coin
	glPushMatrix();
	if(food!=true)
	{

	moveCoinOne();

	}
	else{
    createCoinOne();
    food=false;
	}
	glPopMatrix();


    ///create left obstracle

       glPushMatrix();
    if(obstrac==false && obIndex!=90)
    {
        obstracleMove();
    }
    else
    {
        obstracle();
        obstrac=false;
    }
     glPopMatrix();

     glPushMatrix();
     ///create right obstracle
     if(obstrac==false && obIndex!=45)
    {
        obstracleMove1();
    }
    else
    {
        obstracle1();
        obstrac1=false;
    }

    glPopMatrix();

    glPushMatrix();
    ///create coin
	if(food1!=true && index!=30)
	{
	moveCoinTwo();
	}
	else{
    createCointwo();
    food1=false;
	}

	glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0, -2500, 0.0);

    /// draw speed boat
    drawSpeedBoat();
    glPopMatrix();
	glPopMatrix();
    glPushMatrix();

    ///darw coin
    if(food3!=true && index!=60 )
    {
	moveCoinThree();
	}
	else{
    createCoinThree();
    food3=false;
	}
	glPopMatrix();

	/// draw right boarder
	glPushMatrix();
    rightBoarder();
	glPopMatrix();

	/// draw left bambo
	glPushMatrix();
	glTranslatef(0.0, roadY-300, 0.0);
	multiLeftBambo();
	glPopMatrix();
    drawSpeedBoat();

	/// draw right bambo
	glPushMatrix();
	glTranslatef(0.0, roadY-300, 0.0);
    multiRightBambo();
    objectMovementHandaler();

	glPopMatrix();
    glPopMatrix();
    ///handel create object
    if(startEnvirnment){
        if(index==80)
    {
        food=true;
        std::cout<< index<<std::endl;
        index=0;
    }
    else if(index==30){food1=true; std::cout<< index<<std::endl; }
    else if(index==60){food3=true; std::cout<< index<<std::endl; }
    index++;
    if(obIndex==90)
        {
        obstrac=true;

        obIndex=0;
    }
    else if(obIndex==45)
    {
         obstrac1=true;

    }
    obIndex++;
    }


}


/// draw  Water
void drawWater()
{
    glScalef(35, 400, .02);
    glColor3ub(141, 205, 239);
    glutSolidCube(1);
}

/// draw left boarder
void leftBoarder()
{
    glTranslatef(-1.21, -4.8, 0.0);
    glScalef(.1, 400, .1);
    glColor3ub(226, 45, 13);
    glutSolidCube(1);
}
/// draw right boarder
void rightBoarder()
{
    glTranslatef(1.22, -4.8, 0.0);
    glScalef(.1, 400, .1);
    glColor3ub(226, 45, 13);
    glutSolidCube(1);
}

///draw Speed Baot
void drawSpeedBoat()
{
    glPushMatrix();
    glTranslatef(objPosX, -4, .5);
    glRotatef(-1, 1, 0.0, 0.0);
    glPushMatrix();
    glRotatef(90, 1, 0.0, 0.0);
    glPushMatrix();
    glRotatef(90, 0, -1, 0.0);
    glScalef(.1, .1, .1);
    speedBoatModel();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}





/// draw Speed boat model
void speedBoatModel()
{

    glPushMatrix();
    glPushMatrix();
    glColor3ub(34, 82, 0);
    glTranslatef(-2.4, 0.02, 0.0);
    glScalef(7.5, 0.3, 1.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.75, 0.3, 0.0);
    glScalef(6.1, 0.3, 1.2);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.25, .5, 0.0);
    glScalef(2, 0.1, 1.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.35, .6, 0.0);
    glScalef(1.7, 0.1, 1.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.35, .7, 0.0);
    glScalef(1.3, 0.1, 1.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.45, .8, 0.0);
    glScalef(.9, 0.1, 1.2);
    glutSolidCube(1);
    glPopMatrix();

    /// side body
    glPushMatrix();
    glColor3ub(50, 50, 50);
    glTranslatef(-2.5, .47, 0.0);
    glScalef(3, 0.02, .8);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(-1.7, .6, -.15);
    glScalef(3, 0.02, .4);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(-1.7, -.6, -.15);
    glScalef(3, 0.02, .4);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5.4, 0.30, 0.0);
    glRotatef(11, 0, 0, 1);
    glScalef(1.4, 0.02, 1.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6.13, -.115, .61);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.37, 0.0, 0.0);
    glVertex3f(1.37, 0.54, 0.0);
    glVertex3f(0, 0.28, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6.13, -.115, -.61);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.37, 0.0, 0.0);
    glVertex3f(1.37, 0.54, 0.0);
    glVertex3f(0, 0.28, 0.0);
    glEnd();
    glPopMatrix();



    /// back light
    glPushMatrix();
    glColor3ub(55, 57, 56);
    glTranslatef(1.18, .28, 0.4);
    glutSolidCube(.3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.18, .28, -0.4);
    glutSolidCube(.3);
    glPopMatrix();

    /// head light
    glPushMatrix();
    glColor3ub(50, 50, 50);
    glTranslatef(-6.08, 0.02, 0.45);
    glutSolidSphere(.15, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6.08, 0.02, -0.45);
    glutSolidSphere(.15, 20, 20);
    glPopMatrix();



    glPopMatrix();
}




/// draw obstracle
void obstracle()
{   objY=roadMax;
    glTranslatef(-0.6, roadMax, 0.0);
    glScalef(1.2, .5, 1);
    glColor3ub(128, 0,0);

    glPushMatrix();

        glutSolidCube(1);
        glTranslatef(-0.6, -roadMax, 0.0);

    glPopMatrix();
}
///obstracle movement
void obstracleMove()
{
    glTranslatef(-0.6, objY, 0.0);
    glScalef(1.2, .5, 1);
    glColor3ub(128, 0,0);
    glPushMatrix();
    glutSolidCube(1);
    glTranslatef(-0.6, -objY, 0.0);
    glPopMatrix();
}

/// draw obstracle
void obstracle1()
{   obj1Y=roadMax;
    glTranslatef(0.6, roadMax, 0.0);
    glScalef(1.2, .5, 1);
    glColor3ub(128, 0,0);

    glPushMatrix();

        glutSolidCube(1);
        glTranslatef(0.6, -roadMax, 0.0);

    glPopMatrix();
}
///obstracle movement
void obstracleMove1()
{
    glTranslatef(0.6, obj1Y, 0.0);
    glScalef(1.2, .5, 1);
    glColor3ub(128, 0,0);
    glPushMatrix();
    glutSolidCube(1);
    glTranslatef(0.6, -obj1Y, 0.0);
    glPopMatrix();
}

/// draw coin
void createCoinOne()
{   roadY=roadMax;
    glTranslatef(0.0, roadMax, 0.0);
    glScalef(.3, .2, .7);
    glColor3ub(255,255,0);
    glPushMatrix();
    glutSolidCube(1);
    glTranslatef(0.0, -roadMax, 0.0);
    glPopMatrix();
}
///coin movement
void moveCoinOne()
{
    glTranslatef(0.0, roadY, 0.0);
    glScalef(.3, .2, .7);
    glColor3ub(255,255,0);
    glPushMatrix();
    glutSolidCube(1);
    glTranslatef(0.0, -roadY, 0.0);
    glPopMatrix();
}

/// draw coin
void createCointwo()
{   roadY1=roadMax;
    glTranslatef(0.9, roadMax, 0.0);
    glScalef(.3, .2, .7);
    glColor3ub(255,255,0);

    glPushMatrix();
    glutSolidCube(1);
    glTranslatef(0.9, -roadMax, 0.0);
    glPopMatrix();
}
///coin movement
void moveCoinTwo()
{
    glTranslatef(0.9, roadY1, 0.0);
    glScalef(.3, .2, .7);
    glColor3ub(255,255,0);
    glPushMatrix();
    glutSolidCube(1);
    glTranslatef(0.9, -roadY1, 0.0);
    glPopMatrix();

}
///draw coin
void createCoinThree()
{   roadY3=roadMax;
    glTranslatef(-0.9, roadMax, 0.0);
    glScalef(.3, .2, .7);
    glColor3ub(255,255,0);

    glPushMatrix();
    glutSolidCube(1);
    glTranslatef(-0.9, -roadMax, 0.0);
    glPopMatrix();
}
///coin movement
void moveCoinThree()
{
    glTranslatef(-0.9, roadY3, 0.0);
    glScalef(.3, .2, .7);
    glColor3ub(255,255,0);
    glPushMatrix();
    glutSolidCube(1);
    glTranslatef(-0.9, -roadY3, 0.0);
    glPopMatrix();
}
///movement control here
void objectMovementHandaler()
{
    if(startEnvirnment==true)
    {
        roadY-=4;
        roadY1-=4;
        roadY3-=4;
        objY-=4;
        obj1Y-=4;
        if( (roadY ==-12 && objPosX >-.15 && objPosX<.15) || ( roadY1 == -12 && objPosX >0.3 && objPosX<=0.6) || ( roadY3 == -12 && objPosX >= -0.6 && objPosX<=-0.3)){
        score++;

        std::cout<<score<<std::endl;
        }

        if((objY ==-12 && objPosX<=.1) || (obj1Y ==-12 && objPosX >-.05) )
        {
            std::cout<< "game over" << obj1Y<< std::endl;
            gameOver=true;
        ///generate score output when game over
        char _score[10];
        itoa(score,_score,10);
        char text[50]="your Score: ";
        strcat(text,_score);
        MessageBox(NULL,text,"game Over",0);
        exit(0);

        }
        if(cloudX<=11)
        {
            cloudX+=.008;
        }
        else
        {

            cloudX=0;
        }

    }
}


/// draw single cloud
void drawSingleCloud()
{
    glColor3ub(252, 244, 232);
    glutSolidSphere(.2, 20, 20);
}

/// draw cloud
void drawCloud()
{
    glPushMatrix();
	glTranslatef(-4.3, 1.5, 0.0);
	glScalef(1.5, 1.5, 1.5);
	drawSingleCloud();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-4.2, 1.8, 0.0);
	glScalef(1, 1, 1);
	drawSingleCloud();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-3.75, 1.8, 0.0);
	glScalef(2, 2, 2);
	drawSingleCloud();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-3.2, 1.7, 0.0);
	glScalef(1.7, 1.7, 1.7);
	drawSingleCloud();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-2.85, 1.7, 0.0);
	glScalef(.8, .8, .8);
	drawSingleCloud();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-3.9, 1.3, 0.0);
	glScalef(1, 1, 1);
	drawSingleCloud();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-3.5, 1.4, 0.0);
	glScalef(1.5, 1.5, 1.5);
	drawSingleCloud();
    glPopMatrix();
}


///daw sky element
void otherEnvironment()
{
    glPushMatrix();

        glPushMatrix();
        glTranslatef(cloudX, 0.0, 0.0);
        drawSkyElement();
        glPopMatrix();


	glPopMatrix();
}


/// draw sky element
void drawSkyElement()
{
    /// cloud 1
    glPushMatrix();
    glTranslatef(-13.5, .5, 0);
	glScalef(.6, .6, .6);
	drawCloud();
	glPopMatrix();

    /// cloud 2
    glPushMatrix();
    glTranslatef(-12.5, 1.5, 0);
	glScalef(.3, .3, .3);
	drawCloud();
	glPopMatrix();

    /// cloud 3
    glPushMatrix();
    glTranslatef(-11.5, 1, 0);
	glScalef(.2, .2, .2);
	drawCloud();
	glPopMatrix();

	/// cloud 4
	glPushMatrix();
    glTranslatef(-9.2, 1, 0);
	glScalef(.5, .5, .5);
	drawCloud();
	glPopMatrix();

	/// cloud 5
	glPushMatrix();
    glTranslatef(-8.0, 1.2, 0);
	glScalef(.3, .3, .3);
	drawCloud();
	glPopMatrix();

	/// cloud 6
    glPushMatrix();
    glTranslatef(-5.5, 1.2, 0);
	glScalef(.5, .5, .5);
	drawCloud();
	glPopMatrix();

	/// cloud 7
	glPushMatrix();
    glTranslatef(-4.8, 1.5, 0);
	glScalef(1.3, 1.3, 1.3);
	drawCloud();
	glPopMatrix();

	/// cloud 8
	glPushMatrix();
    glTranslatef(-4, 1.8, 0);
	glScalef(.7, .7, .7);
	drawCloud();
	glPopMatrix();

	/// cloud 9
    glPushMatrix();
    glTranslatef(-3.5, 1.8, 0);
	glScalef(.2, .2, .2);
	drawCloud();
	glPopMatrix();

	/// cloud 10
	glPushMatrix();
    glTranslatef(-1.2, .6, 0);
	glScalef(.5, .5, .5);
	drawCloud();
	glPopMatrix();

	/// cloud 11
	glPushMatrix();
    glTranslatef(3.5, .5, 0);
	glScalef(.8, .8, .8);
	drawCloud();
	glPopMatrix();

	/// cloud 12
	glPushMatrix();
    glTranslatef(4.5, 1, 0);
	glScalef(.3, .3, .3);
	drawCloud();
	glPopMatrix();



}


/// draw left bambo
void leftBambo()
{
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(-1.3, -3, .0);
    glScalef(.1,.1,1);
    glutSolidCube(1);
    glPopMatrix();


}

void multiLeftBambo()
{
    for(int i=0; i<80; i++)
    {
        leftBambo();
        glTranslatef(0.0, 40, 0.0);
    }
}

/// draw right bambo
void rightBambo()
{
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(1.3, -3, .0);
    glScalef(.1,.1,1);
    glutSolidCube(1);
    glPopMatrix();


}
///draw multi right bambo
void multiRightBambo()
{
    for(int i=0; i<80; i++)
    {
        rightBambo();
        glTranslatef(0.0, 40, 0.0);
    }
}


