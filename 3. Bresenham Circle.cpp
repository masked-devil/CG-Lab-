#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int pntx,pnty,R;
void plot(int x, int y)
{
 glBegin(GL_POINTS);
 glVertex2d(x + pntx, y+pnty);
 glEnd();
}
void myInit(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glColor3f(0.0,0.0,0.0);
 glPointSize(4.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0,640.0,0.0,480.0);
}
void bresenhams_circle(int r)
{
 int x=0;
 int y=r;
 float d= 3-2*r;
 plot(x,y);


while(x<=y)

{
 x++;
 if(d<0)

{
 d=d + 4*x+6;

}
 else{
 d=d+4*(x
-y)+10;

y--
;

}
 plot(x,y);
 plot(x,
-y);
 plot(
-x,y);
 plot(
-x,
-y);
 plot(y,x);
 plot(
-y,x);
 plot(y,
-x);
 plot(
-y,
-x);

}
}
void display(void) {
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.0,0.0,0.0);
 glPointSize(1.0);
 cout<<"r:";
 bresenhams_circle(R);
 bresenhams_circle(9*R/10);
 bresenhams_circle(8*R/10);
 bresenhams_circle(7*R/10);
 bresenhams_circle(6*R/10);
 bresenhams_circle(5*R/10);
 bresenhams_circle(4*R/10);
 bresenhams_circle(3*R/10);
 bresenhams_circle(2*R/10);
 bresenhams_circle(R/10);
 glFlush();
}
int main(int argc, char**argv)
{
 cout<<"Enter Value Of x";
 cin>>pntx;
 cout<<"Enter Value Of y";
 cin>>pnty;
 cout<<"Enter Value Of R";
 cin>>R;
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(1000,1000);
 glutCreateWindow(" bresenhams circle drawing algorithm");
 glutDisplayFunc(display);
 myInit();
 glutMainLoop();
 return 0;}
