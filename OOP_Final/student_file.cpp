#include <fstream> // Include filestream support.
#include <string>
#include <iostream>
using namespace std ;
int main() 
{
    string temp;
    struct student
    {
        int roll;
        string name;
    }s;
	
    ofstream fout("pika.txt",ios::app);
    if (!fout.is_open())
    {
        cerr <<"Error opening file for output"<< endl ;
        return -1 ; // Signal an error then exit the program.
    }
    cout<<"\n\t Enter your Data here(type roll -1 to stop ):";
    fout<<"Roll Name"<<endl;
    while(1)
    {
        //getline(cin,poem);
        cout<<"Enter roll and name :";
        cin>>s.roll;
        if(s.roll==-1)
            break;
        cin>>s.name;
        fout<<s.roll<<"	"<<s.name<< endl ; // Write output.
    }
    fout.close() ; // Close filestream

    ifstream fin("pika.txt",ios::in); //reading data
    if ( ! fin )
    {
        cout <<"Error opening file for input"<< endl ;
        return -1 ; // Signal an error then exit the program.
    }
    cout<<"\n File Contents are:\n";
    while(!fin.eof())
    {
        getline(fin,temp);
        cout<<"\n"<<temp;
    }
    fin.close();
    return 0 ;
}
