#include<windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
#include <stdlib.h>
#define rad (3.1416/180)
#define EN_SIZE 30
#define PI 3.142
using namespace std;
int tola[5000][5000];
float zoom=2.5;
float tX=0,tY=0,tZ=-8,rX=0,rY=0,rZ=4,tX1=0;
float tZ1=-20,tZ2=-40,tZ3=-60,tZ4=-80,tZ5=-100,tZ6=-120;
float rotX=0,rotY=0,rotZ=0;
float speed = 0.6;
float angleBackFrac = 0.2;
int TIME=0;
float r[] = {0.1,0.4,0.3,0.9,0.2,0.8,0.0,0.7,0.5,0.0};
float g[] = {0.2,0.0,0.4,0.5,0.2,0.0,0.3,0.9,0.0,0.8};
float b[] = {0.4,0.5,0.3,0.7,0.9,0.0,0.1,0.2,0.5,0.3};
bool START = false;
bool rot = false;
bool START1=false;

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void fan(){
   glColor3d(0.7,0.7,0.7);
    glPushMatrix();
        glTranslated(0,0,0);
        glScaled(1,1,0.7);
        glutSolidSphere(0.8,30,30);
    glPopMatrix();

    glColor3d(0.7,0.7,0.7);
    glPushMatrix();
        glTranslated(0,0,0);
        glRotated(5,0,1,0);
        glScaled(0.5,3.5,0.05);
        glutSolidSphere(1,30,30);
    glPopMatrix();

    glColor3d(0.7,0.7,0.7);
    glPushMatrix();
        glTranslated(0,0,0);
        glRotated(-5,0,1,0);
        glRotated(90,0,0,1);
        glScaled(0.5,3.5,0.05);
        glutSolidSphere(1,30,30);
    glPopMatrix();

}
void windows(){

    glPushMatrix();
        glTranslated(0.5,0.2,-0.8);
        glScaled(0.05,0.8,0.2);
        glutSolidCube(1);
        glColor3d(0.5,0.9,1);
            glPushMatrix();
                glTranslated(0.55,0.15,-0.8);
                glScaled(1,0.5,0.7);
                glutSolidSphere(0.45,30,30);
            glPopMatrix();
    glPopMatrix();

    glColor3d(0,0,0);
     for(float i=0.1;i<1;i=i+0.1){
      glPushMatrix();
        glTranslated(0.5-i,0.2,-0.8);
        if(i<=0.7)
        glScaled(0.06,0.5,0.2+i/2.5);
        else if(i<=0.8)
        glScaled(0.06,0.5,0.2+i/4);
        else if(i<=0.9)
        glScaled(0.06,0.5,0.2+i/6);
        else
        glScaled(0.06,0.5,0.2);
        glutSolidSphere(0.55,30,30);
    glPopMatrix();
    }

     for(float i=0.1;i<1;i=i+0.1){
      glPushMatrix();
        glTranslated(0.5-i,0.2,0.8);
        if(i<=0.7)
        glScaled(0.06,0.5,0.2+i/2.5);
        else if(i<=0.8)
        glScaled(0.06,0.5,0.2+i/4);
        else if(i<=0.9)
        glScaled(0.06,0.5,0.2+i/6);
        else
        glScaled(0.06,0.5,0.2);
        glutSolidSphere(0.55,30,30);
    glPopMatrix();
    }
}
void plane(){
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    /// Main body
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(-0.2,0,0);
        glScaled(3,0.45,0.6);
        glutSolidSphere(1,30,30);
        windows();
    glPopMatrix();
//Mirror
    glColor3d(0.5,0.9,1);
    glPushMatrix();
        glTranslated(1.7,0.1,0);
        glScaled(2.3,0.3,0.8);
        glRotated(40,0,1,0);
        glutSolidSphere(0.45,30,30);
    glPopMatrix();

    // Right
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0,0,1.2);
        glRotated(-50,0,1,0);
        glScaled(0.3,0.1,3);
        glRotated(3,0,1,0);
        glutSolidCube(1);
    glPopMatrix();


    glColor3d(1,0,0);
    glPushMatrix();
        glTranslated(-1.2,0.16,2.27);
        glRotated(-50,-1.5,0.8,0);
        glScaled(0.5,0.8,0.1);
        glRotated(-20,0,1,0);
        glutSolidCube(0.5);
    glPopMatrix();

    glColor3d(1,0,0);
    glPushMatrix();
        glTranslated(-1.2,-0.1,2.23);
        glRotated(-50,1.2,0.8,0);
        glScaled(0.5,0.5,0.1);
        glRotated(-20,0,1,0);
        glutSolidCube(0.5);
    glPopMatrix();

