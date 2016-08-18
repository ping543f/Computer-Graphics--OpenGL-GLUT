//Group Members
//Tokee, Abid Hassan; Id: 13-25244-3
//Ahmed, Fayez; Id: 13-25249-3


#include <stdio.h>
#include<string.h>
#include <GL/glut.h>


//Configuration
const int w=1000, h=600, nBricks=105,nRowLevel=7; //Window Width,Height & Total Bricks & Rows
const float ballMove=0.25; //Ball Moving Speed
float batX1=440,batY1=40,batX2=560,batY2=50,moveBatX=40; //Bat Properties
float ballX1=490,ballY1=batY2,ballX2=510,ballY2=batY2+20.0,ball_dx=ballMove,ball_dy=ballMove; //Ball Properties
float brickWidth=61, brickHeight=30, brickX1[nBricks], brickX2[nBricks], brickY1[nBricks], brickY2[nBricks], level[nRowLevel], brickStartY=580, brickStartX=8, brickSpaceX=5,brickSpaceY=10;//Brick Properties
bool brickStatus[nBricks],gameOver=false,brickDrawn=false,startGame=false; // For Some Checking Purpose
int score=0,perBrickPoint=20;
//End of Configuration


void drawBat()
{
	//Drawing Bat
	glColor3ub(255,23,68);
	glBegin(GL_QUADS);
	glVertex2i(batX1,batY1);
	glVertex2i(batX2,batY1);
	glVertex2i(batX2,batY2);
	glVertex2i(batX1,batY2);
	glEnd();
}

void renderBitmapString(float x,float y,void *font,char *string) {
  char *c;
  glRasterPos2f(x, y);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}

void ballNextPos()
{
	if(ballY2==h)  //Checking Ball Position with Top Edge
	{
		ball_dy=-ball_dy;
	}
	if(ballX1==0 && ballY1!=0)  //Checking Ball Position with Left Edge
	{
		ball_dx=-ball_dx;
	}
	if(ballX2==w && ballY1!=0)  //Checking Ball Position with Right Edge
	{
		ball_dx=-ball_dx;
	}
	if(ballY1==batY2)       
	{
		//Ball & Bat Collision Detection & Calcualting The Next Position
		if(ballX2>batX1 && ballX1<batX2)
		{
			int batMidPoint = (batX2+batX1)/2;
			int batRightQuarterPoint=(batMidPoint+batX2)/2;
			int batLeftQuarterPoint=(batMidPoint+batX1)/2;
			int ballMidPoint = (ballX2+ballX1)/2;
			int batMidLeftEnd=(batLeftQuarterPoint+batMidPoint)/2;
			int batMidRightEnd=(batRightQuarterPoint+batMidPoint)/2;
			if(ballMidPoint<batMidPoint)
			{
				ball_dy=-ballMove;
				ball_dy=-ball_dy;
				if(ballMidPoint<batLeftQuarterPoint)
				{
					if(ball_dx>0)
					{
						ball_dx=-ballMove*2;
						ball_dy*=2;
					}
					if(ball_dx==0)
					{
						ball_dx=-ballMove*2;
						ball_dy*=2;
					}
				}
				else
				{
					if(ballMidPoint>batMidLeftEnd)
					{
						ball_dx=0;
					}
					else
					{
						if(ball_dx>0)
						{
							ball_dx=-ballMove;
						}
						if(ball_dx==0)
						{
							ball_dx=-ballMove;
						}
					}
				}
				
			}
			else
			{
				ball_dy=-ballMove;
				ball_dy=-ball_dy;
				if(ballMidPoint>batRightQuarterPoint)
				{
					if(ball_dx<0)
					{
						ball_dx=ballMove*2;
						ball_dy*=2;
					}
					if(ball_dx==0)
					{
						ball_dx=ballMove*2;
						ball_dy*=2;
					}
				}
				else
				{
					if(ballMidPoint<batMidRightEnd)
					{
						ball_dx=0;
					}
					else
					{
						if(ball_dx<0)
						{
							ball_dx=ballMove;
						}
						if(ball_dx==0)
						{
							ball_dx=ballMove;
						}
					}
				}			
			}
		}
		else
		{
			gameOver=true;
		}
	}
	//End of Ball & Bat Collision Detection & Calcualting The Next Position
	for(int i =0; i<nBricks; i++)
	{
		if(ballY2==brickY1[i])
		{
			if(ballX2>brickX1[i] && ballX1<brickX2[i] && brickStatus[i]==true)
			{
				if(ball_dy>0)
					ball_dy=-ball_dy;
				brickStatus[i]=false;
			}
		}

		if(ballY1==brickY2[i])
		{
			if(ballX2>brickX1[i] && ballX1<brickX2[i] && brickStatus[i]==true)
			{
				if(ball_dy>0)
					ball_dy=-ball_dy;
				brickStatus[i]=false;
			}
		}
		if((ballX1==brickX1[i] || ballX1==brickX2[i] || ballX2==brickX1[i] || ballX2==brickX2[i]) && (ballY1==brickY2[i]||ballY2==brickY1[i]) && brickStatus[i]==true)
		{
			if(ball_dy>0)
				ball_dy=-ball_dy;
			brickStatus[i]=false;
		}
	}

	//Checking All Bricks Are Destroyed or Not
	bool allBricksDestroyed = true;
	score=0;
	for(int i=0; i<nBricks; i++)
	{
		if(brickStatus[i]==true)
		{
			allBricksDestroyed = false;
		}
		else
		{
			score+=perBrickPoint;
		}
	}
	if(allBricksDestroyed==true)
	{
		gameOver=true;
		score+=900;
	}
	char scoreMsg[100];
	sprintf(scoreMsg, "Score : %d",score);
	renderBitmapString(470,20,GLUT_BITMAP_HELVETICA_12,scoreMsg);

	//End of Checking All Bricks Are Destroyed or Not

	//Increment Ball Position
	ballY1+=ball_dy;
	ballY2+=ball_dy;
	ballX1+=ball_dx;
	ballX2+=ball_dx;
	//End of Increment
}

