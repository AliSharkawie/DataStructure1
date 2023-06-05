#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;
set<string> aset;
map<string,int> amap;
void Recpermute(string soFar, string rest)
{
    if(rest == "") //no more characters
        aset.insert(soFar); //print the word
    else
        //for each remaining char
    for(int i=0;i<rest.length();i++){
        string next = soFar + rest[i];//Glue next char
        string remaining = rest.substr(0,i)+rest.substr(i+1);
        Recpermute(next,remaining);


    }
}
//"wrapper" function
void ListPermutations(string s){
    Recpermute("",s);



}
int main()
{
    string s;
    cin>>s;
    ListPermutations(s);
    for(auto it:aset)
    {
        cout<<it<<endl;
    }
}