//boosters
    glColor3d(0.7,0.7,0.7);
    glPushMatrix();
        glTranslated(-0.3,-0.15,1.5);
        glRotated(90,0,1,0);
          /// FAN
        glPushMatrix();
            glTranslated(0,0,0.5);
            glRotated(10*a,0,0,1);
            glScaled(0.1,0.1,0.1);
            fan();
        glPopMatrix();

        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();

    glColor3d(0.7,0.7,0.7);
    glPushMatrix();
        glTranslated(0.2,-0.15,0.9);
        glRotated(90,0,1,0);

        /// FAN
        glPushMatrix();
            glTranslated(0,0,0.5);
            glRotated(10*a,0,0,1);
            glScaled(0.1,0.1,0.1);
            fan();
        glPopMatrix();

        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();

    ///Left
        glColor3d(1,1,1);
        glPushMatrix();
        glTranslated(0,0,-1.2);
        glRotated(50,0,1,0);
        glScaled(0.3,0.1,3);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(1,0,0);
    glPushMatrix();
        glTranslated(-1.15,0.16,-2.23);
        glRotated(50,-3.5,6,0);
        glScaled(0.6,0.8,0.1);
        glRotated(3,-2.5,0,0);
        glutSolidCube(0.5);
    glPopMatrix();

    glColor3d(1,0,0);
    glPushMatrix();
        glTranslated(-1.22,-0.05,-2.25);
        glRotated(-80,3.2,1.3,0);
        glScaled(0.5,0.5,0.1);
        glRotated(-20,0,1,0);
        glutSolidCube(0.5);
    glPopMatrix();


    glColor3d(0.7,0.7,0.7);
    glPushMatrix();
        glTranslated(-0.3,-0.15,-1.5);
        glRotated(90,0,1,0);
               /// FAN
        glPushMatrix();
            glTranslated(0,0,0.5);
            glRotated(10*a,0,0,1);
            glScaled(0.1,0.1,0.1);
            fan();
        glPopMatrix();
        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
        glPopMatrix();

    glColor3d(0.7,0.7,0.7);
    glPushMatrix();
        glTranslated(0.2,-0.15,-0.9);
        glRotated(90,0,1,0);
           /// FAN
        glPushMatrix();
            glTranslated(0,0,0.5);
            glRotated(10*a,0,0,1);
            glScaled(0.1,0.1,0.1);
            fan();
         glPopMatrix();
        glScaled(0.1,0.1,0.9);

        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();


    //Back Wing
    glPushMatrix();
        glTranslated(-2.8,0,0);
        glScaled(0.8,0.5,0.3);

        //Right
        glColor3d(0.7,0.7,0.7);
        glPushMatrix();
            glTranslated(0.4,0,1.5);
            glRotated(-30,0,1,0);
            glScaled(0.7,0.1,3);
            glRotated(10,0,1,0);
            glutSolidCube(1);
        glPopMatrix();

        //left

        glColor3d(0.7,0.7,0.7);

        glPushMatrix();
            glTranslated(0.4,0,-1.5);
            glRotated(30,0,1,0);
            glScaled(0.7,0.1,3);
            glRotated(-10,0,1,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    // Up
    glColor3d(0.7,0.7,0.7);
    glPushMatrix();
        glTranslated(-3,0.4,0);
        glRotated(65,0,0,1);
        glScaled(0.5,2,0.1);
        glRotated(-20,0,0,1);
        glutSolidCube(0.6);
    glPopMatrix();

    glColor3d(1,0,0);
    glPushMatrix();
        glTranslated(-2.5,-0.2,0);
        glScaled(1.3,0.3,0.8);
        glutSolidSphere(0.3,10,10);
    glPopMatrix();

}

