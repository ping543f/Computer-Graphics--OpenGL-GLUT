//*This Program , Scenery Maker has been developed as semester project
//*for the subject Computer Graphics (Section A)
//*under the guidance of our honorable faculty Saef Ullah Miah
//*
//*The project has been developed by
//*1) Ahmed Muhammad Shafique
//*2) Asha Mony
//*3) Kashfiyq Ananya
//*
//*The project has some functions taken from the website :
//*Website : https://nccastaff.bournemouth.ac.uk/jmacey/RobTheBloke/www/opengl_programming.html
//*The functions have been marked accordingly
//*
//*
//*
//*
//*
//*We are really really grateful to our honorable faculty for guiding and enabling us to complete the project
//*We are also thankful to Rob Bateman for his excellent codes and concepts
//*
//*
//*




/*
Rough outline of the project:

//////////////Library definitions
//////////////Color definitions
//////////////Variable declarations
//////////////Mini helper function
//////////////Generic drawing functions (Scaled and Unscaled)
//////////////Hard calculated vertexes for different shapes
////////////////////Cloud
////////////////////House
////////////////////Tree
////////////////////Bird
////////////////////Flower
////////////////////Flock of birds
////////////////////Sun
////////////////////Bush
////////////////////Boat
//////////////Brush functions and their corresponding vertexes
////////////////////Grass
////////////////////Water
////////////////////Rubber
//////////////Mouse draw helper functions
//////////////Mouse manipulation functions
//////////////Palette making function
//////////////Custom Display function
//////////////Custom initialization function
//////////////Custom Screen size selector functions
//////////////Main function
*/




/*
Library declaration starts here
*/
#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <stdarg.h>
/*
Library declaration ends here
*/




/*
Color definition starts here
*/
#define white 1,1,1
#define black 0.0,0.0,0.0
#define orange 255.0,201.0,14.0
#define red 255.0,0.0,0.0
#define green 0.0,255.0,0.0
#define blue 0.0,0.0,255.0
#define maroon 185.0,122.0,87.0
#define greyishYellow 239.0,228.0,176.0
#define yellow 255.0,242.0,0.0
#define brown_tree 51, 0, 0
#define brown 77, 0, 0
#define blue1 0, 102, 204
#define blue2 128, 191, 255
#define blue3 128, 191, 255
#define clearWater 0.118, 0.565, 1.000
#define houseWalls 211,212,213
#define clear 1,1,1
/*
Color definition ends here
*/





/*
Variable declaration starts here
*/
//Full screen window Coordinates are stored in X and Y
int X ;
int Y ;

//Coordinates for separating the items
int paletteYBound,paletteGrassXBound,paletteTreeXBound,paletteCloudXBound,paletteHouseXBound;
int paletteSingleBirdXBound,paletteBunchOfFlowersXBound,paletteAFlockOfBirdsXBound;
int paletteSunXBound,paletteBoatXBound,paletteWaterBrushXBound,paletteRubberXBound;

//Variable for shape selection
int drawMode = 0;
/*
Variable declaration ends here
*/




//Helper function for inverting Y coordinate
int convertToYCoordinate(int i){return Y-i;}




/*
Function for taking ScreenShot starts here
*/
//void takeScreenShot()
//{
//    // Make the BYTE array, factor of 3 because it's RBG.
//BYTE* pixels = new BYTE[ 3 * X * Y];
//
//glReadPixels(0, 0, X, Y, GL_RGB, GL_UNSIGNED_BYTE, pixels);
//
//// Convert to FreeImage format & save to file
//FIBITMAP* image = FreeImage_ConvertFromRawBits(pixels, X, Y, 3 * X, 24, 0x0000FF, 0xFF0000, 0x00FF00, false);
//FreeImage_Save(FIF_BMP, image, "B:\\Projects\\OpenGL projects\\Temporary\\temporarySceneryMaker\\test.bmp", 0);
//
//// Free resources
//FreeImage_Unload(image);
//delete [] pixels;
//}
//bool save_screenshot(char* filename, int w, int h)
//{
//  //This prevents the images getting padded
// // when the width multiplied by 3 is not a multiple of 4
//  glPixelStorei(GL_PACK_ALIGNMENT, 1);
//
//  int nSize = w*h*3;
//  // First let's create our buffer, 3 channels per Pixel
//  char* dataBuffer = (char*)malloc(nSize*sizeof(char));
//
//  if (!dataBuffer) return false;
//
//   // Let's fetch them from the backbuffer
//   // We request the pixels in GL_BGR format, thanks to Berzeger for the tip
//   glReadPixels((GLint)0, (GLint)0,
//		(GLint)w, (GLint)h,
//		 GL_BGR, GL_UNSIGNED_BYTE, dataBuffer);
//
//   //Now the file creation
//   FILE *filePtr = fopen(filename.c_str(), "wb");
//   if (!filePtr) return false;
//
//
//   unsigned char TGAheader[12]={0,0,2,0,0,0,0,0,0,0,0,0};
//   unsigned char header[6] = { w%256,w/256,
//			       h%256,h/256,
//			       24,0};
//   // We write the headers
//   fwrite(TGAheader,	sizeof(unsigned char),	12,	filePtr);
//   fwrite(header,	sizeof(unsigned char),	6,	filePtr);
//   // And finally our image data
//   fwrite(dataBuffer,	sizeof(GLubyte),	nSize,	filePtr);
//   fclose(filePtr);
//
//   free(dataBuffer);
//
//  return true;
//}
/*
Function for taking ScreenShot ends here
*/




