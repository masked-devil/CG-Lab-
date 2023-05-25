#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int ww=600,wh=500;
float bgCol[3]={1.0,1.0,1.0};
float intCol[3]={1.0,1.0,0.0};
float fillCol[3]={1.0,0.0,0.0};
void setPixel(int pntx,int pnty,float f[3])
{
 glBegin(GL_POINTS);
 glColor3fv(f);
 glVertex2i(pntx,pnty);
 glEnd();
 glFlush();
}
void GetPixel(int x,int y,float pixels[3])
{
 glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pixels);
}
void draw_poly(int x1,int y1, int x2, int y2)
{
 glColor3f(1.0,1.0,0.0);
 glBegin(GL_POLYGON);
 glVertex2i(x1,y1);
 glVertex2i(x1,y2);
 glVertex2i(x2,y2);
 glVertex2i(x2,y1);
 glEnd();
 glFlush();
}
void display()
{
 glClearColor(0.0,0.0,0.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 draw_poly(200,200,300,300);
 glFlush();
}
void flood_fill(int x, int y, float o_c[3], float n_c[3])
{
 float color[3];
 GetPixel(x,y,color);
 if(color[0]==o_c[0]&& (color[1])==o_c[1] && (color[2])==o_c[2] )
 {
 setPixel(x,y,n_c);
 flood_fill(x+1,y,o_c,n_c);
 flood_fill(x-1,y,o_c,n_c);
 flood_fill(x,y+1,o_c,n_c);
 flood_fill(x,y-1,o_c,n_c);
 }
}
void mouse(int bt, int state , int x, int y)
{
 if(bt==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
 int xi=x;
 int yi=(wh-y);
 flood_fill(xi,yi,intCol,fillCol);
 }
}
void myInit()
{
 glViewport(0,0,ww,wh);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);
 glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(ww,wh);
 glutCreateWindow("Flood FIll");
 glutDisplayFunc(display);
 myInit();
 glutMouseFunc(mouse);
 glutMainLoop();
 return 0;
}