void singleTolaHouse(int R,int G,int B){
    glColor3d(r[R%11],g[G%11],b[B%11]);
    glPushMatrix();
        glTranslated(0,0,0);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(1,1,0);
    glPushMatrix();
        glTranslated(0.2,0,0);
        glScaled(0.3,0.3,1.001);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(1,1,0);
    glPushMatrix();
        glTranslated(-0.2,0,0);
        glScaled(0.3,0.3,1.001);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(1,1,0);
    glPushMatrix();
        glTranslated(0,0,0.2);
        glScaled(1.001,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(1,1,0);
    glPushMatrix();
        glTranslated(0,0,-0.2);
        glScaled(1.001,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

}
void house(int n,int R,int G){
    for(int i=0;i<n;i++){
        glPushMatrix();
            glTranslated(0,0.8+i,0);
            singleTolaHouse(G,R,i);
        glPopMatrix();
    }
}
void apart(float x,float y,float z)
{
	int i;
	int j;
    glColor3f(0,0.5,0.7);
	glBegin(GL_POLYGON);
	glVertex3f(x,y,z+0.5);
	glVertex3f(x+45,y,z+0.5);
	glVertex3f(x+45,y+100,z+0.5);
 	glVertex3f(x,y+100,z+0.5);
	glEnd();  glColor3f(0.8,0.8,0.8);
    for(j=0;j<8;j++)
    {

	glPushMatrix();
		glTranslatef(0,-12*j,0);
	for(i=0;i<4;i++)
	{
		glPushMatrix();
		glTranslatef(11*i,0,0);
	glBegin(GL_POLYGON);
	glVertex3f(x+2,y+98,z);
	glVertex3f(x+10,y+98,z);
	glVertex3f(x+10,y+88,z);
 	glVertex3f(x+2,y+88,z);
	glEnd();
	glPopMatrix();
	}glPopMatrix();
}glColor3f(0,0,0);
for(j=0;j<8;j++)
{

	glPushMatrix();
		glTranslatef(0,-12*j,0);
	for(i=0;i<4;i++)
	{
		glPushMatrix();
		glTranslatef(11*i,0,0);
		glBegin(GL_LINE_LOOP);
	glVertex3f(x+2,y+98,z);
	glVertex3f(x+10,y+98,z);
	glVertex3f(x+10,y+88,z);
 	glVertex3f(x+2,y+88,z);
	glEnd();
	glPopMatrix();
	}glPopMatrix();
}

glColor3f(0,0.5,0.7);
	glBegin(GL_POLYGON);
	glVertex3f(x,y,z+45-0.5);
	glVertex3f(x+45,y,z+45-0.5);
	glVertex3f(x+45,y+100,z+45-0.5);
 	glVertex3f(x,y+100,z+45-0.5);
	glEnd();  	glColor3f(0.8,0.8,0.8);

for(j=0;j<8;j++)
{

	glPushMatrix();
		glTranslatef(0,-12*j,0);
	for(i=0;i<4;i++)
	{
		glPushMatrix();
		glTranslatef(11*i,0,0);
	glBegin(GL_POLYGON);
	glVertex3f(x+2,y+98,z+45);
	glVertex3f(x+10,y+98,z+45);
	glVertex3f(x+10,y+88,z+45);
 	glVertex3f(x+2,y+88,z+45);
	glEnd();
	glPopMatrix();
	}glPopMatrix();
}glColor3f(0,0,0);

for(j=0;j<8;j++)
{

	glPushMatrix();
		glTranslatef(0,-12*j,0);
	for(i=0;i<4;i++)
	{
		glPushMatrix();
		glTranslatef(11*i,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(x+2,y+98,z+45);
	glVertex3f(x+10,y+98,z+45);
	glVertex3f(x+10,y+88,z+45);
 	glVertex3f(x+2,y+88,z+45);
	glEnd();
	glPopMatrix();
	}glPopMatrix();
}

glColor3f(0,0.5,0.7);
	glBegin(GL_POLYGON);
	glVertex3f(x+0.5,y,z);
	glVertex3f(x+0.5,y,z+45);
	glVertex3f(x+0.5,y+100,z+45);
 	glVertex3f(x+0.5,y+100,z);
	glEnd();
	glColor3f(0.8,0.8,0.8);
for(j=0;j<8;j++)
{

	glPushMatrix();
		glTranslatef(0,-12*j,0);
	for(i=0;i<4;i++)
	{
		glPushMatrix();
		glTranslatef(0,0,11*i);
	glBegin(GL_POLYGON);
	glVertex3f(x,y+98,z+2);
	glVertex3f(x,y+98,z+10);
	glVertex3f(x,y+88,z+10);
 	glVertex3f(x,y+88,z+2);
	glEnd();
	glPopMatrix();
	}glPopMatrix();
}glColor3f(0,0,0);
for(j=0;j<8;j++)
{

	glPushMatrix();
		glTranslatef(0,-12*j,0);
	for(i=0;i<4;i++)
	{
		glPushMatrix();
		glTranslatef(0,0,11*i);
		glBegin(GL_LINE_LOOP);
	glVertex3f(x,y+98,z+2);
	glVertex3f(x,y+98,z+10);
	glVertex3f(x,y+88,z+10);
 	glVertex3f(x,y+88,z+2);
	glEnd();
	glPopMatrix();
	}glPopMatrix();
}

glColor3f(0,0.5,0.7);

	glBegin(GL_POLYGON);
	glVertex3f(x+45-0.5,y,z-0.5);
	glVertex3f(x+45-0.5,y,z+45-0.5);
	glVertex3f(x+45-0.5,y+100,z+45-0.5);
 	glVertex3f(x+45-0.5,y+100,z-0.5);
	glEnd(); glColor3f(0.8,0.8,0.8);
for(j=0;j<8;j++)
{

	glPushMatrix();
		glTranslatef(0,-12*j,0);
	for(i=0;i<4;i++)
	{
		glPushMatrix();
		glTranslatef(0,0,11*i);
	glBegin(GL_POLYGON);
	glVertex3f(x+45,y+98,z+2);
	glVertex3f(x+45,y+98,z+10);
	glVertex3f(x+45,y+88,z+10);
 	glVertex3f(x+45,y+88,z+2);
	glEnd();
	glPopMatrix();
	}glPopMatrix();
}
glColor3f(0,0,0);
for(j=0;j<8;j++)
{

	glPushMatrix();
		glTranslatef(0,-12*j,0);
	for(i=0;i<4;i++)
	{
		glPushMatrix();
		glTranslatef(0,0,11*i);
		glBegin(GL_LINE_LOOP);
	glVertex3f(x+45,y+98,z+2);
	glVertex3f(x+45,y+98,z+10);
	glVertex3f(x+45,y+88,z+10);
 	glVertex3f(x+45,y+88,z+2);
	glEnd();
	glPopMatrix();
	}glPopMatrix();
}

glColor3f(0,0.5,0.7);
glBegin(GL_POLYGON);
	glVertex3f(x,y,z-0.5);
	glVertex3f(x+45,y,z-0.5);
	glVertex3f(x+45,y,z+45-0.5);
 	glVertex3f(x,y,z+45-0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(x,y+100,z);
	glVertex3f(x+45,y+100,z);
	glVertex3f(x+45,y+100,z+45);
 	glVertex3f(x,y+100,z+45);
	glEnd();
}

void sun()
{
    int i;

	GLfloat x=.0f; GLfloat y=.9f; GLfloat radius =.06f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * 3.142;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void cloud1()
{
    int i;

	GLfloat x=.5f; GLfloat y=.86f; GLfloat radius =.05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * 3.142;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=.55f; GLfloat b=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=.45f; GLfloat d=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=.52f; GLfloat f=.8f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=.6f; GLfloat h=.82f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


}

void cloud2()
{
   // glLoadIdentity();
    int i;

	GLfloat x=-.5f; GLfloat y=.86f; GLfloat radius =.05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=-.55f; GLfloat b=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-.45f; GLfloat d=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=-.52f; GLfloat f=.8f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=-.6f; GLfloat h=.82f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void cloud3()
{
    // glLoadIdentity();
    int i;

	GLfloat x=0.0f; GLfloat y=.86f; GLfloat radius =.05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=.05f; GLfloat b=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-0.05f; GLfloat d=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=.02f; GLfloat f=.8f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=.1f; GLfloat h=.82f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1,1,1);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


}
void sky(){
    for(int i=0;i<3;i++){
            glColor3d(1,1,1);
            glPushMatrix();
            glTranslated(12-i,5+i,10-i);
            glScaled(20+i*20,5+(i*10),5);
            cloud1();
            glPopMatrix();
        }

    for(int i=0;i<3;i++){
            glColor3d(1,1,1);
            glPushMatrix();
            glTranslated(-10+i,5+i,10);
            glScaled(20+i*20,5+(i*10),5);
            cloud2();
            glPopMatrix();
        }

        glColor3d(1,1,1);
            glPushMatrix();
                glTranslated(3.5,6,4);
                glScaled(20,20,10);
                cloud1();
            glPopMatrix();

        glColor3d(1,1,1);
            glPushMatrix();
                glTranslated(-1.5,3.7,1);
                glScaled(30,30,10);
                cloud2();
            glPopMatrix();

            glColor3d(1,1,1);
            glPushMatrix();
                glTranslated(2,6.7,1);
                glScaled(30,20,10);
                cloud3();
            glPopMatrix();

        glColor3d(1,1,1);
            glPushMatrix();
                glTranslated(2.5,5.7,1);
                glScaled(15,15,10);
                cloud2();
            glPopMatrix();

        glColor3d(1,1,1);
            glPushMatrix();
                glTranslated(-3.5,6,4);
                glScaled(25,30,10);
                cloud3();
            glPopMatrix();



}
void environment(){

    /// Ground
    glColor3d(0.2,0.2,0.2);
    glPushMatrix();
        glTranslated(0,0,0);
        glScaled(EN_SIZE*3,0.3,EN_SIZE*2);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0.1,0.2,1);
        glScaled(0.3,0.5,3);
        glutSolidCube(1);
    glPopMatrix();

            glColor3d(1,1,1);
            glPushMatrix();
            sky();
            glPopMatrix();



     for(int i=-(EN_SIZE/2)+1;i<(EN_SIZE/2);i+=2){
            for(int j=-(EN_SIZE/2)+1;j<(EN_SIZE/2);j+=2){
                if(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1]!=0){
                    glPushMatrix();
                        glTranslated(i,0,j);
                        house(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1],i+6,j);
                    glPopMatrix();
                }else if(i>=-5&&i<=5){}
                else{
                    tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1]=(rand()%5)+1;
                    glPushMatrix();
                        glTranslated(i,0,j);
                        house(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1],i,j);
                    glPopMatrix();
                }
            }
     }


}


