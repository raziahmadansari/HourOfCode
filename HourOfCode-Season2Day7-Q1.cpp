#include <iostream>
#include <math.h>

using namespace std;

int checkRecursive(int x, int n, int curr_num = 1, int curr_sum = 0)
{
    int result = 0;
    int p = pow(curr_num, n);
    while (p + curr_sum < x)
    {
        result += checkRecursive(x, n, curr_num + 1, p + curr_sum);
        curr_num++;
        p = pow(curr_num, n);
    }

    if (p + curr_sum == x)
        result++;

    return result;
}

int main()
{
    int x, n;
    cin >> x >> n;

    cout << checkRecursive(x, n);

    return 0;
}
