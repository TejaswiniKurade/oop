#include<iostream>
#include<fstream>
using namespace std;
class Employee              // declaring class employee
{
 	string Name;
	 int ID;
	 double salary;

	 public:
	 void accept()			// Accept infromation
	 {
		 cout<<"\n Name : ";
		 cin.ignore();
 	      	getline(cin,Name);
	  	 cout<<"\n Id : ";
		 cin>>ID;
		 cout<<"\n Salary : ";
		 cin>>salary;
	 }

	 void display()			// Display infromation
	 {
		 cout<<"\n Name : "<<Name;
		 cout<<"\n Id : "<<ID;
		 cout<<"\n Salary : "<<salary<<endl;
	 }
};

int main()
{
 	Employee o[5];
 	fstream f;
 	int i,n;


	// Writing to the file

	 f.open("demo.txt",ios::out);
	 cout<<"\n Enter the number of employees you want to store : ";
	 cin>>n;
	 for(i=0;i<n;i++)
	 {
		 cout<<"\n Enter information of Employee "<<i+1<<"\n";
		 o[i].accept();
		 f.write((char*)&o[i],sizeof o[i]);
	 }
	 f.close();

	// Reading from the file
	 f.open("demo.txt",ios::in);
	 cout<<"\n Information of Employees is as follows : \n";
	 for(i=0;i<n;i++)
	 {
		 cout<<"\nEmployee "<<i+1<<"\n";
		 f.write((char*)&o[i],sizeof o[i]);
		 o[i].display();
	 }
	 f.close();
 
	 return 0;
}

/* Sample Output 

moctest@csl5-V520-15IKL:~$ g++ filehand.cpp
moctest@csl5-V520-15IKL:~$ ./a.out

 Enter the number of employees you want to store : 3

 Enter information of Employee 1

 Name : Ram

 Id : 123

 Salary : 70000

 Enter information of Employee 2

 Name : Shyam

 Id : 456

 Salary : 80000

 Enter information of Employee 3

 Name : Sita

 Id : 789

 Salary : 75000

 Information of Employees is as follows : 

Employee 1

 Name : Ram
 Id : 123
 Salary : 70000

Employee 2

 Name : Shyam
 Id : 456
 Salary : 80000

Employee 3

 Name : Sita
 Id : 789
 Salary : 75000
moctest@csl5-V520-15IKL:~$ ^C
moctest@csl5-V520-15IKL:~$ 


*/


