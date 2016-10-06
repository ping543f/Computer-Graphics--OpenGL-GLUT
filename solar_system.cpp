#include <gl/glut.h>
#include <math.h>

float RotationSpeed = 0.0;
float RotationSpeed01 = 0.0;
float RotationSpeed02 = 0.0;
float RotationSpeed03 = 0.0;

float Self_Angle = 0.0f;





void CreateCircle(float radius)
{
	float _angle =  0.0f;
	glLineWidth(3.0); // Circle ar line k mota korar jonno
	glColor3f(1.0f,1.0f,1.0f);

	//Circle create korar jonno GL_LINE_LOOP use kora hoyache
	glBegin(GL_LINE_LOOP );
		for(int i = 0; i<100; i++ )  //for hundrade point
		{
			_angle = 2*3.1416*i/100;  // [2 x pi x r] ---> ai rules a
			glVertex3f( radius*cos(_angle), 0.0, radius*sin(_angle) );
		}
	glEnd();
}


void Drawscene( )
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();

	/*gluLookAt Function ar sahajje camera angel set kora hoyeche. eyepoint theke kono matrix k kivabe dekhabe, central reference point 
	ki hobe and up vector set kore... parameter gula double value set kore */
	gluLookAt(-60.0, 40.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	//Sun
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(1.0f, 0.5f, 0.0f);
	glRotatef(Self_Angle, 0.0, 1.0, 0.0 );
	glutSolidSphere( 6.5, 15, 15);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	// mercury planet = budh groho
	CreateCircle( 12.0 );//Circle ar line ta bozha jai
	glPushMatrix();
	glTranslatef( 12.0*cos(RotationSpeed/0.25), 0., 12.0*sin(RotationSpeed/0.25) );
	glRotatef(Self_Angle, 0.0f, 1.0f, 0.0f);
	glDisable(GL_LIGHTING);
	glColor3f( 8.0f, 0.7f, 0.6f );
	glutSolidSphere( 1.5, 15, 15 );
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//mercury end

	// venus planet = Sukro groho
	CreateCircle( 19.0 );
	glPushMatrix();
	glTranslatef(19.0*cos(RotationSpeed01/0.25), 0., 19.0*sin(RotationSpeed01/0.25));
	glRotatef(Self_Angle, 1.0f, 0.0f, 0.0f);
	glDisable(GL_LIGHTING);
	glColor3f( 1.0f, 0.9f, 0.7f );
	glutSolidSphere( 3.0, 15, 15 );
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//venus end

	//earth planet = prithibi
	CreateCircle( 27.0 );
	glPushMatrix();
	glTranslatef(27.0*cos(RotationSpeed02/0.25), 0., 27.0*sin(RotationSpeed02/0.25));
	glRotatef(Self_Angle, 1.0f, 0.0f, 0.0f);
	glDisable(GL_LIGHTING);
	glColor3f(0.0f, 0.5f, 0.9f);
	glutSolidSphere( 3.5, 15, 15 );
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//earth end

	/*
	//1 ta kolpito groho
	glPushMatrix();
		glTranslatef( 27*cos(RotationSpeed02), 0., 27*sin(RotationSpeed02));
		glRotatef( RotationSpeed02*12, 0., 1., 0. );
		glTranslatef( 3., 0., 0. );
		glRotatef( RotationSpeed02, 0., 1., 0. );
		glutSolidSphere( 0.9, 15, 15 );
	glPopMatrix();
	*/

	// Jupiter planet = brihospoti
	CreateCircle( 35.0 );
	glPushMatrix();
	glTranslatef(35.0*cos(RotationSpeed03/0.25), 0., 35.0*sin(RotationSpeed03/0.25));
	glRotatef(Self_Angle, 0.0f, 1.0f, 0.0f);
	glDisable(GL_LIGHTING);
	glColor3f(1.0f, 0.5f, 0.9f);
	glutSolidSphere( 5.0, 15, 15 );
	glEnable(GL_LIGHTING);
	glPopMatrix();
	// jupeter end



	glutSwapBuffers();
}

void initialization( )
{
	glClearColor(0.0, 0.0, 0.0, 0.0); // SOKOL COLOR INITIALIZE KORA HOLO
	glShadeModel(GL_SMOOTH); // OBJECT GULA SMOOTH KORA HOLO

	GLfloat MATRIX_SHININESS[] = { 50.0 }; // OBJECT SHINGING KORTE
	GLfloat MATRIX_SPECULAR[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //OBJECT AR UPOR RED,GREEN,BLUE,ALFA REFLECT AR JONNO
	GLfloat LIGHT_POSITION[] = { 0.0, 1.0, 1.0, 0.0 };  //LIGHT SOURCE AR POSITION THIK KORA.. 0 HOLE DIRECTIONAL, 1 HOLE POSITIONAL  


	glLightfv(GL_LIGHT0, GL_POSITION, LIGHT_POSITION); //GL_LIGHT0 = light source

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

	/* PRTOTITA INCOMING DEPTH VALUE AR SATHE PRESENT DEPTH BUFFER AR TULONA KORA HOI; 
	GL_EQUAL = Passes if the incoming depth value is less than or equal to the stored depth value.*/
	glDepthFunc(GL_LEQUAL);

	//Makes 3D drawing work when something is in front of something else
    glEnable(GL_DEPTH_TEST);
}

void handleKeypress(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 27:
		exit(0);
	}
}

void spining( void )
{
	
	RotationSpeed = RotationSpeed + .0006;
	RotationSpeed01 = RotationSpeed01 + .0004;
	RotationSpeed02 = RotationSpeed02 + .0002;
	RotationSpeed03 = RotationSpeed03 + .0001;
	glutPostRedisplay();
}


void reshaping(int w, int h)
{

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	/*glFrustum ar kaj hossa current matrix k perspective ar sathe multiply kora. paramater hisabe left, right, buttom, top
	near value & far value naye kaj kore*/ 
	glFrustum(-.4, .4, -.3, .3, .5, 2000); 
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}


void spining(int x)
{
	Self_Angle = Self_Angle + 1.5f;
	if(Self_Angle > 360)
	{
		Self_Angle = -360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, spining, 0);
}

int main(int argc, char* argv[])
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize( 900, 600 );
	glutInitWindowPosition(50,50);
	glutCreateWindow( "SOLAR MODEL ASSIGNMENT" );

	initialization();

	glutDisplayFunc(Drawscene);

	glutReshapeFunc(reshaping);

	glutIdleFunc(spining);

	glutKeyboardFunc(handleKeypress);
	glutTimerFunc(25, spining, 0);

	glutMainLoop();


	return 0;
}
