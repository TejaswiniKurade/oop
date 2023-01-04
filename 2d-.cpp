/*
	Name : Puja
	Roll No : 7243
	
	Assignment : 3
	Problem Statement :
		Implement 2D transformation - translation, rotation and scaling.
		Using mouse event.
*/

#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

int x,y,n;
vector<pair<int,int>> v, trans;
double const pi = 3.14159265359, ert = 180;


class pixel {
	public :
		void plot(int x, int y);
		void plot(float x, float y);
		void plot(vector<pair<int,int>> temp);
		void put_line(int X1, int Y1, int X2, int Y2);
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
void pixel :: put_line(int X1, int Y1, int X2, int Y2){
	glColor3f(1,1,0);
	glBegin(GL_LINE_LOOP);
		glVertex2i(X1,Y1);
		glVertex2i(X2,Y2);
	glEnd();
	glFlush();
}

void pixel :: plot(vector<pair<int, int>> temp){
	glColor3f(0,1,1);
	glBegin(GL_LINE_LOOP);
        	for (int i = 0; i < n; i++)
        		glVertex2i(temp[i].first, temp[i].second);
	glEnd();
	glFlush();
}

void myInit(){
	glClearColor(0,0,0,0);
	glColor3f(1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
}

class Transformation : public pixel {
	public :
		pixel p;
		void translation();
		void rotation();
		void scaling();
		void shearing();
};



void Transformation :: translation(){
	trans = v;
	int tx,ty;
	cout << "Enter the coordinates for translation ::";
	cin >> tx >> ty;
	tx = x-tx; ty = y-ty;
	for (int i = 0; i < n; i++){
		trans[i].first += tx;
		trans[i].second += ty;
	}
	p.plot(trans);
}

void Transformation :: shearing(){
	trans = v;
	int tx,ty;
	char axis;
	cout << "Enter axis::";
	cin >> axis;
	if(axis=='x')
	{
		cout<<"enter factor = ";
		cin>>tx;
		for (int i = 0; i < n; i++){
			trans[i].first += tx*trans[i].second;
			//trans[i].second = trans[i].second;
		}
		
	}
	else if(axis=='y')
	{
		cout<<"enter factor = ";
		cin>>ty;
		for (int i = 0; i < n; i++){
			trans[i].second += tx*trans[i].first;
			//trans[i].first = trans[i].first;
		}
		
	}
	p.plot(trans);
}

void Transformation :: rotation(){
	trans = v;
	double theta;
	cout << "Enter theta :"; cin >> theta;
	theta = theta * pi/ert;
	for (int i = 0; i < n; i++){
		int a = v[i].first,b = v[i].second;
		trans[i].first = a*cos(theta) - b*sin(theta);
		trans[i].second = a*sin(theta) + b*cos(theta);
	}
	p.plot(trans);
}
void Transformation :: scaling(){
	trans = v;
	double sx, sy;
	cout << "Enter the scaling factors ::";
	cin >> sx >> sy;
	for (int i = 0; i < n; i++){
		trans[i].first *= sx;
		trans[i].second *= sy;
	}
	p.plot(trans);
}

void menu(){
	int choice;
	Transformation t;
	while (true){
		cout << "------MENU----\n";
		cout << "1. Translation\n2. Rotation\n3. Scaling\n :: ";
		cin >> choice;
		if (choice == 1)
			t.translation();
		else if (choice == 2)
			t.rotation();
		else if (choice == 3)
			t.scaling();
		else
			break;
	}
	
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(-500,y);
    		glVertex2f(500,y);
	glEnd();
    
	glBegin(GL_LINES);
    		glVertex2f(x,-500);
    		glVertex2f(x,500);
 	glEnd();
    
	glBegin(GL_LINE_LOOP);
        	for (int i = 0; i < n; i++)
        		glVertex2i(v[i].first, v[i].second);
	glEnd();
	glFlush();
	menu();
}


int main(int argc, char** argv){
	cout << "Enter the coordinates of the origin : "; cin >> x >> y;
	cout << "Enter the number of vertices : "; cin >> n;
	v.resize(n);
	cout << "Enter the vertices' coordinates : \n";
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("2D Transformation");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}