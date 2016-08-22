/* Graphics Final Project(Boy With a Ballon)

Islam, Md. Najrul--13-24747-2
Rahman, Md. Hasibur--13-23141-1
Ahmed, Abu Syeed--12-21201-1
Hossain Shakawat--13--23372-1
*/

#include <stdio.h>
#include <stdlib.h> 
#include <GL/glut.h>
#include <time.h>

float x=200, y=-60;
float x1 = 650, y1=20; //x2 = 750, y2 = 50, x3 = 950, y3 =-10, x4=1150, y4=-50, x5=1350, y5=-110;
int score, exit1 = 1;

void boy(float a, float b){

	glBegin(GL_POLYGON);//head
	glColor3f(1, 1, 1);

	glVertex2f(20 + a, 230 + b);//head 1st co-ordinate(-x+y)
	glVertex2f(20.3 + a, 231 + b);
	glVertex2f(20.7+ a, 232 + b);
	glVertex2f(21+ a, 233 + b);
	glVertex2f(21.3 + a, 234 + b);
	glVertex2f(21.7 + a, 235 + b);
	glVertex2f(22.3+ a, 236 + b);
	glVertex2f(22.7 + a, 236.5 + b);
	glVertex2f(23 + a, 237 + b);
	glVertex2f(23.5 + a, 237.3 + b);
	glVertex2f(24 + a, 237.7 + b);
	glVertex2f(24.5 + a, 238+ b);
	glVertex2f(25 + a, 238.3 + b);
	glVertex2f(26 + a, 238.7 + b);
	glVertex2f(27 + a, 239 + b);
	glVertex2f(28 + a, 239.3 + b);
	glVertex2f(29 + a, 239.7 + b);
	glVertex2f(30 + a, 240 + b);


	glVertex2f(31 + a, 239.7 + b);//head 2nd co-ordinate(+x+y)
	glVertex2f(32 + a, 239.5 + b);
	glVertex2f(33 + a, 239.3 + b);
	glVertex2f(33.5 + a, 239 + b);
	glVertex2f(34 + a, 238.7 + b);
	glVertex2f(34.5 + a, 238.3+ b);
	glVertex2f(34.7 + a, 238 + b);
	glVertex2f(34.9 + a, 237.7 + b);
	glVertex2f(35 + a, 237.5 + b);
	glVertex2f(35.2 + a, 237.4 + b);
	glVertex2f(35.3 + a, 237.3 + b);
	glVertex2f(35.5 + a, 237.1 + b);
	glVertex2f(35.7 + a, 237 + b);
	glVertex2f(35.9 + a, 236.9 + b);
	glVertex2f(36 + a, 236.7 + b);
	glVertex2f(36.3 + a, 236.3 + b);
	glVertex2f(36.7+ a, 236 + b);
	glVertex2f(37 + a, 235.7 + b);
	glVertex2f(37.3 + a, 235.3+ b);
	glVertex2f(37.7 + a, 235 + b);
	glVertex2f(38 + a, 234.5 + b);
	glVertex2f(38.3 + a, 234+ b);
	glVertex2f(38.7 + a, 233.5 + b);
	glVertex2f(39 + a, 233 + b);
	glVertex2f(39.3 + a, 232+ b);
	glVertex2f(39.7 + a, 231 + b);
	glVertex2f(40 + a, 230+ b);


	glVertex2f(39.7 + a, 229 + b);//head 3rd co-ordinate(+x-y)
	glVertex2f(39.3 + a, 228 + b);
	glVertex2f(39 + a, 227 + b);
	glVertex2f(38.7 + a, 226.5 + b);
	glVertex2f(38.3 + a, 226 + b);
	glVertex2f(38 + a, 225.5 + b);
	glVertex2f(37.7 + a, 225 + b);
	glVertex2f(37.3 + a, 224.5 + b);
	glVertex2f(37 + a, 224 + b);
	glVertex2f(36.7 + a, 223.7 + b);
	glVertex2f(36 + a, 223.3 + b);
	glVertex2f(35.7 + a, 223  + b);
	glVertex2f(35.3 + a, 222.7 + b);
	glVertex2f(35 + a, 222.3 + b);
	glVertex2f(34.5 + a, 222 + b);
	glVertex2f(34 + a, 221.7 + b);
	glVertex2f(33.5 + a, 221.3 + b);
	glVertex2f(33 + a, 221 + b);
	glVertex2f(32 + a, 220.7 + b);
	glVertex2f(31 + a, 220.3 + b);
	glVertex2f(30 + a, 220 + b);

	glVertex2f(29 + a, 220.3 + b);//head 4th co-ordinate(-x-y)
	glVertex2f(28 + a, 220.7 + b);
	glVertex2f(27.5 + a, 221 + b);
	glVertex2f(27 + a, 221.3 + b);
	glVertex2f(26.5 + a, 221.7 + b);
	glVertex2f(26 + a, 222 + b);
	glVertex2f(25.5 + a, 222.3 + b);
	glVertex2f(25 + a, 222.7 + b);
	glVertex2f(24.5 + a, 223 + b);
	glVertex2f(24 + a, 223.3 + b);
	glVertex2f(23.7 + a, 223.5 + b);
	glVertex2f(23.3 + a, 224 + b);
	glVertex2f(23 + a, 224.5 + b);
	glVertex2f(22.7 + a, 225 + b);
	glVertex2f(22.3 + a, 225.5 + b);
	glVertex2f(22 + a, 226 + b);
	glVertex2f(21.7 + a, 226.5 + b);
	glVertex2f(21.3 + a, 227 + b);
	glVertex2f(21 + a, 227.5 + b);
	glVertex2f(20.7 + a, 228 + b);
	glVertex2f(20.3 + a, 229 + b);
	glVertex2f(20 + a, 230 + b);
	glEnd();


	glBegin(GL_POLYGON);//left eye
	glColor3f(0, 0, 0);
	glVertex2f(25 + a, 228 + b);
	glVertex2f(23 + a, 230 + b);
	glVertex2f(25 + a, 232 + b);
	glVertex2f(27 + a, 230 + b);
	glEnd();

	glBegin(GL_POLYGON);//right eye
	glColor3f(0, 0, 0);
	glVertex2f(35 + a, 228 + b);
	glVertex2f(33 + a, 230 + b);
	glVertex2f(35 + a, 232 + b);
	glVertex2f(37 + a, 230 + b);
	glEnd();

	/*glBegin(GL_LINE_STRIP);//mouth
	glColor3f(0, 0, 0);
	glVertex2f(28 + a, 228 + b);
	glVertex2f(30 + a, 225 + b);
	glVertex2f(32 + a, 228 + b);
	glEnd();*/


	glBegin(GL_POLYGON);//body
	glColor3f(.73, .36, .36);
	glVertex2f(18 + a, 215 + b);
	glVertex2f(25 + a, 220 + b);
	glVertex2f(35 + a, 220 + b);
	glVertex2f(42 + a, 215 + b);
	glVertex2f(42 + a, 180 + b);
	glVertex2f(18 + a, 180 + b);
	glEnd();

	glBegin(GL_POLYGON);//left leg
	glColor3f(1, 1, 1);
	glVertex2f(20 + a, 180 + b);
	glVertex2f(25 + a, 180 + b);
	glVertex2f(25 + a, 160 + b);
	glVertex2f(20 + a, 160 + b);
	glEnd();

	glBegin(GL_POLYGON);//right leg
	glColor3f(1, 1, 1);
	glVertex2f(35 + a, 180 + b);
	glVertex2f(40 + a, 180 + b);
	glVertex2f(40 + a, 160 + b);
	glVertex2f(35 + a, 160 + b);
	glEnd();


	glBegin(GL_LINES);//left hand
	glColor3f(1, 1, 1);
	glVertex2f(18 + a, 210 + b);
	glVertex2f(12 + a, 205 + b);
	glVertex2f(12 + a, 205 + b);
	glVertex2f(12 + a, 195 + b);
	glEnd();

	glBegin(GL_LINES);//right hand
	glColor3f(1, 1, 1);
	glVertex2f(42 + a, 210 + b);
	glVertex2f(50 + a, 200 + b);
	glEnd();

	glBegin(GL_LINES);//bellon stand
	glColor3f(1, 1, 1);
	glVertex2f(50 + a, 200 + b);
	glVertex2f(50 + a, 250 + b);
	glEnd();

}

