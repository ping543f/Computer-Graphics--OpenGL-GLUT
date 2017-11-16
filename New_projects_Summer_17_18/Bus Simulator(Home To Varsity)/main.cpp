

/*

Project Group :

Section : 'H'

1.Dey,Anupam - 14-27703-3
2.Haider,Mohsin - 14-27762-3
3.Siddique, M. Rezwan 13-24482-2
4.Fahad Mohammad


*/


#include<windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include<iostream>
#include<stdio.h>
#include<cmath>
#define PI 3.1416


float tx = 0.0;
float ty = 0.0;
float var_boat = 0.0;//first window boat value
float var_man = 0.0;
float var_boat2 = 0.0;
float var_small_car = 0.0;
float var_car2 = 0.0;
int window = 0;
bool bool_car = false;
bool bool_boat = false;
bool bool_man = false;
bool bus_stop = false;
bool bus_stop_end = false;
bool man_in = false;
bool man_out = false;
void boat_moving();
void var_man_moving();
void small_car_moving();
void drawWheel();
void busstop();
void busstop_top();
void busstop_left();
void lamp();
void bus();
void bus_scal();
void bus_final();
void river();
void crismas();
void display();//for reason
void building_scal();
void building2_abd_bottom();//fahad k bola
void building3_scal();
void building2_translate();
void building_abd_traslate();
void building_abd();
void building2_abd();
void building_abd_scal();
void building_abd_traslate_again_bottom();
void first_window();
void second_window();
void grass();
void building();
GLvoid tree(GLdouble x);
GLvoid window1(GLdouble x);
GLvoid window2(GLdouble y);
GLvoid window3(GLdouble w);
GLvoid window4(GLdouble v);
GLvoid window_bus(GLdouble x);

void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {
	    //for day night

		case 'd':
		    glClearColor(.01,.8,.5,0);
			break;

		case 'n':
			 glClearColor(.04,.09,.02,0);
			break;

		case 'N':
		     glClearColor(.04,.09,.02,0);
			 break;
         case 'D':
              glClearColor(.01,.8,.5,0);
         break;

         // moving the  vodka man

         case 'R':
              bool_man = true;
              glutIdleFunc(var_man_moving);
              glutPostRedisplay();

         break;

          case 'r':
              bool_man = true;
              glutIdleFunc(var_man_moving);
              glutPostRedisplay();
         break;

         //stop the vodka man
         case 'S':
              bool_man = false;
              if(bool_car){
                 glutIdleFunc(small_car_moving);//kahani jana lagbe..caz fahad theaka
                 glutPostRedisplay();
              }
              else if(bool_boat){
                    glutIdleFunc(boat_moving);
                    glutPostRedisplay();
                }
                else{
                    glutIdleFunc(NULL);
                    glutPostRedisplay();
                }
         break;

         case 's':
              bool_man=false;
              if(bool_car){
                 glutIdleFunc(small_car_moving);
                 glutPostRedisplay();
              }
              else if(bool_boat){
                    glutIdleFunc(boat_moving);
                    glutPostRedisplay();
                }
             else{
                glutIdleFunc(NULL);
                glutPostRedisplay();
                }
         break;

         //get in the car from bus stop
         case 'y':
             if((tx>=480 && tx<=650) || (tx>=1330 && tx<=1650)){
                man_in = true;
                glutPostRedisplay();
             }
             else
             {
                man_in = false;
                glutPostRedisplay();
             }

         break;

          case 'Y':
             if((tx>=480 && tx<=650) || (tx>=1330 && tx<=1650)){
                man_in = true;
                //glutPostRedisplay();
             }
             else
             {
                man_in = false;
                glutPostRedisplay();
             }

         break;

         //out the girl in font of varsity

         case 'A':
             if(tx>=1330 && tx<=1650 && man_in == true){ //change korchi
                man_out = true;
                glutPostRedisplay();
             }
             else if(tx<1330 || tx>1650){
                 man_out = false;
                glutPostRedisplay();
             }

         break;

          case 'a':
             if(tx>=1330 && tx<=1600 && man_in == true){ //change korchi
                man_out =true;
                glutPostRedisplay();
             }
             else if(tx<1330 || tx>1600){
                 man_out = false;
                glutPostRedisplay();
             }

         break;


	  default:
			break;
	}
}

//for vodka man moving

void var_man_moving(){
    //check boat is running or not
     if(bool_boat){
        var_boat-=.35;
        glutPostRedisplay();
    }

    //check car is running or not
    if(bool_car){
        var_small_car-=.7;
        glutPostRedisplay();
    }

    //check vodka man is running or not
    if(bool_man){
        if(var_man <= 23){
            var_man+=.005;
            glutPostRedisplay();
        }
         else{
            bool_man=false;
            glutPostRedisplay();
         }
    }
    else{
        glutPostRedisplay();
    }
}

// Boat 1 of first screen movement........

void boat_moving(){
    //check vodka man is running or not
    if(bool_man){
        var_man+=.005;
        glutPostRedisplay();
    }

    //check car is running or not
    if(bool_car){
        var_small_car-=.7;
        glutPostRedisplay();
    }


    //check boat is running or not
    if(bool_boat){
        if(var_boat>-2100){
            var_boat-=.35;
            glutPostRedisplay();
        }
       else{
            bool_boat=false;
            glutPostRedisplay();
         }
    }
    else{
        glutPostRedisplay();
    }
}

