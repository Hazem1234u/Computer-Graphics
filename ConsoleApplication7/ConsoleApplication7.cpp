#include<stdio.h>
#include<stdlib.h>
#include <GL/glut.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#define PI 3.14

void Keys();
double zoom = 0.5;
int rotate_x = 0;
int rotate_y = 0;

float angleMoon = 0.0, angleEarth = 0.0, angleAstroid = 0.0, 
//planets in picture
angleMars = 0.0, 
angleMercury = 0.0,
angleVenus = 0.0,
angleJupiter = 0.0,
angleSaturn = 0.0,
angleUranus = 30.0,
angleNeptune = 60.0;
GLfloat sx = 0.2, sy = 0.2, sz = 0.2;

int planet1;
/*******COLOURS***********/
GLfloat black[] = { 0.0f,0.0f,0.0f,1.0f };
GLfloat white[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat blue[] = { 0.0f,0.0f,0.9f,1.0f };
GLfloat er[] = { 0.0f,5.0f,0.9f,1.0f };
GLfloat yellow[] = { 0.7f,0.2f,0.0f,1.0f };
GLfloat qAmb[] = { 0.1,0.1,0.1,1.0 }; //ambient light
GLfloat qDif[] = { 1.0,1.0,1.0,1.0 }; // light diffuse
GLfloat qSpec[] = { .50,.50,.50,.10 };//specular light
GLfloat qPos[] = { 0,0,0,0.1 }; //visbilty and dimming
GLfloat sc[8] = { 0.295 , 0.40,0.50, 0.60,0.80,1.0,1.05,1.13 }; //scaling
double ang = 2 * PI / 300;
double angular = 2 * PI / 50;

int maxr = 20;
int minR = 10;
int R = 5;
int MinR = 10;
int r = 7;

void initLighting()
{
   glMaterialfv(GL_FRONT,GL_AMBIENT,white);
    glMaterialfv(GL_FRONT,GL_SPECULAR,yellow);   //lighting for bottom rings
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT7);

    glLightfv(GL_LIGHT7, GL_AMBIENT, qAmb);
    glLightfv(GL_LIGHT7, GL_DIFFUSE, qDif);
    glLightfv(GL_LIGHT7, GL_SPECULAR, qSpec);
  // glMaterialfv(GL_FRONT,GL_DIFFUSE,yellow);
}
//LIGHTING-----------
/*
void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0); //backgroundcolor is black
    gluOrtho2D(0,699,0,699);
    glPointSize(1.0);
    glLineWidth(2.0);

}
*/
//background colour
/*
void background()
{
    glBegin(GL_QUADS);
    glColor3f(8.0, 9.00, 0.00);
    glVertex3f(-01.00, 01.00, 1);
    glColor3f(.20, 10.0, 0.70);
    glVertex3f(01.00, 1.00, 1);
    glColor3f(0, 0.0, 0.0);
    glVertex3f(1.00, -1.00, 1);
    glColor3f(.70, .10, .20);
    glVertex3f(-1.00, -1.00, 1);
    glEnd();
}
*/

void orbit()
{
    glColor3f(0.5, 0.5, 0.5);// rings colour


    int i = 0;
    for (i = 0; i < 8; i++) {     //rings drawing
        glPushMatrix(); //for drawing to be visible
        if (i == 5)
        {
            glRotatef(45, 1.0, 0.0, 0.0);  //rings are in circular form
        }
        else
        {
            glRotatef(60, 1.0, 0.0, 0.0); //rings are in circular form
        }
        glScalef(sc[i], sc[i], sc[i]);
        glBegin(GL_POINTS);
        double ang1 = 0.0;
        int i = 0;
        for (i = 0; i < 300; i++) //rings visiblity
        {
            glVertex2d(cos(ang1), sin(ang1));
            ang1 += ang;
        }
        glEnd();
       glPopMatrix(); //visiblity of all planets and rings 
     }
}