/*
Generic drawing functions start here
*/

/*
Generic Line drawing function starts here
*/
void drawLine(float r,float g, float b ,int x1,int y1, int x2, int y2){
    glPushMatrix();
    glBegin(GL_LINES);
    glColor3f(r,g,b);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();
    glFlush();
    glPopMatrix();
}
/*
Generic Line drawing function ends here
*/



/*
Generic Polygon drawing function starts here
*/
void drawPolygon(float r,float g, float b ,int cx,int cy, int numArgs ,...){
    glPushMatrix();

    va_list points;
    va_start(points,numArgs);
    int i;


    glBegin(GL_POLYGON);
    glColor3f (r,g,b);
    for(i=1;i<numArgs;i+=2){
        int px,py;

        px=va_arg(points,int);
        py=va_arg(points,int);

        glVertex2i(cx+px,convertToYCoordinate(cy+py));
    }
    glEnd();

    va_end(points);
    glFlush();

    glPopMatrix();
}
void drawScaledPolygon(float scaleX,float scaleY,float r,float g, float b ,int cx,int cy, int numArgs ,...){
    glPushMatrix();

    glTranslatef(cx,cy,1);
    glScalef(scaleX,scaleY,0);


    glRotatef(180,0.0,1.0,0.0);
    glRotatef(180,1.0,0.0,0.0);


    va_list points;
    va_start(points,numArgs);
    int i;



    glBegin(GL_POLYGON);
    glColor3f (r,g,b);
    for(i=1;i<numArgs;i+=2){
        int px,py;

        px=va_arg(points,int);
        py=va_arg(points,int);

        glVertex2i(px,py);
    }
    glEnd();

    va_end(points);
    glFlush();

    glPopMatrix();
}
/*
Generic Polygon drawing function ends here
*/

/*
Generic drawing functions end here
*/






/*
Asha Mony coding starts here
*/
/*
Cloud drawing function starts here
*/
void drawAcloud(int cx,int cy){

      drawPolygon(blue,cx,cy,52,-60,45,-41,42,-16,20,-5,45,7,48,10,48,26,25,34,39,47,40,58,16,71,32,92,21,94,8,85,
                  -1,72,-1,67,-16,57,-21,42,-15,34,-39,21,-43,3,-36,-20,-29,-28,-15,-35,-21,-53,-13,-74,0,-84,8,-84,18);

}
void drawAScaledCloud(float scaleX, float scaleY ,int cx,int cy){
    if(scaleX == 0.5){cx+=20;}
    drawScaledPolygon(scaleX,scaleY,blue,cx,cy,52,-60,45,-41,42,-16,20,-5,45,7,48,10,48,26,25,34,39,47,40,58,16,71,32,92,21,94,8,85,
                  -1,72,-1,67,-16,57,-21,42,-15,34,-39,21,-43,3,-36,-20,-29,-28,-15,-35,-21,-53,-13,-74,0,-84,8,-84,18);

}
/*
Cloud drawing function ends here
*/


