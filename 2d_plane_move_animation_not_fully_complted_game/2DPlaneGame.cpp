/*
Desh, Salman Rahman: 13-23239-1
Amin, H.M. Ruhul: 13-23624-1
Hassan, Jahidul: 13-25373-1
Mahdi, Dewan Osman: 13-25368-3
*/


#include <sstream>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
using namespace std;

int viewY, viewX;
int move_unit = 5;

int m=0;
int passAViewX=1, passBViewX=1; 
float passCViewX=1, passDViewX=1; 

void myInit (void){glClearColor(0.0, 0.8, 1.0, 0.0);glPointSize(4.0);glMatrixMode(GL_PROJECTION);glLoadIdentity();gluOrtho2D(0.0, 640.0, 0.0, 480.0);}

/*Plane_Control_Keyboard*/
void keyboard(int key, int x, int y){
	if (key == GLUT_KEY_UP){
		viewY -= move_unit;
		cout<<"KEYBOARD_UP | ";
	}
	if (key == GLUT_KEY_DOWN){
		viewY += move_unit;
		cout<<"KEYBOARD_DOWN | ";
	}
	if (key == GLUT_KEY_LEFT){
		viewX -= move_unit;
		cout<<"KEYBOARD_LEFT | ";
	}
	if (key == GLUT_KEY_RIGHT){
		viewX += move_unit;
		cout<<"KEYBOARD_RIGHT | ";
	}
}



void drawBitmapText(string caption, int score, float r, float g, float b, 
   float x,float y,float z) {  
   glColor3f(r,g,b);
   glRasterPos3f(x,y,z);
   stringstream strm;
   strm << caption << score;
   string text = strm.str();
   for(string::iterator it = text.begin(); it != text.end(); ++it) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , *it); 
   }
}


/*void viewScore(){
		int s=0, m=10;
		do{
				//drawBitmapText("Score: ", s, 255, 0 , 0, 550, 450, 0 );
				drawBitmapText("Score: ", m, 255,0,0,100,400,0);
				//Sleep(1000);
				//s++;
				//system("CLS");
			}
			while(s!=0);
}*/


/*void print(int x, int y,int z, char *string)
{
//set the position of the text in the window using the x, y and z coordinates
glRasterPos3f(x,y,z);
//get the length of the string to display
int len = (int) strlen(string);

//loop to display character by character
for(int f=0;f<10;f++){
	for (int i = 0;i<len;i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	}
}
};*/



