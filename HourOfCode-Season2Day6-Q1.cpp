#include <iostream>
#include <algorithm>

using namespace std;

int findMedian(int a[], int n)
{
    sort(a, a + n);

    if (n % 2 != 0)
        return a[n / 2];

    return (a[(n - 1) / 2] + a[n / 2]) / 2;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << findMedian(arr, i + 1) << endl;
    }
}