/*
House drawing function starts here
*/
void drawAHouse(int cx,int cy){
    drawPolygon(brown,cx,cy,8,180,30,442,30,442,18,180,18);

    drawPolygon(green,cx,cy,8,200,18,422,18,422,-84,200,-84);
    //roof
    drawPolygon(brown,cx,cy,6,160,-84,304,-180,462,-84);
    //door
    drawPolygon(black,cx,cy,8,290,18,330,18,330,-60,290,-60);
    //right window
    drawPolygon(black,cx,cy,8,355,-18,390,-18,390,-40,355,-40);
    //left window
    drawPolygon(black,cx,cy,8,232,-18,265,-18,265,-40,232,-40);
}
void drawAScaledHouse(float scaleX, float scaleY ,int cx,int cy){
    if(scaleX == 0.5){cx+=150;cy-=30;}
    drawScaledPolygon(scaleX,scaleY,brown,cx,cy,8,180,30,442,30,442,18,180,18);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,8,200,18,422,18,422,-84,200,-84);
    //roof
    drawScaledPolygon(scaleX,scaleY,brown,cx,cy,6,160,-84,304,-180,462,-84);
    //door
    drawScaledPolygon(scaleX,scaleY,black,cx,cy,8,290,18,330,18,330,-60,290,-60);
    //right window
    drawScaledPolygon(scaleX,scaleY,black,cx,cy,8,355,-18,390,-18,390,-40,355,-40);
    //left window
    drawScaledPolygon(scaleX,scaleY,black,cx,cy,8,232,-18,265,-18,265,-40,232,-40);
}
/*
House drawing function ends here
*/



/*
Tree drawing function starts here
*/
void drawASimpleTree(int cx,int cy){

    drawPolygon(green,cx,cy,56,120,-118,130,-102,140,-92,160,-98,170,-112,180,-112,190,-98,215,-92,
                230,-102,242,-120,232,-130,228,-140,238,-150,242,-160,238,-170,208,-180,202,-192,
                192,-198,182,-180,150,-191,140,-181,130,-161,98,-141,100,-131,150,-92,140,-98,130,-92,
                120, -102);

    drawPolygon(brown_tree,cx,cy,34,160,10,210,10,195,-3,193,-22,190,-38,192,-50,200,-90,188,-100,212,-112,
                204,-122,189,-98,178,-122,165,-112,160,-100,165,-90,155,-60,160,-40);

}
void drawAScaledSimpleTree(float scaleX, float scaleY ,float scaleZ ,int cx,int cy){
    if(scaleX == 0.5){cx+=90;cy-=30;}
    drawScaledPolygon(scaleX,scaleY,green,cx,cy,56,120,-118,130,-102,140,-92,160,-98,170,-112,180,-112,190,-98,215,-92,
                230,-102,242,-120,232,-130,228,-140,238,-150,242,-160,238,-170,208,-180,202,-192,
                192,-198,182,-180,150,-191,140,-181,130,-161,98,-141,100,-131,150,-92,140,-98,130,-92,
                120, -102);

    drawScaledPolygon(scaleX,scaleY,brown_tree,cx,cy,34,160,10,210,10,195,-3,193,-22,190,-38,192,-50,200,-90,188,-100,212,-112,
                204,-122,189,-98,178,-122,165,-112,160,-100,165,-90,155,-60,160,-40);

}
/*
Tree drawing function ends here
*/



/*
Bird drawing function starts here
*/
void drawAScaledBird(float scaleX, float scaleY ,int cx,int cy){


        //leg
    drawScaledPolygon(scaleX,scaleY,black,cx,cy,22,-32,31,-68,69,-34,54,-25,56,-57,90,-34,76,-41,107,-24,82,-19,103,-14,79,-19,40);

        //body
    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,20,-84,-32,-87,-7,-82,15,-68,39,-40,62,-12,67,16,60,39,42,55,23,64,-7);

        //tail
    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,26,64,-7, 86,-12,107,-19,117,-22,142,-37,170,-66,138,-57,171,-100,134,-82,143,-111,106,-83,77,-47,55,-23);

        //head
    drawScaledPolygon(scaleX,scaleY,blue,cx,cy,42,-110,-91,-102,-118,-90,-129,-79,-133,-73,-150,-55,-161,-66,-140,-32,-153,-47,-141,-32,-138,
                -20,-127,-42,-127,-30,-118,-20,-95,-19,-70,-25,-52,-33,-37,-58,-23,-86,-26,-102,-38,-108,-55);

        //leap
    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,6,-140,-89,-110,-100,-100,-74);

        //leap
    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,-100,-74,-113,-78,-135,-55,-100,-62);

        //wings
    drawScaledPolygon(scaleX,scaleY,green,cx,cy,50,14,-53,-8,-59,-29,-53,-42,-35,-48,-22,-49,-9,-40,9,-25,24,-4,31,18,32,31,23,48,19,60,8,47,6,71,-3,
                84,-13,50,-6,76,-16,97,-30,72,-23,87,-38,100,-54,75,-41,57,-40,34,-41);

        //eye white
    drawScaledPolygon(scaleX,scaleY,white,cx,cy,24,-85,-74,-70,-68,-56,-73,-53,-85,-53,-99,-60,-109,-72,-116,-80,-113,-83,-107,-88,-98,-87,-87,-87,-78);

        //eye black
    drawScaledPolygon(scaleX,scaleY,black,cx,cy,18,-80,-80,-71,-82,-66,-88,-64,-96,-63,-107,-76,-109,-83,-105,-86,-97,-87,-87 );
}
/*
Bird drawing function ends here
*/