void drawStrokeText1(char* str,int x,int y,int z)
{
	  char *c;
	  glPushMatrix();
	  glColor3d(0,0,0);
	  glTranslatef(x, y+8,z+1);
	  glScaled(0.009,0.014,z);

	  for (c=str; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *c);
	  }
	  glPopMatrix();
}
void board(){
    glColor3d(0,0.1,0);
    glPushMatrix();
        glTranslated(-5,0,0);
        glScaled(0.5,12,0.5);
        glutSolidCube(1);
    glPopMatrix();
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(-5,9,0);
        glScaled(15,6,0.5);
        glutSolidCube(1);
    glPopMatrix();
}

void draw(){
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    TIME = t;

    ///Plane
    if(rotX>11)rotX=11;
    if(rotX<-11)rotX=-11;
    if(rotZ>10)rotZ=10;
    if(rotZ<-15)rotZ=-15;
    glClearColor(0.4,0.8,0.9 ,0);
    glPushMatrix();
        glTranslated(0,1,0);
        glRotated(90,0,1,0);
        glRotated(5,0,0,1);
        glRotated(rotX,1,0,0);
        glRotated(rotY,0,1,0);
        glRotated(rotZ,0,0,1);
        glScaled(0.4,0.4,0.4);
        plane();
    glPopMatrix();

        glColor3d(1,1,1);
            glPushMatrix();
                glTranslated(-1.2,0.7,-4);
                glScaled(3.5,2.6,5);
                sun();
            glPopMatrix();


    ///Environment
    if(tX>=4.1)tX=4.1;
    if(tX<=-4.1)tX=-4.1;
    if(tY>0.1)tY= 0.1;
    if(tY<-15)tY= -15;

    glPushMatrix();
        glTranslated(tX,tY,tZ);
       environment();
    glPopMatrix();


     glPushMatrix();
        glTranslated(tX+15,tY,tZ);
    glScaled(0.1,0.1,0.1);
    apart(0,0,0);
    glPopMatrix();

     glPushMatrix();
        glTranslated(tX-17,tY,tZ-40);
    glScaled(0.1,0.1,0.1);
    apart(0,0,0);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX-8,tY,tZ+15);
    glScaled(1,1,1);
    board();
    drawStrokeText1("CG MINI PROJECT ",-12,0.2,0);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX+18,tY,tZ-28);
    glScaled(1,1,1);
    board();
    drawStrokeText1("By Kelvin",-12,2,0);
     drawStrokeText1("Jaivardan,Umesh",-12,0.3,0);
    glPopMatrix();


    glPushMatrix();
        glTranslated(tX-18,tY,tZ-90);
    glScaled(0.9,1.2,1);
    board();
    drawStrokeText1("Guide",-8,2,0);
     drawStrokeText1("Dr Manju VN",-10,0.3,0);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX+18,tY,tZ-128);
    glScaled(1,1,1);
    board();
    drawStrokeText1("6th sem CSE",-12,2,0);
    drawStrokeText1(" GCEM",-9,0.25,0);
    glPopMatrix();


    glPushMatrix();
        glTranslated(tX+15,tY,tZ-120);
    glScaled(0.1,0.1,0.1);
    apart(0,0,0);
    glPopMatrix();



    glPushMatrix();
        glTranslated(tX,tY,tZ2);
        environment();
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ3);
        environment();
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ4);
        environment();
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ5);
        environment();
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ6);
        environment();
    glPopMatrix();

    tZ+=speed;
    tZ1+=speed;
    tZ2+=speed;
    tZ3+=speed;
    tZ4+=speed;
    tZ5+=speed;
    tZ6+=speed;

    tX1+=speed;

    if(tX1>30) tX1=0;
 if(tZ>=120)tZ=-110;
    if(tZ1>=20)tZ1=-80;
    if(tZ2>=20)tZ2=-80;
    if(tZ3>=20)tZ3=-80;
    if(tZ4>=20)tZ4=-80;
    if(tZ5>=20)tZ5=-80;
    if(tZ6>=20)tZ6=-80;

    if(rotX>0)rotX-=angleBackFrac;
    if(rotX<0)rotX+=angleBackFrac;
    if(rotY>0)rotY-=angleBackFrac;
    if(rotY<0)rotY+=angleBackFrac;
    if(rotZ>0)rotZ-=angleBackFrac;
    if(rotZ<0)rotZ+=angleBackFrac;


    speed += 0.0002;
    if(speed>=0.7)speed=0.7;
}

