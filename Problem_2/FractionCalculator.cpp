#include "FractionCalculator.h"

FractionCalculator::FractionCalculator()
{
	char action ='j';
	while (action!='0')
	{
	cout << "enter first fraction  or 0/0 to Terminate  \n " ;
	cin >> f1 ;
	if (f1.getX()==0) 
		break ;
	cout << "\n cout enter second fraction \n " ;
	cin >> f2 ;
	cout << " \n  enter operator \n " ;
	cin >> action ;
	Fraction f3 ;
	if (action=='+')
	{
		f3 = f1+f2 ;
		cout << f3 << "\n" ;
		saved.push_back(f3) ;
	}
	else if (action=='-')
	{
		f3 = f1-f2 ;
		cout << f3 << "\n" ;
		saved.push_back(f3) ;
	}
	else if (action=='*')
	{
		f3 = f1*f2 ;
		cout << f3 << "\n" ;
		saved.push_back(f3) ;
	}
	else if (action=='/')
	{
		f3 = f1/f2 ;
		cout << f3 << "\n" ;
		saved.push_back(f3) ;
	}
	if (action=='==')
	{
		if (f1==f2)
			cout << " yes f1 = f2 \n " ;
		else 
			cout << " no  != f2 \n " ;
	}
	if (action=='>=')
	{
		if (f1>=f2)
			cout << " yes f1 >= f2 \n " ;
		else 
			cout << " no f1 < f2 \n " ;
	}
	if (action=='<=')
	{
		if (f1<=f2)
			cout << " yes f1 <= f2 \n " ;
		else 
			cout << " no f1 > f2 \n " ;
	}
	if (action=='>')
	{
		if (f1>f2)
			cout << " yes  f1 > f2 \n " ;
		else 
			cout << " no f1 < f2 \n " ;
	}
	if (action=='<')
	{
		if (f1< f2)
			cout << " yes f1 < f2 \n " ;
		else 
			cout << " no f1 > f2 \n " ;
	}
	
	
	}
}
void FractionCalculator::viewResults()
{
	for (int i=0 ;i<saved.size() ;i++)
		cout << saved[i] << "  " ;
}
FractionCalculator::~FractionCalculator()
{
}