/*
Flower drawing function starts here
*/
void drawAScaledBunchOFlowers(float scaleX, float scaleY ,int cx,int cy){


    drawScaledPolygon(scaleX,scaleY,black,cx,cy,8,-22,-55,-22,125,-5,125,-11,-151);

    drawScaledPolygon(scaleX,scaleY,red,cx,cy,22,-30,-246,-41,-200,-30,-166,-15,-150,17,-160,35,-180,36,-212,27,-245,15,-210,-3,
                -250,-20,-210);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,6,60,-150,27,34,53,37);

    drawScaledPolygon(scaleX,scaleY,red,cx,cy,16,69,-216,48,-182,49,-150,64,-135,87,-140,109,-162,108,-210,74,-175);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,6,143,-132,75,100,100,100);

    drawScaledPolygon(scaleX,scaleY,red,cx,cy,14,120,-166,114,-130,134,-106,170,-110,184,-130);

    drawScaledPolygon(scaleX,scaleY,red,cx,cy,14,120,-166,138,-190,145,-150,171,-192,162,-135,197,-165,184,-130);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,6,-39,91,-39,155,72,111);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,36,-72,-89,-60,-53,-57,-24,-67,6,-58,29,-61,54,-45,77,-35,111,-8,138,7,154,
               18,154,-7,141,-14,90,-35,65,-35,33,-45,12,-46,-40,-60,-69 );

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,22,13,155,-1,121,-9,78,-4,43,13,9,11,-15,49,-63,29,7,17,71,26,128,39,153);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,24,-103,-8,-99,8,-92,36,-72,56,-52,75,-41,135,-50,150,-34,159,-20,157,-52,37,
                -74,21,-80,-2);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,36,-72,-89,-60,-53,-57,-24,-67,6,-58,29,-61,54,-45,77,-35,111,-8,138,7,154,18,154,
                -7,141,-14,90,-35,65,-35,33,-45,12,-46,-40,-60,-69);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,22,13,155,-1,121,-9,78,-4,43,13,9,11,-15,49,-63,29,7,17,71,26,128,39,153);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,20,29,-88,9,-29,19,30,31,69,12,54,32,154,47,78,44,30,27,-35,25,-64);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,36,-72,-89,-60,-53,-57,-24,-67,6,-58,29,-61,54,-45,77,-35,111,-8,138,7,154,
               18,154,-7,141,-14,90,-35,65,-35,33,-45,12,-46,-40,-60,-69);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,22,13,155,-1,121,-9,78,-4,43,13,9,11,-15,49,-63,29,7,17,71,26,128,39,153);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,16,-14,-59,-22,-25,-8,-3,-14,28,-8,54,8,37,4,3,-9,-25);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,36,-72,-89,-60,-53,-57,-24,-67,6,-58,29,-61,54,-45,77,-35,111,-8,138,7,154,
               18,154,-7,141,-14,90,-35,65,-35,33,-45,12,-46,-40,-60,-69 );

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,22, 13,155,-1,121,-9,78,-4,43,13,9,11,-15,49,-63,29,7,17,71,26,128,39,153);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,16,60,-57,49,-2,61,66,47,150,71,150,79,102,68,26,71,-22);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,36,-72,-89,-60,-53,-57,-24,-67,6,-58,29,-61,54,-45,77,-35,111,-8,138,7,154,
               18,154,-7,141,-14,90,-35,65,-35,33,-45,12,-46,-40,-60,-69);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,22,13,155,-1,121,-9,78,-4,43,13,9,11,-15,49,-63,29,7,17,71,26,128,39,153);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,14,169,-64,137,-17,121,60,78,147,110,152,143,72,154,-8);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,16,106,-46,82,-16,83,30,61,148,83,149,95,74,101,17,95,-12);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,22,178,-16,173,11,164,25,161,52,150,111,123,149,154,149,167,129,177,88,179,40,192,17);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,6,127,-47,69,150,90,150);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,6,-10,-27,-12,152,17,155);

    drawScaledPolygon(scaleX,scaleY,green,cx,cy,6,58,-95,18,155,54,155);
}
/*
Flower drawing function ends here
*/



