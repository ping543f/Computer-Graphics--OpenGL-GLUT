#include<windows.h>
#include <stdio.h>

#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<sstream>

using namespace std;

#define n 600
int counter=0;
int gamestate=0;
int Health=50;
int c=0;
string convertInt(int number)
{
   stringstream ss;

   ss << number;
   return ss.str();
}
string convertHealth(int number)
{
   stringstream ss;//create a stringstream
   Health=Health-1;
   ss << Health;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}


int NOB;                //Number of Bullets
int NOF=4;              //Number of enemies per frame
int enemyX[481];        //Generates Random X positions for X

class enemy             //enemy class
{
	public:
	double x;           //Position initial position of x coordinate of enemy spaceship
	double y;           // initial position of y  coordinate of enemy spaceship
    int alive;          // this variable will whether the enemy is alive not not 0 means alive 1 means dead
	double x2;          //this the same x2 coordinate as we have declared earlier but this one will be retrieved for collision detection
	double y2;          //same as the above x2 t
	double w2;          //width of the object
	double h2;          //height of the object
	enemy()             // constructor for enemy
	{
		alive=1;        // we will make the alive  variable 1


	}
	void getcollsioninformation(){  // this function send information about current position

	x2=x-10;
	w2=40;
	y2=y+40;
	h2=50;

}

	void init()
	{
		x=enemyX[rand()%481];
		y=500;
		alive=1;
	}

	void draw()              //this draws the enemy
	{
		glColor3f(0.9,0.91,0.98);
		glBegin(GL_QUADS);
			glVertex2f(x,y);

			glVertex2f(x+20,y);       //BODY
			glVertex2f(x+20,y+40);
			glVertex2f(x,y+40);

		glEnd();
		glBegin(GL_QUADS);
			glVertex2f(x-10,y+15);  //wing 1
			glVertex2f(x,y+15);
			glVertex2f(x,y+15-5);
			glVertex2f(x-10,y+15-5);
		glEnd();
		glBegin(GL_QUADS);
			glVertex2f(x+30-10,y+15);
			glVertex2f(x+40-10,y+15);  // wing2
			glVertex2f(x+40-10,y+10);
			glVertex2f(x+30-10,y+10);
		glEnd();

		glColor3f(0,0,1);


            glBegin(GL_POLYGON);
            glVertex2f(x,y);

            glVertex2f(x+10,y-10);  // warhead
            //glVertex2f(x+10,y-10);
            glVertex2f(x+20,y);

              glEnd();


	}
	void move(float offset) //this function will be descend the enemy according a give speed which is offset in this case
	{
		y=y-offset;
	}

};






class star                      //start object we have made start with glpoints
{
	public:

		double x;                //x and y coordinates of start
		double y;
		void move()              // since stars will be falling y has to be decreased
		{
			y--;
		}
		void show()     // draws the start
		{
		    //glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glPointSize(1);
			glColor3f(1,1,1);
			glBegin(GL_POINTS);
			glVertex2f(x,y);
			glEnd();
			//glFlush();
		}


};

class myship            //class for spaceship
{
	public:
		double x;       //x and y coordinates
		double y;
		int shoot;
		int alive;    // checks whether alive of not
		double x1;
		double y1;
		double w1;
		double h1;
		myship()         //constructor
		{
			x=250;       //initial position
			y=40;
			shoot=0;
			alive=1;      //alive or not
		}
		void information_for_collision(){   // info about collision


		x1=x-10;
		y1=0;
		w1=50;
		h1=60;
		}

		void move_left(int offset)     //moves the object left
		{
			x=x-offset;
		}
		void move_right(int offset)    //right
		{
			x=x+offset;
		}


		void displayShip()   //draws the ship
		{

		glColor3f(1,1,1);
			glBegin(GL_QUADS);
                        glVertex2f(x,0);
                        glVertex2f(x+30,0);
                        glVertex2f(x+30,0+40);  //body
                        glVertex2f(x,0+40);
                        glEnd();

            glBegin(GL_QUADS);
                        glVertex2f(x-10,5);  // the left wing
                        glVertex2f(x,5);
                        glVertex2f(x,20);
                        glVertex2f(x-10,20);
                        glEnd();

                glBegin(GL_QUADS);
                        glVertex2f(x+30,5);
                        glVertex2f(x+40,5); // the right wing
                        glVertex2f(x+40,20);
                        glVertex2f(x+30,20);
                        glEnd();


                glColor3f(1,0,0);
                glBegin(GL_TRIANGLES);
                        glVertex2f(x,0+40);
                        glVertex2f(x+30,0+40); // warhead
                        glVertex2f(x+15,0+60);

                        glEnd();

              }

