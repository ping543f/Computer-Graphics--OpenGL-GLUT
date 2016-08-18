//14-25661-1, MD. IKRAM KHAN FAHIM 
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#define GRAVITY 10
#define PI 3.14159265

double convToRadians(double degrees);
double getGeometricAngle(double angle);

class Point {
private:
    double x;
    double y;
public:
    Point() {
        x = y = 0;
    }

    Point(double x, double y)   {
        this -> x = x;
        this -> y = y;
    }

    double operator-(const Point& otherPoint)   {
        double lx = this -> x - otherPoint.x;
        double ly = this -> y - otherPoint.y;
        return sqrt(lx * lx + ly * ly);
    }

//  Setters

    void set(Point point)   {
        set(point.x, point.y);
    }

    void set(double x, double y)    {
        setX(x);
        setY(y);
    }

    void setX(double x) { this -> x = x; }

    void setY(double y) { this -> y = y; }

//  Getters

    double getX() { return x; }

    double getY() { return y; }
};

double convToRadians(double degrees)    {
    return degrees * PI / 180;
}

class Fan   {
private:
    Point center;
    double wingLength1;
    double wingLength2;
    double wingAngle;
    int    wingCount;
    double displacement;
    double maximumSpeed;
    double currentSpeed;

    void initialize(Point center, double wingLength1, double wingLength2, double wingAngle, int wingCount, double displacement, double maximumSpeed)    {
        this -> center = center;
        this -> wingLength1 = wingLength1;
        this -> wingLength2 = wingLength2;
        this -> wingAngle = wingAngle < 0 ? -wingAngle : wingAngle;
        this -> wingCount = wingCount;
        this -> displacement = displacement;
        this -> maximumSpeed = maximumSpeed;
        currentSpeed = 0;
    }

public:
    Fan(Point center, double wingLength1, double wingLength2, double wingAngle, int wingCount, double maximumSpeed) {
        initialize(center, wingLength1, wingLength2, wingAngle, wingCount, 0, maximumSpeed);
    }

    Fan(Point center, double wingLength1, double wingLength2, double wingAngle, int wingCount)   {
        initialize(center, wingLength1, wingLength2, wingAngle, wingCount, 0, 30);
    }

    Fan(Point center, double maximumSpeed)  {
        initialize(center, 50, 30, 30, 4, 0, maximumSpeed);
    }

    Fan(Point center)   {
        initialize(center, 50, 30, 30, 4, 0, 30);
    }

    Fan(double wingLength1, double wingLength2, double wingAngle, int wingCount, double maximumSpeed)   {
        initialize(Point(), wingLength1, wingLength2, wingAngle, wingCount, 0, maximumSpeed);
    }

    Fan(double wingLength1, double wingLength2, double wingAngle, int wingCount)    {
        initialize(Point(), wingLength1, wingLength2, wingAngle, wingCount, 0, 30);
    }

    Fan(double maximumSpeed)    {
        initialize(Point(), 50, 30, 30, 4, 0, maximumSpeed);
    }

    Fan()   {
        initialize(Point(), 60, 40, 30, 4, 0, 30);
    }

    void getEndPoints(Point** endPoints)    {
    //  Point endPoints[wingCount][2];
        double alpha = displacement;
        double beta = displacement + wingAngle;
        double gap = 360.0 / wingCount;
        for(int i = 0; i < wingCount; i++)  {
            endPoints[i][0] = Point(center.getX() + wingLength1 * cos(convToRadians(alpha)), center.getY() + wingLength1 * sin(convToRadians(alpha)));
            endPoints[i][1] = Point(center.getX() + wingLength2 * cos(convToRadians(beta)), center.getY() + wingLength2 * sin(convToRadians(beta)));
            alpha = getGeometricAngle(alpha + gap);
            beta = getGeometricAngle(beta + gap);
        }
    }

    void tryToRotate()  {
        if(currentSpeed != 0)
            displacement = getGeometricAngle(displacement + currentSpeed);
    }

    bool isTurnedOn()   {
        return currentSpeed != 0;
    }

//  Setters

    void move(Point center)    {
        move(center.getX(), center.getY());
    }

    void move(double x, double y)   {
        center.set(x, y);
    }

    void setWingLength1(double wingLength1) {
        this -> wingLength1 = wingLength1;
    }

    void setWingLength2(double wingLength2) {
        this -> wingLength2 = wingLength2;
    }

    void setWingAngle(double wingAngle) {
        this -> wingAngle = wingAngle;
    }

    void setWingCount(double wingCount) {
        this -> wingCount = wingCount;
    }

