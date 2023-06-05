#include "Fraction.h"
#include <iostream>
#include <list>
using namespace std ;
Fraction::Fraction()
{
	x=0 ; y=0 ;
}
Fraction::Fraction(int up , int down )
{
	x = up ; 
	y = down ;
}
Fraction::Fraction(const Fraction & obj )
{
	x = obj.x ;
	y = obj.y ;
}
Fraction Fraction::operator-(const Fraction & obj )
{

	int up =  x * (obj.y)-y * (obj.x);
	int down = y * obj.y ; 
	Fraction result(up , down ) ;
	//l.ADD(result) ;
	result.reduce();
	return result ;
}
Fraction Fraction::operator+ (const Fraction & obj )
{
	int up =  x * (obj.y) +  y * (obj.x);
	int down = y * obj.y ; 
	Fraction result(up , down ) ;
	//l.ADD(result) ;
	result.reduce();
	return result ;
}
Fraction Fraction::operator*(const Fraction &obj )
{
	Fraction result((x*(obj.x)),(y*(obj.y))) ;
	//l.ADD(result) ;
	result.reduce();
	return result ;
}
Fraction Fraction::operator/(const Fraction &obj )
{
	int up = x*(obj.y) ;
	int down = y*(obj.x);
	Fraction result( up , down); 
	//l.ADD(result) ;
	result.reduce();
	return result ;
}
bool Fraction::operator>(const Fraction &obj)
{
	int up = x*(obj.y) ;
	int down = y*(obj.x);

	if (up>down)
		return true ;
	else return false ;
}
bool Fraction::operator<(const Fraction &obj)
{
	int up = x*(obj.y) ;
	int down = y*(obj.x);

	if (up>down)
		return false ;
	else 
		return true ; 
}
bool Fraction::operator>=(const Fraction &obj )
{
	if (*this > obj || *this == obj)
		return true ;
	else 
		return false ;
}
bool Fraction::operator<=(const Fraction &obj )
{	
	if (*this < obj || *this == obj)
		return true ;
	else 
		return false ;
		
}
bool Fraction::operator==(const Fraction &obj )
{
	if (x== obj.x && y==obj.y)
		return true ;
	else 
		return false ;
}
void Fraction::reduce()
{
	if(x==y)
	{
		x=1 ;
		y=1 ;
	}
	else if (x>y)
	{
		if (x%y==0)
		{
			y = 1 ;
			x = x/y ;
		}
		else 
		{
			int i = y ; 
			while (y>0 && i>1)
			{
				if (y%i==0 && x%i==0)
					{
						x =x/i ;
						y= y/i ;
					}
				i-- ;
			}
		}
	}
	else 
	{
		if (y%x==0)
		{
			x = 1 ;
			y = y/x ;
		}
		else 
		{
			int i = x ; 
			while (x>0 && i>1)
			{
				if (x%i==0 && y%i==0)
					{
						x =x/i ;
						y= y/i ;
					}
				i-- ;
			}
		}
	}
	
	//l.ADD(*this) ;
}
ostream& operator<<(ostream & os , const Fraction &obj ) 
{
	if (obj.x == obj.y)
	{
		os << 1 << endl ;
		return os ;
	}
	os << obj.x << "/" << obj.y << endl ;
	return os ;
}
istream& operator>>(istream & is , Fraction &obj ) 
{
	char c ;
	is >> obj.x ;
	cin >> c ;
	is>> obj.y ; 
	return is ;
}
/*
void Fraction::print_results() 
{
	l.printList();
}*/	

int Fraction::getX(){return x ;}
int Fraction::getY(){return y ;}
void Fraction::setX(int num){x=num ;}
void Fraction::setY(int num){y=num ;}
Fraction::~Fraction()
{
	
}