void draw(void)
{

    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // background();
    orbit();
    glLoadIdentity(); //identiy matrix matrix returns to its original state 
    glPushMatrix();
    glEnable(GL_DEPTH_TEST); //darkens the screen it has depth buffer
    glEnable(GL_COLOR_MATERIAL); //function that tracks current colour it has front and back method 
    glPushMatrix();
    glColor3f(0.7, 0.5, 0.0);
    glScalef(sx, sy, sz);
   glLightfv(GL_LIGHT7, GL_POSITION, qPos); //planet's visibilty
   glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, yellow); //changes the sun's colour 
    glutSolidSphere(1, 50, 50);
   glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, black); //changes orbits colours
    glPopMatrix();

    
    glScalef(0.2, 0.2, 0.2);
    glPushMatrix();
    glRotatef(angleMercury, 0.0, 1.0, -0.5);
    glTranslatef(1.5, 0.0, 0.0);
    glColor3f(1.0, 0.9, 0.0);
    glScalef(0.08, 0.08, 0.08);
    glutSolidSphere(1, 50, 50);
    glPopMatrix();


 //-----------------------
    glPushMatrix();
    glRotatef(angleVenus, 0.0, 1.0, -0.5);
    glTranslatef(2.0, 0.0, 0.0);
    glColor3f(0.9, 0.1, 0.0);
    glScalef(0.1, 0.1, 0.1);
    glutSolidSphere(1, 50, 50);
    glPopMatrix();
    //-----------
    
    glPushMatrix();
    glRotatef(angleEarth, 0.0, 1.0, -0.5);
    glTranslatef(2.5, 0.0, 0.0);
    glColor3f(0.0, 0.1, 0.7);
    glScalef(0.23, 0.23, 0.23);
    glutSolidSphere(1, 50, 50);
    glPushMatrix();
    glRotatef(angleMoon, 0.0, 0.1, 0.05);
    glTranslatef(1.3, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glScalef(0.5, 0.5, 0.5);
    glutSolidSphere(0.5, 50, 50);
    glPopMatrix();//moon made
    glPopMatrix();//earth made
    //---------------
    //mars planet 
    glPushMatrix();
    glRotatef(angleMars, 0.0, 1.0, -0.5);
    glTranslatef(-3.0, 0.0, 0.0);
    glColor3f(0.05, 0.05, 0.01);
    glScalef(0.17, 0.17, 0.17);
    glutSolidSphere(1, 50, 50);
    glPopMatrix();
    //------------------
    glPushMatrix();
    glColor3f(3.30, 3.30, 3.30);
    glRotatef(63, 1.0, 0.0, 0.0);
    int j = 0, i = 0, div = 90; float siz = 2;
    float scl[4] = { 3.3,3.4,3.35,3.2 };
    for (j = 0; j < 4; j++)
    {
        glPushMatrix(); siz -= 0.3;
        glPointSize(siz);
        glScalef(scl[j], scl[j], scl[j]);
        glBegin(GL_POINTS);
        double ang1 = 0.0 - angleAstroid, a = (2 * PI) / div;
        for (i = 0; i < div; i++)
        {
            glVertex2d(cos(ang1), sin(ang1));
            ang1 += a;
        }
        div += 10;
        glEnd();
        glPopMatrix();  //for asteriod belt
    }
     glPopMatrix();//astroid belt

     //jupiter planet
    glPushMatrix();
    glRotatef(angleJupiter, 0.0, 1.0, -0.5);
    glTranslatef(-4.0, 0.0, 0.0);
    glColor3f(0.4, 0.2, 0.0);
    glScalef(0.5, 0.5, 0.5);
    glutSolidSphere(1, 50, 50);
    glPushMatrix();

    //jupiter's moon
    glRotatef(angleMoon, 1.0, -0.5, 0.0);
    glTranslatef(0.0, 0, 1.1);
    glColor3f(1.0, 1.0, 1.0);
    glScalef(0.1, 0.1, 0.1);
    glutSolidSphere(0.5, 50, 50);
    glPopMatrix();//moon made
    glPopMatrix();


    //Saturn planet
    glPushMatrix();
    glRotatef(angleSaturn, 0.0, 1.0, -1.0);
    glTranslatef(-5.0, 0.0, 0.0);
    glColor3f(0.9, 0.0, 0.0);
    glScalef(0.4, 0.4, 0.4);
    glutSolidSphere(1, 50, 50);
    glPushMatrix();
    glRotatef(45, 1.0, 0.0, 0.0);
    glPointSize(3);
    glColor3f(5.0, 3.0, 1.0);
    glScalef(1.2, 1.2, 1.2);
    glBegin(GL_POINTS);
    double ang1 = 0.0;
    i = 0;
    for (i = 0; i < 50; i++)
    {
        glVertex2d(cos(ang1), sin(ang1));
        ang1 += angular;
    }
    glEnd();

    glPointSize(2);  //width of orbits
    glPopMatrix();//ring made         //Saturn's Rings and 
    glPopMatrix();


    glPushMatrix();
    glRotatef(angleUranus, 0.0, 1.0, -0.5);
    glTranslatef(5.2, 0.0, 0.0);
    glColor3f(0.0, 0.5, 0.9);
    glScalef(0.23, 0.23, 0.23);
    glutSolidSphere(1, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glRotatef(angleNeptune, 0.0, 1.0, -0.5);
    glTranslatef(-5.7, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.9);
    glScalef(0.2, 0.2, 0.2);
    glutSolidSphere(1, 50, 50);
    glPopMatrix();


    glPopMatrix();
    glFlush();
}

//movement of planets

void update(int value) {

    glRotatef(rotate_x, 0.5, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 0.2, 0.0);
    if ((angleMoon >= 0 && angleMoon < 180))   //Sun's zooming in and out
    {  
        sx -= 0.0003; sy -= 0.0003; sz -= 0.0003;
    }
    else { sx += 0.0003; sy += 0.0003; sz += 0.0003; }


    angleMoon += 2;  //earth's moon speed
    if (angleMoon > 360) {
        angleMoon -= 360;
    }

    angleEarth += 0.7;//earth's moon speed
    if (angleEarth > 360) {
        angleEarth -= 360;
    }
    angleMercury += 2; //Mercury speed
    if (angleMercury > 360) {
        angleMercury -= 360;
    }
    angleVenus += 0.9; //Venus speed
    if (angleVenus > 360) {
        angleVenus -= 360;
    }
    angleMars += 0.5; //Mars speed
    if (angleMars > 360) {
        angleMars -= 360;
    }
    angleJupiter += 0.2; //Jupiter's speed
    if (angleJupiter > 360) {
        angleJupiter -= 360;
    }
    angleSaturn += 0.1; //Saturn's speed
    if (angleSaturn > 360) {
        angleSaturn -= 360;
    }


    angleUranus += 0.05; //Uranus' speed
    if (angleUranus > 360) {
        angleUranus -= 360;
    }


    angleNeptune += 0.02; //Neptune's speed
    if (angleNeptune > 360) {
        angleNeptune -= 360;
    }


    angleAstroid += 0.002; //asteriod belt speed
    if (angleAstroid > 360) {
        angleAstroid -= 360;
    }


    glutPostRedisplay();
    glutTimerFunc(10, update, 0); //controls the speed of the update method the smaller the number the faster (was 25)
}
/*
void zoom(int key)
{

    if (key == '-')
    {
        if (r > maxr)
            R = maxr;
        else
            R += 0.2;
        printf("R: %f\n", R);
    }
    else if (key == '+')
    {
        if (R <= minR)
            R = MinR;
        else
            R -= 0.2;
        printf("R: %f\n", R);
    }

   // Calc();
   */
void Keys(int key, int x, int y)
{

    //  Right arrow - increase rotation by 2 degree
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 2;

    //  Left arrow - decrease rotation by 2 degree
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 2;

    else if (key == GLUT_KEY_UP)
        rotate_x += 2;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 2;

    //  Request display update
    glutPostRedisplay();

}
   int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Solar System");
    initLighting();
  //  myinit();
   // background();
    glutSpecialFunc(Keys);
    glutDisplayFunc(draw);
   
    glutTimerFunc(25, update, 0);
    glutMainLoop();
   
    return 0;
}