//small car moving for first screen
void small_car_moving(){
    //check vodka man is running or not
     if(bool_man){
        var_man+=.005;
        glutPostRedisplay();
    }

    //check boat is running or not
    if(bool_boat){
        var_boat-=.35;
        glutPostRedisplay();
    }

    //check small car is running or not
    if(bool_car){
        if(var_small_car>-2050){
            var_small_car-=.7;
            glutPostRedisplay();
        }
        else{
            bool_car=false;
            glutPostRedisplay();
        }
    }
    else{
        glutPostRedisplay();
    }
}


//Right and left key task.................
void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:

				tx -=10;
				glutPostRedisplay();
				break;


		case GLUT_KEY_RIGHT:
				tx +=10;
				glutPostRedisplay();

				break;
	  default:
			break;
	}
}

void mouse(int button, int state, int x, int y)
{
   switch (button)
   {

       //for boat moving
      case GLUT_LEFT_BUTTON:
            bool_boat = true; // bool_boat = boat 1
            glutIdleFunc(boat_moving);
            glutPostRedisplay();
         break;


        //for small car moving
      case GLUT_RIGHT_BUTTON:
          bool_car=true; // bool_car = small car in first screen
          glutIdleFunc(small_car_moving);
          glutPostRedisplay();
         break;

    //for vodka man moving;
    case GLUT_MIDDLE_BUTTON:
        bool_car=false;
        bool_boat=false;
       /* if(bool_man)
            glutIdleFunc(var_man_moving);
        else
            glutIdleFunc(NULL);*/
            glutPostRedisplay();
         break;

      default:

         break;
   }
}

//for second window boat
void boat_moving2(){
    if(var_car2<=2000){
         var_car2+=.08;
       glutPostRedisplay();
    }

    if(var_boat2<=1800){
       var_boat2+=.5;
       glutPostRedisplay();
    }


    glutPostRedisplay();
}

//river

void river()
{
     glColor3ub(93,70,69);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,240);
    glVertex2f(200,260);
    glVertex2f(400,240);
    glVertex2f(700,250);
    glVertex2f(900,260);
    glVertex2f(1000,250);
    glVertex2f(1200,270);
    glVertex2f(1500,240);
    glVertex2f(1600,250);
    glVertex2f(1800,240);
    glVertex2f(1800,0);
    glEnd();

     glColor3ub(88,132,169);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,210);
    glVertex2f(200,230);
    glVertex2f(400,210);
    glVertex2f(700,220);
    glVertex2f(900,230);
    glVertex2f(1000,210);
    glVertex2f(1200,240);
    glVertex2f(1500,210);
    glVertex2f(1600,210);
    glVertex2f(1800,230);
    glVertex2f(1800,0);
    glEnd();

    glLineWidth(5);
    glColor3ub(99,145,174);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0,100);
    glVertex2f(200,110);
    glVertex2f(400,100);
    glVertex2f(700,140);
    glVertex2f(900,150);
    glVertex2f(1000,130);
    glVertex2f(1200,160);
    glVertex2f(1500,120);
    glVertex2f(1600,130);
    glVertex2f(1800,130);
    glEnd();

     glLineWidth(5);
    glColor3ub(99,145,174);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0,130);
    glVertex2f(200,190);
    glVertex2f(400,160);
    glVertex2f(700,160);
    glVertex2f(900,170);
    glVertex2f(1000,180);
    glVertex2f(1200,150);
    glVertex2f(1500,160);
    glVertex2f(1600,170);
    glVertex2f(1800,180);
    glEnd();

     glLineWidth(5);
    glColor3ub(99,145,174);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0,100);
    glVertex2f(200,50);
    glVertex2f(400,40);
    glVertex2f(700,40);
    glVertex2f(900,50);
    glVertex2f(1000,30);
    glVertex2f(1200,60);
    glVertex2f(1500,20);
    glVertex2f(1600,30);
    glVertex2f(1800,30);
    glEnd();

}


//building 2nd scaling
void building_abd_scal()
{
     glPushMatrix();
    glScalef(.9,.8,0);
    building_abd_traslate_again_bottom();
    glPopMatrix();
}


//building 1st scalling
void building_scal()
{
     glPushMatrix();
    glScalef(6,6,0);
    building();
    glPopMatrix();

}


//building 2nd scaling
void building3_scal()
{
     glPushMatrix();
    glScalef(.9,.9,0);
    building2_translate();
    glPopMatrix();

}


//building 2nd transalte
void building_abd_traslate(){
     glPushMatrix();
    glTranslatef(1000,390,0);
     building_abd();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(1050,390,0);
     building_abd();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(1100,390,0);
     building_abd();
	glPopMatrix();


}


//building 3rd translate
void building_abd_traslate_again_bottom(){

    glColor3ub(100,100,100);
    glBegin(GL_TRIANGLES);
    glVertex2f(1050,490);
    glVertex2f(1200,490);
    glVertex2f(1125,600);
    glEnd();


     glPushMatrix();
    glTranslatef(1050,440,0);
     building_abd();
	glPopMatrix();


    building_abd_traslate();
      glPushMatrix();
    glTranslatef(0,-50,0);
     building_abd_traslate();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(0,-100,0);
     building_abd_traslate();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(0,-150,0);
     building_abd_traslate();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(0,-200,0);
     building_abd_traslate();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(0,-250,0);
     building_abd_traslate();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(150,-200,0);
     building_abd_traslate();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(150,-250,0);
     building_abd_traslate();
	glPopMatrix();
}



