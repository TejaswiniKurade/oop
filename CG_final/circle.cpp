#include<GL/glut.h>

#include<bits/stdc++.h>



using namespace std;



class pixel

{

    public:

   void plot(float x,float y);

};



void pixel::plot(float x,float y)

{



    glBegin(GL_POINTS);

    glVertex2i(x,y);

    glEnd();

    glFlush();

}



class circle: public pixel

{



    public:

    int X1,Y1,r;

    void getpoint();

    void dda();

    void bresenham();

    void midpoint();

} cr;



void circle::getpoint(){



    cout<<"enter the cordinate of center"<<endl;

    cout<<"enter x cordinate:";

    cin>>X1;

    cout<<"enter y cordinate:";

    cin>>Y1;

    cout<<"enter the radius of the circle:";

    cin>>r;



}



void circle::bresenham()

{



    int x = 0, y = r;

    float d = 3 -2* r;

    while (y >= x){



        glColor3f(0.2,0.4,0.0);

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



void circle::dda(){



    float x1,x2,y1,y2,sx,sy,eps;

    int i,val;

    x1=0;

    y1=r;

    sx=x1;

    sy=y1;

    i=0;



    do{

        val=pow(2,i);

        i++;

    }while(val<r);

    eps=1/pow(2,i-1);

    do{



        x2=x1+eps*y1;

        y2=y1-eps*x2;

        glBegin(GL_POINTS);

        glColor3f(1.0,0.0,0.0);

        glVertex2i(X1+x2,Y1+y2);

        glEnd();

        glFlush();

        x1=x2;

        y1=y2;



    }while((y2-sy)<eps||(sx-x2)>eps);

}



void circle::midpoint()

{

   int x,y;

    x = 0;

    y = r;

    float decision = 5/4 - r;

    plot(x, y);



    while (y > x)

    {

        if (decision < 0)

        {

            x++; 

            decision += 2*x+1;

        }

        else

        {

            y--;

            x++;

            decision += 2*(x-y)+1;

        }

        glColor3f(0.0,0.4,1.0);

        plot(x, y);

        plot(x, -y);

        plot(-x, y);

        plot(-x, -y);

        plot(y, x);

        plot(-y, x);

        plot(y, -x);

        plot(-y, -x);

    }



}

void MyInit(void){



    glClearColor(1,1,1,1);

    glColor3f(0.2,0.3,0.7);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-500,500,-500,500);



}



void keyboard(unsigned char key, int x, int y)



{

 if (key == 'd')

        {cr.dda();}

    else if (key == 'b')

       { cr.bresenham();}

else if (key == 'm')

   { cr.midpoint();}

   glutPostRedisplay();

}

int main(int argc,char* argv[]){



    glutInit(&argc,argv);

    glutInitWindowSize(500,500);

    glutInitWindowPosition(10,10);

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    glutCreateWindow("efnefeif");

    MyInit();

    cr.getpoint();

    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;

}





// void circle::midPoint(int x,int y,int r)

// {

//     x = 0;

//     y = r;

//     float decision = 5/4 - r;

//     plot(x, y);



//     while (y > x)

//     {

//         if (decision < 0)

//         {

//             x++; 

//             decision += 2*x+1;

//         }

//         else

//         {

//             y--;

//             x++;

//             decision += 2*(x-y)+1;

//         }

//         plot(x, y);

//         plot(x, -y);

//         plot(-x, y);

//         plot(-x, -y);

//         plot(y, x);

//         plot(-y, x);

//         plot(y, -x);

//         plot(-y, -x);

//     }



// }