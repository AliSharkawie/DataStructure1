#include<iostream>
#include"Matrix.h"

template<class T>
matrix<T>::matrix(int row1,int col1,T** a)
{
    row1=0;
    col1=0;
    this->a= NULL;
    cout<<"welcome to calculation matrix"<<endl;
}
//parameterize constructor
template<class T>
matrix<T>::matrix(int row,int col)
{
    this->row=row;;
    this->col=col;
    arr=new T* [row];
    for(int i=0;i<row;i++)
        arr[i]=new T[col];

}
//copy constructor
template<class T>
matrix<T>::matrix(const matrix<T> & copy1)
{
    row=copy1.row;
    col=copy1.col;
    arr=new T* [row];

    for(int i=0;i<row;i++)
    {
        arr[i]=new T[col];

    }
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
    {
        arr[i][j]=copy1.arr[i][j];
    }
}
template<class T2>
istream& operator>> (istream& in, matrix<T2>& input)
{
    in >> input.row >> input.col;

    input.arr = new T2*[input.row];

    for (int i = 0; i < input.row; i++)
        input.arr[i] = new T2[input.col];

    for (int i = 0; i < input.row; i++)
        for (int j = 0; j < input.col; j++)
            in >> input.arr[i][j];

    return in;
}

template<class T2>
ostream& operator<< (ostream& out, const matrix<T2>& output)
{

    for (int i = 0; i < output.row; i++)
    {

        for (int j = 0; j < output.col; j++)
            out << output.arr[i][j] << "  ";
    }
    out << endl << endl;

    return out;
}

template <class T>
matrix<T>matrix<T>::operator+(T element)
{
    matrix<T> m(row,col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            m.arr[i][j] = 0;


    for (int i = 0; i <m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            m.arr[i][j] = (arr[i][j] + element);
        }
    }
    return m;
}

template <class T>
matrix<T>matrix<T>::operator-(T element)
{
    matrix<T> m(row,col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            m.arr[i][j] = 0;


    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            m.arr[i][j] = (arr[i][j] - element);
        }
    }
    return m;
}
template <class T>
matrix<T>matrix<T>::operator*(T element)
{

    matrix<T> m(row,col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            m.arr[i][j] = 0;


    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            m.arr[i][j] = (arr[i][j] * element);
        }
    }
    return m;

}


template<class T>
matrix<T>matrix<T>::operator+( matrix<T> & add_m)
{
    matrix<T> m(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            m.arr[i][j] = 0;

    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            m.arr[i][j] = arr[i][j] + add_m.arr[i][j];
        }
    }
    return m;
}
template<class T>
matrix<T>matrix<T>::operator-(matrix<T> &sub_m)
{
    matrix<T> m(row,col);
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        m.arr[i][j]=0;

    for(int i=0;i<m.row;i++)
    {
        for(int j=0;j<m.col;j++)
        {
            m.arr[i][j]=(arr[i][j] - sub_m.arr[i][j]);
        }
    }
    return m;

}
template<class T>
matrix<T>matrix<T>::operator*(matrix<T> &malti_m)
{
    matrix<T> m(row,col);
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        m.arr[i][j]=0;
    for(int i=0;i<m.row;i++)
    {
        for(int j=0;j<m.col;j++)
        {
            m.arr[i][j]=(arr[i][j]*malti_m.arr[i][j]);
        }
    }
    return m;
}
template<class T>
matrix<T>& transpose(matrix<T>& trans_m)
{
    matrix<T> m(trans_m.col,trans_m.row);

    for (int i = 0; i < m.row; i++)
        for (int j = 0; j < m.col; j++)
            trans_m.arr[i][j] = m.arr[j][i];
    for (int i = 0; i < m.row; i++)
        for (int j = 0; j < m.col; j++)
            m.arr[i][j] = trans_m.arr[i][j];

    return m;
}
template<class T>
matrix<T>::~matrix()
{
    delete arr;
}







