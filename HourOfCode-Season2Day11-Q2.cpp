#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

long long requiredInteger(long long n)
{
    // for storing 32 bit binary number
    int binaryArray[32];

    // initialize array element to 1
    for (int i = 0; i < 32; i++)
        binaryArray[i] = 1;

    vector<int> v;
    int num;
    while (n > 0) // converting it into binary and storing it in as 0->1 and 1->0(remember bits are in reverse order)
    {
        num = n % 2 == 0;
        v.push_back(num);
        n /= 2;
    }

    reverse(v.begin(), v.end()); // reverse the binary vector to get the correct sequence of binary bits
    vector<int>::iterator itr = v.begin();
    // updating the end from (32 - size of v) to 31 with the bits of number n
    for (int i = 32 - v.size(); i < 32; i++, itr++)
        binaryArray[i] = *itr;

    // now converting binary array to decimal number
    long long result = 0;
    for (int i = 0; i < 32; i++)
        result += pow(2, 32 - i - 1) * binaryArray[i];

    return result;
}

int main()
{
    long long n;
    cin >> n;

    cout << requiredInteger(n);

    return 0;
}
