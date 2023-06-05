#include "PhoneDirectory.h"
#include<bits/stdc++.h>
#include <string>
using namespace std;
//CONSTRUCTER
PhoneDirectory::PhoneDirectory(){

}

// SETTER FOR THE FIRST NAME
void PhoneDirectory :: set_first_name(string x){
     first_name = x;

}

//GETTER FOR THE FIRST NAME
string PhoneDirectory :: get_first_name(){

// SETTER FOR THE LAST NAME


    return first_name;
}
void PhoneDirectory :: set_last_name(string x){

//GETTER FOR THE LAST NAME


    last_name = x;
}
string PhoneDirectory :: get_last_name(){

// SETTER FOR THE PHONE NUMBER


    return last_name;
}
void PhoneDirectory :: set_phone_number(string x){

//GETTER FOR THE PHONE NUMBER


    phone_number = x;
}
string PhoneDirectory :: get_phone_number(){
    return phone_number;
}

//FUNCTION TO ADD AN ENTRY TO THE DIRECTORY
void PhoneDirectory ::add_entry(){

    string first, last;
    string phone;

    cout << "enter first name" << endl;
    cin >> first;
    set_first_name(first);
    first_names.push_back(get_first_name());

    cout << "enter last name " << endl;
    cin >> last;
    set_last_name(last);
    last_names.push_back(get_last_name());

    cout << "enter phone number" << endl;
    cin >> phone;
    set_phone_number(phone);
    phone_numbers.push_back(get_phone_number());
}

//FUNCTIONS TO LIST ALL ELEMENTS
void PhoneDirectory::list_all(){
    cout << "all directory: " << endl;
    cout << "first" << "         " << "last" << "         " << "phone" << endl;

    for(int i =0; i < first_names.size(); i++){
            cout << first_names[i] << "         " << last_names[i] << "         " << phone_numbers[i] << endl;
    }

}

//FUNCTION TO SEARCH AN ANTRY BY NAME
void PhoneDirectory::lookup_name(){
    string name;
    cout << "enter first name" << endl;
    cin >> name;
    bool found = 0;
    for (int i=0; i<first_names.size(); i++){
        if (first_names[i] == name){
            cout << "first name : " << first_names[i] << endl;
            cout << "last name : " << last_names[i] << endl;
            cout << "phone number : " << phone_numbers[i]<<endl;
            found = 1;
        }
    }
    if (found == 0){
        cout << "not found!!";
    }
}

//FUNCTION TO SEARCH AN ANTRY BY PHONE
void PhoneDirectory::lookup_phone(){
    string phone;
    cout << "enter phone number" << endl;
    cin >> phone;
    bool found = 0;
    for (int i=0; i<phone_numbers.size(); i++){
        if (phone_numbers[i] == phone){
            cout << "first name : " << first_names[i] << endl;
            cout << "last name : " << last_names[i] << endl;
            cout << "phone number : " << phone_numbers[i]<<endl;
            found = 1;
        }
    }
    if (found == 0){
        cout << "not found!!";
    }
}

//FUNCCTION TO DELETE AN ENTRY BY NAME
void PhoneDirectory::delete_by_name(){
    cout << "enter the first name " << endl;
    string name;
    cin >> name;


    for ( int i=0; i<first_names.size(); i++){
        if (first_names[i] == name){
            first_names[i].erase();
            last_names[i].erase();
            phone_numbers[i].erase();
        }
    }
}

//SORTING FUNCTION USING THE BUBBLE SORT
void PhoneDirectory::bubble_sort(){
    string temp1, temp2,temp3;
    for(int i=0; i< first_names.size()-1; i++){
        for(int j=0; j < (first_names.size()-i-1); j++){
            if( first_names[j] > first_names[j+1] ) {
                temp1 = first_names[j];
                first_names[j] = first_names[j+1];
                first_names[j+1] = temp1;

                temp2 = last_names[j];
                last_names[j] = last_names[j+1];
                last_names[j+1] = temp2;

                temp3 = phone_numbers[j];
                phone_numbers[j] = phone_numbers[j+1];
                phone_numbers[j+1] = temp3;
            }
        }
    }
    list_all();


}

//SORTING FUNCTION USING THE INSERTION SORT
void PhoneDirectory::insertion_sort(){

    for(int i=1;i<first_names.size();i++){
       string key1 = first_names[i];
       string key2 = last_names[i];
       string key3 = phone_numbers[i];
       int j = i-1;

       while (j>=0 && first_names[j] > key1){
            first_names[j+1] = first_names[j];
            last_names[j+1] = last_names[j];
            phone_numbers[j+1] = phone_numbers[j];
            j = j-1;
       }
       first_names[j+1] = key1;
       last_names[j+1] = key2;
       phone_numbers[j+1] = key3;
    }
    list_all();
}

//SORTING FUNCTION USING THE SELECTION SORT
void PhoneDirectory::selection_sort(){
    for(int i=0; i<first_names.size()-1; i++){
        int min = i;
        for (int j = i+1; j < first_names.size(); j ++){
            if (first_names[j] < first_names[min]) min = j;
            string temp1,temp2,temp3;

            temp1 = first_names[i];
            first_names[i] = first_names[min];
            first_names[min] = temp1;

            temp2 = last_names[i];
            last_names[i] = last_names[min];
            last_names[min] = temp2;

            temp3 = phone_numbers[i];
            phone_numbers[i] = phone_numbers[min];
            phone_numbers[min] = temp3;
        }
    }
    list_all();
}

// FUNCTION TO CHOSE WHICH SORTING METHOD YOU WANT
void PhoneDirectory::sort(){
    cout << "which sort method you want? " << endl;
    cout << "1- bubble , 2- insertion, 3- selection " << endl;
    string x;

        cin >> x;
        if (x == "1" || x == "bubble") bubble_sort();
        else if (x == "2" || x == "insertion") insertion_sort();
        else if (x == "3" || x == "selection") selection_sort();
        else
            cout << "please chose a valid entry";

    }

