#include <iostream>
#include <vector>
using namespace std;

void list_all(vector<string> &name){
    cout << "all songs: " << endl;

    for(int i =0; i < name.size(); i++){
            cout << name[i] << endl;
    }

}

void bised_array(vector<string> &name) {

    string temp1;
    for(int i=0; i< name.size()-1; i++){
        for(int j=0; j < (name.size()-i-1); j++){
            if( name[j] > name[j+1] ) {
                temp1 = name[j];
                name[j] = name[j+1];
                name[j+1] = temp1;
            }
        }
    }

for(int i=0; i<name.size(); i++){
    if(name[i] == "untiteled" ) {
        name[i].erase();
        name.insert(name.begin(), "untiteled");
    }
}

    list_all(name);
}


int main()
{

    vector<string> name = {"rolling","a b c","q z y","7 yeasrs old","untiteled","b b"};
    bised_array(name);

}
