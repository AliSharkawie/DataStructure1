#include <iostream>
#include <string>
#include <vector>
#include "student_name.h"
using namespace std;

int main()
{
     student_name st1("Braa Ahmed Mohamed");
     if (st1.Reblace(1,3)){
        st1.print();
        cout<<endl;
     }

     student_name st2("Hala");
     if (st2.Reblace(1,2)){
        st2.print();
        cout<<endl;
     }

     student_name st3("Amna Adil");
     if (st3.Reblace(1,2)){
        st3.print();
        cout<<endl;
     }

     student_name st4("Belal Ahmed Hashim Anwar");
     if (st4.Reblace(2,3)){
        st4.print();
        cout<<endl;
     }

     student_name st5("Manar Hatim");
     if (st5.Reblace(1,2)){
        st5.print();
        cout<<endl;
     }



    return 0;
}
