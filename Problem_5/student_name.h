#include <iostream>
#include <string>
#include<vector>
using namespace std;
class student_name{
private :
    string st_name;
public :
    student_name(){}
    student_name(string name)
    {
        int n=st_name.length();
        int count=0;
        int last=0;
        for (int i=0; i<n; ++i)
        {
            if(st_name[i]==' ')
             {++count ;
             last=i;
        }}
        if (count>=2)
            st_name=name;
        else
        {
                if (count=0)
                st_name=name+" "+name+" "+name;
                else
                    st_name=name+name.substr(last);
            }
        }

    void print()
    {
        vector<string> name;
        string n="";
        for(int i=0; i< st_name.length(); i++)
        { if (st_name[i]==' ')
             {
                name.push_back(n);
                n="";
            }
            else if(i==st_name.length()-1)
            {
                n+=name[i];
                name.push_back(n);
            }
             else
                n+=st_name[i];
    }

    int j=1;
        for(int i=0; i<name.size(); ++i)
        {
            cout<<j<<") "<<name[i]<<endl;
            ++j;
        }
    }

    bool Reblace (int i, int j)
    {
        vector<string> name;
        string n="";
        for(int i=0; i<st_name.length(); i++)
        {
            if (st_name[i]==' ')
            {
                name.push_back(n);
                n="";
            }
            else if(i==st_name.length()-1)
            {
                n+=st_name[i];
                name.push_back(n);
            }
            else
                n+=st_name[i];
        }

        if(i > name.size() || j > name.size())
        {
            return false;
        }
        else
        {
            string rep=name[j-1];
            name[j-1]=name[i-1];
            name[i-1]=rep;
            string s;
            for(int i = 0 ; i < name.size() ; i++)
            {
                s=s+name[i] + " ";
            }
            st_name = s;
            cout << st_name<<endl;
            return true;
        }
    }
};
