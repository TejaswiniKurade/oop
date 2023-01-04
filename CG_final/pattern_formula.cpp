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
        void getPointsDDA();
        void drawLine(int X1, int Y1, int X2, int Y2);
};

void line :: getPointsDDA(){
    cout << "Enter the Coordinates : \n";
    cout << "x1, y1 : "; cin >>  this->X1 >>  this->Y1;
    cout << "x2, y2 : "; cin >>  this->X2 >>  this->Y2;
    cout << "-------------------------------\n";
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    drawLine(this->X1,this->Y1, this->X2, this->Y2);
    glFlush();
}

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
        void getPoints();
        void drawCircle(float X1, float Y1, float r);
};

void circle :: getPoints(){
    cout << "Enter the coordinates of the center:\n";
    cout << "X-coordinate   : "; cin >> X1;
    cout << "Y-coordinate : "; cin >> Y1;
    cout << "Enter radius : "; cin >> r;
    cout << "-------------------------------\n";
}

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

void myInit(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}

void mouse(int btn, int state, int x, int y){
    myInit();
    int rad;
    cout << "Enter radius : "; cin >> rad;
    circle c;
    c.drawCircle(x,y,rad);
    int x1,y1, x2,y2, x3,y3;
    x1 = x; y1 = y+rad;
    x2 = x + rad*cos(-3.14/6);y2 = y + rad*sin(-3.14/6);
    x3 = x - rad*cos(-3.14/6);y3 = y + rad*sin(-3.14/6);

    line l;
    l.drawLine(x1,y1,x2,y2);
    l.drawLine(x2,y2,x3,y3);
    l.drawLine(x3,y3,x1,y1);

    int nrad = y-y2;
    c.drawCircle(x,y,nrad);

    return;
}

int main(int argc, char** argv){
    cout << "=============================================\n";
    int min_x, min_y, max_x, max_y;
    cout << "	X1,Y1 : "; cin >> min_x >> min_y;
    cout << "	X2,Y2 : "; cin >> max_x >> max_y;
    cout << "=============================================\n";
    cout << "Now wait for the magic!\n";
    cout << "=============================================\n";

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(50,50);
    glutCreateWindow("ASSIGNMENT-3");
    myInit();
        // code for drawing the pattern
        line l;

        l.drawLine(min_x, min_y, min_x, max_y);
        l.drawLine(min_x, max_y, max_x, max_y);
        l.drawLine(max_x, max_y, max_x, min_y);
        l.drawLine(max_x, min_y, min_x, min_y);


        l.drawLine((min_x + max_x)/2, min_y, min_x, (min_y + max_y)/2);
        l.drawLine(min_x, (min_y + max_y)/2, (min_x + max_x)/2, max_y);
        l.drawLine((min_x + max_x)/2, max_y, max_x, (min_y + max_y)/2);
        l.drawLine(max_x, (min_y + max_y)/2, (min_x + max_x)/2, min_y);

        circle c;

        float xc, yc, rc;
        xc = (min_x + max_x)/2;
        yc = (min_y + max_y)/2;
        float t = min(max_x - min_x , max_y - min_y);
        float s = max(max_x - min_x , max_y - min_y);
        t = (t+s)/2;
        rc = (t/1.414) /2;
        c.drawCircle(xc, yc, rc);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}