void drawBitmapText(char *str,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x,y+8,z);

	for (c=str; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}


void drawStrokeText(char* str,int x,int y,int z)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y+8,z);
	  glScalef(0.002f,0.002f,z);

	  for (c=str; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	  }
	  glPopMatrix();
}

void drawStrokeChar(char c,float x,float y,float z)
{
	  glPushMatrix();
          glTranslatef(x, y+8,z);
          glScalef(0.002f,0.002f,z);
          glutStrokeCharacter(GLUT_STROKE_ROMAN , c);
	  glPopMatrix();
}

void menu()
{ const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;
    double aa=a;

    if(!rot){
        a=0;
    }
        if(START1){

        glPushMatrix();
            glTranslated(0,0,0);
            glScaled(zoom,zoom,zoom);
            glRotated(a,0,1,0);
            draw();
        glPopMatrix();
        glColor3f(0,0,0);
        drawStrokeText("P-PAUSE , Q-QUIT",-8,0.9,0);
        drawStrokeText("TIME : ",3,0,0);
        int mod,number=0;
        while(TIME){
            mod=TIME%10;
            number=number*10+mod;
            TIME/=10;
        }
        float tmp=0;
        while(number){
            mod=number%10;
            drawStrokeChar(mod+48,4+tmp,0,0);
            number/=10;
            tmp+=0.2;
        }
    }else{
         glClearColor(0.4,1,0.9  ,0);
        glPushMatrix();
            glTranslated(0,3,0);
            glRotated(aa,1,1,1);
            glScaled(1.5,1.5,1.5);
            plane();
        glPopMatrix();
        glColor3f(0,0,1);
        drawBitmapText("INSTRUCTIONS",-1,0,0);
        drawBitmapText("Press H to Start",-2,-2.5,0);
        drawBitmapText("MOVEMENTS",-9,-2,0);
        drawBitmapText("W-UP",-8.8,-3,0);
        drawBitmapText("S-DOWN",-8.8,-3.5,0);
        drawBitmapText("A-LEFT",-8.8,-4,0);
        drawBitmapText("D-RIGHT",-8.8,-4.5,0);
        drawBitmapText("R-ROTATE",-8.8,-5,0);
        drawBitmapText("T- STOP ROTATE",-8.8,-5.5,0);
        drawBitmapText("Continue - M",6,-4,0);
        drawBitmapText("QUIT-Q",6,-4.5,0);
    }
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;
    double aa=a;

    if(!rot){
        a=0;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(	0.0, 4.5, 10.0,
                0, 4, 0,
                0, 1.0f, 0.0f);

    if(START){
            menu();
     }
    else{

        glPushMatrix();
            glTranslated(0,3,0);
            glRotated(aa,0,1,0);
            glScaled(1.5,1.5,1.5);
            plane();
        glPopMatrix();

        glColor3f(0,0,1);
        drawBitmapText("GOPALAN COLLEGE OF ENGINEERING AND MANAGEMENT",-4,0,0);
        drawBitmapText("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING",-4,-0.5,0);
        drawBitmapText("A MINI PROJECT ON",-1.2,-1,0);
        glColor3f(0,0,1);
        drawBitmapText("Press Enter to Go",-1,-8,0);
        drawBitmapText("City Ride 3D",-0.5,-1.5,0);
        drawBitmapText("By",-8.8,-4,0);
        drawBitmapText("J PRINCE KELVIN",-8.8,-4.5,0);
        drawBitmapText("PAYYAVULA UMESH CHANDRA",-8.8,-5,0);
        drawBitmapText("JAIVARDHANA REDDY",-8.8,-5.5,0);
        drawBitmapText("GUIDE:",6,-4,0);
        drawBitmapText("Dr. MANJU V N",6,-4.5,0);
    }

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    float frac = 0.3;
    float rotFrac = 1;
    switch (key)
    {
        case 'q':
            exit(0);
            break;

        case 13:
            START=true;
            break;

        case 'h':
            START1=true;
            break;
        case 'm':
            START1=true;
            break;
        case 'p':
            START1=false;
            break;
        case 'w':
            tY-=frac;
            rotZ+=rotFrac;
            break;
        case 's':
            tY+=frac;
            rotZ-=rotFrac;
            break;
        case 'a':
            tX+=frac;
            rotX-=rotFrac*3;
            rotY+=rotFrac/2;
            break;
        case 'd':
            tX-=frac;
            rotX+=rotFrac*3;
            rotY-=rotFrac/2;
            break;

         case 'r':
            rot=true;
            break;

        case 't':
            rot=false;
            break;

    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };



/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
	glutInitWindowSize(1366,720);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

    glutCreateWindow("CITY RIDE 3D");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

   //PlaySound(TEXT("1.wav"),NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

    glClearColor(1,0.9,0.7,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
