
// Roy, Tamal             12-20396-1
// Rocky, Maksudur Rahman 12-20776-1
// Rahman, md. Sohanur    12-20660-1					****WIND MILL PROJECT****



#include <stdio.h>
#include <GL/glut.h>
#include<math.h>

GLfloat rotation = 90.0;
float posX = 0, posY = 0, posZ = 0;
float move_unit = 3;
float rate = 1.0f;
float angle = -0.0f;
float RotateX = 0.f, RotateY = 45.f;

void Timer(int value)
{
	glutPostRedisplay();      // Post re-paint request to activate display()
	glutTimerFunc(16, Timer, 0); // next Timer call milliseconds later
}

void stand()
{
	// windmill stand
	glBegin(GL_QUADS);
	glColor3f(0.69, 0.43, 0.314);
	glVertex2i(106, 298);
	glVertex2i(199, 296);
	glVertex2i(160, 420);
	glVertex2i(140, 420);
	glEnd();
	glFlush();

}

void windmill()
{

	//left 1st wing
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.176, 0.070);
	glVertex2i(200, 400);
	glVertex2i(180, 450);
	glVertex2i(20, 570);
	glVertex2i(40, 520);
	//glEnd();
	glFlush();
	//2nd wing	
	glColor3f(0.4, 0.176, 0.070);
	glVertex2i(0, 400);
	glVertex2i(190, 520);
	glVertex2i(210, 570);
	glVertex2i(20, 450);
	glEnd();
	glFlush();


}

void drawCircle(int x1, int y1, int radius)

{
	float x2, y2;
	float angle;
	glBegin(GL_POLYGON);
	for (angle = .1f; angle<361.0f; angle += 1.0f)

	{
		x2 = x1 + sin(angle)*radius;
		y2 = y1 + cos(angle)*radius;
		glVertex2f(x2, y2);
	}

	glEnd();
}

void dheu()

{

	glColor3f(0.019, 0.35, 0.65);
	drawCircle(0, 40, 20);
	drawCircle(50, 40, 22);
	drawCircle(100, 42, 15);
	drawCircle(150, 42, 18);
	drawCircle(200, 42, 12);
	drawCircle(240, 42, 20);
	drawCircle(280, 40, 20);
	drawCircle(340, 40, 22);
	drawCircle(400, 42, 15);
	drawCircle(460, 42, 18);
	drawCircle(530, 42, 12);
	drawCircle(600, 42, 20);
	drawCircle(650, 42, 25);
	drawCircle(720, 42, 15);
	drawCircle(780, 42, 24);
}

void megh()

{
	glColor3f(0.94, 1.0, 0.94);
	drawCircle(45, 680, 20);
	drawCircle(75, 680, 40);
	drawCircle(90, 680, 45);
	drawCircle(120, 680, 35);
	drawCircle(140, 680, 20);

	drawCircle(200, 670, 25);
	drawCircle(220, 670, 35);
	drawCircle(260, 670, 50);
	drawCircle(290, 670, 35);
	drawCircle(320, 670, 20);

}

void tree()
{
	//right leaf
	glColor3f(0, 0.098, 0);
	drawCircle(1170, 288, 25);
	drawCircle(1190, 344, 45);
	drawCircle(1185, 320, 30);
	drawCircle(1245, 380, 55);
	drawCircle(1238, 310, 25);
	drawCircle(1259, 315, 30);
	drawCircle(1200, 295, 25);

	//left leaf

	glColor3f(0, 0.098, 0);
	drawCircle(956, 364, 20);
	drawCircle(990, 361, 25);
	drawCircle(1046, 361, 25);
	drawCircle(1070, 360, 20);

	glColor3f(0, 0.098, 0);
	drawCircle(980, 400, 25);
	drawCircle(1020, 387, 35);
	drawCircle(1065, 392, 25);

	glColor3f(0, 0.098, 0);
	drawCircle(999, 440, 30);
	drawCircle(1030, 435, 35);



}

