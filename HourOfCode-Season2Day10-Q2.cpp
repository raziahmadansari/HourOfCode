#include <iostream>

/*
 *input: n=148 k=3
 *output: 3
 *
 *
 *input: n=12 k=3
 *output: 9
 */

 /*
  *CONCEPT
  *n=148 k=3
  *
  *excellentDigit=excellentDigit(sumOfDigits(148148148))
  *excellentDigit=excellentDigit(sumOfDigits(148) * k)
  *excellentDigit=excellentDigit(13 * 3)
  *excellentDigit=excellentDigit(39)
  *
  *since 39 not less than 10 (or single digit)
  *excellentDigit=excellentDigit(sumOfDigits(39))
  *excellentDigit=excellentDigit(12)
  *
  *12 is also not less than 10
  *excellentDigit=excellentDigit(sumOfDigits(12))
  *excellentDigit=3
  *
  *since 3 is less than 10
  *so excellent digit= 3
  */

/*
 *n=12 k=3
 *p=121212
 *sum=(1+2)*3    or sumOfDigits(n) * k
 *sum=9
 *
 *since 9 is less than 10
 *so excellent digit = 9
 */

using namespace std;

int sumOfDigits(int n)
{
    int remainder;
    int sum = 0;
    while (n > 0)
    {
        remainder = n % 10;
        sum += remainder;
        n /= 10;
    }

    return sum;
}

int excellentDigit(int n)
{
    if (n < 10)
        return n;
    excellentDigit(sumOfDigits(n));
}

int main()
{
    int n, k;
    cin >> n >> k;

    cout << excellentDigit(sumOfDigits(n) * k);

    return 0;
}
