#include<bits/stdc++.h>
#include<GL/glut.h>
#include<math.h>
#include<windows.h>
using namespace std;

int I=0;
bool polygon_complete=false;

class points{
    public:
    int x,y;
    void set_xy(int p1,int p2){
        x=p1;
        y=p2;
    }
    void scanline(int n);
}p[100];

class line{
    public:
    void dda(int ax1,int ay1,int ax2,int ay2);
}l;

void plot(int x,int y){
    glPointSize(1.0);
    glColor3f(1.0,0.4,0.8);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}

void line:: dda(int ax1,int ay1,int ax2,int ay2){
    double x,y,dx,dy,steps;

    dx=ax2-ax1;
    dy=ay2-ay1;
    steps=max(abs(dx),abs(dy));

    double xinc=dx/steps;
    double yinc=dy/steps;

    x=ax1,y=ay1;
    plot(x,y);

    for(int i=0;i<steps;i++){
        x+=xinc;y+=yinc;
        plot(x,y);
    }

}

void points::scanline(int n){
    int y_min=INT_MAX,y_max=0;
    float m[n];
    for(int i=0;i<=n-1;i++){
        if(p[i].y>y_max){
            y_max=p[i].y;
        }
        if(p[i].y<y_min){
            y_min=p[i].y;
        }

        float dx=p[i+1].x-p[i].x;
        float dy=p[i+1].y-p[i].y;

        if(dy==0){
            m[i]=1;
        }
        else m[i]=dx/dy;
    }

    for(int y=y_max;y>=y_min;y--){
        vector<int>inter_x;

        for(int i=0;i<=n-1;i++){
            if((y<=p[i].y && y>p[i+1].y) || (y>p[i].y && y<=p[i+1].y)){
                inter_x.push_back(p[i].x+(m[i]*(y-p[i].y)));
            }
        }

        sort(inter_x.begin(),inter_x.end());

        for(int i=0;i<inter_x.size();i+=2){
            int x1=inter_x[i],x2=inter_x[i+1];
            l.dda(x1,y,x2,y);
        }

    }

}

void mouse(int btn,int state,int x,int y){

    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        p[I].set_xy(x,y);
        if(I)
        {
            l.dda(p[I].x,p[I].y,p[I-1].x,p[I-1].y);
        }
        I++;
    }
    else if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
        l.dda(p[I-1].x,p[I-1].y,p[0].x,p[0].y);
        p[I].set_xy(p[0].x,p[0].y);
        polygon_complete=true;
    }
    else if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN ){
        if(polygon_complete)
        p[0].scanline(I);
    }


}

void display(){

}

void init(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,500,0);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutCreateWindow("Scanline");
    glutInitWindowSize(500,500);
    glutReshapeWindow(500,500);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();

}