void background()
{
	//*******backgrounds*******
	//back sky ash background
	glBegin(GL_QUADS);
	glColor3f(0.70, 0.96, 0.96);
	glVertex2i(0, 420);
	glVertex2i(1277, 420);
	glVertex2i(1277, 780);
	glVertex2i(0, 780);
	glEnd();
	glFlush();

	//back grass left
	glBegin(GL_QUADS);
	glColor3f(0.30, 0.701, 0.235);
	glVertex2i(0, 420);
	glVertex2i(0, 80);
	glVertex2i(1236, 80);
	glVertex2i(625, 420);
	glEnd();
	glFlush();

	//road black middle
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(1236, 80);
	glVertex2i(1277, 117);
	glVertex2i(700, 420);
	glVertex2i(625, 370);
	glEnd();
	glFlush();

	//road black middle
	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 0);
	glVertex2i(1277, 117);
	glVertex2i(1236, 80);
	glVertex2i(1277, 80);

	glEnd();
	glFlush();

	//back grass right
	glBegin(GL_TRIANGLES);
	glColor3f(0.30, 0.701, 0.235);
	glVertex2i(1277, 117);
	glVertex2i(1277, 420);
	glVertex2i(600, 420);
	glEnd();
	glFlush();

	//river side
	glBegin(GL_QUADS);
	glColor3f(0.34, 0.266, 0.19);
	glVertex2i(0, 80);
	glVertex2i(0, 50);
	glVertex2i(1277, 50);
	glVertex2i(1277, 80);
	glEnd();
	glFlush();


	glBegin(GL_TRIANGLES);
	glColor3f(0.34, 0.266, 0.19);
	glVertex2i(30, 80);
	glVertex2i(60, 80);
	glVertex2i(60, 85);
	glEnd();
	glFlush();

	glBegin(GL_TRIANGLES);
	glColor3f(0.34, 0.266, 0.19);
	glVertex2i(90, 80);
	glVertex2i(140, 80);
	glVertex2i(140, 90);
	glEnd();
	glFlush();

	glBegin(GL_TRIANGLES);
	glColor3f(0.34, 0.266, 0.19);
	glVertex2i(250, 80);
	glVertex2i(350, 80);
	glVertex2i(340, 85);
	glEnd();
	glFlush();

	glBegin(GL_TRIANGLES);
	glColor3f(0.34, 0.266, 0.19);
	glVertex2i(450, 80);
	glVertex2i(580, 80);
	glVertex2i(590, 92);
	glEnd();
	glFlush();

	glBegin(GL_TRIANGLES);
	glColor3f(0.34, 0.266, 0.19);
	glVertex2i(750, 80);
	glVertex2i(850, 80);
	glVertex2i(835, 90);
	glEnd();
	glFlush();

	//river water
	glBegin(GL_QUADS);
	glColor3f(0.019, 0.35, 0.65);
	glVertex2i(0, 50);
	glVertex2i(0, 0);
	glVertex2i(1277, 0);
	glVertex2i(1277, 50);
	glEnd();
	glFlush();
}

void leftHouse()
{
	//******left house ******

	//house front part
	glBegin(GL_QUADS);
	glColor3f(0.698, 0.675, 0.612);
	glVertex2i(80, 213);
	glVertex2i(80, 120);
	glVertex2i(275, 125);
	glVertex2i(280, 213);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.28, 0.36, 0.49);
	glVertex2i(80, 120);
	glVertex2i(80, 110);
	glVertex2i(275, 114);
	glVertex2i(275, 125);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.28, 0.36, 0.49);
	glVertex2i(66, 139);
	glVertex2i(66, 135);
	glVertex2i(80, 110);
	glVertex2i(80, 120);
	glEnd();
	glFlush();


	//house left side
	glBegin(GL_QUADS);
	glColor3f(0.698, 0.675, 0.612);
	glVertex2i(65, 212);
	glVertex2i(64, 139);
	glVertex2i(80, 120);
	glVertex2i(80, 213);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(82, 120);
	glVertex2i(82, 213);
	glEnd();
	glFlush();

	//house left most window
	glBegin(GL_QUADS);
	glColor3f(0.384, 0.384, 0.384);//dark side
	glVertex2i(70, 205);
	glVertex2i(70, 178);
	glVertex2i(76, 171);
	glVertex2i(76, 204);
	glEnd();
	glFlush();

	//house left window
	glBegin(GL_QUADS);
	glColor3f(0.909, 0.780, 0.486);//house light
	glVertex2i(105, 203);
	glVertex2i(105, 165);
	glVertex2i(146, 166);
	glVertex2i(146, 203);
	glEnd();
	glFlush();

	//house left window shades
	glBegin(GL_QUADS);
	glColor3f(0.284, 0.284, 0.284);
	glVertex2i(146, 203);
	glVertex2i(145, 203);
	glVertex2i(145, 166);
	glVertex2i(146, 166);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.24, 0.24, 0.24);
	glVertex2i(105, 163);
	glVertex2i(105, 165);
	glVertex2i(146, 166);
	glVertex2i(146, 163);
	glEnd();
	glFlush();

	//house right window
	glBegin(GL_QUADS);
	glColor3f(0.909, 0.780, 0.486);
	glVertex2i(220, 204);
	glVertex2i(220, 168);
	glVertex2i(256, 168);
	glVertex2i(256, 204);
	glEnd();
	glFlush();


	//house right window middle part
	glBegin(GL_QUADS);
	glColor3f(0.30, 0.701, 0.235);
	glVertex2i(241, 204);
	glVertex2i(241, 183);
	glVertex2i(256, 178);
	glVertex2i(256, 204);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0.24, .24, .24);
	glVertex2i(240, 204);
	glVertex2i(240, 183);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0.24, .24, .24);
	glVertex2i(241, 183);
	glVertex2i(256, 178);
	glEnd();
	glFlush();



	//house door lower
	glBegin(GL_QUADS);
	glColor3f(0.24, .24, .24);
	glVertex2i(164, 146);
	glVertex2i(164, 120);
	glVertex2i(201, 121);
	glVertex2i(201, 146);
	glEnd();
	glFlush();

	glBegin(GL_TRIANGLES);
	glColor3f(0.24, .24, .24);
	glVertex2i(201, 187);
	glVertex2i(200, 146);
	glVertex2i(201, 146);
	glEnd();
	glFlush();

	//house door upper
	glBegin(GL_QUADS);
	glColor3f(0.909, 0.780, 0.486);
	glVertex2i(164, 187);
	glVertex2i(164, 146);
	glVertex2i(200, 146);
	glVertex2i(201, 187);
	glEnd();
	glFlush();




	//house roof left 
	glBegin(GL_POLYGON);
	glColor3f(0.686, 0.278, 0.180);
	glVertex2i(79, 300);
	glVertex2i(33, 233);
	glVertex2i(45, 213);
	glVertex2i(250, 213);
	glVertex2i(250, 299);
	glEnd();
	glFlush();

	//house roof front down
	glBegin(GL_TRIANGLES);
	glColor3f(0.686, 0.278, 0.180);
	glVertex2i(250, 299);
	glVertex2i(250, 213);
	glVertex2i(310, 213);
	glEnd();
	glFlush();
}

