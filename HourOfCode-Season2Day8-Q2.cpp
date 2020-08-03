#include <iostream>

using namespace std;

int optimalStrategyOfGame(int* arr, int n)
{
    int table[n][n];

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            int x = ((i + 2) <= j) ? table[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
            int z = (i <= (j - 2)) ? table[i][j - 2] : 0;

            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }

    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << table[i][j] << " ";
        cout << endl;
    }*/

    return table[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << optimalStrategyOfGame(arr, n);

    return 0;
}