/*
Flock of birds drawing function starts here
*/
void drawAFlockOfBirds(float scaleX, float scaleY ,int cx,int cy){

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,10,-5,-118,21,-112,21,-121,11,-125,-2,-126);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,16,13,-119,24,-118,40,-138,34,-143,21,-126,19,-133,13,-131,13,-122);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,24,53,-129,67,-122,74,-119,81,-120,85,-132,96,-138,107,-140,105,-145,91,-144,82,-133,72,-131,61,-136);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,24,112,-159,134,-160,145,-152,152,-170,158,-182,173,-183,173,-189,155,-189,146,-173,134,-175,
               133,-166,112,-166);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,12,44,-176,61,-175,81,-169,74,-178,70,-180,49,-183);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,8,80,-170,104,-206,97,-210,74,-178);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,8,-8,-164,17,-145,9,-157,-15,-162);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,8,8,-155,15,-147,26,-184,16,-186);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,12,111,-201,127,-201,142,-196,141,-202,129,-208,112,-208);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,12,141,-192,152,-234,153,-237,138,-209,132,-212,132,-203);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,12,20,-195,29,-196,41,-192,39,-198,31,-201,10,-205);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,16,39,-193,43,-201,58,-211,52,-223,39,-210,37,-203,32,-205,32,-200);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,18,72,-226,80,-216,90,-226,96,-225,104,-219,102,-225,95,-232,82,-232,74,-230);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,14,100,-226,105,-219,109,-230,121,-239,112,-248,102,-238,101,-225);

}
/*
Flock of birds drawing function ends here
*/



/*
Sun drawing function starts here
*/
void drawAScaledSun(float scaleX, float scaleY ,int cx,int cy){
    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,50,0,38,7,37,14,35,23,30,30,25,33,20,35,15,36,7,35,0,33,-5,32,-10,27,-15,20,-20,0,-26,
                -19,-20,-22,-15,-31,-10,-34,-5,-35,0,-37,7,-35,15,-31,20,-29,25,-22,30,-15,34);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,-5,-34,1,-34,1,-110,-5,-110);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,-5,123,1,123,1,48,-5,48);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,-130,9,-42,9,-42,2,-130,2);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,44,9,134,9,134,2,44,2);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,44,-6,91,-31,86,-36,42,-13);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,37,-20,88,-84,83,-87,31,-26);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,19,-35,36,-75,30,-77,13,-38);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,-25,-35,-20,-38,-33,-77,-40,-75);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,-36,-18,-31,-27,-98,-75,-103,-72);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,-52,-6,-49,-11,-83,-29,-87,-23);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,-41,27,-44,23,-79,35,-77,40);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,-24,41,-29,37,-92,81,-87,87);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,-15,58,-20,54,-37,84,-32,87);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,18,53,23,50,40,87,35,90);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,30,43,35,40,94,98,90,103);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,8,45,29,49,25,89,51,84,54);
}
/*
Sun drawing function ends here
*/



/*
Bush drawing function starts here
*/
void drawbush(int cx,int cy){
    drawPolygon(green,cx,cy,28,-1,-211,-18,-196,-67,-164,-113,-75,-143,50,-95,119,-20,128,138,122,190,69,198,8,
                197,-53,143,-129,72,-170,21,-210);
}
/*
Bush drawing function ends here
*/



/*
Boat drawing function starts here
*/
void drawAScaledBoat(float scaleX, float scaleY ,int cx,int cy){
    drawScaledPolygon(scaleX,scaleY,black,cx,cy,8,-94,-71,-28,-15,26,12,26,-42);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,8,140,-42,140,12,188,-12,255,-85);

    drawScaledPolygon(scaleX,scaleY,black,cx,cy,20,26,-42,26,12,49,24,82,28,119,22,140,12,140,-42,111,-28,72,-26,43,-30);

    drawScaledPolygon(scaleX,scaleY,red,cx,cy,18,6,-45,23,-28,169,-37,169,-58,162,-83,147,-103,22,-103,8,-82,4,-61);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,6,-94,-71,6,-45,23,-28);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,6,255,-85,169,-58,169,-37);

    drawScaledPolygon(scaleX,scaleY,yellow,cx,cy,6,6,-45,23,-28,25,-45);

    drawScaledPolygon(scaleX,scaleY,blue,cx,cy,12,6,-45,25,-45,29,-78,22,-103,8,-82,4,-61);
}
/*
Boat drawing function ends here
*/



