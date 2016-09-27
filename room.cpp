# include <iostream>
#include <gl\glut.h>	//Mostafiz,Md.Tasrul(12-20782-1)
using namespace std;    //Zaidi,Abir Mohammad Mahbub (12-20640-1)

static float  megh_t = 0.0;
static float  drop_t = 0.0;

void triangle()
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.88, 0.88, 0.88);
glPointSize(4.0);
glBegin(GL_TRIANGLES);
glVertex2f(0.0,768.0);
glVertex2f(0.0,748.0);
glVertex2f(70.0,748.0);
glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0, 0.0, 0.0);
glVertex2f(0.0,768.0);
glVertex2f(0.0,748.0);
glVertex2f(70.0,748.0);

glEnd();
glFlush ();

}

void roof()
{
//roof
glBegin(GL_POLYGON);
glColor3f (0.96, 0.96, 0.93);
glVertex2f(0.0,768.0);
glVertex2f(70.0,748.0);
glVertex2f(130.0,748.0);
glVertex2f(300.0,718.0);
glVertex2f(800.0,718.0);
glVertex2f(1024.0,768.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0, 0.0, 0.0);
glVertex2f(0.0,768.0);
glVertex2f(70.0,748.0);
glVertex2f(130.0,748.0);
glVertex2f(300.0,718.0);
glVertex2f(800.0,718.0);
glVertex2f(1024.0,768.0);

glEnd();
glFlush ();
}

