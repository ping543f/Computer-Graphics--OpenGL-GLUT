#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>


int boatStatus = 1;

float boatX = 0;
float boatY = 0;



void drawBoat(int);

void tree();
void scene();

float move, angle;

void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 

	}
	glEnd();
}

void tree()
{
	glPushMatrix();

	glBegin(GL_POLYGON); //Tree 
	glColor3f(1.2, 0.5, 0.4);
	glVertex2i(435, 344);
	glVertex2i(450, 345);
	glVertex2i(450, 550);
	glVertex2i(435, 550);
	
	glEnd();
	glColor3f(0.0, 0.7, 0.1);
	DrawCircle(415, 545, 50, 1000); // 4
	glColor3f(0.0, 0.7, 0.1);
	DrawCircle(430, 600, 50, 1000);
	glColor3f(0.0, 0.7, 0.1);
	DrawCircle(460, 550, 50, 1000);
	
	glPopMatrix();

}
void scene()
{
	glPushMatrix();

	glBegin(GL_POLYGON); //Sky  
	glColor3f(0.4, 0.5, 1.0);
	glVertex2i(0, 800);
	glVertex2i(1200, 800);
	glColor3f(0.7, 0.7, 1.0);
	glVertex2i(1200, 0);
	glVertex2i(0, 0);
	glEnd();

	glBegin(GL_POLYGON); //Middle ground 
	glColor3f(0.0, 0.7, 0.0);
	glVertex2i(0, 100);
	glVertex2i(0, 280);
	glVertex2i(200, 330);
	glVertex2i(400, 350);
	glVertex2i(600, 330);
	glVertex2i(800, 320);
	glVertex2i(1000, 300);
	glVertex2i(1200, 270);
	glVertex2i(1200, 100);
	
	glEnd();


	glBegin(GL_POLYGON); // River
	glColor3f(0.2, 0.3, 1.1);
	glVertex2i(0, 150);
	glVertex2i(200, 150);
	glVertex2i(400, 150);
	glVertex2i(600, 150);
	//glColor3f(0.2, 0.3, 1.1);
	glVertex2i(800, 150);
	glVertex2i(1000, 150);
	glVertex2i(1200, 150);
	glVertex2i(1200, 0);
	glVertex2i(0, 0);
	glEnd();

	//tree();

	
	glBegin(GL_POLYGON); //House 
	glColor3f(0.9, 0.7, 0.1);
	glVertex2i(350, 344);
	glVertex2i(350, 460);
	glVertex2i(430, 460);
	glVertex2i(430, 344);
	glEnd();


	glBegin(GL_POLYGON); //House 
	glColor3f(0.9, 0.0, 0.0);
	glVertex2i(340, 460);
	glVertex2i(390, 500);
	glVertex2i(440, 460);
	glEnd();

	glBegin(GL_POLYGON); //Door
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(370, 344);
	glVertex2i(370, 430);
	glVertex2i(410, 430);
	glVertex2i(410, 344);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(390, 344);
	glVertex2i(390, 430);
	glEnd();

	
	

	

	

	
	glPopMatrix();

}




void drawBoat(int i)
{
	glPushMatrix();

	glBegin(GL_POLYGON); // Boat Starts
	glColor3f(0.7, 0.8, 0.1);
	glVertex2i(230, 100);
	glVertex2i(230, 165);
	glVertex2i(480, 165);
	glVertex2i(480, 100);
	
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.5, 0.1);
	glVertex2i(250, 20);
	glVertex2i(220, 100);
	glVertex2i(550, 100);
	glVertex2i(500, 20);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.1, 0.1);
	glVertex2i(235, 135);
	glVertex2i(235, 160);
	glVertex2i(270, 160);
	glVertex2i(270, 135);
	glEnd();
	glFlush();
	glPopMatrix();
}



void myInit(void)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1200.0, 0.0, 800.0);
}

void keyboard(unsigned char key, int x, int y)
{

	switch (key) {
	
	case 'b':		//boat start
	case 'B':
		boatStatus = 1;
		break;
	case 'n':		//boat stop
	case 'N':
		boatStatus = 0;
		break;
	
	default:
		break;
	}
}

void boat()
{
	if (boatStatus == 1)
	{
		boatX += .5;
	}
	if (boatX>1000)
	{
		boatX = -600;
	}
	glPushMatrix();
	glTranslatef(boatX, boatY, 0);
	drawBoat(1);
	glPopMatrix();
}



void myDisplay(void)
{
	scene();
	tree();
	boat();
	
	glFlush();

	glutPostRedisplay();
	glutSwapBuffers();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1250, 600);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Project");
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}