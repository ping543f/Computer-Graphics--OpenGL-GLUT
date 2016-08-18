#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <gl/glut.h>
//////////////////////////

GLubyte space[] =
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
GLubyte letters[][13] = {
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18},
{0x00, 0x00, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x7e, 0xe7, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0xfc, 0xce, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0xce, 0xfc},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xff},
{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xff},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xcf, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e},
{0x00, 0x00, 0x7c, 0xee, 0xc6, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06},
{0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xe0, 0xf0, 0xd8, 0xcc, 0xc6, 0xc3},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0},
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb, 0xff, 0xff, 0xe7, 0xc3},
{0x00, 0x00, 0xc7, 0xc7, 0xcf, 0xcf, 0xdf, 0xdb, 0xfb, 0xf3, 0xf3, 0xe3, 0xe3},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e},
{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x3f, 0x6e, 0xdf, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c},
{0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0xe0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x7e, 0x0c, 0x06, 0x03, 0x03, 0xff}
};
GLubyte numbers[][13] = 
	{
		{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e},// 0
		{0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78},// 1
		{0x00, 0x00, 0xff, 0xff, 0x70, 0x38, 0x0e, 0x03, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e},// 2
		{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0x03, 0x03, 0x0e, 0x03, 0x03, 0xc3, 0xe7, 0x7e},// 3
		{0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0xff, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6},// 4
		{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x03, 0x07, 0xfe, 0xc0, 0xc0, 0xc0, 0xff},// 5
		{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},// 6
		{0x00, 0x00, 0x18, 0x18, 0x0c, 0x0c, 0x0c, 0x06, 0x06, 0x06, 0x03, 0x03, 0xff},// 7
		{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0x7e, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e},// 8
		{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x7f, 0xe3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e} // 9
	};
GLuint fontOffset;
void makeRasterFont(void)
{
GLuint i, j;
glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
fontOffset = glGenLists (128);
for (i = 0,j = 'A'; i < 26; i++,j++) {
glNewList(fontOffset + j, GL_COMPILE);
glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, letters[i]);
glEndList();
}

for (i = 0,j = '0'; i < 10; i++,j++) {
glNewList(fontOffset + j, GL_COMPILE);
glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, numbers[i]);
glEndList();
}


glNewList(fontOffset + ' ', GL_COMPILE);
glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, space);
glEndList();
}
void printString(char *s)
{
glPushAttrib (GL_LIST_BIT);
glListBase(fontOffset);
glCallLists(strlen(s), GL_UNSIGNED_BYTE, (GLubyte *) s);
glPopAttrib ();
}
////////////////
const float DEG2RAD = 3.14159/180.0;
float posX = 0, posY = -3, posZ = 0;
float move_unit = 1.0f;
int point = 0;
float missileCounter = 0;

struct missile
{
    float pointX;
	float pointY;
	float colorRED;
	float colorGREEN;
	float colorBLUE;
	bool setVisible;

};
struct car
{
	float pointX;
	float pointY;
	float colorRED;
	float colorGREEN;
	float colorBLUE;
	bool setVisible;
};
struct missile m[4];
struct car car[100];
float roadCounter=0.0;
float life=100;
float gameSpeed = 5, carSpeed = 0.005;
float carSpeedCounter=0.0;
void updateSpeed()
{
	if(carSpeed<0.05){
	if(carSpeedCounter>carSpeed)
	{
		carSpeed +=0.001;
		carSpeedCounter=0.0;
	}
	carSpeedCounter+=0.0002;
	}
}


void initialCar()
{
	int yyy;
	float r,b,g;

	for(int i = 0;i<100;i++)
	{
		r = rand()%255;
		 g = rand()%255;
		 b = rand()%255;
		 r/=255;g/=255;b/=255;
		 car[i].colorRED=r;
		 car[i].colorGREEN=g;
		 car[i].colorBLUE=b;
			yyy = rand()%6;
			yyy -=3;
			car[i].pointX=yyy;
			car[i].pointY=1.5*(i+3);
			car[i].setVisible = true;

	}

}
bool isGameOver()
{
		if(life<=0)
		{
			return true;
		}
		else
			return false;
}
bool isRoadEmpty()
{
	bool flag = true;
	for(int i=0;i<100;i++)
	{
		if(car[i].setVisible)
			flag = false;
	}
//	printf("\n");
	//printf("flag %d\n",flag);
	return flag;
}
void reshape(int width, int heigth){
    /* window ro reshape when made it bigger or smaller*/

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //clip the windows so its shortest side is 2.0
    if (width < heigth) {
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)heigth / (GLfloat)width, 2.0 * (GLfloat)heigth / (GLfloat)width, 2.0, 2.0);
    }
    else{
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)width / (GLfloat)heigth, 2.0 * (GLfloat)width / (GLfloat)heigth,2.0 , 2.0);
    }
    // set viewport to use the entire new window
    glViewport(0, 0, width, heigth);
}
void drawArc(float start, float end, float radiusX,float radiusY,float positionX,float positionY)
{
	for(int i=start;i<end;i++)
   {
      float rad = i*DEG2RAD;
	  glVertex2f(positionX+cos(rad)*radiusX,
		  positionY+sin(rad)*radiusY);
   }
}

