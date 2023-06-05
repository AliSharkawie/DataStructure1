#include"matrixcalculator.h"
void matrixcalculator::menu()
{
    cout<<"welcome to matrices calculator \n";
    char mark;
    while(true)
    {
        cout<<"please enter the operation you want to calculate (+,-,*,T(transpose)) or (0) to exit: ";

        if(mark=='0')
        {
            cout<<"there is some mistake ...\n";
            cout<<"Please try again\n";
            break;
        }
        cout<<"Enter the dimentions of the matrix (rows,columns): ";
        int x,y;
        cin>>x>>y;
        matrix<int>matrix1(x,y);
        cout<<"Enter matrix elements\n";
        cin>>matrix1;
        if(mark=='+')
        {
            cout<<"Enter the dimentions of another matrix: ";
            cin>>x>>y;
            matrix<int>matrix2(x,y);
            cout<<"Enter another matrices elements\n";
            cin>>matrix2;
            matrix<int> result=(matrix1+matrix2);
            cout<<"the result of the addition of the matrices = "<<result;

        }
        else if(mark=='-')
        {

            cout<<"Enter the dimentions of the another matrix: ";
            cin>>x>>y;
            matrix<int>matrix2(x,y);
            cout<<"Enter the another matrix elements\n" ;
            cin>>matrix2;
            matrix<int> result=matrix1-matrix2;
            cout<<"The result of the subtraction of the matrices = \n"<<result;


        }
        else if(mark=='*')
        {
            cout<<"Enter the dimentions of the another matrix: ";
            cin>>x>>y;
            matrix<int> matrix2(x,y);

            cout<<"Enter the another matrix elements\n";
            cin>>matrix2;
            matrix<int> result=(matrix1*matrix2);
            cout<<"The result of maltiplication of two matrices= ";

        }
        else if(mark=='t' || mark=='T')
        {
            matrix<int> result=transpose(matrix1);
            cout<<"matrix after transposing= \n";
        }
        else
        {
            cout<<"not found\n";
        }
    }

}

