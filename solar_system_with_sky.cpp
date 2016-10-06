
#include <iostream>
#include <stdlib.h>
#include <math.h>

#include <GL/glut.h>

#define RAD 180.0/3.141592
#define SIZE 300
using namespace std;

GLfloat mat_ambient[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_shininess[] = {50.0};
GLfloat light_position[] = {1.0, 1.0, -1.0, 0.0};
GLfloat model_ambient[] = {1.0, 0.5, 0.5, 1.0};

void setupMaterials() {
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
}

void changeColour(GLfloat r, GLfloat g, GLfloat b, GLfloat A) {
	model_ambient[0] = r;
	model_ambient[1] = g;
	model_ambient[2] = b;
	model_ambient[3] = A;
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	setupMaterials();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glShadeModel(GL_SMOOTH);
}

struct PLANET
{
	float radius;
	float speed;
	float xpos;
	float ypos;
	float zpos;
	float orbitradius;
	float orbitpos;
	float color[3];
};

struct PLANET mercury, venus, earth, mars, jupiter, saturn, urenus, neptune, pluto;

void initPlanets()
{
	//mercury
	mercury.radius = 0.1;
	mercury.speed = 0.00025;
	mercury.xpos = 0.0;
	mercury.ypos = 0.0;
	mercury.zpos = 0.0;
	mercury.orbitradius = 0.8;
	mercury.orbitpos = 0;
	mercury.color[0] = 0.8;
	mercury.color[1] = 0.4;
	mercury.color[2] = 0.2;

	//venus
	venus.radius = 0.12;
	venus.speed = 0.00023;
	venus.xpos = 0.0;
	venus.ypos = 0.0;
	venus.zpos = 0.0;
	venus.orbitradius = 1.0;
	venus.orbitpos = 180.0;
	venus.color[0] = 0.8;
	venus.color[1] = 0.8;
	venus.color[2] = 0.8;

	//earth
	earth.radius = 0.14;
	earth.speed = 0.00019;
	earth.xpos = 0.0;
	earth.ypos = 0.0;
	earth.zpos = 0.0;
	earth.orbitradius = 1.2;
	earth.orbitpos = 90.0;
	earth.color[0] = 0.4;
	earth.color[1] = 0.6;
	earth.color[2] = 0.8;

	//mars
	mars.radius = 0.13;
	mars.speed = 0.00017;
	mars.xpos = 0.0;
	mars.ypos = 0.0;
	mars.zpos = 0.0;
	mars.orbitradius = 1.4;
	mars.orbitpos = 270.0;
	mars.color[0] = 0.8;
	mars.color[1] = 0.2;
	mars.color[2] = 0.2;

	//jupiter
	jupiter.radius = 0.3;
	jupiter.speed = 0.00012;
	jupiter.xpos = 0.0;
	jupiter.ypos = 0.0;
	jupiter.zpos = 0.0;
	jupiter.orbitradius = 1.7;
	jupiter.orbitpos = 45.0;
	jupiter.color[0] = 0.8;
	jupiter.color[1] = 0.4;
	jupiter.color[2] = 0.3;

	//saturn
	saturn.radius = 0.26;
	saturn.speed = 0.00009;
	saturn.xpos = 0.0;
	saturn.ypos = 0.0;
	saturn.zpos = 0.0;
	saturn.orbitradius = 2.0;
	saturn.orbitpos = 135.0;
	saturn.color[0] = 0.8;
	saturn.color[1] = 0.4;
	saturn.color[2] = 0.8;

	//urenus
	urenus.radius = 0.12;
	urenus.speed = 0.00007;
	urenus.xpos = 0.0;
	urenus.ypos = 0.0;
	urenus.zpos = 0.0;
	urenus.orbitradius = 2.2;
	urenus.orbitpos = 315.0;
	urenus.color[0] = 0.8;
	urenus.color[1] = 0.2;
	urenus.color[2] = 0.4;

	//neptune
	neptune.radius = 0.12;
	neptune.speed = 0.00005;
	neptune.xpos = 0.0;
	neptune.ypos = 0.0;
	neptune.zpos = 0.0;
	neptune.orbitradius = 2.4;
	neptune.orbitpos = 225.0;
	neptune.color[0] = 0.8;
	neptune.color[1] = 0.4;
	neptune.color[2] = 0.2;

	//pluto
	pluto.radius = 0.1;
	pluto.speed = 0.00002;
	pluto.xpos = 0.0;
	pluto.ypos = 0.0;
	pluto.zpos = 0.0;
	pluto.orbitradius = 2.6;
	pluto.orbitpos = 0.0;
	pluto.color[0] = 0.2;
	pluto.color[1] = 0.2;
	pluto.color[2] = 0.2;
}

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
	}
}

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