void drawCar(float r ,float g , float b)
{


    glColor3f(r,g,b);
	glBegin(GL_POLYGON);
	drawArc(230,313,.24,.11,.49,.13);
	glVertex2d(.70,.23);
	glVertex2d(.69,.43);
	glVertex2d(.69,.71);
	drawArc(-17,198,.21,.17,.49,.76);
    glVertex2d(.29,.71);
    glVertex2d(.29,.43);
	glVertex2d(.28,.23);
	glEnd();
	////
	glLineWidth(1.5);
    glColor3f(r/5,g/5,b/5);
    glBegin(GL_LINE_LOOP);
	drawArc(230,313,.24,.11,.49,.13);
	glVertex2d(.70,.23);
	glVertex2d(.69,.43);
	glVertex2d(.69,.71);
	drawArc(-17,198,.21,.17,.49,.76);
    glVertex2d(.29,.71);
    glVertex2d(.29,.43);
	glVertex2d(.28,.23);
	
	glEnd();
glLineWidth(1.0);
////////////////////////
	glColor3f(r/1.5,g/1.5,b/1.5);
	glBegin(GL_POLYGON);
	glVertex2f(.61,.53);
	drawArc(52,129,.25,.28,.49,.44);
 glVertex2f(.37,.53);
   glEnd();
	glColor3f(r/3,g/3,b/3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(.61,.53);
	drawArc(52,129,.25,.28,.49,.44);
 glVertex2f(.37,.53);
   glEnd();
   ////////
  glColor3f(r/1.5,g/1.5,b/1.5);
   glBegin(GL_POLYGON);
	glVertex2f(.38,.23);
	//drawArc(181,359,12,7,49,16);
	drawArc(-134,-45,.15,.18,.49,.27);
 glVertex2f(.60,.23);
   glEnd();
   glColor3f(r/3,g/3,b/3);
glBegin(GL_LINE_LOOP);
	glVertex2f(.38,.23);
	//drawArc(181,359,12,7,49,16);
	drawArc(-134,-45,.15,.18,.49,.27);
 glVertex2f(.60,.23);
   glEnd();
   ///////////
  glColor3f(r/1.5,g/1.5,b/1.5);
   glBegin(GL_POLYGON);
	glVertex2f(.31,.31);
	drawArc(348,390,.25,.42,.11,.36);
   glEnd();
   glColor3f(r/3,g/3,b/3);
glBegin(GL_LINE_LOOP);
	glVertex2f(.31,.31);
	drawArc(348,390,.25,.42,.11,.36);
   glEnd();
   /////////////
  glColor3f(r/1.5,g/1.5,b/1.5);
   glBegin(GL_POLYGON);
	glVertex2f(.67,.30);
	drawArc(151,194,.25,.42,.87,.36);
   glEnd();
glColor3f(r/3,g/3,b/3);
   
glBegin(GL_LINE_LOOP);
	glVertex2f(.67,.30);
	drawArc(151,194,.25,.42,.87,.36);
   glEnd();


}

void rect(){
    glBegin(GL_POLYGON);
    
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(1.0, 0.0);
    glEnd();
}
void drawRoad()
{// gluOrtho2D(-4.0, 4.0, -3.0, 3.0);
	glPushMatrix();
    glTranslatef(0,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.137, 0.556, 0.137);
    glVertex2f(-4,-3);
    glVertex2f(-4,3);
    glVertex2f(-3,3);
    glVertex2f(-3, -3);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.137, 0.556, 0.137);
    glVertex2f(3,-3);
    glVertex2f(3,3);
    glVertex2f(4,3);
    glVertex2f(4, -3);
    glEnd();
	

glColor3f(0.8,0.8,0.8);
float x=0;
	   glBegin(GL_POLYGON);
	glVertex2f(x+0.0625,5.5+roadCounter);
    glVertex2f(x+0.0625,3.5+roadCounter);
    glVertex2f(x-0.0625,3.5+roadCounter);
    glVertex2f(x-0.0625,5.5+roadCounter);
    glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x+0.0625,1.5+roadCounter);
    glVertex2f(x+0.0625,-0.5+roadCounter);
    glVertex2f(x-0.0625,-0.5+roadCounter);
    glVertex2f(x-0.0625,1.5+roadCounter);
    glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(x+0.0625,-2.5+roadCounter);
    glVertex2f(x+0.0625,-4.5+roadCounter);
    glVertex2f(x-0.0625,-4.5+roadCounter);
    glVertex2f(x-0.0625,-2.5+roadCounter);
	glEnd();
 
	////////////////
   glTranslatef(4.0,-2.5,0.0);
   //life bar
   glBegin(GL_POLYGON);
	glColor3f(0.15,0.15,0.15);
	glVertex2f(0.625,2);
    glVertex2f(0.625,0.0);
    glVertex2f(0.375,0.0);
    glVertex2f(0.375,2);
	glEnd();
	if(life>50)
	{
         glColor3f(0.02*(100-life),1,0.0);
	}
	else
	{
		glColor3f(1,0.02*life,0);
	}
	glBegin(GL_POLYGON);

	glVertex2f(0.625,0.02*life);
    glVertex2f(0.625,0.0);
    glVertex2f(0.375,0.0);
    glVertex2f(0.375,0.02*life);
    glEnd();
	//glColor3f(0.1,0.0,0.8);

	//speed bar
	glBegin(GL_POLYGON);
	glColor3f(0.15,0.15,0.15);
	glVertex2f(1.625,2);
    glVertex2f(1.625,0.0);
    glVertex2f(1.375,0.0);
    glVertex2f(1.375,2);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1-20*carSpeed,0);
	glVertex2f(1.625,40*carSpeed);
   glColor3f(1,1,0);
    glVertex2f(1.625,0.0);
    glVertex2f(1.375,0.0);
	glColor3f(1,1-20*carSpeed,0);
    glVertex2f(1.375,40*carSpeed);
    glEnd();
	///////////////

	  glBegin(GL_POLYGON);
    glColor3f(0.15,0.15,0.15);
    glVertex2f(0.375, 2.5);
    glVertex2f(0.375, 3);
	glVertex2f(1.625,3);
	glVertex2f(1.625, 2.5);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.15,0.15,0.45);
    glVertex2f(0.375, 2.5);
    glVertex2f(0.375, 3);
	glVertex2f(0.375+0.625*missileCounter,3);
	glVertex2f(0.375+0.625*missileCounter, 2.5);
    glEnd();