void ballon(float a, float b)
{
	glBegin(GL_POLYGON);//head
	glColor3f(0.7,0.5,0.7);

	glVertex2f(40 + a, 260 + b);//head 1st co-ordinate
	glVertex2f(40.3 + a, 261 + b);
	glVertex2f(40.7+ a, 262 + b);
	glVertex2f(41+ a, 263 + b);
	glVertex2f(41.3 + a, 264 + b);
	glVertex2f(41.7 + a, 265 + b);
	glVertex2f(42.3+ a, 266 + b);
	glVertex2f(42.7 + a, 266.5 + b);
	glVertex2f(43 + a, 267 + b);
	glVertex2f(43.5 + a, 267.3 + b);
	glVertex2f(44 + a, 267.7 + b);
	glVertex2f(44.5 + a, 268+ b);
	glVertex2f(45 + a, 268.3 + b);
	glVertex2f(46 + a, 268.7 + b);
	glVertex2f(47 + a, 269 + b);
	glVertex2f(48 + a, 269.3 + b);
	glVertex2f(49 + a, 269.7 + b);
	glVertex2f(50 + a, 270 + b);


	glVertex2f(51 + a, 269.7 + b);//head 2nd co-ordinate
	glVertex2f(52 + a, 269.5 + b);
	glVertex2f(53 + a, 269.3 + b);
	glVertex2f(53.5 + a, 269 + b);
	glVertex2f(54 + a, 268.7 + b);
	glVertex2f(54.5 + a, 268.3+ b);
	glVertex2f(54.7 + a, 268 + b);
	glVertex2f(54.9 + a, 267.7 + b);
	glVertex2f(55 + a, 267.5 + b);
	glVertex2f(55.2 + a, 267.4 + b);
	glVertex2f(55.3 + a, 267.3 + b);
	glVertex2f(55.5 + a, 267.1 + b);
	glVertex2f(55.7 + a, 267 + b);
	glVertex2f(55.9 + a, 266.9 + b);
	glVertex2f(56 + a, 266.7 + b);
	glVertex2f(56.3 + a, 266.3 + b);
	glVertex2f(56.7+ a, 266 + b);
	glVertex2f(57 + a, 265.7 + b);
	glVertex2f(57.3 + a, 265.3+ b);
	glVertex2f(57.7 + a, 265 + b);
	glVertex2f(58 + a, 264.5 + b);
	glVertex2f(58.3 + a, 264+ b);
	glVertex2f(58.7 + a, 263.5 + b);
	glVertex2f(59 + a, 263 + b);
	glVertex2f(59.3 + a, 262+ b);
	glVertex2f(59.7 + a, 261 + b);
	glVertex2f(60 + a, 260+ b);


	glVertex2f(59.7 + a, 259 + b);//head 3rd co-ordinate
	glVertex2f(59.3 + a, 258 + b);
	glVertex2f(59 + a, 257 + b);
	glVertex2f(58.7 + a, 256.5 + b);
	glVertex2f(58.3 + a, 256 + b);
	glVertex2f(58 + a, 255.5 + b);
	glVertex2f(57.7 + a, 255 + b);
	glVertex2f(57.3 + a, 254.5 + b);
	glVertex2f(57 + a, 254 + b);
	glVertex2f(56.7 + a, 253.7 + b);
	glVertex2f(56 + a, 253.3 + b);
	glVertex2f(55.7 + a, 253  + b);
	glVertex2f(55.3 + a, 252.7 + b);
	glVertex2f(55 + a, 252.3 + b);
	glVertex2f(54.5 + a, 252 + b);
	glVertex2f(54 + a, 251.7 + b);
	glVertex2f(53.5 + a, 251.3 + b);
	glVertex2f(53 + a, 251 + b);
	glVertex2f(52 + a, 250.7 + b);
	glVertex2f(51 + a, 250.3 + b);
	glVertex2f(50 + a, 250 + b);

	glVertex2f(49 + a, 250.3 + b);//head 4th co-ordinate
	glVertex2f(48 + a, 250.7 + b);
	glVertex2f(47.5 + a, 251 + b);
	glVertex2f(47 + a, 251.3 + b);
	glVertex2f(46.5 + a, 251.7 + b);
	glVertex2f(46 + a, 252 + b);
	glVertex2f(45.5 + a, 252.3 + b);
	glVertex2f(45 + a, 252.7 + b);
	glVertex2f(44.5 + a, 253 + b);
	glVertex2f(44 + a, 253.3 + b);
	glVertex2f(43.7 + a, 253.5 + b);
	glVertex2f(43.3 + a, 254 + b);
	glVertex2f(43 + a, 254.5 + b);
	glVertex2f(42.7 + a, 255 + b);
	glVertex2f(42.3 + a, 255.5 + b);
	glVertex2f(42 + a, 256 + b);
	glVertex2f(41.7 + a, 256.5 + b);
	glVertex2f(41.3 + a, 257 + b);
	glVertex2f(41 + a, 257.5 + b);
	glVertex2f(40.7 + a, 258 + b);
	glVertex2f(40.3 + a, 259 + b);
	glVertex2f(40 + a, 260 + b);
	glEnd();

}