void myDisplay(void){	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	/******************************************/
	/*------- custom code starts -------*/drawBitmapText("Game Score: ", m, 255,255,255,530,450,0);/*plane_tail*/glColor3ub (153, 76, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(10 + viewX, 330 - viewY);glVertex2i(15 + viewX, 330 - viewY);glVertex2i(35 + viewX, 310 - viewY);glVertex2i(15 + viewX, 290 - viewY);glEnd();/*plane_wing_back*/glColor3ub (204, 102, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(80 + viewX, 290 - viewY);glVertex2i(90 + viewX, 330 - viewY);glVertex2i(85 + viewX, 330 - viewY);glVertex2i(50 + viewX, 290 - viewY);glEnd();/*plane_wing_design_back*/glColor3ub (153, 76, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(80 + viewX, 290 - viewY);glVertex2i(90 + viewX, 330 - viewY);glVertex2i(88 + viewX, 330 - viewY);glVertex2i(55 + viewX, 290 - viewY);glEnd();/*plane_body*/glColor3ub (255, 128, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(90 + viewX, 280 - viewY);glVertex2i(30 + viewX, 280 - viewY);glVertex2i(15 + viewX, 290 - viewY);glVertex2i(35 + viewX, 310 - viewY);glVertex2i(80 + viewX, 310 - viewY);glVertex2i(90 + viewX, 300 - viewY);glEnd();/*plane_body_design*/glColor3ub(204, 102, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(90 + viewX, 295 - viewY);glVertex2i(30 + viewX, 295 - viewY);glVertex2i(30 + viewX, 300 - viewY);glVertex2i(90 + viewX, 300 - viewY);glEnd();/*plane_front*/glColor3ub (204, 102, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(90 + viewX, 280 - viewY);glVertex2i(90 + viewX, 300 - viewY);glVertex2i(100 + viewX, 285 - viewY);glVertex2i(100 + viewX, 280 - viewY);glEnd();/*plane_pilot_glass*/glColor3ub (204, 229, 255);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(90 + viewX, 300 - viewY);glVertex2i(80 + viewX, 310 - viewY);glVertex2i(75 + viewX, 305 - viewY);glVertex2i(75 + viewX, 300 - viewY);glEnd();/*plane_wing*/glColor3ub (204, 102, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(80 + viewX, 290 - viewY);glVertex2i(35 + viewX, 260 - viewY);glVertex2i(25 + viewX, 260 - viewY);glVertex2i(50 + viewX, 290 - viewY);glEnd();/*plane_wing_design*/glColor3ub (153, 76, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(80 + viewX, 290 - viewY);glVertex2i(35 + viewX, 260 - viewY);glVertex2i(30 + viewX, 260 - viewY);glVertex2i(55 + viewX, 290 - viewY);glEnd();/*============DANGER_BOX_01===============================*//*main_box*/glColor3ub (178, 190, 181);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(800 - passAViewX, 240);glVertex2i(770 - passAViewX, 240);glVertex2i(770 - passAViewX, 200);glVertex2i(800 - passAViewX, 200);glEnd();/*--black*/glColor3ub (0, 0 , 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(790 - passAViewX, 240);glVertex2i(780 - passAViewX, 240);glVertex2i(780 - passAViewX, 230);glVertex2i(790 - passAViewX, 230);glEnd();/*--yellow*/glColor3ub (255, 2555, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(790 - passAViewX, 230);glVertex2i(780 - passAViewX, 230);glVertex2i(780 - passAViewX, 220);glVertex2i(790 - passAViewX, 220);glEnd();/*--black*/glColor3ub (0, 0, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(790 - passAViewX, 220);glVertex2i(780 - passAViewX, 220);glVertex2i(780 - passAViewX, 210);glVertex2i(790 - passAViewX, 210);glEnd();/*--yellow*/glColor3ub (255, 2555, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(790 - passAViewX, 210);glVertex2i(780 - passAViewX, 210);glVertex2i(780 - passAViewX, 200);glVertex2i(790 - passAViewX, 200);glEnd();/*============DANGER_BOX_02===============================*//*main_box*/glColor3ub (178, 190, 181);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(800 - passBViewX, 140);glVertex2i(770 - passBViewX, 140);glVertex2i(770 - passBViewX, 100);glVertex2i(800 - passBViewX, 100);glEnd();/*--black*/glColor3ub (0, 0 , 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(790 - passBViewX, 140);glVertex2i(780 - passBViewX, 140);glVertex2i(780 - passBViewX, 130);glVertex2i(790 - passBViewX, 130);glEnd();/*--yellow*/glColor3ub (255, 2555, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(790 - passBViewX, 130);glVertex2i(780 - passBViewX, 130);glVertex2i(780 - passBViewX, 120);glVertex2i(790 - passBViewX, 120);glEnd();/*--black*/glColor3ub (0, 0, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(790 - passBViewX, 120);glVertex2i(780 - passBViewX, 120);glVertex2i(780 - passBViewX, 110);glVertex2i(790 - passBViewX, 110);glEnd();/*--yellow*/glColor3ub (255, 2555, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(790 - passBViewX, 110);glVertex2i(780 - passBViewX, 110);glVertex2i(780 - passBViewX, 100);glVertex2i(790 - passBViewX, 100);glEnd();/*============DANGER_BOX_03===============================*//*main_box*/glColor3ub (178, 190, 181);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(700 - passCViewX, 440);glVertex2i(670 - passCViewX, 440);glVertex2i(670 - passCViewX, 400);glVertex2i(700 - passCViewX, 400);glEnd();/*--black*/glColor3ub (0, 0 , 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(690 - passCViewX, 440);glVertex2i(680 - passCViewX, 440);glVertex2i(680 - passCViewX, 430);glVertex2i(690 - passCViewX, 430);glEnd();/*--yellow*/glColor3ub (255, 2555, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(690 - passCViewX, 430);glVertex2i(680 - passCViewX, 430);glVertex2i(680 - passCViewX, 420);glVertex2i(690 - passCViewX, 420);glEnd();/*--black*/glColor3ub (0, 0, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(690 - passCViewX, 420);glVertex2i(680 - passCViewX, 420);glVertex2i(680 - passCViewX, 410);glVertex2i(690 - passCViewX, 410);glEnd();/*--yellow*/glColor3ub (255, 2555, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(690 - passCViewX, 410);glVertex2i(680 - passCViewX, 410);glVertex2i(680 - passCViewX, 400);glVertex2i(690 - passCViewX, 400);glEnd();/*============DANGER_BOX_04===============================*//*main_box*/glColor3ub (178, 190, 181);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(700 - passDViewX, 340);glVertex2i(670 - passDViewX, 340);glVertex2i(670 - passDViewX, 300);glVertex2i(700 - passDViewX, 300);glEnd();/*--black*/glColor3ub (0, 0 , 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(690 - passDViewX, 340);glVertex2i(680 - passDViewX, 340);glVertex2i(680 - passDViewX, 330);glVertex2i(690 - passDViewX, 330);glEnd();/*--yellow*/glColor3ub (255, 2555, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(690 - passDViewX, 330);glVertex2i(680 - passDViewX, 330);glVertex2i(680 - passDViewX, 320);glVertex2i(690 - passDViewX, 320);glEnd();/*--black*/glColor3ub (0, 0, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(690 - passDViewX, 320);glVertex2i(680 - passDViewX, 320);glVertex2i(680 - passDViewX, 310);glVertex2i(690 - passDViewX, 310);glEnd();/*--yellow*/glColor3ub (255, 2555, 0);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(690 - passDViewX, 310);glVertex2i(680 - passDViewX, 310);glVertex2i(680 - passDViewX, 300);glVertex2i(690 - passDViewX, 300);glEnd();/*=====================LAND=========================*/glColor3ub (43, 29 ,14);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(0, 0);glVertex2i(1000, 0);glVertex2i(1000, 35);glVertex2i(0, 35);glEnd();glColor3ub (101, 101, 33);glPointSize(4.0);glBegin(GL_POLYGON);glVertex2i(0, 35);glVertex2i(1000, 35);glVertex2i(1000, 45);glVertex2i(0, 45);glEnd();glFlush ();/*------- custom code ends -------*/
/******************************************/
	glutSwapBuffers();	glutPostRedisplay();}



/*Timer_Control_Object*/
void timerLoopA(int t1) {
		if (passAViewX >= 0)
		{
			passAViewX += 3;
		}
		if(passAViewX >= 1050)
		{
			passAViewX=0;
			m += 5;
		}
		glutPostRedisplay(); 
		glutTimerFunc(15, timerLoopA, 0);
	}

void timerLoopB(int t2) {
	if (passBViewX >= 0)
	{
		passBViewX += 2;
	}
	if(passBViewX >= 1050)
	{
		passBViewX=0;
		m += 5;
	}
	glutPostRedisplay(); 
	glutTimerFunc(15, timerLoopB, 0);
}

void timerLoopC(int t3) {
	if (passCViewX >= 0)
	{
		passCViewX += 2.5;
	}
	if(passCViewX >= 1050)
	{
		passCViewX=0;
		m += 5;
	}
	glutPostRedisplay(); 
	glutTimerFunc(15, timerLoopC, 0);
}

void timerLoopD(int t4) {
	if (passDViewX >= 0)
	{
		passDViewX += 2.75;
	}
	if(passDViewX >= 1050)
	{
		passDViewX=0;
		m += 5;
	}
	glutPostRedisplay(); 
	glutTimerFunc(15, timerLoopD, 0);
}


/*void score(){
		int s=0;
		for (;;){
		system("CLS");
		glRasterPos2f(400, 400);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s);
		s++;
		Sleep(1000);
		}
}*/





/*main_function*/
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1208, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Plane");
	glutDisplayFunc(myDisplay);
	glutSpecialFunc(keyboard);
	glutTimerFunc(0, timerLoopA, 0);
	glutTimerFunc(0, timerLoopB, 0);
	glutTimerFunc(0, timerLoopC, 0);
	glutTimerFunc(0, timerLoopD, 0);
	myInit();
	glutMainLoop();
}