    void setCurrentSpeed(double currentSpeed)   {
        if(abs(currentSpeed) <= abs(maximumSpeed)) this -> currentSpeed = currentSpeed;
    }

    void turnOn()   {
        currentSpeed = maximumSpeed;
    }

    void turnOff()  {
        currentSpeed = 0;
    }

//  Getters

    Point getCenter() { return center; }

    double getWingLength1() { return wingLength1; }

    double getWingLength2() { return wingLength2; }

    double getWingAngle() { return wingAngle; }

    int getWingCount() { return wingCount; }

    double getDisplacement() { return displacement; }

    double getCurrentSpeed() { return currentSpeed; }

    double getMaximumSpeed() { return maximumSpeed; }

    double getWingWeight() { return (wingLength1 + wingLength2) / 2 * wingAngle; }
};

class Projectile	{
private:
    Point location;
    double velocity_x;
    double velocity_y;
    double size;

    void initialize(Point location, double velocity_x, double velocity_y, double size)  {
        this -> location = location;
        this -> velocity_x = velocity_x;
        this -> velocity_y = velocity_y;
        this -> size = size;
    }

public:
    Projectile(Point location, double velocity_x, double velocity_y)    {
        initialize(location, velocity_x, velocity_y, 20);
    }

    Projectile(Point location)  {
        initialize(location, 0, 0, 20);
    }

    Projectile(double velocity_x, double velocity_y)    {
        initialize(Point(), velocity_x, velocity_y, 20);
    }

    Projectile()    {
        initialize(Point(), 0, 0, 20);
    }

    Projectile(Point location, double velocity_x, double velocity_y, double size)   {
        initialize(location, velocity_x, velocity_y, size);
    }

    Projectile(Point location, double size) {
        initialize(location, 0, 0, size);
    }

    Projectile(double velocity_x, double velocity_y, double size)   {
        initialize(Point(), velocity_x, velocity_y, size);
    }

    Projectile(double size) {
        initialize(Point(), 0, 0, size);
    }

    void shoot(double velocity_x, double velocity_y)    {
        this -> velocity_x = velocity_x;
        this -> velocity_y = velocity_y;
    }

    void move() {
        location.setX(location.getX() + velocity_x);
        location.setY(location.getY() + (velocity_y -= GRAVITY));
    }

    double getSpeed()   {
        return sqrt(velocity_x * velocity_x + velocity_y * velocity_y * 1.0);
    }

//  Setters

    void setLocation(Point location)    {
        this -> location = location;
    }

    void setSize(int size)  {
        this -> size = size;
    }

//  Getters

    Point getLocation() { return location; }

    double getSize() { return size; }

    double getHorizontalVelocity() { return velocity_x; }

    double getVerticalVelocity() { return velocity_y; }

    void getEndPoints(Point* endPoints) {
        int radius = this -> size / 2;
        endPoints[0].set(location.getX() - radius, location.getY() - radius);
        endPoints[1].set(location.getX() + radius, location.getY() - radius);
        endPoints[2].set(location.getX() + radius, location.getY() + radius);
        endPoints[3].set(location.getX() - radius, location.getY() + radius);
    }

    double getWeight() { return size * size * size; }
};

void display();
void init();
void onClick(int button, int state, int x, int y);
void onWindowSizeChange(int width, int height);
void onKeyPress(unsigned char key, int x, int y);
void onSpecialKeyPress(int key, int x, int y);
void onMouseMove(int x, int y);
void drawObject(Projectile&);
void drawObject(Fan& fan);
int getRandomNumber(int minimum, int maximum);
void proceed();
void sortByAbscissa(Point*, int start, int count);
void swapPoints(Point&, Point&);
void writeString(char* str, int number, void* font, Point location);
void writeString(char* str, void* font, Point location);

int window_width = 1200;
int window_height = 600;

int center_x = window_width / 2;
int center_y = window_height / 2;

int delay = 30;
int countDown = 0;

int score = 0;
int fuel = 1000;

bool gameIsPaused = false;

Fan blades;

Projectile p1(Point(0, 0), 10, 80), p2(Point(0, 0), 10, 90), p3(Point(0, 0), 10, 100);

Projectile blocks[1000], specialBlocks[1000];
int blockCount = 10, specialBlockCount = 1;