void floor()
{
//floor
glBegin(GL_QUADS);
glColor3f (1.1,1.0,0.6);
glVertex2f(130.0,0.0);
glVertex2f(1024.0,0.0);
glVertex2f(800.0,238.0);
glVertex2f(300.0,238.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(130.0,0.0);
glVertex2f(1024.0,0.0);
glVertex2f(800.0,238.0);
glVertex2f(300.0,238.0);

glEnd();
glFlush ();

}
void background_wall()
{
//background wall
glBegin(GL_POLYGON);
glColor3f (0.2,0.1,0.0);

glVertex2f(800.0,718.0);
glVertex2f(300.0,718.0);
glVertex2f(300.0,538.0);
glVertex2f(220.0,491.0);
glVertex2f(220.0,360.0);
glVertex2f(300.0,360.0);
glVertex2f(300.0,238.0);
glVertex2f(800.0,238.0);

glEnd();
glFlush ();


glBegin(GL_QUADS);
glColor3f (0.25,0.25,0.25);

glVertex2f(700.0,718.0);
glVertex2f(500.0,718.0);
glVertex2f(500.0,360.0);
glVertex2f(700.0,360.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(700.0,718.0);
glVertex2f(500.0,718.0);
glVertex2f(500.0,360.0);
glVertex2f(700.0,360.0);

glEnd();
glFlush ();

}
void right_side_wall()
{
//right side wall
glBegin(GL_QUADS);
glColor3f (0.88, 0.88, 0.88);
glVertex2f(1024.0,768.0);
glVertex2f(800.0,718.0);
glVertex2f(800.0,238.0);
glVertex2f(1024.0,0.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0, 0.0, 0.0);
glVertex2f(1024.0,768.0);
glVertex2f(800.0,718.0);
glVertex2f(800.0,238.0);
glVertex2f(1024.0,0.0);

glEnd();
glFlush ();

}

void window()
{
//window
glBegin(GL_QUADS);
glColor3f (0.90,0.97, 0.98);
glVertex2f(900.0,600.0);
glVertex2f(900.0,300.0);
glVertex2f(970.0,280.0);
glVertex2f(970.0,600.0);

glEnd();
glFlush();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0, 0.0);
glVertex2f(900.0,600.0);
glVertex2f(900.0,300.0);
glVertex2f(970.0,280.0);
glVertex2f(970.0,600.0);

glEnd();
glFlush();

}
void cabinet_top()
{
//cabinet side top
glBegin(GL_QUADS);
glColor3f (0.25,0.25,0.25);
glVertex2f(0.0,748.0);
glVertex2f(0.0,438.0);
glVertex2f(130.0,438.0);
glVertex2f(130.0,748.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(0.0,748.0);
glVertex2f(0.0,438.0);
glVertex2f(130.0,438.0);
glVertex2f(130.0,748.0);

glEnd();
glFlush ();

//cabinet front top
glBegin(GL_QUADS);
glColor3f (0.25,0.25,0.25);
glVertex2f(130.0,748.0);
glVertex2f(130.0,438.0);
glVertex2f(300.0,538.0);
glVertex2f(300.0,718.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(130.0,748.0);
glVertex2f(130.0,438.0);
glVertex2f(300.0,538.0);
glVertex2f(300.0,718.0);

glEnd();
glFlush ();
}

void cabinet_top_design()
{
	//cabinet front door design 
glBegin(GL_QUADS);
glColor3f (0.88,0.93,0.93);
glVertex2f(130.0,480.0);
glVertex2f(130.0,455.0);
glVertex2f(135.0,455.0);
glVertex2f(135.0,480.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(130.0,480.0);
glVertex2f(130.0,455.0);
glVertex2f(135.0,455.0);
glVertex2f(135.0,480.0);

glEnd();
glFlush ();

glBegin(GL_QUADS);
glColor3f (0.88,0.93,0.93);
glVertex2f(135.0,480.0);
glVertex2f(135.0,455.0);
glVertex2f(300.0,550.0);
glVertex2f(300.0,565.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(135.0,480.0);
glVertex2f(135.0,455.0);
glVertex2f(300.0,550.0);
glVertex2f(300.0,565.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(135.0,477.0);
glVertex2f(300.0,562.0);

glEnd();
glFlush ();

//cabinet front door 
glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(200.0,737.0);
glVertex2f(200.0,480.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(250.0,728.0);
glVertex2f(250.0,508.0);

glEnd();
glFlush ();

}

void cabinet_bottom() 
{
	//cabinet side Bottom
glBegin(GL_QUADS);
glColor3f (0.25,0.25,0.25);
glVertex2f(0.0,200.0);
glVertex2f(0.0,0.0);
glVertex2f(130.0,0.0);
glVertex2f(130.0,200.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(0.0,200.0);
glVertex2f(0.0,0.0);
glVertex2f(130.0,0.0);
glVertex2f(130.0,200.0);


glEnd();
glFlush ();

//cabinet front Bottom
glBegin(GL_QUADS);
glColor3f (0.25,0.25,0.25);
glVertex2f(130.0,200.0);
glVertex2f(130.0,0.0);
glVertex2f(300.0,238.0);
glVertex2f(300.0,360.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(130.0,200.0);
glVertex2f(130.0,0.0);
glVertex2f(300.0,238.0);
glVertex2f(300.0,360.0);

glEnd();
glFlush ();

}

void cabinet_bottom_design()
{
//cabinet front Bottom Design

glBegin(GL_QUADS);
glColor3f (0.88,0.93,0.93);
glVertex2f(130.0,180.0);
glVertex2f(130.0,155.0);
glVertex2f(135.0,155.0);
glVertex2f(135.0,180.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(130.0,180.0);
glVertex2f(130.0,155.0);
glVertex2f(135.0,155.0);
glVertex2f(135.0,180.0);

glEnd();
glFlush ();

glBegin(GL_QUADS);
glColor3f (0.88,0.93,0.93);
glVertex2f(130.0,180.0);
glVertex2f(135.0,180.0);
glVertex2f(305.0,345.0);
glVertex2f(300.0,345.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(130.0,180.0);
glVertex2f(135.0,180.0);
glVertex2f(305.0,345.0);
glVertex2f(300.0,345.0);

glEnd();
glFlush ();



glBegin(GL_QUADS);
glColor3f (0.88,0.93,0.93);
glVertex2f(135.0,180.0);
glVertex2f(135.0,155.0);
glVertex2f(305.0,325.0);
glVertex2f(305.0,345.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(135.0,180.0);
glVertex2f(135.0,155.0);
glVertex2f(305.0,325.0);
glVertex2f(305.0,345.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(200.0,300.0);
glVertex2f(200.0,97.0);
glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(260.0,350.0);
glVertex2f(260.0,183.0);
glEnd();
glFlush ();
}

void sink()
{
	//sink
glBegin(GL_QUADS);
glColor3f (0.63,0.63,0.63);
glVertex2f(0.0,200.0);
glVertex2f(130.0,200.0);
glVertex2f(300.0,360.0);
glVertex2f(220.0,360.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(0.0,200.0);
glVertex2f(130.0,200.0);
glVertex2f(300.0,360.0);
glVertex2f(220.0,360.0);

glEnd();
glFlush ();



//sink side wall
glBegin(GL_POLYGON);
glColor3f (0.63,0.63,0.63);
glVertex2f(0.0,200.0);
glVertex2f(220.0,360.0);
glVertex2f(220.0,491.0);
glVertex2f(130.0,438.0);
glVertex2f(0.0,438.0);


glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(0.0,200.0);
glVertex2f(220.0,360.0);
glVertex2f(220.0,491.0);
glVertex2f(130.0,438.0);
glVertex2f(0.0,438.0);

glEnd();
glFlush ();

}

void stove()
{
glBegin(GL_QUADS);
glColor3f (0.25,0.25,0.25);
glVertex2f(221.0,357.0);
glVertex2f(170.0,320.0);
glVertex2f(250.0,320.0);
glVertex2f(292.0,357.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);
glVertex2f(221.0,357.0);
glVertex2f(170.0,320.0);
glVertex2f(250.0,320.0);
glVertex2f(292.0,357.0);
glEnd();
glFlush ();

}

void water_tap()
{
//sink
glBegin(GL_QUADS);
glColor3f (0.50,0.50,0.50);

glVertex2f(162.0,310.0);
glVertex2f(85.0,250.0);
glVertex2f(178.0,250.0);
glVertex2f(243.0,310.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(162.0,310.0);
glVertex2f(85.0,250.0);
glVertex2f(178.0,250.0);
glVertex2f(243.0,310.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(233.0,300.0);
glVertex2f(165.0,300.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(165.0,300.0);
glVertex2f(105.0,250.0);


glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(165.0,300.0);
glVertex2f(162.0,310.0);

glEnd();
glFlush ();

//tap
glBegin(GL_QUADS);
glColor3f (0.50,0.50,0.50);

glVertex2f(140.0,320.0);
glVertex2f(160.0,315.0);
glVertex2f(160.0,323.0);
glVertex2f(130.0,330.0);

glEnd();
glFlush ();

glBegin(GL_QUADS);
glColor3f (0.50,0.50,0.50);

glVertex2f(130.0,330.0);
glVertex2f(130.0,295.0);
glVertex2f(140.0,293.0);
glVertex2f(140.0,320.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(140.0,320.0);
glVertex2f(160.0,315.0);
glVertex2f(160.0,323.0);
glVertex2f(130.0,330.0);
glVertex2f(130.0,295.0);
glVertex2f(140.0,293.0);
glVertex2f(140.0,320.0);

glEnd();
glFlush ();

}

void tv_cabinet()
{
glBegin(GL_QUADS);
glColor3f (0.25,0.25,0.25);

glVertex2f(450.0,360.0);
glVertex2f(452.0,358.0);
glVertex2f(752.0,358.0);
glVertex2f(750.0,360.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(450.0,360.0);
glVertex2f(452.0,357.0);
glVertex2f(752.0,357.0);
glVertex2f(750.0,360.0);

glEnd();
glFlush ();

glBegin(GL_QUADS);
glColor3f (0.25,0.25,0.25);

glVertex2f(452.0,357.0);
glVertex2f(452.0,220.0);
glVertex2f(752.0,220.0);
glVertex2f(752.0,357.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(452.0,357.0);
glVertex2f(452.0,220.0);
glVertex2f(752.0,220.0);
glVertex2f(752.0,357.0);

glEnd();
glFlush ();

}


void tv_cabinet_design()
{
glBegin(GL_QUADS);
glColor3f (0.88,0.93,0.93);

glVertex2f(452.0,345.0);
glVertex2f(452.0,335.0);
glVertex2f(752.0,335.0);
glVertex2f(752.0,345.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(452.0,345.0);
glVertex2f(452.0,335.0);
glVertex2f(752.0,335.0);
glVertex2f(752.0,345.0);

glEnd();
glFlush ();


}

void tv()
{
//stand
glBegin(GL_QUADS);
glColor3f (0.0,0.0,0.0);

glVertex2f(550.0,367.0);
glVertex2f(550.0,360.0);
glVertex2f(650.0,360.0);
glVertex2f(650.0,367.0);

glEnd();
glFlush ();

//frame

glBegin(GL_QUADS);
glColor3f (0.0,0.0,0.0);

glVertex2f(475.0,500.0);
glVertex2f(475.0,367.0);
glVertex2f(725.0,367.0);
glVertex2f(725.0,500.0);

glEnd();
glFlush ();

//screen
glBegin(GL_QUADS);
glColor3f (0.70,0.96,0.96);

glVertex2f(485.0,490.0);
glVertex2f(485.0,377.0);
glVertex2f(715.0,377.0);
glVertex2f(715.0,490.0);

glEnd();
glFlush ();
}

void floor_mat()
{
 glBegin(GL_QUADS);
glColor3f (0.11,0.13,0.51);

glVertex2f(472.0,200.0);
glVertex2f(482.0,130.0);
glVertex2f(800.0,130.0);
glVertex2f(772.0,200.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.11,0.13,0.51);

glVertex2f(472.0,200.0);
glVertex2f(482.0,130.0);
glVertex2f(800.0,130.0);
glVertex2f(772.0,200.0);


glEnd();
glFlush ();

 glBegin(GL_QUADS);
glColor3f (0.57,0.57,0.59);

glVertex2f(482.0,190.0);
glVertex2f(492.0,140.0);
glVertex2f(785.0,140.0);
glVertex2f(762.0,190.0);

glEnd();
glFlush ();
}

void sofa()
{

	//top
	glBegin(GL_QUADS);
glColor3f (0.50,0.50,0.50);

glVertex2f(950.0,145.0);
glVertex2f(940.0,160.0);
glVertex2f(700.0,160.0);
glVertex2f(720.0,145.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(950.0,145.0);
glVertex2f(940.0,160.0);
glVertex2f(700.0,160.0);
glVertex2f(720.0,145.0);

glEnd();
glFlush ();

//back
glBegin(GL_QUADS);
glColor3f (0.50,0.50,0.50);

glVertex2f(950.0,145.0);
glVertex2f(720.0,145.0);
glVertex2f(720.0,65.0);
glVertex2f(950.0,65.0);
glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(950.0,145.0);
glVertex2f(720.0,145.0);
glVertex2f(720.0,65.0);
glVertex2f(950.0,65.0);
glEnd();
glFlush ();

//side
glBegin(GL_QUADS);
glColor3f (0.50,0.50,0.50);

glVertex2f(700.0,160.0);
glVertex2f(700.0,120.0);
glVertex2f(720.0,120.0);
glVertex2f(720.0,145.0);
glEnd();
glFlush ();

glBegin(GL_QUADS);
glColor3f (0.50,0.50,0.50);

glVertex2f(720.0,120.0);
glVertex2f(660.0,140.0);
glVertex2f(660.0,90.0);
glVertex2f(720.0,65.0);
glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(700.0,160.0);
glVertex2f(700.0,120.0);
glVertex2f(660.0,140.0);
glVertex2f(660.0,90.0);
glVertex2f(720.0,65.0);
glVertex2f(720.0,145.0);
glEnd();
glFlush ();

//stand
glBegin(GL_QUADS);
glColor3f (0.0,0.0,0.0);

glVertex2f(720.0,65.0);
glVertex2f(720.0,50.0);
glVertex2f(730.0,50.0);
glVertex2f(730.0,65.0);

glEnd();
glFlush ();


glBegin(GL_QUADS);
glColor3f (0.0,0.0,0.0);

glVertex2f(940.0,65.0);
glVertex2f(940.0,50.0);
glVertex2f(950.0,50.0);
glVertex2f(950.0,65.0);

glEnd();
glFlush ();

glBegin(GL_QUADS);
glColor3f (0.0,0.0,0.0);

glVertex2f(660.0,90.0);
glVertex2f(660.0,75.0);
glVertex2f(670.0,77.0);
glVertex2f(670.0,87.0);
glEnd();
glFlush ();

}

void chair_right()
{
//back
glBegin(GL_QUADS);
glColor3f (1.0,0.5,0.0);

glVertex2f(545.0,270.0);
glVertex2f(545.0,170.0);
glVertex2f(550.0,165.0);
glVertex2f(550.0,270.0);

glEnd();
glFlush ();

//seat

glBegin(GL_QUADS);
glColor3f (1.0,0.5,0.0);

glVertex2f(545.0,170.0);
glVertex2f(470.0,170.0);
glVertex2f(470.0,165.0);
glVertex2f(550.0,165.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(545.0,270.0);
glVertex2f(545.0,170.0);
glVertex2f(470.0,170.0);
glVertex2f(470.0,165.0);
glVertex2f(550.0,165.0);
glVertex2f(550.0,270.0);

glEnd();
glFlush ();

glBegin(GL_QUADS);
glColor3f (1.0,0.5,0.0);

glVertex2f(544.0,200.0);
glVertex2f(472.0,200.0);
glVertex2f(470.0,170.0);
glVertex2f(545.0,170.0);

glEnd();
glFlush ();


glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(544.0,200.0);
glVertex2f(472.0,200.0);
glVertex2f(470.0,170.0);
glVertex2f(545.0,170.0);

glEnd();
glFlush ();

}

void chair_right_stand()
{
glBegin(GL_QUADS);
glColor3f (0.0,0.0,0.0);

glVertex2f(470.0,165.0);
glVertex2f(470.0,115.0);
glVertex2f(475.0,120.0);
glVertex2f(475.0,165.0);

glEnd();
glFlush ();

glBegin(GL_QUADS);
glColor3f (0.0,0.0,0.0);

glVertex2f(475.0,120.0);
glVertex2f(550.0,120.0);
glVertex2f(550.0,115.0);
glVertex2f(470.0,115.0);

glEnd();
glFlush ();
}

void chair_left() 
{
glBegin(GL_QUADS);
glColor3f (1.0,0.5,0.0);

glVertex2f(290.0,270.0);
glVertex2f(290.0,170.0);
glVertex2f(295.0,175.0);
glVertex2f(295.0,270.0);

glEnd();
glFlush ();

//seat

glBegin(GL_QUADS);
glColor3f (1.0,0.5,0.0);

glVertex2f(295.0,175.0);
glVertex2f(290.0,170.0);
glVertex2f(370.0,170.0);
glVertex2f(370.0,175.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(290.0,270.0);
glVertex2f(290.0,170.0);
glVertex2f(370.0,170.0);
glVertex2f(370.0,175.0);
glVertex2f(295.0,175.0);
glVertex2f(295.0,270.0);

glEnd();
glFlush ();


glBegin(GL_QUADS);
glColor3f (1.0,0.5,0.0);

glVertex2f(297.0,200.0);
glVertex2f(295.0,175.0);
glVertex2f(370.0,175.0);
glVertex2f(368.0,200.0);

glEnd();
glFlush ();


glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(297.0,200.0);
glVertex2f(295.0,175.0);
glVertex2f(370.0,175.0);
glVertex2f(368.0,200.0);

glEnd();
glFlush ();
}

void chair_left_stand()
{
glBegin(GL_QUADS);
glColor3f (0.0,0.0,0.0);

glVertex2f(370.0,170.0);
glVertex2f(370.0,120.0);
glVertex2f(365.0,125.0);
glVertex2f(365.0,170.0);

glEnd();
glFlush ();

glBegin(GL_QUADS);
glColor3f (0.0,0.0,0.0);

glVertex2f(365.0,125.0);
glVertex2f(290.0,125.0);
glVertex2f(290.0,120.0);
glVertex2f(370.0,120.0);

glEnd();
glFlush ();
}

void table()
{
glBegin(GL_QUADS);
glColor3f (1.0,1.0,1.0);

glVertex2f(315.0,220.0);
glVertex2f(315.0,210.0);
glVertex2f(500.0,210.0);
glVertex2f(500.0,220.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(315.0,220.0);
glVertex2f(315.0,210.0);
glVertex2f(500.0,210.0);
glVertex2f(500.0,220.0);

glEnd();
glFlush ();


glBegin(GL_QUADS);
glColor3f (0.8,0.0,0.0);

glVertex2f(315.0,220.0);
glVertex2f(500.0,220.0);
glVertex2f(515.0,300.0);
glVertex2f(370.0,300.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(315.0,220.0);
glVertex2f(500.0,220.0);
glVertex2f(515.0,300.0);
glVertex2f(370.0,300.0);

glEnd();
glFlush ();


glBegin(GL_QUADS);
glColor3f (1.0,1.0,1.0);

glVertex2f(502.0,217.0);
glVertex2f(517.0,298.0);
glVertex2f(515.0,300.0);
glVertex2f(500.0,220.0);

glEnd();
glFlush ();


glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(502.0,217.0);
glVertex2f(517.0,298.0);
glVertex2f(515.0,300.0);
glVertex2f(500.0,220.0);
glEnd();
glFlush ();
}

void table_stand_left()
{
//front
glBegin(GL_QUADS);
glColor3f (0.5,0.5,0.5);

glVertex2f(317.0,210.0);
glVertex2f(317.0,110.0);
glVertex2f(327.0,110.0);
glVertex2f(327.0,210.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(317.0,210.0);
glVertex2f(317.0,110.0);
glVertex2f(327.0,110.0);
glVertex2f(327.0,210.0);

glEnd();
glFlush ();

glBegin(GL_QUADS);
glColor3f (0.5,0.5,0.5);

glVertex2f(327.0,210.0);
glVertex2f(327.0,110.0);
glVertex2f(330.0,113.0);
glVertex2f(330.0,210.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(327.0,210.0);
glVertex2f(327.0,110.0);
glVertex2f(330.0,113.0);
glVertex2f(330.0,210.0);

glEnd();
glFlush ();


//back
glBegin(GL_QUADS);
glColor3f (0.5,0.5,0.5);

glVertex2f(375.0,210.0);
glVertex2f(375.0,160.0);
glVertex2f(385.0,160.0);
glVertex2f(385.0,210.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(375.0,210.0);
glVertex2f(375.0,160.0);
glVertex2f(385.0,160.0);
glVertex2f(385.0,210.0);

glEnd();
glFlush ();

glBegin(GL_QUADS);
glColor3f (0.5,0.5,0.5);

glVertex2f(385.0,210.0);
glVertex2f(385.0,160.0);
glVertex2f(388.0,163.0);
glVertex2f(388.0,210.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(385.0,210.0);
glVertex2f(385.0,160.0);
glVertex2f(388.0,163.0);
glVertex2f(388.0,210.0);

glEnd();
glFlush ();
}

void table_stand_right()
{
//front
glBegin(GL_QUADS);
glColor3f (0.5,0.5,0.5);

glVertex2f(500.0,210.0);
glVertex2f(490.0,210.0);
glVertex2f(490.0,110.0);
glVertex2f(500.0,110.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(500.0,210.0);
glVertex2f(490.0,210.0);
glVertex2f(490.0,110.0);
glVertex2f(500.0,110.0);

glEnd();
glFlush ();

glBegin(GL_QUADS);
glColor3f (0.5,0.5,0.5);

glVertex2f(500.0,210.0);
glVertex2f(500.0,110.0);
glVertex2f(503.0,113.0);
glVertex2f(503.0,217.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(500.0,210.0);
glVertex2f(500.0,110.0);
glVertex2f(503.0,113.0);
glVertex2f(503.0,217.0);

glEnd();
glFlush ();

//back

glBegin(GL_QUADS);
glColor3f (0.5,0.5,0.5);

glVertex2f(517.0,298.0);
glVertex2f(514.0,295.0);
glVertex2f(514.0,210.0);
glVertex2f(517.0,213.0);

glEnd();
glFlush ();


glBegin(GL_LINE_LOOP);
glColor3f (0.0,0.0,0.0);

glVertex2f(517.0,298.0);
glVertex2f(514.0,295.0);
glVertex2f(514.0,210.0);
glVertex2f(517.0,213.0);

glEnd();
glFlush ();

glBegin(GL_QUADS);
glColor3f (0.5,0.5,0.5);

glVertex2f(514.0,295.0);
glVertex2f(504.0,220.0);
glVertex2f(504.0,210.0);
glVertex2f(514.0,210.0);

glEnd();
glFlush ();

glBegin(GL_LINE_LOOP); 
glColor3f (0.0,0.0,0.0);

glVertex2f(514.0,295.0);
glVertex2f(504.0,215.0);
glVertex2f(504.0,210.0);
glVertex2f(514.0,210.0);

glEnd();
glFlush ();
}

void drawCircle(float x1, float y1,double radius)
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
void waterdrop(){

	glPushMatrix();
	glTranslatef(0,-drop_t, 0);
	glColor3f(0.70,0.96,0.96);
	drawCircle(160.0, 315.0,3);

	glPopMatrix();
	if (drop_t<50)
		drop_t += 1.0;
	else
		drop_t =1.0;
}
void megh()
{
	glPushMatrix();
	glTranslatef(megh_t,0, 0);
	glColor3f(0.9411, 1,0.9411);
	drawCircle(500.0, 470.0,10);
	drawCircle(510.0, 465.0,10);
	drawCircle(520.0, 465.0,10);
	drawCircle(530.0, 470.0,10);
	drawCircle(520.0, 475.0,10);
	drawCircle(510.0, 475.0,10);

	drawCircle(560.0, 460.0,10);
	drawCircle(570.0, 455.0,10);
	drawCircle(580.0, 455.0,10);
	drawCircle(590.0, 460.0,10);
	drawCircle(580.0, 465.0,10);
	drawCircle(570.0, 465.0,10);

	drawCircle(610.0, 470.0,10);
	drawCircle(620.0, 465.0,10);
	drawCircle(630.0, 465.0,10);
	drawCircle(640.0, 470.0,10);
	drawCircle(630.0, 475.0,10);
	drawCircle(620.0, 475.0,10);

	glPopMatrix();
	if (megh_t>60)
		megh_t = -1.0;
	else
		megh_t += 1.0;
}

void draw()
{
	triangle();
	roof();
	floor();
	background_wall();
	right_side_wall();
	window();
	cabinet_top();
	cabinet_top_design();
	cabinet_bottom();
	cabinet_bottom_design();
	sink();
	stove();
	water_tap();
	tv_cabinet();
	tv_cabinet_design();
	tv();
	floor_mat();
	sofa();
	chair_right();
	chair_right_stand();
	chair_left();
	chair_left_stand();
	table();
	table_stand_left();
	table_stand_right();
	megh();
	waterdrop();
	glutSwapBuffers();
}

void myDisplay(void)
{
glViewport(-400,-300,1600,1200);
glPushMatrix();
draw(); 
glPopMatrix();
	
}

void keyboard(unsigned char key, int x, int y) {

	if(key == 'w'){
		glTranslatef(0, -50, 0);
		glutPostRedisplay();
	}
	else if (key == 's'){
		glTranslatef(0, 50, 0);
		glutPostRedisplay();
	}
	else if (key == 'd'){
		glTranslatef(-50, 0, 0);
		glutPostRedisplay();
	}
	else if (key == 'a'){		
		glTranslatef(50, 0, 0);			
		glutPostRedisplay();		
	}
	
}

void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION_MATRIX);
glLoadIdentity();
gluOrtho2D(0.0, 1024.0, 0.0, 768.0);
}

void update (int value) {
	megh_t+=1.0;
	drop_t +=1.0;
   glutPostRedisplay();
   glutTimerFunc(50, update, 0);


}

void main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize (800, 600);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Living Room");
glutKeyboardFunc(keyboard);
glutDisplayFunc(myDisplay);
glutTimerFunc(1000, update, 0);
myInit ();
glutMainLoop();
}

