#include<iostream>
#include<string>

using namespace std;
template<class T>
class matrix
{
public:


    T **arr;
    int row ,col;

    //default constructor
    matrix(int row1,int col1,T** a);

    //parameterize constructor
    matrix(int row,int col);

    //copy constructor
    matrix(const matrix<T> &copy1);

    //function allow user input
    template<class T2>
    friend istream& operator>>(istream &in, matrix<T2> &input);


    //function allow user output
    template<class T2>
    friend ostream& operator<< (ostream &out ,const matrix<T> &output);

    //function to add element to a matrix
    matrix<T> operator+(T element);

    //function to subtract element from a matrix
    matrix<T>operator-(T element);

    //function to multiply element to a matrix
    matrix<T> operator*(T element);

    //function to add matrix to another one
    matrix<T> operator+(matrix<T> &add_m);

    //function to subtract matrix from another  matrix
    matrix<T> operator-(matrix<T> &sub_m);

    //function to muliply matrix into another matrix
    matrix<T> operator*(matrix<T> &multi_m);

    //function to transpose a function
    matrix<T> &transpose(matrix<T> &trans_m);


    ~matrix();



};