int main(int argc, char** argv)	{
	blocks[0] = p1;
	blocks[1] = p2;
	blocks[2] = p3;
    Point center(center_x, center_y);
    srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(window_width, window_height);
	glutCreateWindow("The Grinder - By the Grace of Allah");
	glutSetCursor(GLUT_CURSOR_DESTROY);
	glutDisplayFunc(display);
	glutIdleFunc(proceed);
	glutMouseFunc(onClick);
    glutKeyboardFunc(onKeyPress);
	glutReshapeFunc(onWindowSizeChange);
	glutSpecialFunc(onSpecialKeyPress);
	glutMotionFunc(onMouseMove);
	glutPassiveMotionFunc(onMouseMove);
	init();

	glutMainLoop();

	return 0;
}

void endGame()	{
	glClear(GL_COLOR_BUFFER_BIT);
	glutIdleFunc(NULL);
	glColor3ub(255, 255, 255);
	writeString("G  A   M   E       O   V   E   R", GLUT_BITMAP_HELVETICA_18, Point(window_width / 2, window_height / 2));
	writeString("Your  score  is  ", score, GLUT_BITMAP_HELVETICA_18, Point(window_width / 2, window_height / 2 - 40));
	glutSwapBuffers();
}

void swapPoints(Point& point1, Point& point2)   {
    Point temp = point1;
    point1 = point2;
    point2 = temp;
}

void sortByAbscissa(Point* points, int start, int count)    {
    int end = start + count;
    for(int i = start; i < end - 1; i++)    {
        for(int j = i + 1; j < end; j++)    {
            if(points[i].getX() > points[j].getX())
                swapPoints(points[i], points[j]);
        }
    }
}

/*
void checkForCollisions()   {
    int wingCount = blades.getWingCount();
    Point endPoints[wingCount][2];
    blades.getEndPoints(endPoints);
    Point wing[3];
    for(int i = 0; i < blockCount; i++) {
        for(int j = 0; j < wingCount; j++)  {
            wing[0] = blades.getCenter();
            wing[1] = endPoints[j][0];
            wing[2] = endPoints[j][1];
            sortByAbscissa(wing, 0, 3);
            Point location = blocks[i].getLocation();
            double x = location.getX();
            double y = location.getY();
            double xL = wing[0].getX();
            double yL = wing[0].getY();
            double xM = wing[1].getX();
            double yM = wing[1].getY();
            double xR = wing[2].getX();
            double yR = wing[2].getY();
            if(x < xL || x > xR) break;
            if(yL + (xM - xL) * (yL - yR) / (xL - xR) < yM) {
                if(y > yM) break;
                if(((xM != xR && y <= yM + (x - xM) * (yM - yR) / (xM - xR)) || x <= xR) && ((xM != xL && y <= yM + (x - xM) * (yM - yL) / (xM - xL)) || x >= xL) && y >= yL + (x - xL) * (yL - yR) / (xL - xR))    {
                    blocks[i].shoot(0, abs(blocks[i].getVerticalVelocity() * 2));
                    break;
                }
            }
            else    {
                if(y < yM) break;
                if(((xM != xR && y >= yM + (x - xM) * (yM - yR) / (xM - xR)) || x <= xR) && ((xM != xL && y >= yM + (x - xM) * (yM - yL) / (xM - xL)) || x >= xL) && y <= yL + (x - xL) * (yL - yR) / (xL - xR))    {
                    blocks[i].shoot(0, abs(blocks[i].getVerticalVelocity() * 2));
                    break;
                }
            }
        }
    }
}
*/

/*
Point getNearestPoint(Projectile block, Point center)   {
    Point endPoints[4];
    block.getEndPoints(endPoints);
    double cx = center.getX();
    double cy = center.getY();
    Point& nearestPoint = endPoints[0];
    double lxmin = abs(cx - endPoints[0].getX());
    double lymin = abs(cy - endPoints[0].getY());
    double lx, ly;
    for(int i = 1; i < 4; i++)  {
        lx = abs(cx - endPoints[i].getX());
        ly = abs(cy - endPoints[i].getX());
        if(lx + ly < lxmin + lymin) {
            lxmin = lx;
            lymin = ly;
            nearestPoint = endPoints[i];
        }
    }
    return nearestPoint;
}
*/