/*
Asha Mony coding ends here
*/





/*
Ahmed Muhammad Shafique -- Brush functions start here
*/

/*
Grass brush starts here
*/
void drawATuftOfGrass(int cx,int cy){
    drawPolygon(green,cx,cy,18,-2,13,2,13,7,-3,7,-17,2,6,0,-16,-3,2,-6,-18,-10,-9);
}
void drawAScaledTuftOfGrass(float scaleX,float scaleY,float scaleZ , int cx,int cy){
    drawScaledPolygon(scaleX,scaleY,green,cx,cy,18,-2,13,2,13,7,-3,7,-17,2,6,0,-16,-3,2,-6,-18,-10,-9);
}
/*
Grass Brush ends here
*/




/*
Water Brush starts here
*/
void drawWater(float scaleX,float scaleY , int cx,int cy){
    drawScaledPolygon(scaleX,scaleY,clearWater,cx,cy,14,-1,11,2,11,10,5,10,-5,1,-10,-10,-5,-9,5);
}
/*
Water Brush starts here
*/



/*
Rubber Starts here
*/
void drawRubberOutline(int cx,int cy){

    glPushMatrix();
    glTranslatef(cx,cy,1);
    glColor3f (black);
    glBegin(GL_LINE_LOOP);
    glVertex2i(-10,10);
    glVertex2i(7,10);
    glVertex2i(7,-12);
    glVertex2i(-10,-12);
    glEnd();
    glFlush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cx,cy,1);
    glColor3f (black);
    glBegin(GL_LINE_LOOP);
    glVertex2i(-7,13);
    glVertex2i(10,13);
    glVertex2i(10,-9);
    glVertex2i(7,-12);
    glVertex2i(7,10);
    glVertex2i(-10,10);
    glEnd();
    glFlush();
    glPopMatrix();
}
void rubUsingRubber(int cx,int cy){

    glPushMatrix();
    glTranslatef(cx,cy,1);
    glColor3f (white);
    glBegin(GL_POLYGON);
    glVertex2i(-10,10);
    glVertex2i(7,10);
    glVertex2i(7,-12);
    glVertex2i(-10,-12);
    glEnd();
    glFlush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cx,cy,1);
    glColor3f (white);
    glBegin(GL_POLYGON);
    glVertex2i(-7,13);
    glVertex2i(10,13);
    glVertex2i(10,-9);
    glVertex2i(7,-12);
    glVertex2i(7,10);
    glVertex2i(-10,10);
    glEnd();
    glFlush();
    glPopMatrix();
}
/*
Rubber Ends here
*/

/*
Ahmed Muhammad Shafique -- Brush functions end here
*/





/*
Mouse Draw helper functions start here
*/

/*
Draw Mode Selector starts here
*/
void drawModeSelector(int x, int y){
    if(x<=paletteGrassXBound) drawMode = 1;
    else if(x<=paletteTreeXBound) drawMode = 2;
    else if(x<=paletteCloudXBound) drawMode = 3;
    else if(x<=paletteHouseXBound) drawMode = 4;
    else if(x<=paletteSingleBirdXBound) drawMode = 5;
    else if(x<=paletteBunchOfFlowersXBound) drawMode = 6;
    else if(x<=paletteAFlockOfBirdsXBound) drawMode = 7;
    else if(x<=paletteSunXBound) drawMode = 8;
    else if(x<=paletteBoatXBound) drawMode = 9;
    else if(x<=paletteWaterBrushXBound) drawMode = 10;
    else if(x<=paletteRubberXBound) drawMode = 11;
}
/*
Draw Mode Selector ends here
*/