        void Constructor() //resets the ship object
        {
        	x=250;
			y=40;
			shoot=0;
			alive=1;


        }
};



class bullet
{
	public:
		double x;
		double y;
		int firing;
		double x3;
		double y3;
		double w3;
		double h3;

		bullet()
		{
			firing=0;
		}
		void getPosition(myship ship)   // takes the position of ship
		{
			x=ship.x+15;
			y=ship.y+35;
		}
        void fire()
		{
           firing=1;
		}
		void draw()             //draws the bullet
		{
			glColor3f(1,0,0);
			glLineWidth(3);
			glBegin(GL_LINES);
				glVertex2f(x,y);
				glVertex2f(x,y+10);
			glEnd();
		}
		void move(int offset)   //ascends the bullet
		{
			y=y+offset;
		}
		void reinit()         //initialize
		{
			firing=0;
		}
};



bullet b[n];       //instance of bullet object



star s[n];        //start
void showstars()  //renders the start;
{
	int i;

	for(i=0;i<n;i++)
	{
		if(s[i].y >= 0)
		{
			s[i].show();    //render each object
			s[i].move();    //moves starts
		}
		else
		{
			s[i].y=500;     //initial y position 500
			s[i].x=rand()%500; //initial x position
		}
	}

}


myship ship;

void FireBulletsIfShot()
{
if(ship.shoot)                 //when ship.ship=1
	{
		b[NOB-1].fire();       //sets firing of bullet into 1
	b[NOB-1].getPosition(ship); //collects the current x position of ship
		ship.shoot=0;         //sets the shoot variable of ship into 0
	}
}
void drawship()       //renders the ship object
{


	if(ship.alive) //as long as the ship is alive
	{
		ship.displayShip(); //it will render the ship object
}

	FireBulletsIfShot(); //if ship.shot is 1 it sets the bullet ready to shot

}





/////////////////////////////////////////////Move Object with mouse////////////////////////////////////////

void move(int x, int y)  //takes the current position of mouse and sets the ship according to that
{
	ship.x=x;
	glutPostRedisplay();
}






int bulletspeed=26;  //this value will be added to the y of bullet
void drawbullet()    //renders bullet
{
	int i;

	for(i=0;i<NOB;i++)
	{
		if(b[i].firing)
		{
			b[i].draw(); //renders
			b[i].move(bulletspeed); //move
		}
		if(b[i].y > 500)
		{
			b[i].reinit();  //resets the bullet object when it goes beyond the screen

		}
	}
	if(NOB>30)  // number of bullets can never go beyond 30
	{
		NOB=0;
	}
}



enemy e[4];         //enemy object
int enemyspeed=5;   // speed at which enemy will fall
void drawenemy()
{

	int i;
	for(i=0;i<NOF;i++)
	{
		if(e[i].alive)  //as long as the enemy is alive  it will be rendered
		{
			e[i].draw();             //render the each enemy
			e[i].move(enemyspeed);  //enemies will fall at this speed
			if(e[i].y -10 < 0)  //when the y coordinate of y will be 0 new enemies will be initialized
			{
				e[i].init();  //initialize
			}
		}
		if(e[i].alive==0) //if the current enemy is dead it will also be initialized
		{

				e[i].init();


		}
	}



}

 ////////////////////////Collision detection of enemy with space ship/////////////////////////////////////
 collisionship(){

       for(int i=0;i<NOF;i++){

        e[i].getcollsioninformation();
        ship.information_for_collision();

    if((ship.x1<(e[i].x2+e[i].w2)) &&(e[i].x2<ship.x1+ship.w1) &&((ship.y1+ship.h1==e[i].y2-e[i].h2))){//|| ((ship.x1+ship.w1)>e[i].x2) && (ship.y1+ship.h1>e[i].y2+e[i].h2))){

       Health=Health-5;
       }

}

}





