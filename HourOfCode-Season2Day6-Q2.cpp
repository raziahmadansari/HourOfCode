#include <iostream>

using namespace std;

int maxCircularSum(int a[], int n)
{
    if (n == 1)
        return a[0];

    int sum = 0;
    // calculate total sum of the array
    for (int i = 0; i < n; i++)
        sum += a[i];

    int curr_max = a[0];
    int max_so_far = a[0];
    int curr_min = a[0];
    int min_so_far = a[0];

    for (int i = 1; i < n; i++)
    {
        curr_max = max(curr_max + a[i], a[i]);
        max_so_far = max(max_so_far, curr_max);

        curr_min = min(curr_min + a[i], a[i]);
        min_so_far = min(min_so_far, curr_min);
    }

    if (min_so_far == sum)
        return max_so_far;

    return max(max_so_far, sum - min_so_far);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxCircularSum(arr, n);

    return 0;
}