void checkForCollisions(Projectile* blocks, int& blockCount)    {
    if(!blades.isTurnedOn()) return;
    Point fanCenter = blades.getCenter();
    Point blockCenter;
    double lx, ly, d;
    double radius = max(blades.getWingLength1(), blades.getWingLength2());
    double hittingAngle, shootingAngle1, shootingAngle2, resultantAngle, dispersionAngle;
    double v, vx, vy, vyMax = sqrt(window_height * GRAVITY * 2);
    double boost;
    int extraBlockCount = 0;
    double blockWeight;
    double wingWeight = blades.getWingWeight();
    double bladeSpeed = blades.getCurrentSpeed();
    double totalWingAngle = blades.getWingAngle() * blades.getWingCount();
    for(int i = 0; i < blockCount; i++) {
        blockCenter.set(blocks[i].getLocation());
        lx = blockCenter.getX() - fanCenter.getX();
        ly = blockCenter.getY() - fanCenter.getY();
        d = sqrt(lx * lx + ly * ly);
        if(d <= radius) {
            boost = d / radius;
            vx = blocks[i].getHorizontalVelocity();
            vy = blocks[i].getVerticalVelocity();
            blockWeight = blocks[i].getWeight();
            hittingAngle = PI / 2 + atan2((double)ly, (double)lx);
            vx += bladeSpeed * cos(hittingAngle) * boost;
            vy += bladeSpeed * sin(hittingAngle) * boost;
            v = sqrt(vx * vx + vy * vy);
            resultantAngle = atan2((double)vy, (double)vx);
            dispersionAngle = boost * (wingWeight - blockWeight) / wingWeight * (PI / 4);
            shootingAngle1 = hittingAngle + dispersionAngle;
            shootingAngle2 = hittingAngle - dispersionAngle;
            blocks[i].setSize(blocks[i].getSize() / pow(2, 1.0 / 3));
            if(blocks[i].getSize() <= 3)    {
                blocks[i].shoot(0, -100);
                continue;
            }
            blocks[blockCount].setLocation(blocks[i].getLocation());
            blocks[blockCount].setSize(blocks[i].getSize());
            blocks[i].shoot(v * cos(shootingAngle1), v * sin(shootingAngle1));
            blocks[blockCount].shoot(v * cos(shootingAngle2), v * sin(shootingAngle2));
            extraBlockCount++;
        }
    }
    if(extraBlockCount > 0)
        blockCount += extraBlockCount;
}

double getGeometricAngle(double angle)  {
    while(angle >= 360) angle -= 360;
    while(angle < 0)    angle += 360;
    return angle;
}

void onMouseMove(int x, int y)	{
	blades.move(x, window_height - y);
}

void proceed()  {
    glutPostRedisplay();
}

void display()	{
    Sleep(delay);
	glClear(GL_COLOR_BUFFER_BIT);

	if(!gameIsPaused)
        blades.tryToRotate();

	drawObject(blades);

	if(blades.isTurnedOn()) fuel--;

	if(fuel <= 0)	{
		glutDisplayFunc(endGame);
		glutPostRedisplay();
	}

	if(countDown == 0)  {
        bool windowIsOutOfBlocks = true;
        glColor3ub(255, 0, 0);
        for(int i = 0; i < blockCount; i++)	{
            if(blocks[i].getLocation().getX() >= 0 && blocks[i].getLocation().getX() <= window_width && blocks[i].getLocation().getY() >= 0)    {
                if(windowIsOutOfBlocks == true)
                    windowIsOutOfBlocks = false;
                blocks[i].move();
                drawObject(blocks[i]);
            }
        }

        glColor3ub(0, 255, 0);
        for(int i = 0; i < specialBlockCount; i++)  {
            if(specialBlocks[i].getLocation().getX() >= 0 && specialBlocks[i].getLocation().getX() <= window_width && specialBlocks[i].getLocation().getY() >= 0)   {
                if(windowIsOutOfBlocks == true)
                    windowIsOutOfBlocks = false;
                specialBlocks[i].move();
                drawObject(specialBlocks[i]);
            }
        }

        if(windowIsOutOfBlocks) {
            countDown = blockCount;
            blockCount = getRandomNumber(1, 10);
            score -= blockCount;
            if(getRandomNumber(0, 3) == 0)  {
                specialBlockCount = 1;
            }   else    {
                specialBlockCount = 0;
            }
            double maxSpeed = sqrt(window_height * GRAVITY * 2.0);
            for(int i = 0; i < blockCount; i++)
                blocks[i] = Projectile(Point(window_width / getRandomNumber(2, 3), 0), getRandomNumber(-20, 20), getRandomNumber(maxSpeed / 2, maxSpeed));
            if(specialBlockCount == 1)
                specialBlocks[0] = Projectile(Point(window_width / getRandomNumber(2, 3), 0), getRandomNumber(-20, 20), getRandomNumber(maxSpeed / 2, maxSpeed));
        }
    }

    else countDown--;

    int lastBlockCount = blockCount;
	checkForCollisions(blocks, blockCount);
	score += blades.getCenter().getY() / window_height * (blockCount - lastBlockCount) * 10;
	if(specialBlockCount > 0)   {
        lastBlockCount = specialBlockCount;
        checkForCollisions(specialBlocks, specialBlockCount);
        fuel += (specialBlockCount - lastBlockCount) * 50;
    }

    if(score >= 3000 && blades.getWingCount() < 7)  {
        blades.setWingCount(7);
    }   else if(score >= 2000 && blades.getWingCount() < 6) {
        blades.setWingCount(6);
    }   else if(score >= 1000 && blades.getWingCount() < 5) {
        blades.setWingCount(5);
    }

    glColor3ub(255, 255, 255);
    writeString("SCORE: ", score, GLUT_BITMAP_HELVETICA_18, Point(2, window_height - 20));
	writeString("FUEL: ", fuel, GLUT_BITMAP_HELVETICA_18, Point(300, window_height - 20));

	glutSwapBuffers();
}

