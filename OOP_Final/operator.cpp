#include<iostream>
#include<math.h>
using namespace std;

class cmplx
{
        float real , imag;      
public :
        cmplx()
        {
             real = 0;
             imag = 0;
        }
                
        cmplx(float tempx , float tempy)
        {
             real = tempx;
             imag = tempy;
        }
                 
        cmplx operator + (cmplx);
        cmplx operator - (cmplx);
        cmplx operator * (cmplx);
        cmplx operator / (cmplx);                
                 
        void getdata()
        {
             cout<<"enter real and imaginary part of complex number ";
             cin>>real>>imag;                   
        } 
                 
        void putdata()
        {
             cout<<real<<" "<<imag<<endl;
        }   
                 
        friend istream & operator >>( istream & , cmplx &);     
        friend ostream & operator <<( ostream & , cmplx &); 
};

//overloading addition operator
cmplx cmplx :: operator + (cmplx temp1)
// return_type class_name scope_resolution operator (calling_object passed_object)
{
        cmplx temp2;
        temp2.real = real + temp1.real;
        temp2.imag = imag + temp1.imag;
        return temp2;
}

//overloading substraction operator
cmplx cmplx :: operator - (cmplx temp1)                     
// return_type class_name scope_resolution operator (calling_object passed_object)
{
        cmplx temp2;
        temp2.real = real - temp1.real;
        temp2.imag = imag - temp1.imag;
        return temp2;
}

//overloading multiplication operator
cmplx cmplx :: operator * (cmplx temp1)                 
// return_type class_name scope_resolution operator (calling_object passed_object)
{
        cmplx temp2;
        temp2.real = (real * temp1.real) + (imag * temp1.imag);
        temp2.imag = (real * temp1.imag) + (imag * temp1.real);
        return temp2;
}

//overloading division operator
cmplx cmplx :: operator / (cmplx temp1)                     
// return_type class_name scope_resolution operator (calling_object passed_object)
{
    cmplx temp2;
    temp2.real = ((real * temp1.real) + (imag * temp1.imag)) / ((pow(temp1.real,2) + pow(temp1.imag,2)));

    temp2.imag = ((imag * temp1.real) - (real * temp1.imag)) / ((pow(temp1.real,2) + pow(temp1.imag,2)));

    return temp2;
}

// overloading insertion operator
istream & operator >>( istream & mycin, cmplx & t)             
{
        cout<<"enter real and imaginary part of complex number :";
        mycin >> t.real >> t.imag;
        return mycin;
}

//overloading extraction operator
ostream & operator <<( ostream & mycout, cmplx & t)            
{
        mycout << t.real<<" "<<t.imag;
        return mycout;
}

int main()
{      
    int n;
    cmplx c3;
    cmplx c1;
    cmplx c2;
    mycin>> c1;
    cin>> c2;     
    do
{   
cout<<"press 1 for addition, 2 for subtraction, 3 for multiplication, 4 for       division "<<endl;                      
       	cin>>n; 
       	switch (n)
       	{
           		case 1:
                   	c3 = c1 + c2;
                   	break;
           		case 2:
                   	c3 = c1 - c2;
                   	break;
           		case 3:
                   	c3 = c1 * c2;
                   	break;
           		case 4:
                   	c3 = c1 / c2;
                   	break;
           		default:
                   	break;
       	}     
       cout<< c3 <<endl;
      }
       while(0 < n and n < 5);   
       return 0;
}    

// -----------------------------------------------------------OUTPUT------------------------------------------------------------------

// enter real and imaginary part of complex number :10 -65
// enter real and imaginary part of complex number :-32 -5
// press 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division 
// 1
// -22 -70
// press 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division 
// 2
// 42 -60
// press 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division 
// 3
// 5 2030
// press 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division 
// 4
// 0.00476644 2.03051
// press 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division 
// 5
// 0.00476644 2.03051
