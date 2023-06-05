#include "bigint.h"
#include <iostream>
#include <string>
using namespace std;


//CLASS FIRST CONSTRUCTER
BigInt::BigInt()
{
    num="";
}

//CLASS SECOND CONSTRUCTER
BigInt::BigInt(string str)
{
    num=str;
}

//A FUNCTION TO REVERSE A STRING
void reverse(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

//CLASS THIRD CONSTRUCTER
BigInt :: BigInt (int dec)
{
    if (dec < 0)
    {
        dec*=-1;

        while ( dec!=0)
    {

        num+=(dec%10)+'0';
        dec-= dec%10;
        dec/=10;

    }
    num+='-';
    }



 else   if (dec == 0)
    {

        num="0";
    }


else if (dec >0 ){
    while ( dec!=0)
    {

        num+=(dec%10)+'0';
        dec-= dec%10;
        dec/=10;

    }
}
    reverse(num);

}

//  FUNCTION TO DELETE LEFT ZEROS
void remove_zeros(string &str)
{
    if (str[0]=='0')
    {
        int i=0;
        while (str[i]=='0')
            i++;

        if (i==(str.length()))
            str.erase(0,i-1);
       else
            str.erase(0,i);
    }

   else if (str[0]=='-'&&str[1]=='0')
    {
       int i=0;
       while (str[i+1]=='0')
            i++;
        if (i==str.length())
            str.erase(1,i-1);
       else
            str.erase(1,i);
    }
}

//FUNCTION TO CHECK THE SIGN
bool check_sign(BigInt &b)
{
    string c="";
    if (b.num[0]=='-')
    {
        for (int i=1; i<b.num.length(); i++)
        {
            c+=b.num[i];
        }
        b.num=c;
        return 1;
    }

    else if(b.num[0]=='+')
    {

        for (int i=1; i<b.num.length(); i++)
        {
            c+=b.num[i];
        }
        b.num=c;
        return 0;

    }
    else
    {
        return 0;
    }


}

//CHECK WHICHIS BIGGER
bool check_bigger(string a, string b)
{
    if (a.length()==b.length())
    {
        for (int i=0; i<a.length(); i++)
        {
            if (a[i]>b[i])
            {

                return 1;
            }
            else if (b[i]>a[i])
            {

                return 0;
            }
        }

    }

}

//CHECK IF EQUAL
bool check_equality(string a, string b)
{

    for (int i=0;i<a.length();i++)
    {
        if (a[i]==b[i])
        {
            continue;
        }
        else
            return 0;

    }

    return 1;
}

//OVERLOADING + OPERATOR
BigInt BigInt::operator+(BigInt b)
{

   if (  num[0]=='-'   &&  (b.num[0]=='+'||(b.num[0]<='9'&&b.num[0]>='0'))  )


    {
        check_sign(*this);
        return b - *this;
    }

    if ((num[0]=='+'||(num[0]<='9'&&num[0]>='0'))       &&      b.num[0]=='-')
    {
        check_sign(b);
        return *this - b;
    }


    if (b.num.length()>num.length())
    {

        bool checker = (check_sign(b)&&check_sign(*this));

        int diff=b.num.length()-num.length();

        BigInt c;
        c.num="";
        c.carry=0;

        for (int i=(num.length()-1); i>=0; i--)
        {

            c.sum=0;
            c.sum=num[i]+b.num[i+diff]-2*'0'+c.carry;
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;
            }
            c.num+=c.sum+'0';

        }
        for (int i=diff-1; i>=0; i--)
        {
            c.sum=0;
            c.sum+=b.num[i]+c.carry-'0';
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;

            }

            c.num+=c.sum+'0';
        }
        if (c.carry>0)
        {
            c.num+=c.carry+'0';
        }

        if (checker)
        {
            c.num+='-';
        }
        reverse(c.num) ;
        return c;

    }


    else if (num.length()>b.num.length())
    {

        bool checker=check_sign(b)&&check_sign(*this);
        int diff=num.length()-b.num.length();
        BigInt c;
        c.num="";
        c.carry=0;

        for (int i=(b.num.length()-1); i>=0; i--)
        {
            c.sum=0;
            c.sum=num[i+diff]+b.num[i]-2*'0'+c.carry;
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;
            }
            c.num+=c.sum+'0';

        }
        for (int i=diff-1; i>=0; i--)
        {
            c.sum=0;
            c.sum+=num[i]+c.carry-'0';
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;

            }
            c.num+=c.sum+'0';

        }

        if (c.carry>0)
        {
            c.num+=c.carry+'0';
        }

        if (checker)
        {
            c.num+='-';
        }
        reverse(c.num) ;
        return c;
    }


    else
    {

        bool checker=check_sign(b)&&check_sign(*this);

        BigInt c;
        c.num="";
        c.carry=0;

        for (int i=(num.length()-1); i>=0; i--)
        {

            c.sum=0;
            c.sum=num[i]+b.num[i]-2*'0'+c.carry;
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;
            }
            c.num+=c.sum+'0';

        }

        if (c.carry>0)
        {
            c.num+=c.carry+'0';
        }

        if (checker)
        {
            c.num+='-';
        }


        reverse(c.num) ;
        return c;

    }
}