void box(float a, float b){

	glBegin(GL_QUADS);

	glColor3f(1, 0, 0);//red box
	glVertex2f(20 + a, 220 + b);
	glVertex2f(70 + a, 220 + b);
	glVertex2f(70 + a, 240 + b);
	glVertex2f(20 + a, 240 + b);
	glEnd();
}

void drawDisplay(void){

	glClear(GL_COLOR_BUFFER_BIT);
	//down road-side
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0, 0);
	glVertex2f(0,120);
	glVertex2f(650, 120);
	glVertex2f(650, 0);
	glEnd();


	//road
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0, 120);
	glVertex2f(650,120 );
	glVertex2f(650, 380);
	glVertex2f(0, 380);
	glEnd();

	//up road-side
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0, 550);
	glVertex2f(650, 550);
	glVertex2f(650, 380);
	glVertex2f(0, 380);
	glEnd();

}

void drawSc(int scor){

	int i, j, k;
	i = scor / 100;
	j = scor / 10 - i * 10;
	k = scor - j * 10 - i * 100;
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslated(480, 440, 0);
	glScaled(.2, .2, 0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'S');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'c');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)':');
	glColor3f(1.0, 0.0, 0.0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)i + 48);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)j + 48);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)k + 48);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslated(480, 50, 0);
	glScaled(.06, .1, 0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'P');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'S');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'a');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslated(480, 35, 0);
	glScaled(.06, .1, 0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'P');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'q');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'q');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'u');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'i');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glPopMatrix();
}