void powerHouse()
{
	//******power house *********

	//phouse base left 
	glBegin(GL_POLYGON);
	glColor3f(0.28, 0.29, 0.34);
	glVertex2i(559, 331);
	glVertex2i(559, 320);
	glVertex2i(660, 318);
	glVertex2i(660, 330);
	glVertex2i(565, 333);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	glColor3f(0.21, 0.15, 0.12);
	glVertex2i(554, 389);
	glVertex2i(564, 386);
	glVertex2i(565, 395);
	glVertex2i(607, 444);
	glVertex2i(607, 446);
	glEnd();
	glFlush();

	//phouse base ri8 
	glBegin(GL_POLYGON);
	glColor3f(0.28, 0.29, 0.34);
	glVertex2i(660, 330);
	glVertex2i(660, 318);
	glVertex2i(685, 327);
	glVertex2i(685, 336);
	glVertex2i(678, 336);
	glEnd();
	glFlush();


	//phouse wall right side
	glBegin(GL_POLYGON);
	glColor3f(0.69, 0.407, 0.34);
	glVertex2i(659, 397);
	glVertex2i(659, 329);
	glVertex2i(679, 336);
	glVertex2i(679, 386);
	glVertex2i(669, 389);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0, 0.01, 0.02);
	glVertex2i(660, 329);
	glVertex2i(660, 400);
	glEnd();
	glFlush();

	//phouse wall front
	glBegin(GL_POLYGON);
	glColor3f(0.69, 0.407, 0.34);
	glVertex2i(607, 443);
	glVertex2i(564, 396);
	glVertex2i(565, 333);
	glVertex2i(659, 329);
	glVertex2i(659, 397);
	glEnd();
	glFlush();

	//phouse door
	glBegin(GL_QUADS);
	glColor3f(0.37, 0.250, 0.12);
	glVertex2i(620, 391);
	glVertex2i(620, 331);
	glVertex2i(650, 331);
	glVertex2i(650, 390);
	glEnd();
	glFlush();

	//phouse window
	glBegin(GL_QUADS);
	glColor3f(0.909, 0.780, 0.486);
	glVertex2i(572, 390);
	glVertex2i(572, 354);
	glVertex2i(607, 354);
	glVertex2i(607, 390);
	glEnd();
	glFlush();


	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(578, 390);
	glVertex2i(578, 354);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(584, 390);
	glVertex2i(584, 353);
	glEnd();
	glFlush();


	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(590, 389);
	glVertex2i(590, 353);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(598, 389);
	glVertex2i(598, 353);
	glEnd();
	glFlush();

	//phouse top left
	glBegin(GL_QUADS);
	glColor3f(0.31, 0.31, 0.39);
	glVertex2i(545, 397);
	glVertex2i(554, 388);
	glVertex2i(607, 443);
	glVertex2i(607, 466);
	glEnd();
	glFlush();

	//phouse top right
	glBegin(GL_QUADS);
	glColor3f(0.28, 0.29, 0.34);
	glVertex2i(643, 447);
	glVertex2i(607, 466);
	glVertex2i(677, 401);
	glVertex2i(695, 394);
	glEnd();
	glFlush();

	//phouse top right
	glBegin(GL_QUADS);
	glColor3f(0.28, 0.29, 0.34);
	glVertex2i(607, 466);
	glVertex2i(607, 443);
	glVertex2i(668, 389);
	glVertex2i(677, 401);
	glEnd();
	glFlush();


	//phouse top right
	glBegin(GL_QUADS);
	glColor3f(0.28, 0.29, 0.34);
	glVertex2i(695, 394);
	glVertex2i(677, 401);
	glVertex2i(668, 389);
	glVertex2i(687, 386);
	glEnd();
	glFlush();
}