//building 2nd reanslate
void building2_translate(){

    int j=0;
    for(int i=50;i<=200;i+=50){
        glPushMatrix();
        glTranslatef(i,j,0);
        building2_abd();
        glPopMatrix();
        if(i==200){
            i=0;
            j+=50;
        }
        if(j>200)
            break;
    }
    building2_abd_bottom();
}

void building2_abd_bottom()
{
    glBegin(GL_POLYGON);
    glColor3ub(15, 0, 105);
        glVertex2f(100,50);
        glVertex2f(100,-20);
        glVertex2f(170,-20);
        glVertex2f(170,50);

  glEnd();



  glPushMatrix();
   glTranslatef(130,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(15, 0, 105);
        glVertex2f(100,50);
        glVertex2f(100,-20);
        glVertex2f(170,-20);
        glVertex2f(170,50);

  glEnd();
	glPopMatrix();

	  glBegin(GL_POLYGON);
    glColor3ub(150, 210, 105);
        glVertex2f(170,50);
        glVertex2f(170,-20);
        glVertex2f(230,-20);
        glVertex2f(230,50);

  glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(15, 0, 105);
        glVertex2f(100,300);
        glVertex2f(300,300);
        glVertex2f(200,370);
  glEnd();


}

void building2_abd(){
    glBegin(GL_POLYGON);
    glColor3ub(15, 0, 105);
        glVertex2f(50,50);
        glVertex2f(50,100);
        glVertex2f(100,100);
        glVertex2f(100,50);

  glEnd();

  glBegin(GL_POLYGON);
    glColor3ub(102, 1, 255);
        glVertex2f(60,60);
        glVertex2f(60,90);
        glVertex2f(90,90);
        glVertex2f(90,60);

  glEnd();
}


//abd first building
void building_abd(){
    glBegin(GL_POLYGON);
    glColor3ub(102, 255, 255);
        glVertex2f(50,50);
        glVertex2f(50,100);
        glVertex2f(100,100);
        glVertex2f(100,50);

  glEnd();

  glBegin(GL_POLYGON);
    glColor3ub(102, 1, 255);
        glVertex2f(60,60);
        glVertex2f(60,90);
        glVertex2f(90,90);
        glVertex2f(90,60);

  glEnd();
}

//building mohsin/// campus

void building()
{
    //building

  glBegin(GL_QUADS);
    glColor3ub(102, 255, 255);
        glVertex2f(70,85);
        glVertex2f(100,85);
        glVertex2f(100,30);
        glVertex2f(70,30);

  glEnd();



//gate1
   glBegin(GL_QUADS);
    glColor3ub(255, 128, 0);
        glVertex2f(50,30);
        glVertex2f(50,40);
        glVertex2f(58,44);
        glVertex2f(58,30);

  glEnd();


//gate2
  glBegin(GL_QUADS);
    glColor3ub(255, 128, 0);
        glVertex2f(68,30);
        glVertex2f(75,30);
        glVertex2f(75,40);
        glVertex2f(68,44);

  glEnd();

window1(1);
window1(8);
window1(16);
window1(24);

window2(1);
window2(8);
window2(16);
window2(24);

window3(1);
window3(8);
window3(16);
window3(24);

window4(1);
window4(8);
window4(16);
window4(24);




//wall-right

glBegin(GL_QUADS);
    glColor3ub(204, 0, 0);
        glVertex2f(75,40);
        glVertex2f(120,40);
        glVertex2f(120,30);
        glVertex2f(75,30);

  glEnd();


  //wall-left

  glBegin(GL_QUADS);
    glColor3ub(204, 0, 0);
        glVertex2f(20,30);
        glVertex2f(20,40);
        glVertex2f(50,40);
        glVertex2f(50,30);

  glEnd();


}

GLvoid window1(GLdouble y)
{
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
        glVertex2f(y+70,50);
        glVertex2f(y+75,50);
        glVertex2f(y+75,45);
        glVertex2f(y+70,45);

        glEnd();
        glFlush();
}
GLvoid window2(GLdouble z)
{
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
        glVertex2f(z+70,60);
        glVertex2f(z+75,60);
        glVertex2f(z+75,55);
        glVertex2f(z+70,55);

        glEnd();
        glFlush();
}

GLvoid window3(GLdouble w)//mohsin
{
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
        glVertex2f(w+70,70);
        glVertex2f(w+75,70);
        glVertex2f(w+75,65);
        glVertex2f(w+70,65);

        glEnd();
        glFlush();

}

GLvoid window4 (GLdouble v)
{
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
        glVertex2f(v+70,80);
        glVertex2f(v+75,80);
        glVertex2f(v+75,75);
        glVertex2f(v+70,75);

        glEnd();
        glFlush();
}




//grass flowers

void grass()
{
    glColor3ub(84,15,61);
    glBegin(GL_QUADS);
    glVertex2f(150,150);
    glVertex2f(150,170);
    glVertex2f(230,170);
    glVertex2f(230,150);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(190,150);
    glVertex2f(210,150);
    glVertex2f(200,300);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(195,150);
    glVertex2f(215,150);
    glVertex2f(210,295);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(200,150);
    glVertex2f(215,150);
    glVertex2f(220,280);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(210,150);
    glVertex2f(225,150);
    glVertex2f(230,270);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(230,260);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(245,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(255,240);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(265,230);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(270,220);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(275,210);
    glEnd();
     glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(280,205);
    glEnd();
     glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(285,200);
    glEnd();
     glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(290,190);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(180,150);
    glVertex2f(200,150);
    glVertex2f(190,295);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(175,150);
    glVertex2f(195,150);
    glVertex2f(185,285);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(170,150);
    glVertex2f(185,150);
    glVertex2f(180,275);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(160,150);
    glVertex2f(180,150);
    glVertex2f(170,265);
    glEnd();



    glBegin(GL_POLYGON);
    glVertex2f(160,150);
    glVertex2f(180,150);
    glVertex2f(160,255);
    glEnd();
     glBegin(GL_POLYGON);
    glVertex2f(160,150);
    glVertex2f(180,150);
    glVertex2f(150,245);
    glEnd();

      glBegin(GL_POLYGON);
    glVertex2f(170,150);
    glVertex2f(160,150);
    glVertex2f(145,235);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(165,150);
    glVertex2f(155,150);
    glVertex2f(140,225);
    glEnd();


       glBegin(GL_POLYGON);
    glVertex2f(170,150);
    glVertex2f(160,150);
    glVertex2f(135,220);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(165,150);
    glVertex2f(155,150);
    glVertex2f(124,210);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(170,150);
    glVertex2f(160,150);
    glVertex2f(125,210);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(165,150);
    glVertex2f(155,150);
    glVertex2f(120,200);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(170,150);
    glVertex2f(160,150);
    glVertex2f(110,195);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(165,150);
    glVertex2f(155,150);
    glVertex2f(100,185);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(160,150);
    glVertex2f(150,150);
    glVertex2f(90,180);
    glEnd();

}


//bus stop translation
void busstop()
{
      //bus stop
    glColor3ub(100,100,100);
    glBegin(GL_POLYGON);
    glVertex2f(380,650);
    glVertex2f(420,750);
    glVertex2f(720,750);
    glVertex2f(680,650);
    glEnd();

    glColor3ub(200,200,100);
    glBegin(GL_POLYGON);
    glVertex2f(380,650);
    glVertex2f(380,630);
    glVertex2f(690,630);
    glVertex2f(680,650);
    glEnd();

    glColor3ub(200,200,100);
    glBegin(GL_POLYGON);
    glVertex2f(690,630);
    glVertex2f(680,650);
    glVertex2f(720,750);
    glVertex2f(730,730);
    glEnd();


    glPushMatrix();
    glColor3ub(50,50,80);
    glTranslatef(0,200,0);
    busstop_top();
	glPopMatrix();

	busstop_left();

	//busstop right
	glPushMatrix();
    glTranslatef(300,0,0);
    busstop_left();
	glPopMatrix();
}

void busstop_top()
{
      //bus stop
    glColor3ub(50,50,80);
    glBegin(GL_POLYGON);
    glVertex2f(380,650);
    glVertex2f(420,710);
    glVertex2f(730,710);
    glVertex2f(700,650);
    glEnd();

    glColor3ub(200,200,200);
    glBegin(GL_POLYGON);
    glVertex2f(380,650);
    glVertex2f(380,630);
    glVertex2f(690,630);
    glVertex2f(680,650);
    glEnd();

    glColor3ub(200,200,200);
    glBegin(GL_POLYGON);
    glVertex2f(690,630);
    glVertex2f(680,650);
    glVertex2f(730,710);
    glVertex2f(735,685);
    glEnd();
}

void busstop_left()
{
glColor3ub(50,50,80);
    glBegin(GL_POLYGON);
    glVertex2f(390,675);
    glVertex2f(390,865);
    glVertex2f(415,895);
    glVertex2f(415,735);
    glEnd();
}


//lamp
void lamp()
{
    glColor3ub(200,200,150);
    glBegin(GL_POLYGON);
    glVertex2f(120,600);
    glVertex2f(140,600);
    glVertex2f(140,800);
    glVertex2f(120,800);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(70,800);
    glVertex2f(70,810);
    glVertex2f(190,810);
    glVertex2f(190,800);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(70,800);
    glVertex2f(50,760);
    glVertex2f(90,760);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(190,800);
    glVertex2f(170,760);
    glVertex2f(210,760);
    glEnd();

}


//crismas tree
void crismas(){
    glColor3ub(200,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(50,0);
    glVertex2f(70,0);
    glVertex2f(70,110);
    glVertex2f(50,110);
    glEnd();

     glColor3ub(0,51,0);
    glBegin(GL_POLYGON);
    glVertex2f(60,230);
    glVertex2f(120,110);
    glVertex2f(0,110);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(60,270);
    glVertex2f(110,150);
    glVertex2f(10,150);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(60,280);
    glVertex2f(100,190);
    glVertex2f(20,190);
    glEnd();
}

//bus by mohsin
GLvoid drawCircle(GLdouble xc, GLdouble yc, GLdouble rad)
{
    GLfloat i;
    glPointSize(3);
	glBegin(GL_POLYGON);

    for(i=0;i<=7;i+=.01)
        glVertex2f(xc+rad*cos(i),yc+rad*sin(i));
	glEnd();

}

 GLvoid  window_bus(GLdouble x)
{
    glBegin(GL_QUADS);
    glColor3ub(0, 255, 255);
    glVertex2f(x+12,20);
    glVertex2f(x+17,20);
    glVertex2f(x+17,25);
    glVertex2f(x+12,25);
    glEnd();
    glFlush();



}

GLvoid Tire(GLdouble y)
{
    glColor3ub(153, 0, 0);

    drawCircle(y+15,15,3);


}

void bus(){
     glPushMatrix();
    glTranslatef(30,15,0);
    glScalef(3,3,0);
    drawWheel();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(16,15,0);
    glScalef(3,3,0);
    drawWheel();
	glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 51);
    glVertex2f(10,15);
    glVertex2f(10,28);
    glVertex2f(34.5,28);
    glVertex2f(36,23);
    glVertex2f(36,15);
    glEnd();


    window_bus(0);
    window_bus(8);

    glBegin(GL_POLYGON);
   glColor3ub(0, 255, 255);
    glVertex2f(28,20);
    glVertex2f(28,25);
    glVertex2f(33.2,25);
    glVertex2f(34,22);
    glVertex2f(34,20);

    glEnd();


    glEnd();

}

//bus scaling

void bus_scal(){

    glPushMatrix();
    glScalef(9,9,0);
    bus();
    glPopMatrix();


}

//bus translating
void bus_final(){
    glPushMatrix();
    glTranslatef(-200,410,0);
    bus_scal();
	glPopMatrix();
}







//----------- car 2 + vodka moving -------->

//disk  for car and others
void drawDisk(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {//kaj ki
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}




//mouth for vodka man and all the started from here
//.....................................

void Mouth(double radius) {// mohsin theka buja lagbe
    int d;
	glBegin(GL_POLYGON);
	for (d = 16; d < 32; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}



void Hair(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 18; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}

void brew(double radius) { // fahad
	int d;
	glBegin(GL_LINE_LOOP);
	for (d = 0; d < 16; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();

}



void Hand()
{
       glPushMatrix();
  glTranslatef(-0.5,-0.5,0);
   glScalef(0.09,0.2,0);
     glColor3f (0.0, 0.9, .9);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(-0.5,-0.7,0);
   glScalef(0.09,0.4,0);
    glColor3f (1.0, 0.8, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
    glEnd();
  glPopMatrix();

  glPushMatrix();
     glTranslatef(-0.5,-0.95,0);
   glScalef(0.1,0.08,0);
     glColor3f (1.0, 0.8, 0.6);
     drawDisk(0.7);
     glPopMatrix();
}

void Leg()
{
    glPushMatrix();
  glTranslatef(-.5,-0.5,0);
   glScalef(.12,.9,0);
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
    glEnd();
  glPopMatrix();
   glPushMatrix();
    glTranslatef(-0.45,-0.9,0);
   glScalef(0.14,0.08,0);
     drawDisk(0.7);
     glPopMatrix();

}




void Hand1()
{
       glPushMatrix();
  glTranslatef(-0.5,-0.5,0);
   glScalef(0.09,0.2,0);
     glColor3f (0.0, 0.9, .9);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
     glEnd();
     glPopMatrix();



     glPushMatrix();
     glTranslatef(-0.5,-0.7,0);
   glScalef(0.09,0.4,0);
    glColor3f (1.0, 0.8, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
    glEnd();
  glPopMatrix();

  glPushMatrix();
     glTranslatef(-0.5,-0.95,0);
   glScalef(0.1,0.08,0);
     glColor3f (1.0, 0.8, 0.6);
     drawDisk(0.7);
     glPopMatrix();
}

void Leg1()
{
    glPushMatrix();
  glTranslatef(-.5,-0.5,0);
   glScalef(.09,.9,0);
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
    glEnd();
  glPopMatrix();
   glPushMatrix();
    glTranslatef(-0.5,-0.9,0);
   glScalef(0.14,0.08,0);
     drawDisk(0.6);
     glPopMatrix();

}

void Man1()
{
     glPushMatrix();
  glTranslatef(0.5,0,0);
  Leg();
glPopMatrix();
       glPushMatrix();
   glTranslatef(0,0.8,0);
   glScalef(0.4,0.456,0);
    glColor3f (1.0, 0.8, 0.6);
  drawDisk(.5);
  glPopMatrix();
   glPushMatrix();
  glTranslatef(0,0.5,0);
   glScalef(0.1,0.2,0);
    glColor3f (1.0, 0.8, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
    glEnd();
  glPopMatrix();

    glPushMatrix();
     glTranslatef(0,0.1,0);
   glScalef(0.6,0.9,0);
    glColor3f (0.0, 0.9, .9);
  drawDisk(.5);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.5,0.9,0);
  Hand();
glPopMatrix();
   glFlush();
     glPushMatrix();
  glTranslatef(0.5,0.9,0);
  Hand();
glPopMatrix();



 glPushMatrix();
   glTranslatef(0.13,0.85,0);
   glScalef(0.1,0.05,0);
    glColor3f (1.0, 1.0, 1.0);
  drawDisk(.5);
  glPopMatrix();
   glPushMatrix();
   glTranslatef(0.13,0.85,0);
   glScalef(0.03,0.03,0);
    glColor3f (0.0, 0.0, 0.0);
  drawDisk(.5);
  glPopMatrix();
     glPushMatrix();
   glTranslatef(0.1,0.68,0);
   glScalef(0.06,0.03,0);
    glColor3f (.8, .5, 0.0);
    Mouth(1);
  glPopMatrix();
   glPushMatrix();
   glTranslatef(0,.98,0);
   glScalef(0.15,0.05,0);
  glColor3f(0,0,0);
  Hair(1);
glPopMatrix();

 glPushMatrix();
   glTranslatef(0.12,.88,0);
   glScalef(0.05,0.01,0);
  glColor3f(0,0,0);

  brew(1);
glPopMatrix();
   glPushMatrix();
   glTranslatef(.2,.76,0);
   glScalef(0.05,0.02,0);
   glColor3f (1.0, 0.8, 0.6);;
  drawDisk(1);
glPopMatrix();
}





//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//for car wheel

void drawWheel() {

	glColor3f(0,0,0);
	drawDisk(1);
	glColor3f(0.75f, 0.75f, 0.75f);
	drawDisk(0.8);
	glColor3f(0,0,0);
	drawDisk(0.2);

}



//circle for car and others  using disk
void drawCircle() {
	glColor3f(0.5,0,0);
	drawDisk(0.2);
}


//drawing small car ...............

void drawCart() {

glPushMatrix();
	glTranslatef(-1.2f, -1.6f, 0);
	glScalef(0.4,0.4f,1);
	drawWheel();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.2f, -1.6f, 0);
	glScalef(0.4f,0.4f,1);
	drawWheel();
	glPopMatrix();
	glColor3f(1,0,0);

	glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(0.30f,0.30f,0.30f);            // Set The Color To Red
  glVertex2f(-1.0f, .90f);
  glVertex2f(1.0f, .90f);
  glVertex2f(1.5 , -.10f);
  glVertex2f(-1.5f, -.10f);       // Top left
  glEnd();


    glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(0.0f,0.0f,1.0f);            // Set The Color To Red
  glVertex2f(1.5f, -.10f);
  glVertex2f(2.5f, -.6f);
  glVertex2f(-2.0f , -.6f);
  glVertex2f(-1.5f, -.10f);        // Top left
  glEnd();

  glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(0.0f,0.0f,1.0f);            // Set The Color To Red
  glVertex2f(2.5f, -.6f);
  glVertex2f(2.5f, -1.6f);
  glVertex2f(-2.0f , -1.6f);
  glVertex2f(-2.0f , -.6f);;        // Top left
  glEnd();

glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(0.0f,0.0f,1.0f);            // Set The Color To Red
  glVertex2f(-1.0f, .90f);
  glVertex2f(1.0f, .90f);
  glVertex2f(1.0 , .75f);
  glVertex2f(-1.0f, .75f);       // Top left
  glEnd();

  glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(0.0f,0.0f,1.0f);            // Set The Color To Red
  glVertex2f(-1.0f, .90f);
  glVertex2f(-.90f, .90f);
  glVertex2f(-.90 , -.10f);
  glVertex2f(-1.0f, -.10f);       // Top left
  glEnd();

   glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(0.0f,0.0f,1.0f);            // Set The Color To Red
  glVertex2f(-.15f, .90f);
  glVertex2f(.15f, .90f);
  glVertex2f(.15f , -.10f);
  glVertex2f(-.15f, -.10f);       // Top left
  glEnd();

glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(0.0f,0.0f,1.0f);            // Set The Color To Red
  glVertex2f(1.0f, .90f);
  glVertex2f(.90f, .90f);
  glVertex2f(.90 , -.10f);
  glVertex2f(1.0f, -.10f);
  glEnd();
}


//rotate the car for first window

void small_car_rotate(){
    glPushMatrix();
    glTranslatef(1900,480, 0);
	glScalef(35,35,0);
    glRotatef(180, 0, 360,0);
    drawCart();
    glPopMatrix();
}



//<------------Drawing girl for passenger------------------>>


//circle for girl face and other thing
GLvoid circle_for_girl(GLdouble rad)
{
	GLint points = 500;
	GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
	GLdouble theta = 0;

GLint i=0;
	glBegin(GL_POLYGON);
	{
		for(i = 0; i <=500; i++, theta += delTheta )
		{

			glVertex2f(rad * cos(theta),rad * sin(theta));
		}
	}
	glEnd();
}


//not proper circle for girl hair;
GLvoid semi_circle_for_girl(GLdouble rad)
{
	GLint points = 110;
	GLdouble delTheta = (PI) / (GLdouble)points;
	GLdouble theta = 30;

    GLint i=0;
	glBegin(GL_POLYGON);
	{

		for(i = 0; i <=100; i++, theta += delTheta )
		{

            glVertex2d(rad *cos(theta),rad * sin(theta));

		}
	}
	glEnd();
}


GLvoid ghand(void)
{
glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glColor3d(1,.8,.5);
    glVertex2f(.2,.05);
    glVertex2f(.3,-.2);
    glVertex2f(.2,-.4);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glColor3d(1,.8,.5);
    glVertex2f(-.2,.05);
    glVertex2f(-.3,-.2);
    glVertex2f(-.2,-.4);
    glEnd();
}


GLvoid gleg(void)
{
    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glColor3d(1,.8,.5);
    glVertex2f(-.2,-0.8);
    glVertex2f(-.4,-1.4);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glColor3d(1,.8,.5);
    glVertex2f(.2,-0.8);
    glVertex2f(.4,-1.4);
    glEnd();
}


GLvoid girldress(void)
{
    gleg();
    glBegin(GL_POLYGON);
    glColor3d(.2,0,.2);
    glVertex2f(-.2,.05);
    glVertex2f(.2,.05);
    glVertex2f(.3,-1);
    glVertex2f(-.3,-1);
    glEnd();
    glPushMatrix();
    glColor3d(.8,0,.4);
    glRotated(90,0,0,1);
    semi_circle_for_girl(.33);
    glPopMatrix();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0,0);
    glVertex2f(0,-.8);
    glVertex2f(0,0);
    glVertex2f(-.1,-.7);
    glVertex2f(0,0);
    glVertex2f(.1,-.7);
    glEnd();

    glPushMatrix();
    glColor3d(0,.2,0);
    glTranslated(-.4,-1.35,0);
    circle_for_girl(.09);
    glTranslated(.8,0,0);
    circle_for_girl(.09);
    glPopMatrix();

    ghand();

    glEnd();

}


//girl final
GLvoid girl(void)
{

    glPushMatrix();
    glTranslated(-4,3.4,0);
    girldress();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4,4,0);
    glColor3d(1,.8,.5);
    circle_for_girl(.25);
    glColor3d(0,0,0);
    glRotated(65,0,0,1);
    glTranslated(.1,.08,0);
    semi_circle_for_girl(.25);
    glRotated(65,0,0,1);
    semi_circle_for_girl(.25);
    glTranslated(-.15,0,0);
    circle_for_girl(.03);
    glTranslated(.11,.1,0);
    circle_for_girl(.03);
    glTranslated(-.13,.01,0);
    circle_for_girl(.0185);
    glColor3d(1,0,0);
    glTranslated(-.09,.07,0);
    glColor3d(1,0,0.2);
    circle_for_girl(.033);
    glColor3d(1,.8,.5);
    glTranslated(-.05,.07,0);
    circle_for_girl(.05);
    glPopMatrix();

}



//drawing boat

void boat(){

glColor3ub(0,0,251);

 glBegin(GL_POLYGON);
 glVertex2f(100,50);
    glVertex2f(0,100);
    glVertex2f(400,100);
    glVertex2f(300,50);
    glEnd();

    glColor3ub(255,0,0);

     glBegin(GL_POLYGON);
    glVertex2f(50,100);
    glVertex2f(50,120);
    glVertex2f(350,120);
    glVertex2f(350,100);
    glEnd();

    glColor3ub(0,0,128);

    glBegin(GL_POLYGON);
    glVertex2f(70,120);
    glVertex2f(70,140);
    glVertex2f(330,140);
    glVertex2f(330,120);
    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(110,65);
    glVertex2f(110,85);
    glVertex2f(140,85);
    glVertex2f(140,65);
    glEnd();

     glPushMatrix();
     glTranslatef(50,0,0);
     glColor3ub(255,255,255);
     glBegin(GL_POLYGON);
     glVertex2f(110,65);
     glVertex2f(110,85);
     glVertex2f(140,85);
     glVertex2f(140,65);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(100,0,0);
     glColor3ub(255,255,255);
     glBegin(GL_POLYGON);
     glVertex2f(110,65);
     glVertex2f(110,85);
     glVertex2f(140,85);
     glVertex2f(140,65);
     glEnd();
     glPopMatrix();

     glPushMatrix();
    glTranslatef(150,0,0);
     glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(110,65);
    glVertex2f(110,85);
    glVertex2f(140,85);
    glVertex2f(140,65);
    glEnd();
    glPopMatrix();

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(110,140);
    glVertex2f(110,180);
    glVertex2f(140,180);
    glVertex2f(140,140);
    glEnd();

     glPushMatrix();
    glTranslatef(75,0,0);
     glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(110,140);
    glVertex2f(110,180);
    glVertex2f(140,180);
    glVertex2f(140,140);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(150,0,0);
     glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(110,140);
    glVertex2f(110,180);
    glVertex2f(140,180);
    glVertex2f(140,140);
    glEnd();
    glPopMatrix();


}



//road

void road(){
    glBegin(GL_POLYGON);
    glVertex2f(0,400);
    glVertex2f(1800,400);
    glVertex2f(1800,600);
    glVertex2f(0,600);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(150,600);
    glVertex2f(300,1000);
    glVertex2f(450,1000);
    glVertex2f(300,600);
    glEnd();

}


 //read er dag
void road_strip()
{

 glColor3ub(255,229,0);
    int j = 185;
    for(int i = 535 ;i <= 1000; i+=80)
        {
            glBegin(GL_POLYGON);
            glColor3ub(255,229,0);
            glVertex2f(j,i);
            glVertex2f(j+5,i);
            glVertex2f(j+15,i+50);
            glVertex2f(j+20,i+50);
            glEnd();
            j+=35;
       }

 for(int i=10;i<=1800;i+=100)
    {
        glBegin(GL_POLYGON);
        glColor3ub(255,229,0);
        glVertex2f(i,505);
        glVertex2f(i,510);
        glVertex2f(i+50,510);
        glVertex2f(i+50,505);
        glEnd();
     }

}




//first window
void first_window()
{


    road();
    road_strip();
    busstop();

	//crismas tree
	glPushMatrix();
    glTranslatef(130,760,0);
    crismas();
	glPopMatrix();


	//printing 9/10 grass
	for(int i=-100;i<=1800;i+=200){
        glPushMatrix();
        glTranslatef(i,150,0);
        grass();
        glPopMatrix();
	}

//crismas tree 4ta translate
	glPushMatrix();
    glTranslatef(750,650,0);
    crismas();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(900,650,0);
    crismas();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(1050,650,0);
    crismas();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(1700,650,0);
    crismas();
	glPopMatrix();


	//car small one which will moving
	glPushMatrix();
	glTranslatef(var_small_car,0, 0);
    small_car_rotate();
	glPopMatrix();


	//printing 3/4 grass other side of road
	for(int i=600;i<=1050;i+=180){
        glPushMatrix();
        glTranslatef(i,465,0);
        grass();
        glPopMatrix();
	}



	glPushMatrix();
    glTranslatef(1600,465,0);
    grass();
    glPopMatrix();




	glPushMatrix();
    glTranslatef(20,40,0);
    lamp();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(210,30,0);
    lamp();
	glPopMatrix();


	glPushMatrix();
    glTranslatef(660,0,0);
    lamp();
	glPopMatrix();



	    glPushMatrix();
    glTranslatef(280,480,0);
     building_abd_scal();
	glPopMatrix();


    glPushMatrix();
    glTranslatef(1400,630,0);
     building2_translate();
	glPopMatrix();

    glPushMatrix();
    glTranslatef(-50,-320,0);
    lamp();
	glPopMatrix();

	river();


	// if the car is in font of bus stop then man_in will be true press y/Y
	 if(!man_in){
         glPushMatrix();
        glTranslatef(740,520, 0);
        glScalef(43,45,0);
        girl();
        glPopMatrix();
	 }

	 // the second vodka man
    glPushMatrix();
    glTranslatef(320,655, 0);
	glScalef(60,60,0);
	glTranslatef(var_man,0, 0);
    Man1();
	glPopMatrix();


	//boat for first window

	glPushMatrix();
	glTranslatef(1900,0, 0);
	glTranslatef(var_boat,0, 0);
    boat();
	glPopMatrix();


}


//second window.............
void second_window()
{
    //road
    glBegin(GL_POLYGON);
    glVertex2f(0,400);
    glVertex2f(1800,400);
    glVertex2f(1800,600);
    glVertex2f(0,600);
    glEnd();

    glColor3ub(255,229,0);


    //second window road strip
    for(int i=10;i<=1800;i+=100){
        glBegin(GL_POLYGON);
        glColor3ub(255,229,0);
        glVertex2f(i,505);
        glVertex2f(i,510);
        glVertex2f(i+50,510);
        glVertex2f(i+50,505);
        glEnd();
    }


    // printing grass on my side
    for(int i=-50;i<=1450;i+=250){
        glPushMatrix();
        glTranslatef(i,150,0);
        grass();
        glPopMatrix();
    }


    //crismas tree
	glPushMatrix();
    glTranslatef(130,720,0);
    crismas();
	glPopMatrix();


	glPushMatrix();
    glTranslatef(870,720,0);
    crismas();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(950,470,0);
    grass();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(-50,470,0);
    grass();
	glPopMatrix();


	glPushMatrix();
    glTranslatef(450,470,0);
    grass();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(700,470,0);
    grass();
	glPopMatrix();


	//printing crismas tree

for(int i=200;i<=1400;i+=400){ //problem

        glPushMatrix();
        glTranslatef(i,220,0);
        crismas();
        glPopMatrix();
	}


    glPushMatrix();
    glTranslatef(310,480,0);
     building_abd_scal();
	glPopMatrix();

    glPushMatrix();
    glTranslatef(1100,430,0);
    building_scal();
	glPopMatrix();


	glPushMatrix();
    glTranslatef(200,650,0);
     building3_scal();
	glPopMatrix();


	//if the car is in font of varsity that time man out will be true press A/a
	if(man_out){
        glPushMatrix();
        glTranslatef(1640,520, 0);
        glScalef(43,45,0);
        girl();
        glPopMatrix();
	 }


	 glPushMatrix();
    glTranslatef(100,640, 0);
	glScalef(30,30,0);
	glTranslatef(var_car2,0,0);
    drawCart();
    glPopMatrix();

	river();



    glPushMatrix();
	glTranslatef(500,110, 0);
	glScalef(.7,.7,0);
	glTranslatef(var_boat2,0, 0);
    boat();
	glPopMatrix();

}


//display
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(30,40,60);

    if(window==1){
        glClear(GL_COLOR_BUFFER_BIT);
        glutIdleFunc(NULL);
        second_window();
        glutIdleFunc(boat_moving2);

        glutPostRedisplay();
        if(tx<=0){
            window=0;
            tx=1750;
        }
        else if(tx>1800){
            window=0;
            tx=0;
        }
    }
    else{
        glClear(GL_COLOR_BUFFER_BIT);
        first_window();

        glutPostRedisplay();
        if(tx>=1790){
             glutIdleFunc(NULL);
            window = 1 ;
            glutPostRedisplay();
            tx=10;
        }
    }

    glPushMatrix();
	glTranslatef(tx,ty,0);
    bus_final();
	glPopMatrix();


    glFlush();
    glutSwapBuffers();

}


//initialization ............
void init()
{
    glClearColor(.01,.9,.5,0);
    glOrtho(0,1800,0,1000,0,1);
}


//main
int main()
{

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1800,1000);
    glutInitWindowPosition(0,0);
    glutCreateWindow("BEGINNERS");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutMouseFunc(mouse);
    glutKeyboardFunc(my_keyboard);
    glutMainLoop();
    return 0;
}
