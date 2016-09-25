#include<stdio.h>
#include<math.h>
#include<glut.h>

static GLfloat spin = 0.0;
static GLfloat spin_speed = 2.0;
float spin_x = 0;
float spin_y = 1;
float spin_z = 0;

float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;

// assuming work-window width=50unit, height=25unit;
void init()
{
    	glClearColor(0,0,0,0);   
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
}

//------- custom functions starts -------

void setSpin(float x, float y, float z)
{
	spin_x = x;
	spin_y = y;
	spin_z = z;
}

void reset()
{
	spin_x = 0;
	spin_y = 1;
	spin_z = 0;
	translate_x = 0.0;
	translate_y = 0.0;
	translate_z = -30.0;
}

//------- custom functions ends   -------

void reshape(int w,int h)
{
	glViewport(0,0, (GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
	
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-6.5f);
//glRotatef(rang,0.0f,1.0f,0.0f);
glRotatef(spin,spin_x,spin_y,spin_z);


	glColor3f(0.0f,1.0f,1.0f);  
	
/*
/* Draw the bottom box */

glPushMatrix();
glScaled(0.8,0.04,0.8);
glTranslatef(0.0,-30.2,0.0); 
glutSolidCube(7.0);
glPopMatrix();

// DOOR

 //glBegin(GL_QUADS);
	//glColor3f(1.0f,1.0f,1.0f);
	//glutSolidSphere( 11, 100, 6 );
	//glEnd();

//main cube 

glTranslatef(0.0,-.6,0.0);
glutSolidCube(2.0);

//main gumbazz

glPushMatrix(); 

glScaled(0.8,1.0,0.8);
glTranslatef(0.0,1.5,0.0); 
glutSolidSphere(0.8,80,120);
glPopMatrix();
glTranslatef(0.0,1.0,0.0);
glScaled(1.2,0.25,1.2);
glutSolidCube(0.9);

//gumbaz pointer
glPushMatrix();
glScaled(0.03,0.5,0.03);
glTranslatef(0.0,10.8,0.0);
glutSolidSphere(2,80,120);
 

glPopMatrix();

//Minars
glPushMatrix();
glTranslated(2,-1.9,2);
glScaled(.2,10.5,.2);
glutSolidSphere(0.4,80,120);
glPopMatrix();

//minar's sphere

glPushMatrix();

glTranslated(2,0.8,2); 
glScaled(0.3,1.5,0.3);
glutSolidSphere(0.4,80,120);
glPopMatrix();
//Minars

glPushMatrix(); 
glTranslated(-2,-1.9,2);
glScaled(.2,10.5,.2); 
glutSolidSphere(0.4,80,120); 
glPopMatrix();

//minar's sphere

glPushMatrix();

glTranslated(-2,0.8,2);
glScaled(0.3,1.5,0.3);
glutSolidSphere(0.4,80,120);
glPopMatrix();
//Minars

glPushMatrix();
glTranslated(-2,-1.9,-2);
glScaled(.2,10.5,.2);
glutSolidSphere(0.4,80,120); 
glPopMatrix();

//minar's sphere

glPushMatrix(); 
glTranslated(-2,0.8,-2); 
glScaled(0.3,1.5,0.3);
glutSolidSphere(0.4,80,120);
glPopMatrix();
//Minars

glPushMatrix(); 
glTranslated(2,-1.9,-2);
glScaled(.2,10.5,.2);
glutSolidSphere(0.4,80,120); 
glPopMatrix();

//minar's sphere

glPushMatrix();

glTranslated(2,0.8,-2);
glScaled(0.3,1.5,0.3);
glutSolidSphere(0.4,80,120);
glPopMatrix();

//short Minars

glPushMatrix(); 

glTranslated(0.6,-0.5,0.6); glScaled(.2,11.5,.2); glutSolidSphere(0.2,80,120); glPopMatrix();

//short minar's sphere 

glPushMatrix();

glTranslated(0.6,0.5,0.6); glScaled(0.3,1.5,0.3); glutSolidSphere(0.4,80,120); glPopMatrix();

//short Minars

glPushMatrix(); 

glTranslated(0.6,-0.5,-0.6); glScaled(.2,11.5,.2); glutSolidSphere(0.2,80,120); glPopMatrix();

//short minar's sphere
glPushMatrix(); glTranslated(0.6,0.5,-0.6); glScaled(0.3,1.5,0.3); glutSolidSphere(0.4,80,120); glPopMatrix();

//short Minars

glPushMatrix();

glTranslated(-0.6,-0.5,-0.6); glScaled(.2,11.5,.2); glutSolidSphere(0.2,80,120); glPopMatrix();

//short minar's sphere

glPushMatrix();

glTranslated(-0.6,0.5,-0.6); glScaled(0.3,1.5,0.3); glutSolidSphere(0.4,80,120); glPopMatrix();

//short Minars

glPushMatrix();

glTranslated(-0.6,-0.5,0.6); glScaled(.2,11.5,.2); glutSolidSphere(0.2,80,120); glPopMatrix();

//short minar's sphere
 	 

glPushMatrix();
glTranslated(-0.6,0.5,0.6);
glScaled(0.3,1.5,0.3);
glutSolidSphere(0.4,80,120); 
glPopMatrix();
glFlush();
	glutSwapBuffers();


}

void spinDisplay(void)
{
	spin=spin+spin_speed;
	if(spin>360.0)
	{
		spin=spin-360.0;
	}
	glutPostRedisplay();
}

void spinDisplayReverse(void)
{
	spin=spin-spin_speed;
	if(spin<360.0)
	{
		spin=spin+360.0;
	}
	glutPostRedisplay();
}

void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
		case GLUT_LEFT_BUTTON:
			if(state==GLUT_DOWN)
				glutIdleFunc(spinDisplay);
		break;
		case GLUT_MIDDLE_BUTTON:
			if(state==GLUT_DOWN)
			{
				glutIdleFunc(NULL);
			   
			}
		break;
		case GLUT_RIGHT_BUTTON:
			if(state==GLUT_DOWN)
				glutIdleFunc(spinDisplayReverse);
		break;
		
		default:
		break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	//-------- spin --------
	if(key=='x')
	{
		 setSpin(1.0,0.0,0.0);
		 glutPostRedisplay();
	}
	else if(key=='y')
	{
		 setSpin(0.0,1.0,0.0);
		 glutPostRedisplay();
	}
	else if(key=='z')
	{
		setSpin(0.0,0.0,1.0);
		glutPostRedisplay();
	}
	else if(key=='a')
	{
		setSpin(1.0,1.0,1.0);
		glutPostRedisplay();
	}
	//-------- spin --------	

	//-------- zoom --------	
	else if(key=='i')
	{		
		translate_z++;
		glutPostRedisplay();
	}	
	else if(key=='o')
	{		
		translate_z--;
		glutPostRedisplay();
	}
	//-------- zoom --------

	//-------- reset -------
	else if(key=='r')
	{
		reset();
		glutPostRedisplay();		
	}
	//-------- reset -------

	GLfloat mat_ambient[]={0.0f,1.0f,2.0f,1.0f}; 
	GLfloat mat_diffuse[]={0.0f,1.5f,.5f,1.0f}; 
	GLfloat mat_specular[]={5.0f,1.0f,1.0f,1.0f}; 
	GLfloat mat_shininess[]={50.0f};
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient); 
glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse); 
glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular); 
glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
 	 
 

//GLfloat lightIntensity[]={3.7f,0.7f,0.7f,1.0f}; 
//Orange GLfloat light_position[]={2.0f,5.0f,3.0f,1.0f};
/*light source properties*/

GLfloat lightIntensity[]={1.7f,1.7f,1.7f,1.0f}; 
GLfloat light_position[]={2.0f,0.0f,0.0f,0.0f};
glLightfv(GL_LIGHT0,GL_POSITION,light_position); 
GLfloat light_position2[]={0.0f,0.0f,8.0f,0.0f}; 
glLightfv(GL_LIGHT0,GL_POSITION,light_position2); 
GLfloat light_position3[]={0.0f,5.0f,2.0f,0.5f}; 
glLightfv(GL_LIGHT0,GL_POSITION,light_position3); 
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity); 
glFlush();
glutSwapBuffers();

}

int main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(300,300);
	glutCreateWindow(argv[0]);
	//init();
	glutDisplayFunc(myDisplay);
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST); 
	glEnable(GL_NORMALIZE);
    glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
