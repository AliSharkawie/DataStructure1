#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <list>
using namespace std ;
class Fraction
{
	private:
		int x , y ;
////////////////////////////////////////////////////////////////////
	public:
	/*	template <class T>
		class linked_list 
		{
			struct node 
			{
				T item ;
				node * next ;
			};
			node * first  ;
			node * last ;
			
		public :
			int length ; 
			linked_list ()
			{
				length = 0 ;
				first = last = NULL ;
			}
			bool isEmpty ()
			{
				return (length==0) ;
			}
			void ADD(T element )
			{
				node * newN ;
				newN = new node ;
				newN -> item = element ;
				
				if (isEmpty())
				{
					first = last = newN ;
					newN->next = NULL ;
				}
				else 
				{
					last->next = newN ;
					newN->next = NULL ;
					last = newN ;
				}
				length ++ ;
			}
			void printList() 
			{
				node * cur = new node ;
				cur = first ;
				
				while (cur!=NULL)
				{
					cout << cur->item << " " ;
					cur = cur->next ;
				} 
				cout << endl ; 
			}
		};
		linked_list<Fraction> l ;
		*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////
		Fraction();
		Fraction(int up , int down );
		Fraction(const Fraction & obj ) ;
		Fraction operator-(const Fraction & obj ) ;
		Fraction operator+(const Fraction & obj );
		Fraction operator*(const Fraction &obj );
		Fraction operator/(const Fraction &obj ) ;
		bool operator>(const Fraction &obj ) ;
		bool operator<(const Fraction &obj ) ;
		bool operator>=(const Fraction &obj ) ;
		bool operator<=(const Fraction &obj ) ;
		bool operator==(const Fraction &obj ) ;
		void reduce() ;
		friend ostream& operator<<(ostream &os , const Fraction & obj) ;
		friend istream& operator>>(istream &is , Fraction & obj) ;	
	//	void print_results();	
		void setX(int num) ;
		void setY(int num) ;
		int getX();
		int getY();	
		~Fraction();
};

#endif