/*
Mouse Left click checker function starts here
*/
void onMouseLeftClick(int mx,int my){
    //If above lower bound of drawing palette , select the shape inside
    if(my >= paletteYBound){
       printf("Selecting draw mode\n");

        drawModeSelector(mx,my);
        printf("draw mode is %d\n",drawMode);
    }
    //Else draw selected/default function
    else{
        ///Call draw selected function here
        printf("draw mode is %d  ;;;  drawing now...\n",drawMode);
        //if(drawMode==1) drawATuftOfGrass(mx,convertToYCoordinate(my));
        if(drawMode==1) drawAScaledTuftOfGrass(0.7,0.7,1,mx,my-15);
        else if(drawMode==2) drawAScaledSimpleTree(0.5,0.5,1,mx,my);
        else if(drawMode==3) drawAScaledCloud(0.5,0.5,mx,my);
        else if(drawMode==4) drawAScaledHouse(0.5,0.5,mx,my);
        else if(drawMode==5) drawAScaledBird(0.03,0.03,mx,my-15);
        else if(drawMode==6) drawAScaledBunchOFlowers(0.08,0.08,mx+10,my-15);
        else if(drawMode==7) drawAFlockOfBirds(0.2,0.2,mx+10,my-40);
        else if(drawMode==8) drawAScaledSun(1.0,0.8,mx,my);
        else if(drawMode==9) drawAScaledBoat(0.2,0.2,mx+20,my-30);
        else if(drawMode==10) drawWater(1,1,mx,my);
        else if(drawMode==11) rubUsingRubber(mx,my-20);
    }
}
/*
Mouse Left click checker function ends here
*/

/*
Mouse Draw helper functions ends here
*/



/*
Functions collected from Internet starts here
The mouse functions made by Rob Bateman have been modified and used here
We are very grateful for this and other resources he provided
*/

/*
Static Mouse functionality starts here
*/
void MouseButton(int button,int state,int x, int y)
{
	if (state == GLUT_DOWN)
	{
		/*
		 *	Which button was pressed?
		 */
		switch(button)
		{
		case GLUT_LEFT_BUTTON:
			onMouseLeftClick(x,convertToYCoordinate(y));
			break;
		case GLUT_MIDDLE_BUTTON:
			break;
		case GLUT_RIGHT_BUTTON:
			break;
		}
	}
}
/*
Static Mouse functionality Ends here
*/

/*
Mouse motion while button pressed down starts here
*/
/*----------------------------------------------------------------------------------------
 *	\brief	This function is called whenever the mouse cursor is moved AND A BUTTON IS HELD.
 *	\param	x	-	the new x-coord of the mouse cursor.
 *	\param	y	-	the new y-coord of the mouse cursor.
 */
void MouseMotion(int mx, int my)
{
	if(my < paletteYBound){
        if(drawMode==1) drawAScaledTuftOfGrass(0.7,0.7,1,mx,Y-my-15);
        //else if(drawMode==2) drawAScaledSimpleTree(0.5,0.5,1,mx,Y-my);
        //else if(drawMode==3) drawAScaledCloud(0.5,0.5,mx,Y-my);
        //else if(drawMode==4) drawAScaledHouse(0.5,0.5,mx,Y-my);
        //else if(drawMode==5) drawAScaledBird(0.03,0.03,mx,Y-my-15);
        //else if(drawMode==6) drawAScaledBunchOFlowers(0.08,0.08,mx+10,Y-my-15);
        //else if(drawMode==7) drawAFlockOfBirds(0.2,0.2,mx+10,Y-my-40);
        //else if(drawMode==8) drawAScaledSun(1.0,0.8,mx,Y-my);
        //else if(drawMode==9) drawAScaledBoat(0.2,0.2,mx+20,Y-my-30);
        else if(drawMode==10) drawWater(1,1,mx,Y-my);
        else if(drawMode==11) rubUsingRubber(mx,Y-my-20);
    }

}
/*
Mouse motion while button pressed down ends here
*/

/*
Functions collected from Internet ends here
*/




