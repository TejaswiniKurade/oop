#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

class pixel {
	public :
		void plot(int x, int y);
		void plot(float x, float y);
};

void pixel :: plot(float x, float y){
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();

}
void pixel :: plot(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

class line : public pixel{

	public :
		int X1, X2, Y1, Y2;
        
		void drawLine(int X1, int Y1, int X2, int Y2);
};


void line :: drawLine(int X1, int Y1, int X2, int Y2){
	pixel p;
	float dx, dy, step, xInc, yInc, x = X1, y = Y1;

	dx = X2 - X1;
	dy = Y2 - Y1;

	if(abs(dx) > abs(dy))
		{step = abs(dx);}
	else{ step = abs(dy);}
	xInc = dx/step;
	yInc = dy/step;
	for (int i = 1; i <= step+1 ; i++){
		p.plot(x,y);
		x += xInc;
		y += yInc;
	}
}

class circle : public pixel{

	public :
		int X1, Y1, r;
        
		void drawCircle(float X1, float Y1, float r);
};


void circle :: drawCircle(float X1, float Y1, float r){
	int x = 0, y = r;
	float d = 3 -2*r;

	while (y >= x){
		plot(x+X1,y+Y1);
		plot(x+X1,-y+Y1);
		plot(-x+X1,y+Y1);
		plot(-x+X1,-y+Y1);
		plot(y+X1,x+Y1);
		plot(y+X1,-x+Y1);
		plot(-y+X1,x+Y1);
		plot(-y+X1,-x+Y1);
		if (d < 0)
			d += 4*x + 6;
		else {
			d += 4*(x-y) + 10;
			y--;
		}
		x++;
	}
}

void pattern1()
{
	// code for drawing the pattern
		line l;

		l.drawLine(100, 100, 200, 100);
		l.drawLine(200, 100, 200, 200);
		l.drawLine(100, 200, 200, 200);
		l.drawLine(100, 200, 100, 100);


		l.drawLine(150, 100, 200, 150);
		l.drawLine(200, 150, 150, 200);
		l.drawLine(100, 150, 150, 200);
		l.drawLine(100, 150, 150, 100);

		circle c;
		c.drawCircle(150, 150, 35.35);
		glFlush();
}
void pattern2()
{
    
		line l;
	l.drawLine(100,200,13.67,49.52);
	l.drawLine(13.67,49.52,186.87,50.47);
	l.drawLine(186.87,50.47,100,200);
	circle c;
	c.drawCircle(100,100,50);
	c.drawCircle(100,100,100);
	glFlush();
}

void myInit(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glFlush();
}

void keyboard(unsigned char key, int x, int y)

{
 if (key == 'd')
		{pattern1();}
 else if (key == 'b')
		{pattern2();}

}

int main(int argc, char** argv){
   

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("ASSIGNMENT-3");
	myInit();
	glutKeyboardFunc(keyboard); 
	glutMainLoop();

	return 0;
}