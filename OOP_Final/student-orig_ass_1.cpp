#include<iostream>
using namespace std;
int n;
int key;
int flag;

class student
{
	protected :
		static int count ;			// static variable
		int roll_no;
		char name[10];
		char Class[10];
		char division;
		string DOB;
		char blood_group[5];
		string address;
		string mobile_number;
		char driving_license_number[20];
	public :
		student();
		student(int temp);
		student(student &temp);
		~student();
		int get_roll();
		void getdata();
		void putdata();
		static void showcount()		// static function
		{
			count = 5;
			cout<<student :: count<<endl;
		}
		friend class lib;
};

class lib 							// friend class
{ 
	public :	
	    void display(student &o)
	    {
			cout<<o.roll_no<<endl;
	    }
};

int student :: count;


student :: student()               // default constructor 
	{ roll_no = 0;
	}

student :: student(int temp)       // parameter constructor
	{this -> roll_no = temp;
	}

student :: student(student &temp)      //copy constructor
	{this -> roll_no = temp.roll_no;
	}

student :: ~student()
	{roll_no = -1;}


void student :: getdata()
	{
	cout<<"enter roll no :";
	cin>>roll_no;

	cout<<"enter name :";
	cin>>name;

	cout<<"enter the class :";
	cin>>Class;

	cout<<"enter division :";
	cin>>division;

	cout<<"enter date of birth : ";
	cin>>DOB;

	cout<<"enter blood group :";
	cin>>blood_group;

	cout<<"enter mobile number :";
	cin>>mobile_number;

	cout<<"enter driving license number :";
	cin>>driving_license_number;

	cout<<"enter address :";
	getline(cin>>ws , address);
	}

inline void student :: putdata()			//inline code		
	{
		cout<<"roll no , name , DOB is "<<roll_no<<", "<<name<<", "<<DOB<<endl;
		cout<<"class , division , blood group is "<<Class<<" "<<division<<", "<<blood_group<<endl;
		cout<<"mobile number , driving license number is "<<mobile_number<<", "<<driving_license_number<<endl;
		cout<<"address is "<<address<<endl;
	}

void search(student s[],int n)
	{flag = 0;

	cout<<"enter roll no of student to search :";
	cin>>key;

	for(int i=0;i<n;i++)
	{
		if(s[i].get_roll() == key)
			{cout<<"details of searched student are : "<<endl;
			s[i].putdata();
			flag = 1;
			}
	}

	if(flag == 0)
		{cout<<"roll no. not found"<<endl;}
	}
int student :: get_roll()
	{return  roll_no;}

int main()
{	
	lib l;
	student s[10];
	cout <<"enter n :";				//number of students
	cin>>n;

	for(int i=0;i<n;i++)
		{s[i].getdata();}

	cout<<endl;
	if(n>0)
	{
		cout<<"student details are"<<endl;
	}
	for(int i = 0; i<n;i++)
		{s[i].putdata();
		cout<<endl;
		}

	search(s,n);
	cout<<endl;
	student x (15);        // call for parameter constructor
	student t (x);          //call for copy constructor	
	
	if(n>0)
	{
	l.display(s[0]);
	}
	s[0].showcount();
	return 0;
} 


