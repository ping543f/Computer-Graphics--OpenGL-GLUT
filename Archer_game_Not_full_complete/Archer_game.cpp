#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include<string.h>
#include<iostream>


//GLfloat rotation = 90.0;
int posX = 70, posY = -120, posZ = 0;
int goal = 0;

int dartX = -150, dartY = 30;
int width = 120, height = 130;
int mousewidth = 25, mouseheight = 25;

int dartX1 = -130, dartY1 = 50;
int width1 = 80, height1 = 90;

int dartX2 = -110, dartY2 = 70;
int width2 = 40, height2 = 50;


void renderBitmapString(float x, float y, char *string) {
	int len;
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glRasterPos2i(x, y);

	for (int i = 0, len = strlen(string); i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)string[i]);
	}
}

bool collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
	if (y1 + h1<y2) return false;
	if (y1>y2 + h2) return false;
	if (x1 + w1<x2) return false;
	if (x1>x2 + w2) return false;

	return true;

}

void dartBoard() {

	//first 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(dartX, dartY);
	glVertex2f(dartX + width, dartY);
	glVertex2f(dartX + width, dartY + height);
	glVertex2f(dartX, dartY + height);
	glEnd();
	

	//second 
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(dartX1, dartY1);
	glVertex2f(dartX1 + width1, dartY1);
	glVertex2f(dartX1 + width1, dartY1 + height1);
	glVertex2f(dartX1, dartY1 + height1);
	glEnd();


	//third 
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(dartX2, dartY2);
	glVertex2f(dartX2 + width2, dartY2);
	glVertex2f(dartX2 + width2, dartY2 + height2);
	glVertex2f(dartX2, dartY2 + height2);
	glEnd();

	/*glVertex2f(posX, posY);//a
	glVertex2f(posX + mousewidth - 10, posY + 10);
												  
	glVertex2f(posX - 35, posY + mouseheight + 20);*/

	//Archer
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(posX, posY);//a
	glVertex2f(posX + mousewidth, posY);
	//glVertex2f(posX + mousewidth, posY + mouseheight);
	glVertex2f(posX, posY + mouseheight);
	glEnd();


	if (collision(dartX, dartY, width, height, posX, posY, mousewidth, mouseheight)) {
		renderBitmapString(0, 0, "Point 5");
		if (collision(dartX1, dartY1, width1, height1, posX, posY, mousewidth, mouseheight)) {
			renderBitmapString(0, 10, "Point 10");
			if (collision(dartX2, dartY2, width2, height2, posX, posY, mousewidth, mouseheight)) {
				renderBitmapString(0, 20, "Point 15");
			}
		}
	}
}



void display() {
	//Clear Window
	glClear(GL_COLOR_BUFFER_BIT);

	dartBoard();
	//rectangle();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	glPopMatrix();
	glFlush();
}


void init() {
	// set clear color to black
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200.0, 200.0, -200.0, 200.0);

}

float move_unit = 130.5f;
void keyboardown(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_RIGHT:
		posX += move_unit / 10;
		break;
	case GLUT_KEY_LEFT:
		//posY+=move_unit;
		posX -= move_unit / 10;
		break;

	case GLUT_KEY_UP:
		posY += move_unit / 10;
		break;
	case GLUT_KEY_DOWN:
		posY -= move_unit / 10;
		break;
		/*case GLUT_KEY=="x":
		posY+=move_unit;
		posX-=move_unit;
		break;*/
	default:
		break;
	}
	glutPostRedisplay();
}

void Normalkey(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 's':
		while (goal <= move_unit) {
			posY += 1;
			posX -= 1;
			goal++;
			for (long i = 0; i < 1600000; i++)
			{

			}
			display();
		}
		break;
	case 'r':
		goal = 0;
		break;
	case 'e':
		exit(0);

	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(650, 600);
	glutInitWindowPosition(250, 250);
	glutCreateWindow("ARCHER_BOARD");
	glutDisplayFunc(display);
	init();
	glutSpecialFunc(keyboardown);
	glutKeyboardFunc(Normalkey);
	glutMainLoop();

}