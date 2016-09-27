islam,safrin
12-21450-2

#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<math.h>
#define PI 3.1416

int move=0,movey=0;

void drawcircle(GLfloat x, GLfloat y, GLfloat radius)
{
int triangleAmount = 2000; //# of triangles used to draw circle
float twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
for(int i = 0; i <= triangleAmount;i++)
        {
            glVertex2f( x + (radius * cos(i * twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
}

void moveright()
{
if (move==0)
        move=100;
}

void moveleft()
{
if (move==100 && move >0)
        move=move-100;
else
        move=0;
}

void movefront()
{
if (movey>-500)  //substracting lowest point of objects initial head from 0
    {
        movey=movey-5;;
    }


}

void moveback()
{
if (movey<170) //substracting 768 from highest point of legs
    {
       movey=movey+5;
    }

}

void keyboard(int key, int x, int y)
{
switch (key)
    {
case GLUT_KEY_LEFT: moveleft();
break;

case GLUT_KEY_RIGHT: moveright();
break;

case GLUT_KEY_UP: movefront();
break;

case GLUT_KEY_DOWN: moveback();
break;
    }

}

void drawroad()
{
    glBegin(GL_QUADS);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(350, 768);
        glVertex2f(350, 0);
        glVertex2f(650 , 0);
        glVertex2f(650 , 768);
    glEnd();
}

void drawdivider()
{

for(int i = 1; i <= 7; i++)
    {
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS); //creating the mid rectangles of the road;
            glVertex2f(510  , 100*i+25); //starting from 125 creating a 25 axis square box with a distance between 100
            glVertex2f(510  , 100*i-25);
            glVertex2f(490  , 100*i-25);
            glVertex2f(490  , 100*i+25);
        glEnd();
    }

}



void Init()
{
 glClearColor(0.25,0.25,0.25,0.0);
//glColor3f(1.0,1.0,0.0);
 glOrtho(0.0, 1024.0, 768.0, 0.0, 0.0, 1);//sets (0,0) to the top left position
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glColor3f(0.25, 0.25, 0.25);
//glRectf(0,768,1024,598); //Drawing ground


  drawroad();
  drawdivider();

  glColor3f(1.0, 0.0, 1.0);
    drawcircle(420+move,521+movey,18); //Drawing head
    glRectf(415+move,542+movey,425+move,535+movey);//Drawing neck
    glRectf(395+move,591+movey,445+move,542+movey);//Drawing body

    glBegin(GL_LINE_LOOP); //Drawing left hand
    glVertex2d(395+move,548+movey);
    glVertex2d(385+move,560+movey);
    glVertex2d(395+move,570+movey);
    glEnd();

    glBegin(GL_LINE_LOOP); //Drawing right hand
    glVertex2d(445+move,548+movey);
    glVertex2d(455+move,560+movey);
    glVertex2d(445+move,570+movey);
    glEnd();

    glBegin(GL_LINES);      //Drawing legs
    glVertex2d(410+move,591+movey);
    glVertex2d(410+move, 598+movey);

    glVertex2d(430+move,591+movey);
    glVertex2d(430+move, 598+movey);
    glEnd();

 glutPostRedisplay();
 glFlush();
 glutSwapBuffers();

}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1024,768);
	glutCreateWindow("Run Robot");
	Init();
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
	glutMainLoop();
}
