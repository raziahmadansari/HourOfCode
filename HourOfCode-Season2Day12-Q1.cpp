#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int minSquare(int n)
{
    /**THIS METHOD IS NOT 100% CORRECT**/
    /*cout << "value of square - " << square << endl;
    int root = sqrt(n);
    cout << "value of root = " << root << endl;
    if (root * root == n)
    {
        square++;
        return square;
    }
    return minSquare(n - root * root, square + 1);*/

    /**using Dynamic Programming**/
    if (n <= 3) //basic case (this is not necessary, did this just for optimization)
        return n;

    int* dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= n; i++)
    {
        // maximum value is i as i is written i times as 1*1 + 1*1 + ...
        dp[i] = i;
        for (int j = 1; j <= ceil(sqrt(i)); j++)
        {
            int temp = j*j;
            if (temp > i)
                break;
            else
                dp[i] = min(dp[i], dp[i - temp] + 1);            
        }
    }

    int result = dp[n];
    delete[] dp;    // free up the memory which is dynamically assinged
    return result;
}

int main()
{
    int n;
    cin >> n;

    cout << minSquare(n);

    return 0;
}