//OVERLOADING - OPERATOR
BigInt BigInt::    operator-(BigInt b)
{
    if (b.num[0]=='-'  &&  (num[0]=='+'||(num[0]<='9'&&num[0]>='0')))
    {
        check_sign(b);
        return *this+b;
    }


    else if (num[0]=='-'  &&  (b.num[0]=='+'||(b.num[0]<='9'&&b.num[0]>='0')))
    {

        check_sign(*this);
        return *this + b;

    }

    else if (b.num[0]=='-'&&num[0]=='-')
    {
        check_sign(b);
        check_sign(*this);
        return b- *this;
    }


    if (num.length()>b.num.length())
    {

        int diff = num.length()-b.num.length();
        BigInt c;
        c.num="";
        c.carry=0;
        for (int i=(b.num.length()-1); i>=0; i--)
        {


            c.sum=0;
            c.sum=num[i+diff]-b.num[i]+c.carry;
            c.carry=0;
            if (c.sum<0)
            {
                c.sum+=10;
                c.carry--;
            }
            c.num+=c.sum+'0';


        }

        for (int i=diff-1; i>=0; i--)
        {
            c.sum=0;
            c.sum+=num[i]+c.carry-'0';
            c.carry=0;
            if (c.sum<0)
            {
                c.sum+=10;
                c.carry--;
            }

            c.num+=c.sum+'0';
        }

        reverse(c.num);

        remove_zeros(c.num);
        return c;




    }




    if (b.num.length()>num.length())
    {

        int diff =b.num.length()-num.length();
        BigInt c;
        c.num="";
        c.carry=0;
        for (int i=(num.length()-1); i>=0; i--)
        {


            c.sum=0;
            c.sum=b.num[i+diff]-num[i]+c.carry;
            c.carry=0;
            if (c.sum<0)
            {
                c.sum+=10;
                c.carry--;
            }
            c.num+=c.sum+'0';


        }

        for (int i=diff-1; i>=0; i--)
        {
            c.sum=0;
            c.sum+=b.num[i]+c.carry-'0';
            c.carry=0;
            if (c.sum<0)
            {
                c.sum+=10;
                c.carry--;
            }
            c.num+=c.sum+'0';
        }

        c.num+='-';

        reverse(c.num);
        remove_zeros(c.num);

        return c;




    }

    if (num.length()==b.num.length())
    {
        if (check_equality(num,b.num))
        {
            BigInt c;
            c.num="0";
            return c;
        }

        if (check_bigger(num,b.num))
        {



            BigInt c;
            c.num="";
            c.carry=0;
            for (int i=(num.length()-1); i>=0; i--)
            {


                c.sum=0;
                c.sum=num[i]-b.num[i]+c.carry;
                c.carry=0;
                if (c.sum<0)
                {
                    c.sum+=10;
                    c.carry--;
                }
                c.num+=c.sum+'0';


            }


            reverse(c.num) ;

           remove_zeros(c.num);
            return c;
        }

        else if (check_bigger(b.num,num))
        {

            BigInt c;
            c.num="";
            c.carry=0;
            for (int i=(b.num.length()-1); i>=0; i--)
            {
                c.sum=0;
                c.sum=b.num[i]-num[i]+c.carry;
                c.carry=0;
                if (c.sum<0)
                {
                    c.sum+=10;
                    c.carry--;
                }
                c.num+=c.sum+'0';
            }
            c.num+='-';
            reverse(c.num) ;
            remove_zeros(c.num);

            return c;
        }
    }
}

//OVERLOADING << OPERATOR
ostream& operator<< (ostream& output, BigInt a)
{
    cout<<a.num;
}
//
//RETURN THE LENGTH
int BigInt ::size()
{
    return num.length();
}
