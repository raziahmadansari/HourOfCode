#include <iostream>

using namespace std;

const long long mod = 10e9 + 7;

long long nthTerm(int n)
{
    if (n <= 2)
    {
        if (n % 2 == 0)
            return 1;
        else
            return 0;
    }
    return (nthTerm(n - 2) % mod + nthTerm(n - 3) % mod) % mod;
}

int main()
{
    int n;
    cin >> n;

    cout << nthTerm(n);

    return 0;
}