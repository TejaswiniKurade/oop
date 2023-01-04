#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string,long> mp;
    int n;
    cout<<"Enter no of enteries = ";
    cin>>n;
    string st[n];
    long pop[n];
    for(int i=0;i<n;i++)
    {
        getline(cin>>ws,st[i]);
        cin>>pop[i];
        mp[st[i]]=pop[i];
    }
    char cho;
    do
    {
        cout<<"\n\t"<<"*****Menu*****"<<"\n";
        cout<<"\t"<<"1. Display all"<<"\n";
        cout<<"\t"<<"2. Find state"<<"\n";
        cout<<"\t"<<"3. Update"<<"\n";
        cout<<"\t"<<"4. add new"<<"\n";
        cout<<"\t"<<"5. exit"<<"\n";
        int ch;
        
        cout<<"Enter choice = ";
        cin>>ch;
        string x="";
        long no;
        bool flag=0;
        switch(ch)
        {
            case 1:
            cout<<"\n\t"<<left<<setw(20)<<"STATES"<<setw(20)<<left<<setw(20)<<"POPULATION";
            for(auto &it:mp)
            {
                
                cout<<"\n\t"<<left<<setw(20)<<it.first<<setw(20)<<left<<setw(20)<<it.second;
            }
            break;
            case 2:
            cout<<"Enter name of state = ";
            getline(cin>>ws,x);
            for(auto &it:mp)
            {
                if(it.first==x)
                {
                    cout<<"State found"<<endl;
                    cout<<"\n\t"<<"STATES"<<"\t\t"<<"POPULATION"<<"\n";
                    cout<<"\n\t"<<it.first<<"\t\t"<<it.second<<"\n";
                    flag=1;
                }
            }
            if(flag==0)
            {
                cout<<"Not Found"<<endl;
            }
            break;
            case 3:
            cout<<"Enter state = ";
            getline(cin>>ws,x);
            long new_p;
            for(auto &it:mp)
            {
                 if(it.first==x)
                 {
                    cout<<"Enter Population updated =";
                    cin>>new_p;
                    mp[x]=new_p;
                 }
            }
            break;
            case 4:
            cout << "enter the state name: ";
            getline(cin>>ws, x);
            cin >> no;
            mp.insert(pair<string, long>(x, no));
            break;
            case 5:
            exit(0);
            
        }
        cout<<"Do u wanna continue?  ";
        cin>>cho;
    }while(cho=='y'||cho=='Y');
}