int flag = 1;
//float _dist1 = -1.8f, _dist2 = 1.8, _dist3 = -1.8, _dist4 = 1.8;
float _cameraAngle = 0.0f;
float starx[SIZE];
float stary[SIZE];
unsigned long nSeed = 52473;
void initRand()
{
	for(int i = 0; i < SIZE; i++)
	{
		nSeed = (8253927L*nSeed+2396403);
        starx[i] = ((nSeed % 1000) / 1000.0) * 20.0;
        nSeed = (8253927L*nSeed+2396403);
        stary[i] = ((nSeed % 1000) / 1000.0) * 20.0;
	}
}

void drawStar()
{
	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (int i = 0; i < SIZE; i++)
	{
		glVertex3f(starx[i]-0.02, stary[i], 0.0f);
        glVertex3f(starx[i]+0.02, stary[i], 0.0f);

        glVertex3f(starx[i], stary[i]-0.02, 0.0f);
        glVertex3f(starx[i], stary[i]+0.02, 0.0f);

        glVertex3f(starx[i]-0.02, stary[i]-0.02, 0.0f);
        glVertex3f(starx[i]+0.02, stary[i]+0.02, 0.0f);

        glVertex3f(starx[i]-0.02, stary[i]+0.02, 0.0f);
        glVertex3f(starx[i]+0.02, stary[i]-0.02, 0.0f);
	}
	glEnd();
	glPopMatrix();
}

void drawPlanet(struct PLANET &p)
{
	p.xpos = p.orbitradius*p.orbitradius*cos(p.orbitpos*RAD);
	p.ypos = p.orbitradius*p.orbitradius*sin(p.orbitpos*RAD);

    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	changeColour(p.color[0], p.color[1], p.color[2], 1.0);
	glTranslatef(p.xpos, p.ypos, p.zpos);
	glBegin(GL_LINES);
    //glColor3fv(p.color);
	/*for(int i = 0; i < 360; i++)
	{
		glVertex3f(p.radius*cos(i*RAD), p.radius*sin(i*RAD),0.0f);
	}*/
	glutSolidSphere(p.radius,30,30);
	glEnd();
	glPopMatrix();

	p.orbitpos += p.speed;
	if(p.orbitpos >= 360.0)
	{
		p.orbitpos = 0.0;
	}
}


//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(10.0, 1.0f, 0.0f, 0.0f); //Rotate the camera
	glTranslatef(0.0f, -1.0f, -14.0f); //Move forward 5 units

	//Sender
	glPushMatrix(); //Save the transformations performed thus far
	//glTranslatef(-1.8f, 1.8f, 0.0f); //Move to the center of the trapezoid
    glRotatef(-60.0, 1.0f, 0.0f,0.0f);
    //draw the SUN
	glPushMatrix();
	changeColour(0.9, 0.4, 0.2, 1.0);
	glBegin(GL_LINES);
	glutSolidSphere(0.4f, 30, 30);
	glEnd();
	glPopMatrix();

    changeColour(1.0, 1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(-8.0f, -8.0f, 0.0f);
	drawStar();
	glPopMatrix();


	drawPlanet(mercury);
	drawPlanet(venus);
	drawPlanet(earth);
	drawPlanet(mars);
	drawPlanet(jupiter);
	drawPlanet(saturn);
	drawPlanet(urenus);
	drawPlanet(neptune);
	drawPlanet(pluto);
    glPopMatrix();
	glutSwapBuffers();
}

void update(int value) {
	//drawPlanet(mercury);
    _cameraAngle += 2.0;
    if(_cameraAngle >= 360.0)
    {
        _cameraAngle = 0.0;
    }
	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	initPlanets();
	initRand();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (800, 600);
    glutCreateWindow (argv[0]);
    init();
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
    glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}
