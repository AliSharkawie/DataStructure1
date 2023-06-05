#include <iostream>
#include "BigInt.h"
#include <string>
using namespace std;

int main()
{


    BigInt num1("123456789012345678901234567890");
    BigInt num2("113456789011345678901134567890");
    BigInt sum1 = num2 + num1;
    BigInt sum2 = num2 - num1;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num2 + num1 = " << sum1 << endl;
    cout << "num2 - num1 = " << sum2 << endl;

    cout << endl;

    BigInt num3("4545454545454545454545454545454545");
    BigInt num4("2323232323232323232323232323232323");
    BigInt sum3 = num3 + num4;
    BigInt sum4 = num3 - num4;
    cout << "num3 = " << num3 << endl;
    cout << "num4 = " << num4 << endl;
    cout << "num3 + num4 = " << sum3 << endl;
    cout << "num3 - num4 = " << sum4 << endl;

}
