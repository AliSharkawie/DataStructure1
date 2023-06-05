#ifndef PHONEDIRECTORY_H
#define PHONEDIRECTORY_H
#include<bits/stdc++.h>
#include <string>
using namespace std;


class PhoneDirectory
{
    public:
        PhoneDirectory();
        void set_first_name(string);
        void set_last_name(string);
        void set_phone_number(string);
        string get_first_name();
        string get_last_name();
        string get_phone_number();

        void add_entry();
        void lookup_name();
        void lookup_phone();
        void delete_by_name();
        void list_all();
        void bubble_sort();
        void insertion_sort();
        void selection_sort();
        void sort();

// VECTORS AS CONTAINERS
        vector <string> first_names;
        vector <string> last_names;
        vector <string> phone_numbers;


    private:
        string first_name;
        string last_name;
        string phone_number;
};

#endif
