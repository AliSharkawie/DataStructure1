//alie
//	ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;

#include <iostream>
#include<chrono>
using namespace std ;
using namespace std::chrono ;
#include <bits/stdc++.h>
#include<algorithm>


///////////////////////////////////////////////////
void print (int arr[],int size)
{
	for (int i=0 ;i<size ;i++)
		cout << arr[i]  << " ";
	cout << endl ;
}
//////////////////////////////////////////////////

class Sorter
{
	public :
		virtual void sort(int arr[] ,int size) {}
		virtual ~Sorter(){}
	//	friend class Testbed ;
};

class QuickSorter : public Sorter
{
/*	T *arr ;
	int size ;
*/
	public :
/*	QuiqSorter(T * arrIN ,int sizeIN)
	{
		arr = arrIN ;
		size =sizeIN ;
	}
*/
	void sort(int arr[] , int size )
	{
		int left = 0 ;int right =size ;
		quick( arr, left , right ) ;
	}
	int partition(int arr[] , int left , int right )
	{
			int pivot= arr[left] ;
			int i = left ;
			for (int j= left + 1 ; j< right ; j++ )
			{
				if (arr[j]<pivot)
				{
					i++ ;
					swap(arr[i],arr[j]) ;
				}

				swap(arr[i], arr[left] );
			}
			return i ;
	}
	void quick(int arr[] , int left , int right )
	{
		if(left<right)
		{
			int pivot = partition(arr,left,right) ;
			quick (arr,left,pivot-1) ;
			quick (arr , pivot +1 , right ) ;

		}
		//else return -1;
	}
};

class SelectionSorter: public Sorter
{
	int * ptr ;
	int size ;
	public:
		void sort(int arr[] , int size )
		{
			for (int i=0 ; i<size-1 ; i++)
			{
				//T minimum = arr[i] ;
				int key = i ;
				for (int j=i+1 ; j<size ; j++ )
				{
					if (arr[j] < arr[key]) //replace:  arr[key] -> minimum
						key = j  ;		   //replace:  minimum -> arr[j] ;
				}
				swap(arr[i],arr[key]) ;    //replace:  arr[key] -> minimum
			}
		}

};

class Testbed
{
	Sorter SORT ;
	QuickSorter QS ;
//	int* arr ;
public :
	int* GenerateRandomList(int min, int max, int size)
	{
		int * arr = new int [size] ;
		for (int i=0 ; i<size ;i++)
		{
			arr[i] = (rand() % max) + min ;
		}
		return arr ;
	}
	int * GenerateReverseOrderedList(int min,int  max, int size)
	{
		int * arr = GenerateRandomList(min,max,size) ;
		QS.sort(arr,size) ;
		reverse( arr, arr+size) ;
//		arr =arrIN ;
		return arr ;
	}
	auto RunOnce(Sorter * S, int *data,int  size)// Sorter S
	{
		auto start = high_resolution_clock::now();

        S->sort(data,size);

        auto stop = high_resolution_clock::now() ;

        auto duration = duration_cast<microseconds>(stop - start) ;

        return  (duration.count());
	}
	auto RunAndAverage(Sorter * S,int type ,int min,int  max,int size,int sets_num)
	{
		auto sum = 0 ;
		if(type==1)
		{
		    int * cycle , *arr;
			arr = cycle =GenerateReverseOrderedList( min,max,size);//arr =sorted reverse array
			for (int i=0 ;i<sets_num ;i++)
			{
				sum+= RunOnce( S , arr , size) ;
				arr = cycle ;
			}
			return sum/sets_num ;
		}
		else
		{
			int * cycle ,*arr ;
			arr = cycle =GenerateRandomList(min,  max,  size); // arr = random array
			//S->sort(arr,size) ; // make array sorted
			//cycle = arr ;
			for (int i=0 ;i<sets_num ;i++)
			{
		        sum+= RunOnce( S , arr , size) ;
		        arr = cycle ;
			}
			return sum/sets_num ;
		}
	}
void RunExperient (Sorter *S, int type,int min, int max,int  min_val, int max_val,int sets_num, int step)
{
    while (min_val<=max_val)
    {

        auto time = RunAndAverage( S,type, min, max,min_val,sets_num) ;

        cout << min_val << "\t \t" << time << endl ;
        min_val += step ;
    }
}

};

int main()
{
//	int TestArray[7]={80,90,60,30,50,70,40} ;
/*	SelectionSorter<int> s ;
	s.sort(TestArray,7) ;
//    SelectionSorter *s ;*/
//	Sorter * S = new SelectionSorter ;
//	Testbed test ;
//	int * arr  ;
//	arr = test.GenerateRandomList(1,100,100) ;
    Sorter * S = new SelectionSorter ;
	Testbed test ;
	cout << " type 0 random \n " ;
	test.RunExperient(S , 0 , 1, 100 , 1 , 1601 , 5 , 100);
	cout <<"_______________________________________________________\n" ;
	cout << " type 1 sorted reverse \n " ;
	test.RunExperient(S , 1 , 1, 100 , 1 , 1601 , 5 , 100);



//	cout << test.RunOnce( S , arr ,100) << endl ;
//	print(arr,100) ;
	return 0 ;
}