void drawBall()
{
	ballNextPos();
	//Drawing Ball
	if(gameOver==false)
		glColor3ub(255,255,255);
	else
		glColor3ub(0,0,0);
	glBegin(GL_QUADS);
	glVertex2i(ballX1,ballY1);
	glVertex2i(ballX2,ballY1);
	glVertex2i(ballX2,ballY2);
	glVertex2i(ballX1,ballY2);
	glEnd();
}

void drawBricks()
{
	int n=0,rowFirstN=0,rowLastN=15;
	if(!brickDrawn)
	{
		bool firstTime = true;	
		while(n<nRowLevel)
		{
			if(firstTime)
			{
				level[n]=brickStartY;
				firstTime = false;
			}
			else
				level[n]=level[n-1]-(brickHeight+brickSpaceY);
			brickX1[rowFirstN]=brickStartX;
			brickX2[rowFirstN]=brickX1[rowFirstN]+brickWidth;
			brickY1[rowFirstN]=level[n]-brickHeight;
			brickY2[rowFirstN]=level[n];
			switch(n) 
			{
				case 0:	
					glColor3ub(103,58,183);
					break;
				case 1:
					glColor3ub(63,81,181);
					break;
				case 2:
					glColor3ub(33,150,243);
					break;
				case 3:
					glColor3ub(244,67,64);
					break;
				case 4:
					glColor3ub(233,33,99);
					break;
				case 5:
					glColor3ub(156,39,176);
					break;
				case 6:
					glColor3ub(255,87,34);
					break;
			}
	
			glBegin(GL_QUADS);
			glVertex2i(brickX1[rowFirstN],brickY1[rowFirstN]);
			glVertex2i(brickX2[rowFirstN],brickY1[rowFirstN]);
			glVertex2i(brickX2[rowFirstN],brickY2[rowFirstN]);
			glVertex2i(brickX1[rowFirstN],brickY2[rowFirstN]);
			glEnd();
			for (int i=(rowFirstN+1);i<rowLastN;i++)
			{
				brickX1[i]=brickX2[i-1]+brickSpaceX;
				brickX2[i]=brickX1[i]+brickWidth;
				brickY1[i]=level[n]-brickHeight;
				brickY2[i]=level[n];
				glBegin(GL_QUADS);
				glVertex2i(brickX1[i],brickY1[i]);
				glVertex2i(brickX2[i],brickY1[i]);
				glVertex2i(brickX2[i],brickY2[i]);
				glVertex2i(brickX1[i],brickY2[i]);
				glEnd();		
			}
			n++;
			rowFirstN=rowFirstN+15;
			rowLastN=rowLastN+15;
		}
		brickDrawn=true;
	}
	else
	{
		for (int i=0; i<nBricks; i++)
		{
			if(i%rowLastN==0 && i!=0)
				n++;
			switch(n) 
			{
				case 0:	
					glColor3ub(103,58,183);
					break;
				case 1:
					glColor3ub(63,81,181);
					break;
				case 2:
					glColor3ub(33,150,243);
					break;
				case 3:
					glColor3ub(244,67,64);
					break;
				case 4:
					glColor3ub(233,33,99);
					break;
				case 5:
					glColor3ub(156,39,176);
					break;
				case 6:
					glColor3ub(255,87,34);
					break;
			}
			if(brickStatus[i] == true)
			{
				glBegin(GL_QUADS);
				glVertex2i(brickX1[i],brickY1[i]);
				glVertex2i(brickX2[i],brickY1[i]);
				glVertex2i(brickX2[i],brickY2[i]);
				glVertex2i(brickX1[i],brickY2[i]);
				glEnd();	
			}
		}
	}
}

void assignBrickStatus()
{
	for(int i=0;i<nBricks;i++)
	{
		brickStatus[i]=true;
	}
}