glPopMatrix();


}
void drawEnemy()
{
	
	for(int i=0;i<100;i++)
	{
		if(car[i].setVisible)
		{
			if(car[i].pointY<3&&car[i].pointY>-4){
			glPushMatrix();
			glTranslatef(car[i].pointX,car[i].pointY,0);
			drawCar(car[i].colorRED,car[i].colorGREEN,car[i].colorBLUE);
			  glPopMatrix();
			}
			if(car[i].pointY<=-4)
			car[i].setVisible = false;
		}
	}
}
void drawMissile()
{
	for(int i=0;i<4;i++)
	{
		if(m[i].setVisible)
		{
			if(m[i].pointY<3)
			{
				glPushMatrix();
				glTranslatef(m[i].pointX,m[i].pointY,0);
				glBegin(GL_POLYGON);
				glColor3f(1,0,0);
				drawArc(0,181,.04,.1,0.49,0.53);
				glEnd();
				glBegin(GL_POLYGON);
				glColor3f(1,1,1);
				glVertex2f(.45, 0.53);
				glVertex2f(.53, .53);
				glVertex2f(.53, .23);
				glVertex2f(.45, .23);
				glEnd();
				glPopMatrix();
			}
			else
			{
				m[i].setVisible = false;
			}
			
		}
}
}
void printText()
{
	char buffer[10];
	char str[80];
	int missile = missileCounter*2;
	//print score
	glPushMatrix();
	glTranslatef(4.5,2,0);
	glColor3f(1,1,1);
	glRasterPos2i(0, 0);
	
	sprintf(buffer, "%d", point);
    strcpy (str,"SCORE ");
    strcat (str,buffer);
	printString(str);
	glPopMatrix();
	///
	glPushMatrix();
	glTranslatef(4.25,-2.7,0);
	glColor3f(1,1,1);
	glRasterPos2i(0, 0);
	printString(" LIFE     SPEED");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.44,0.20,0);
	glColor3f(1,1,1);
	glRasterPos2i(0, 0);
	sprintf(buffer, "%d", missile);
    strcpy (str,"MISSILE ");
    strcat (str,buffer);
	printString(str);
	glPopMatrix();

}
void display(){
    //Clear Window
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	drawRoad();
	drawEnemy();
	
drawMissile();
    glPushMatrix();
    glTranslatef(posX,posY,posZ);

	drawCar(.5,.5,.5);
    
	glPopMatrix();


	printText();

    glFlush();
}


