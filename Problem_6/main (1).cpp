#include<bits/stdc++.h>
#include "PhoneDirectory.h"
#include <string>
using namespace std;

int main()
{

    PhoneDirectory entry;
    char num;
    do {
        cout << "chose your action" << endl;
        cout << "1. Add an entry to the directory" << endl;
        cout << "2. Look up a phone number" << endl;
        cout << "3. Look up by first name" << endl;
        cout << "4. Delete an entry from the directory" << endl;
        cout << "5. List All entries in phone directory" << endl;
        cout << "6. Exit form this program" << endl;
        cin >> num;

        if (num == '1'){
            entry.add_entry();
        }
        else if (num== '2'){
            entry.lookup_phone();
        }
        else if (num== '3'){
            entry.lookup_name();
        }
        else if (num== '4'){
            entry.delete_by_name();
        }
        else if (num== '5'){
            entry.sort();
        }
        else if (num== '6'){
            return 0;
        }
        else cout << "please chose a valid number: " << endl;
        }

    while (num != 6);

}
