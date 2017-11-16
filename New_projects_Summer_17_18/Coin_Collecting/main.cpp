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


#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include "game.h"
int index=0;
extern int score;
void drawText(const char * text,int xpos,int ypos);
using namespace std;
bool food=false;
float objPosX=0.0;
bool start = false;
bool startEnvirnment=false;
void KeyboardControls(unsigned char key, int x, int y);
void initRendering();
void display_callback();
void reshape_callback(int,int);
void timer_callback(int);
void keyboard_callback(int,int,int);

void initRendering() {
	glEnable(GL_DEPTH_TEST);
}
///initial compnent
void init()
{
    glClearColor(0.64, 0.90, 0.88, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1000.0, 0, 600.0);


}

void drawText(const char *text,int length ,int xpos,int ypos)
    {
        glMatrixMode(GL_PROJECTION);
        double *matrix = new double[16];
        glGetDoublev(GL_PROJECTION_MATRIX,matrix);
        glLoadIdentity();
        //glOrtho(0,800,0,600,0,0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glPushMatrix();
        glLoadIdentity();
        glRasterPos2i(xpos,ypos);

        //glColor3f(0.0,0.0,0.0);

    for(int i=0;i<=length-1;i++)
     {
     glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)text[i]);

     }
     glPopMatrix();
     glMatrixMode(GL_PROJECTION);
     glLoadMatrixd(matrix);
     glMatrixMode(GL_MODELVIEW);

    }
///main
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1350, 690);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Coin Collect");
    initRendering();
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0,timer_callback,0);
    glutSpecialFunc(keyboard_callback);
    glutKeyboardFunc(KeyboardControls);
    init();
    glutMainLoop();
    return 0;
}
///main display
void display_callback()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	char _score[10];
    itoa(score,_score,10);
    char text[50]="your Score: ";
    strcat(text,_score);
    drawText(text,22,-1,0);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -6.0);
	glPushMatrix();
    glRotatef(80, -1, 0, 0); /// final rotate
    glPushMatrix();
	glPushMatrix();
	drawEnvirnment();

	glPopMatrix();
	glPushMatrix();
    glPopMatrix();
    glPushMatrix();

    glTranslatef(0.0, 0.0, -6.0);
    otherEnvironment();

    glPopMatrix();



    glutSwapBuffers();

}

///reshape window
void reshape_callback(int w,int h)
{
    glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);



}

///timer function
void timer_callback(int)
{

    glutPostRedisplay();
    glutTimerFunc(100,timer_callback,0);

}
///special keyboard
void keyboard_callback(int key,int,int)
{
    switch(key)
    {


        /// left movement
        case GLUT_KEY_LEFT:
        {


            if(start==true)
            {
                if(objPosX>=-.55)


                    objPosX-=.05;


            }

            break;
        }
        /// right movement
        case GLUT_KEY_RIGHT:{
            if(start==true)
            {
                if(objPosX<=.55)

                    objPosX+=.05;
                }

            break;
    }
}
}

///character input keyboard func
void KeyboardControls(unsigned char key, int x, int y)
{
    /// start
	switch (key)
	{
        case 's':
        if(!startEnvirnment){
            startEnvirnment=true;
            start=true;
        }
        else
        {
            startEnvirnment=false;
            start=false;
        }
            break;

	    case 'S':
             if(!startEnvirnment){
            startEnvirnment=true;
            start=true;
        }
        else
        {
            startEnvirnment=false;
            start=false;
        }
            break;
	}
}
