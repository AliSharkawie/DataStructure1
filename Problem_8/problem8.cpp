//alie
//	ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;

#include <iostream>
#include <chrono>
using namespace std ;
using namespace std::chrono ;
#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
template <class T >
void insertion (T arr[],int size)
{
	for (int i=1 ; i<size ;i++) // time = n  //
		{
			T temp = arr[i] , j = i ;
			for ( ; j>0 && temp<arr[j-1];) // time = n  //
			{
				arr[j] = arr[j-1] ;
				j-- ;

			}
			arr[j] = temp ;
		}
	// total time = n*n //
}
template <class T >
int binaryS(T arr[],int left, int right, int element)
{
    if (right <= left)   // base case
        if (element > arr[left])
        	return left + 1 ;
        else
        	return left ;

    int mid = (left + right) / 2;

    if (element == arr[mid])
        return mid + 1;             //not base case for my func but this stop point if arr[i]== element
 									// so we can shifting from after mid
    if (element > arr[mid])
        return binaryS(arr , mid + 1,right ,element); // recursion
    else
    	return binaryS(arr, left ,mid - 1,element);  // recursion

    // time = log (n)
}
template <class T >
void insertionSort_binary(T arr[], int size)
{
    int i, pos, j ;
    T temp;

    for (i = 1; i < size; ++i) // time = n
    {
        j = i - 1;
        temp = arr[i];

        pos = binaryS(arr, 0, j , temp); // time = log( n )
        while (j >= pos)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    // total time = nlog(n)
}
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void print (T arr[],int size)
{
	for (int i=0 ;i<size ;i++)
		cout << arr[i]  << " ";
	cout << endl ;
}

int main()
{
    cout << "for normal insertion \n " ;
    int n ;
   // int arr[10] = {8,5,2,7,4,1,9,6,3,10} ;
    for (int i=0 ; i<4 ;i++ )
        {
       // int n ;
        cin >> n ;
        auto f =[]() -> int { return rand() % 10000 ;} ;
        int * ptr = new int[n] ;
        generate(ptr,ptr+n , f ) ;
        auto start = high_resolution_clock::now() ;

        insertion(ptr , n) ;

        auto stop = high_resolution_clock::now() ;

        auto duration = duration_cast<microseconds>(stop - start) ;

        cout << duration.count() << "  microSeconds \n " << endl ;

        }

        cout << " \n \n for binary insertion Sort \n " ;
    for (int i=0 ; i<4 ;i++ )
        {
        //int n ;
        cin >> n ;
        auto f =[]()-> int { return rand() % 10000 ;} ;
        int * ptr = new int[n] ;
        generate(ptr,ptr+n , f ) ;
        auto start = high_resolution_clock::now() ;

        insertionSort_binary(ptr , n) ;

        auto stop = high_resolution_clock::now() ;

        auto duration = duration_cast<microseconds>(stop - start) ;

        cout << duration.count() << "  microSeconds \n" << endl;
        }

//	print(arr,n) ; // for static array

    return 0 ;
}

