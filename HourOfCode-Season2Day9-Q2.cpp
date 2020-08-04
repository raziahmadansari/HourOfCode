// HourOfCode-Season2Day9-Q2
#include <iostream>
#include <algorithm>
#include <vector>

/*
 *n = 3, k = 3
 *2 5 6
 *output = 13

 *n = 4, k = 3
 *1 2 3 4
 *output = 11
*/

using namespace std;

bool cmp(int& a, int& b)
{
    return a > b;
}

int minPrice(vector<int>& v, int n, int k)
{
    // sort in descending order
    sort(v.begin(), v.end(), cmp);

    int prevBought = n / k;
    int leftToffees = n % k;

    int price = 0;

    for (int i = 0; i < n - leftToffees; i++)
        price += v[i];

    // remove the bought toffees
    v.erase(v.begin(), v.end() - leftToffees);

    for (int i = 0; i < leftToffees; i++)
        price += v[i] * (1 + prevBought);

    return price;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    cout << minPrice(v, n, k);

    return 0;
}