void treeBase()
{
	//tree base

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex2i(1230, 304);
	glVertex2i(1230, 169);
	glVertex2i(1260, 169);
	glVertex2i(1260, 304);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex2i(1230, 180);
	glVertex2i(1225, 170);
	glVertex2i(1265, 170);
	glVertex2i(1260, 180);
	glEnd();
	glFlush();


	//tree base 2

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex2i(1004, 360);
	glVertex2i(1004, 267);
	glVertex2i(1027, 267);
	glVertex2i(1027, 360);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex2i(1004, 267);
	glVertex2i(1000, 265);
	glVertex2i(1029, 265);
	glVertex2i(1027, 267);
	glEnd();
	glFlush();

	tree();


	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(1124, 296);
	glVertex2i(994, 317);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(1124, 296);
	glVertex2i(994, 317);
	glEnd();
	glFlush();


	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(994, 317);
	glVertex2i(850, 363);
	glEnd();
	glFlush();
}

void lightPost()
{
	//light post

	glBegin(GL_QUADS);
	glColor3f(0.37, 0.37, 0.37);
	glVertex2i(1048, 312);
	glVertex2i(1048, 87);
	glVertex2i(1071, 87);
	glVertex2i(1071, 312);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.20, 0.20, 0.20);
	glVertex2i(1010, 296);
	glVertex2i(1010, 289);
	glVertex2i(1126, 289);
	glVertex2i(1126, 296);
	glEnd();
	glFlush();



	//2nd 
	glBegin(GL_QUADS);
	glColor3f(0.37, 0.37, 0.37);
	glVertex2i(940, 330);
	glVertex2i(940, 140);
	glVertex2i(960, 140);
	glVertex2i(960, 330);
	glEnd();
	glFlush();


	glBegin(GL_QUADS);
	glColor3f(0.20, 0.20, 0.20);
	glVertex2i(920, 318);
	glVertex2i(920, 312);
	glVertex2i(995, 312);
	glVertex2i(995, 318);
	glEnd();
	glFlush();

	//left wire
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(1012, 296);
	glVertex2i(922, 319);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(780, 365);
	glVertex2i(922, 319);
	glEnd();
	glFlush();


	//3rd
	glBegin(GL_QUADS);
	glColor3f(0.37, 0.37, 0.37);
	glVertex2i(805, 375);
	glVertex2i(805, 240);
	glVertex2i(822, 240);
	glVertex2i(822, 375);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.20, 0.20, 0.20);
	glVertex2i(780, 365);
	glVertex2i(780, 360);
	glVertex2i(850, 360);
	glVertex2i(850, 365);
	glEnd();
	glFlush();
}

void Display1(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.5);
	glPointSize(4.0);

	background();

	stand();
	/////////rotatoin
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(150.0, 420.0f, 1);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	angle = angle - rate;
	glTranslatef(-100.0f, -500.0f, -2.0f);


	windmill();
	glPopMatrix();
	glFlush();

	leftHouse();
	powerHouse();
	treeBase();
	lightPost();



	//megh box
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(posX, posY, posZ);
	megh();
	dheu();
	glPopMatrix();
	glutSwapBuffers();

}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1280.0, 0.0, 768.0);
}

void update(int value)
{
	posX += move_unit;
	if (posX>1000)
	{
		posX -= 1000;
	}
	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1300, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("wind");
	glutDisplayFunc(Display1);
	myInit();
	glutTimerFunc(1000, update, 0);
	glutMainLoop();
}
