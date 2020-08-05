#include <iostream>
#include <string>

/*
 *input: 16
 *output: 23
*/

/*
 *THEORY BEHIND IT
 *Example : num = "1234"
 *sumofdigit[0] = 1 = 1
 *sumofdigit[1] = 2 + 12  = 14
 *sumofdigit[2] = 3 + 23  + 123 = 149
 *sumofdigit[3] = 4 + 34  + 234 + 1234  = 1506
 *Result = 1670

 *For above example,
 *sumofdigit[3] = 4 + 34 + 234 + 1234
           = 4 + 30 + 4 + 230 + 4 + 1230 + 4
           = 4*4 + 10*(3 + 23 +123)
           = 4*4 + 10*(sumofdigit[2])
 *In general,
 *sumofdigit[i]  =  (i+1)*num[i] + 10*sumofdigit[i-1]
*/

const unsigned long long Modulo = 10e9 + 7;

using namespace std;

int toDigit(char ch)
{
    return (ch - '0');
}

int sumOfSubstrings(string str)
{
    int length = str.length();

    // create array of size "length"
    int sumOfDigits[length];

    // initializing the first element to str[0]
    sumOfDigits[0] = toDigit(str[0]);
    int prevSum = sumOfDigits[0];

    // traversing each digit
    for (int i = 1; i < length; i++)
    {
        int currentNum = toDigit(str[i]);

        // updating sumOfDigits from prevSum
        sumOfDigits[i] = (i + 1)*currentNum + 10*sumOfDigits[i - 1];

        // prevSum += sumOfDigits[i];
        // did this to handle large integers (overcome buffer overflow)
        prevSum = ((prevSum % Modulo) + (sumOfDigits[i] % Modulo)) % Modulo;
    }

    return prevSum;
}

int main()
{
    string str;
    cin >> str;

    cout << sumOfSubstrings(str);

    return 0;
}
