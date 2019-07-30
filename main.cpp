#include<bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;
bool rainday=false;
float _rain=0.0f;
void init(){

	glClearColor(0.0,0.5,0.8,1.0);
	glColor3f(0.0,0.0,0.5);
	glPointSize(4.0);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);

}
void Rain(int value)
{
    if(rainday)
    {
        _rain+= 0.01f;
        glBegin(GL_POINTS);
        for(int i=1;i<=1000;i++)
        {
            int x=rand(),y=rand();
            x%=1000; y%=1000;
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2d(x,y);
            glVertex2d(x+5,y+5);
            glEnd();
        }
        glutPostRedisplay();
        glutTimerFunc(5,Rain,0);
        glFlush();
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();

}

void handleKeypress(unsigned char key, int x, int y){
    if(key=='r'||key=='R')
    {
        rainday=true;
        PlaySound(TEXT("Others/rsound.WAV"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
        Rain(_rain);
    }
    else if(key=='E'||key=='e')
    {
        PlaySound(NULL,0,0);
        rainday=false;
    }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitWindowSize(640,480);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Basic Animation");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMainLoop();
   return 0;
}

