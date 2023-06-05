#ifndef BIGINT_H
#define BigInt_H
#include <iostream>
#include <string>
using namespace std;

class BigInt
{
public:
    string num;
    int sum, carry;

    BigInt(string decstr);
    BigInt(int decint);
    BigInt();

    BigInt operator+(BigInt);
    BigInt operator-(BigInt);
    friend ostream& operator<< (ostream&, BigInt);

    friend bool check_sign(BigInt &);
    friend bool check_equality(string , string );
    friend bool check_bigger(string , string );
    friend void remove_zeros(string &);
    int size();

};

#endif