int random()
{
	srand((int)time(0));//random generation
	int c= rand() % 5 + 1;
	if(c==1)
	{
		y1=110;
	}
	else if(c==2)
	{
		y1=50;
	}
	else if(c==3)
	{
		y1=-10;
	}
	else if(c==4)
	{
		y1=-50;
	}
	else if(c==4)
	{
		y1=-110;
	}
	return y1;
}

void myDisplay()
{

	if (exit1 == 1)
	{	

		/*if(y<-120 || y>120)
		{
		printf("Y\n");
		printf("%f\n",x);
		printf("%f\n",x1);
		printf("%f\n",y);
		exit1 = 1;
		}*/
		if(x1<=x+40 && x1>x+20 && y==y1-30)
		{
			printf("X1\n");
			printf("%f\n",x);
			printf("%f\n",x1);
			printf("%f\n",y);
			exit1 = 0;
		}
		

		if (score < 25)
		{
			x1 -= .5;
			/*x2 -= .8;
			x3 -= .9;
			x4 -= 1;
			x5 -= 1.1;*/
		}
		if (score >= 20 && score < 50)
		{
			x1 -= 2.1;
			/*x2 -= 1.3;
			x3 -= 1.4;
			x4 -= 1.5;
			x5 -= 1.6;*/
		}
		if (score >= 50)
		{
			x1 -= 2.3;
			/*x2 -= 1.8;
			x3 -= 1.9;
			x4 -= 2;
			x5 -= 2.1;*/
		}

		if (x1 < -500)
		{
			score += 1;
			srand((int)time(0));//random generation
			int c= rand() % 8 + 1;
			if(c==1)
			{
				x1 = 600;
				y1=130;
			}
			else if(c==2)
			{
				x1 = 590;
				y1=110;
			}
			else if(c==3)
			{
				x1 = 610;
				y1=90;
			}
			else if(c==4)
			{
				x1 = 620;
				y1=70;
			}
			else if(c==5)
			{
				x1 = 590;
				y1=50;
			}
			else if(c==6)
			{
				x1 = 620;
				y1=30;
			}
			else if(c==7)
			{
				x1 = 580;
				y1=10;
			}
			else if(c==8)
			{
				x1 = 610;
				y1=-10;
			}

		}

		glClear(GL_COLOR_BUFFER_BIT);
		drawDisplay();
		drawSc(score);
		if(exit1==1)
		{
			ballon(x,y);
		}
		boy(x, y);
		box(x1, y1);
		//box(x2, y2);
		//box(x3, y3);
		//box(x4, y4);
		//box(x5, y5);
		glutSwapBuffers();

	}
	if(exit1==2)
	{
		glutPostRedisplay();
	}

	if (exit1==0)
	{
		glutPostRedisplay();
		for(int i =0;i<900000000;i++)
		{

		}


		glClear(GL_COLOR_BUFFER_BIT);


		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(0, 550);
		glVertex2f(650, 550);
		glVertex2f(650, 0);
		glVertex2f(0, 0);
		glEnd();



		drawSc(score);
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslated(200, 400, 0);
		glScaled(.4, .4, 0);

		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'G');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'A');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'M');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'E');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'O');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'V');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'E');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'R');
		glEnd();
		glPopMatrix();

		glutSwapBuffers();
	}

}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void keyboards(unsigned char keys, int x4, int y4)
{
	//start key	
	if (keys == 's')
	{
		glutIdleFunc(myDisplay);
	}
	//stop key
	if (keys == 'q')
	{
		exit(-1);
	}

	if(keys=='0')
	{
		exit1=2;
	}
	if(keys=='1')
	{
		exit1=1;
	}


	glutPostRedisplay();
}

void keyPressed( int keys, int x4, int y4)
{
	if (keys == GLUT_KEY_LEFT)
		x -= 20;
	if (keys == GLUT_KEY_RIGHT)
		x += 20;
	if (keys == GLUT_KEY_UP)
		y += 20;
	if (keys == GLUT_KEY_DOWN)
		y -= 20;
	glutPostRedisplay();
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(150, 50);
	glutCreateWindow("Boy With a Bellon");
	glutDisplayFunc(myDisplay);
	glutSpecialFunc(keyPressed);
	glutKeyboardFunc(keyboards);
	myInit();
	glutMainLoop();
}
