#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

float posX = 15;
float posY = 40;
float bspd=0.04;
float b1x=50.0,b1y=0;//block 1
float b=0.0;//ball moving
int i=0,sci=0;
int wflag=1;

void drawball()
{
	glColor3f(1.0,1.0,1.0);

	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(posX+x, posY+y );
	}
    glEnd();

}

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);


	if( (i==460||i==-290) //top and bottom checking
||(((int)b1x==7||(int)b1x==3||(int)b1x==4)&&(int)b1y<45+(int)b&&(int)b1y+20>30+(int)b)//lower body checking
||(((int)b1x==0)&&(int)b1y<45+(int)b&&(int)b1y+20>30+(int)b)//lower tail checking
	)
	{
		glColor3f(0.9,0.9,0.9);
		glRectf(0.0,0.0,100.0,100.0);
		glColor3f(0.1,0.1,0.1);
		glutSwapBuffers();
		glFlush();
		printf("GAME OVER");
		exit(0);
	}
    if(wflag==1)//Welcome Screen
	{
		wflag=0;
		glColor3f(0.3,0.3,0.3);
		printf("CLICK TO START\n");
		printf("CLICK AND HOLD LEFT MOUSE BUTTON TO GO UP\n");
		printf("RELEASE TO GO DOWN\n");
		drawball();
		glutSwapBuffers();
		glFlush();
	}
	else
	{
		glPushMatrix();
		glColor3f(0.3,0.3,0.3);
		glRectf(0.0,0.0,1000.0,10.0);//floor
		glRectf(0.0,100.0,1000.0,90.0);//ceil
		glTranslatef(0.0,b,0.0);
		drawball();
		if(b1x<-10)
		{
			b1x=50;
			b1y=(rand()%25)+20;
		}
		else b1x-=bspd;
		glTranslatef(b1x,-b,0.0);
		glColor3f(0.0,1.0,0.0);
		glRectf(b1x,b1y,b1x+5,b1y+35);//block 1
		glPopMatrix();
		glutSwapBuffers();
		glFlush();
	}
}
void ballup()
{
	b+=0.1;
	i++;
	glutPostRedisplay();
}
void balldown()
{
	b-=0.1;
	i--;
	glutPostRedisplay();
}
void Reshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w<=h)
        gluOrtho2D(0.0,640.0,0.0,480.0);//,-10.0,20.0);
	else
	gluOrtho2D(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0);//,-10.0,20.0);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void mouse(int btn,int state,int x,int y)
{
	if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		glutIdleFunc(ballup);
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP)
		glutIdleFunc(balldown);

		glutPostRedisplay();
}

void init(void)
{
	b1y=(rand()%45)+10;
	glClearColor (0.0, 0.0, 0.0, 0.0);
	//glMatrixMode(GL_PROJECTION);
	glShadeModel (GL_SMOOTH);
	glLoadIdentity ();
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);//, -1.0 , 0.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (1000, 1000);
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Jumping Bubble");
	init();
	glutReshapeFunc(Reshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();

	return 0;
}


//Courtesy: 1. https://www.youtube.com/watch?v=7PkoWJrYXQ0
//          2. Source code of Missile Control Game which one uploded in vues

// Saiket, Shah Paran.     ID-14-26994-2
// Tasnim, Anika.          ID-14-26955-2
// Khan,Md. Nazmul         ID-13-23971-2
// Tanmoy, Asheq Siddiquee ID-14-26053-1*/