int sco=0;
///////////////////////////////////////Collision detection for bullet and enemy//////////////////////
void BulletsVsEnemyCollisionTest()
{
    int i;
	int j;
	for(i=0;i<NOB;i++)
	{

            for(j=0;j<NOF;j++){
            e[j].getcollsioninformation();
		if(e[j].x2<=b[i].x && b[i].x <= (e[j].x2+e[j].w2) && e[j].alive)
		{

				e[j].alive=0;
				b[i].firing=0;
				b[i].x=0;
				b[i].y=0;
				sco +=1;

		}
	}
}

}


/////////////////displays text////////////////////////////////////
void rendertext(float x,float y, string strings){

    glColor3d(1,0,0);

    glRasterPos2d(x,y);
    glDisable(GL_TEXTURE);
    glDisable(GL_TEXTURE_2D);
    for(int i=0;i<=strings.length();i++){
         glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)strings[i]);


    }
    glEnable(GL_TEXTURE);
    glEnable(GL_TEXTURE_2D);

}




void overdisplay()                //displays text when game is over
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	string text1="GAME OVER";
	string text2="You Scored ";
	string text3="Press r to restart";

	string temp=convertInt(sco);

	glColor3f(1,0,0);
	glRasterPos2f(180,250);
	int i;
	for(i=0;i<=text1.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)text1[i]);

	}
	glRasterPos2f(180,150);
	for(i=0;i<=text2.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)text2[i]);
	}

	for(i=0;i<=temp.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)temp[i]);
	}
	glRasterPos2f(180,130);

	for(i=0;i<=text3.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)text3[i]);
	}
	 glFlush();
	 glutSwapBuffers();
}

void display()
{
    start:
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	showstars();
    drawship();
	drawenemy();
	drawbullet();
ship.information_for_collision();

BulletsVsEnemyCollisionTest();
     collisionship();
char score[10]={0};
string sf="Score :"+ convertInt(sco);
string ss="Health :"+ convertInt(Health);
rendertext(10,480,ss);
rendertext(10,460,sf);

if(Health<=0){
ship.alive=0;

gamestate=1;


}
	glFlush();
	system("sleep 0.00001");
	glutSwapBuffers();
	glutPostRedisplay();
}

//////////////////////////////////////////Reset  All the function/////////////////////////////////////////////////

void Reinitialization()
{

	ship.Constructor();
    Health=100;
	sco=0;
	int i;
	NOF=4;
	for(i=0;i<NOF;i++)
	{
		e[i].init();
	}


	return;
}




/////////////////////////////////////////Keyboard/////////////////////////////////////////



void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	    //case 32:
		case 32:	if(ship.alive)
					{ship.shoot=1;
				NOB++;}
		break;
		case 'D':
		case 'd':




			break;

        case 'A':
		case 'a':



			break;
		case 'R':
		case 'r': if(ship.alive==0)
			{

					Reinitialization();
					gamestate=0;


			}
			break;

}
	glutPostRedisplay();
}
void keyboard(int button, int x, int y)
{
    if (button == GLUT_KEY_RIGHT)
    {
        ship.x=ship.x+10;

    }


    else if (button == GLUT_KEY_LEFT)
    {
         ship.x=ship.x-10;
    }




//update display
glutPostRedisplay();
}

/////////////////////////////////////////////////////Main Display Function////////////////////////////////////////

void loop()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	switch(gamestate)
	{
		case 0: display();
		break;
		case 1: overdisplay();
		break;
}
}



void myinit()
{
    int i;
	int inc=10;
	for(i=0;i<n;i++)
	{
    s[i].x=rand()%500;
		s[i].y=rand()%500;
     }


	for(i=0;i<481;i++)
	{
		enemyX[i]=inc;
		inc++;
	}

glClearColor(0.0, 0.0, 0.0, 0.0);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,100);
	glutCreateWindow("Spcae Shooter");
    glutDisplayFunc(loop);
	glutPassiveMotionFunc(move);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboard);
	myinit();
	glutMainLoop();
}