void reset()
{
	 batX1=440,batY1=40,batX2=560,batY2=50,moveBatX=40; //Bat Properties
	 ballX1=490,ballY1=batY2,ballX2=510,ballY2=batY2+20.0,ball_dx=ballMove,ball_dy=ballMove; //Ball Properties
	 brickWidth=61, brickHeight=30, brickX1[nBricks], brickX2[nBricks], brickY1[nBricks], brickY2[nBricks], level[nRowLevel], brickStartY=580, brickStartX=8, brickSpaceX=5,brickSpaceY=10;//Brick Properties
	 brickStatus[nBricks],gameOver=false,brickDrawn=false,startGame=false; // For Some Checking Purpose
	 score=0,perBrickPoint=20;
	 assignBrickStatus();
}

void playGame()
{
	//Game Started
	if(!gameOver)
	{
		drawBall();
		drawBat();
	}
	else
	{
		char str[100];
		strcpy(str,"Game Over");
		renderBitmapString(445,80,GLUT_BITMAP_TIMES_ROMAN_24,str);
		sprintf(str, "Your Score is : %d",score);
		renderBitmapString(420,50,GLUT_BITMAP_HELVETICA_18,str);
		strcpy(str,"Press F5 to Restart The Game");
		renderBitmapString(380,20,GLUT_BITMAP_HELVETICA_18,str);
	}
	glutPostRedisplay();
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT); 
	drawBricks();
	glColor3ub(255,255,255);
	if(!startGame)
	{
		char str[100];
		strcpy(str,"Use Keyboard Left Arrow Key & Right Arrow Key to Move The Bat");
		renderBitmapString(240,80,GLUT_BITMAP_HELVETICA_18,str);
		strcpy(str,"Or Use Mouse Left Button & Right Button to Move The Bat.");
		renderBitmapString(270,50,GLUT_BITMAP_HELVETICA_18,str);
		strcpy(str,"Press F5 to Start The Game");
		renderBitmapString(380,20,GLUT_BITMAP_HELVETICA_18,str);
	}
	else
	{
		playGame();
	}
	glutSwapBuffers(); 
}

void myInit (void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0); 
	glShadeModel(GL_SMOOTH); 
	glClearDepth(1.0f); 	                
	glEnable(GL_DEPTH_TEST);  
	gluOrtho2D(0.0, 1000.0, 0.0, 600.0);
}

void keyboard(int key, int x, int y)
{
	//All Keyboard Event
	if (key == GLUT_KEY_RIGHT)
	{
		//Moving Bat to The Right Side
		if(startGame==true && gameOver==false)
		{
			if(batX2<w)
			{
				batX1+=moveBatX;
				batX2+=moveBatX;
				glutPostRedisplay(); 
			}
		}		  
	}
	if (key == GLUT_KEY_LEFT)
	{
		//Moving Bat to The Left Side
		if(startGame==true && gameOver==false)
		{
			if(batX1>0)
			{
				batX1-=moveBatX;
				batX2-=moveBatX;
				glutPostRedisplay(); 
			}
		}
	}
	if(key == GLUT_KEY_F5)
	{
		if(startGame==false)
		{
			startGame=true;
			glutPostRedisplay(); 
		}
		if(gameOver==true)
		{
			reset();
		}
	}
}

void batMoveLeft()
{
	//Moving Bat to The Left Side
	if(startGame==true && gameOver==false)
	{
		if(batX1>0)
		{
			batX1-=1;
			batX2-=1;
			glutPostRedisplay(); 
		}
	}
}

void batMoveRight()
{
	//Moving Bat to The Right Side
	if(startGame==true && gameOver==false)
	{
		if(batX2<w)
		{
			batX1+=1;
			batX2+=1;
			glutPostRedisplay(); 
		}
	}		  
}

 void mouse(int button,int state,int x,int y)
{
	switch(button)
	{      
		case GLUT_LEFT_BUTTON:
			if(state==GLUT_DOWN)         
				glutIdleFunc(batMoveLeft);
			if(state==GLUT_UP)         
				glutIdleFunc(NULL);  
			break;     
		case GLUT_RIGHT_BUTTON: 
			if(state==GLUT_DOWN)
				glutIdleFunc(batMoveRight);
			if(state==GLUT_UP)         
				glutIdleFunc(NULL); 
			break; 
	}
}

void main(int argc, char** argv)
{
	printf("Welcome to DX Ball 2D\n\n");
	printf("***Instruction***\n");
	printf("Use Keyboard Left Arrow Key & Right Arrow Key to Move The Bat\n");
	printf("Or Use Mouse Left Button & Right Button to Move The Bat.\n\n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize (w,h);
	glutInitWindowPosition (100, 50);
	glutCreateWindow ("DX Ball 2D");
	assignBrickStatus();
	glutDisplayFunc(myDisplay);	
	glutSpecialFunc(keyboard);
	glutMouseFunc(mouse);
	myInit();
	glutMainLoop();	
}