/*
Drawing palette making starts here
*/
void drawingPaletteCreation(){

    //Create palette lower bound
    int reqy = (Y/10)*9;
    drawLine(black,0,reqy,X,reqy);
    paletteYBound=reqy;
    //Lower bound creation ends here


    /*
    Item 1 : Grass
    */
    int reqX =X/20;
    paletteGrassXBound=reqX;
    //creating vertical end boundary for grass
    drawLine(black,reqX,reqy,reqX,Y);
    drawATuftOfGrass(30,30);
    /*
    Grass ready
    */


    /*
    Item 2 : Tree
    */
    reqX =(X/20)*2;
    paletteTreeXBound=reqX;
    //creating vertical end boundary for Tree
    drawLine(black,reqX,reqy,reqX,Y);
    //Drawing Tree to palette
    glPushMatrix();
    glTranslatef(20,480,0);
    glScaled(0.3,0.3,0);
    drawASimpleTree(105,42);
    glPopMatrix();
    /*
    Tree ready
    */

    /*
    Item 3 : Cloud
    */
    reqX =(X/20)*3;
    paletteCloudXBound=reqX;
    //creating vertical end boundary for Cloud
    drawLine(black,reqX,reqy,reqX,Y);
    //Drawing Cloud to palette
    glPushMatrix();
    glTranslatef(140,520,0);
    glScaled(0.3,0.3,0);
    drawAcloud(100,50);
    glPopMatrix();
    /*
    Cloud ready
    */

    /*
    Item 4 : House
    */
    reqX =(X/20)*4;
    paletteHouseXBound=reqX;
    //creating vertical end boundary for House
    drawLine(black,reqX,reqy,reqX,Y);
    //Drawing House to palette
    glPushMatrix();
    glTranslatef(155,560,0);
    glScaled(0.2,0.2,0);
    drawAHouse(100,50);
    glPopMatrix();
    /*
    House ready
    */

    /*
    Item 5 : Single Bird
    */
    reqX =(X/20)*5;
    paletteSingleBirdXBound=reqX;
    //creating vertical end boundary for Single Bird
    drawLine(black,reqX,reqy,reqX,Y);
    //Drawing Single Bird to palette
    drawAScaledBird(0.03,0.03,300,Y-50);
    /*
    Single Bird ready
    */

    /*
    Item 6 : Bunch Of Flowers
    */
    reqX =(X/20)*6;
    paletteBunchOfFlowersXBound=reqX;
    //creating vertical end boundary for Bunch Of Flowers
    drawLine(black,reqX,reqy,reqX,Y);
    //Drawing Bunch Of Flowers to palette
    drawAScaledBunchOFlowers(0.08,0.08,380,Y-50);
    /*
    Bunch Of Flowers
    */

    /*
    Item 7 : A Flock Of Birds
    */
    reqX =(X/20)*7;
    paletteAFlockOfBirdsXBound=reqX;
    //creating vertical end boundary for A Flock Of Birds
    drawLine(black,reqX,reqy,reqX,Y);
    //Drawing A Flock Of Birds to palette
    drawAFlockOfBirds(0.2,0.2,460,Y-80);
    /*
    A Flock Of Birds ready
    */

    /*
    Item 8 : Sun
    */
    reqX =(X/20)*8;
    paletteSunXBound=reqX;
    //creating vertical end boundary for Sun
    drawLine(black,reqX,reqy,reqX,Y);
    //Drawing Sun to palette
    drawAScaledSun(0.2,0.2,510,Y-40);
    /*
    Sun ready
    */

    /*
    Item 9 : Boat
    */
    reqX =(X/20)*9;
    paletteBoatXBound=reqX;
    //creating vertical end boundary for Boat
    drawLine(black,reqX,reqy,reqX,Y);
    //Drawing Boat to palette
    drawAScaledBoat(0.15,0.15,590,Y-40);
    /*
    Boat ready
    */

    /*
    Item 10 : Water Brush
    */
    reqX =(X/20)*10;
    paletteWaterBrushXBound=reqX;
    //creating vertical end boundary for Water Brush
    drawLine(black,reqX,reqy,reqX,Y);
    //Drawing Water Brush to palette
    drawWater(1.5,1.5,650,Y-40);
    /*
    Water Brush ready
    */

    /*
    Item 11 : Rubber
    */
    reqX =(X/20)*11;
    paletteRubberXBound=reqX;
    //creating vertical end boundary for Rubber
    drawLine(black,reqX,reqy,reqX,Y);
    //Drawing Rubber to palette
    drawRubberOutline(710,Y-40);
    /*
    Rubber ready
    */

}
/*
Drawing Palette making ends here
*/



//Custom display function
void myDisplay(void){
drawingPaletteCreation();
}

//Custom initialization function
void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(15.0);
glLineWidth(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, X, 0.0, Y);

}

//Function for setting screen size
void setFullScreen(){
    /*
    X = GetSystemMetrics(SM_CXSCREEN);
    Y = GetSystemMetrics(SM_CYSCREEN);
    */
    X=1366;
    Y=768;
}


int main(int argc, char** argv)
{
setFullScreen();
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (X, Y);
glutInitWindowPosition (-1, -1);
glutCreateWindow ("Hello OpenGL");
glutDisplayFunc(myDisplay);
glutMouseFunc(MouseButton);
glutMotionFunc(MouseMotion);
myInit ();

glClear (GL_COLOR_BUFFER_BIT);

glutMainLoop();
}