void writeString(char* str, int number, void* font, Point location)	{
	char numBuffer[100];
	int index = 0;
	int temp = abs(number);
	do	{
		numBuffer[index++] = temp % 10 + '0';
	}	while((temp /= 10) != 0);
	if(number < 0) numBuffer[index++] = '-';
	writeString(str, font, location);
	while(--index >= 0)
		glutBitmapCharacter(font, numBuffer[index]);
}

void writeString(char* str, void* font, Point location)	{
	glRasterPos2f(location.getX(), location.getY());
	for(int i = 0; str[i] != NULL; i++)
		glutBitmapCharacter(font, str[i]);
}

int getRandomNumber(int minimum, int maximum)	{
	return rand() % (maximum - minimum + 1) + minimum;
}

void drawObject(Fan& fan)  {
    glColor3ub(200, 200, 200);
    int wingCount = fan.getWingCount();
    Point** endPoints = new Point*[wingCount];
    for(int i = 0; i < wingCount; i++)
        endPoints[i] = new Point[2];

    fan.getEndPoints(endPoints);

    glBegin(GL_TRIANGLES);
        for(int i = 0; i < wingCount; i++)  {
            glVertex2i(fan.getCenter().getX(), fan.getCenter().getY());
            glVertex2i(endPoints[i][0].getX(), endPoints[i][0].getY());
            glVertex2i(endPoints[i][1].getX(), endPoints[i][1].getY());
        }
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
        for(int i = 0; i < wingCount; i++)  {
            glVertex2i(fan.getCenter().getX(), fan.getCenter().getY());
            glVertex2i(endPoints[i][1].getX(), endPoints[i][1].getY());
            glVertex2i(endPoints[i][1].getX(), endPoints[i][1].getY());
            glVertex2i(endPoints[i][0].getX(), endPoints[i][0].getY());
        }
    glEnd();

    for(int i = 0; i < wingCount; i++)
        delete[] endPoints[i];
    delete[] endPoints;
}

void drawObject(Projectile& projectile) {
//	glColor3ub(rand() % 256, rand() % 256, rand() % 256);
	Point endPoints[4];
	projectile.getEndPoints(endPoints);
	Point location = projectile.getLocation();
	int x = location.getX();
	int y = location.getY();
	int size = projectile.getSize();
    glBegin(GL_QUADS);
        for(int i = 0; i < 4; i++)
            glVertex2i(endPoints[i].getX(), endPoints[i].getY());
    glEnd();
}

void onWindowSizeChange(int width, int height)	{
	window_width = width;
	window_height = height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, window_width, 0, window_height);
}

void onClick(int button, int state, int x, int y)	{
	switch(button)	{
	case GLUT_LEFT_BUTTON:
		if(state == GLUT_DOWN)	{
            blades.turnOn();
		}	else	{
            blades.turnOff();
		}
		break;
	default:
		break;
	}
}

void onSpecialKeyPress(int key, int x, int y)	{
	switch(key)	{
	case GLUT_KEY_UP:
		center_y += 10;
		break;
	case GLUT_KEY_DOWN:
		center_y -= 10;
		break;
	case GLUT_KEY_RIGHT:
		center_x += 10;
		break;
	case GLUT_KEY_LEFT:
		center_x -= 10;
		break;
	default:
		break;
	}
}

void onKeyPress(unsigned char key, int x, int y)    {
	if(key == 'p' || key == 'P')    {
		glutIdleFunc(NULL);
	}	else if(key == 'r' || key == 'R')	{
		glutIdleFunc(proceed);
	}
}

void init()	{
	glClearColor(0, 64.0 / 255, 64.0 / 255, 1);
	glLineWidth(2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, window_width, 0, window_height);
}