void init(){
	//set missile visibility false
	for(int i=0;i<4;i++)
	{
		m[i].setVisible = false;
	}
	//create color box
	initialCar();



    // set clear color to black
    glClearColor(0.08,0.08,0.08,0.0);

    // set fill color to white
    glColor3f(1.0, 1.0, 1.0);

    //set up standard orthogonal view with clipping
    //box as cube of side 2 centered at origin
    //This is the default view and these statements could be removed
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-4.0, 6.0, -3.0, 3.0);
	makeRasterFont();

}


void keyboard(unsigned char key, int x, int y)
{
	float move_unit = 1.0f;
	switch (key){
		case ' ':
			if(missileCounter>0.50)
			{
				missileCounter-=0.50;
				for(int i=0;i<4;i++)
				{
					if(!m[i].setVisible)
					{
						m[i].pointX = posX;
						m[i].pointY = posY;
						m[i].setVisible = true;
						break;
					}
				}
			}
            break;


        default:
         break;
	}
	glutPostRedisplay();
}



void keyboardown(int key, int xx, int yy)
{
    switch (key){
        case GLUT_KEY_RIGHT:
			if(posX<2)
				posX+=move_unit;
            break;

        case GLUT_KEY_LEFT:
			if(posX>-3)
            posX-=move_unit;
        break;

        case GLUT_KEY_UP:
			if(posY<2)
            posY+=move_unit;
            break;

        case GLUT_KEY_DOWN:
			if(posY>-3)
            posY-=move_unit;
        break;

        default:
         break;
    }

    glutPostRedisplay();
}
bool isCarCollusion()
{
	bool flag = false;
	for(int i=0;i<100;i++)
	{
		if(car[i].setVisible){
			float a,b;
			if(posX>car[i].pointX)
				a=posX-car[i].pointX;
			else
				a= car[i].pointX-posX;
			if(posY>car[i].pointY)
				b=posY-car[i].pointY;
			else
				b= car[i].pointY-posY;
			if(a<1&&b<0.9)
			{
				flag = true;
				car[i].setVisible = false;
			}
		}
	}
	return flag;

}
///
bool isMissileCollusion()
{
	//printf("%d",setMissile);
	bool flag = false;//printf("\n");
	for(int mm=0;mm<4;mm++)
	{
		if(m[mm].setVisible)
		{
			for(int i=0;i<100;i++)
			{
				if(car[i].setVisible)
				{
					float a,b;
					if(m[mm].pointX>car[i].pointX)
						a=m[mm].pointX-car[i].pointX;
					else
						a= car[i].pointX-m[mm].pointX;

					if(m[mm].pointY>car[i].pointY)
						b=m[mm].pointY-car[i].pointY;
					else
						b= car[i].pointY-m[mm].pointY;

					if(b<0.7&&a<1)
					{
						flag = true;
						m[mm].setVisible = false;
						car[i].setVisible = false;
						//printf("%d %d %d\n",m[mm].setVisible ,	car[i].setVisible,mm);
						
					}
				}
			}
		}
	}
	return flag;

}
void update(int value) {
	for(int i=0;i<100;i++)
	{
		car[i].pointY-=carSpeed;
		
	}
	roadCounter-=2*carSpeed;
	if(roadCounter<-3.5)
	{
		roadCounter=0.5;
		point++;
		if(isRoadEmpty())
		{
			initialCar();
		}
	}
	glutPostRedisplay(); //Tell GLUT that the display has changed
	for(int i=0;i<4;i++)
	{
		if(m[i].setVisible)
		{
			m[i].pointY+=0.03;
		}
	}
	//missilePointY+=.03;
	//check collition
	if(isCarCollusion())
	{
		life -= 10;
		carSpeed/=2;
	
	}


		isMissileCollusion();
	
	updateSpeed();
	if(missileCounter<2){
		missileCounter+=0.0005;
	}
	if(isGameOver())
		return;
	//Tell GLUT to call update again in 25 milliseconds
		glutTimerFunc(gameSpeed, update, 0);
		
}

int main(int argc, char** argv){
    //initialize mode and open a windows in upper left corner of screen
    //Windows tittle is name of program
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Car Game");
	//start:

    glutDisplayFunc(display);
    init();
	glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardown);
	
	glutTimerFunc(2000, update, 0); //Add a timer

    glutMainLoop();
}