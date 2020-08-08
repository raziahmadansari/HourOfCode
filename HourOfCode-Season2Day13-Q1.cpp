#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

// sort in decreasing order based on max difference
bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return (fabs(a.first - a.second) > fabs(b.first - b.second));
}

int maxTip(vector<pair<int, int> >& v, int n, int x, int y)
{
    sort(v.begin(), v.end(), cmp);
    int tip = 0;
    for (int i = 0; i < n; i++)
    {
        if ((x > 0) && ((v[i].first >= v[i].second) || y == 0))
        {
            tip += v[i].first;
            x--;
        }
        else if ((y > 0) && ((v[i].first < v[i].second) || x == 0))
        {
            tip += v[i].second;
            y--;
        }
    }
    return tip;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    int temp;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v[i].first = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v[i].second = temp;
    }

    cout << maxTip(v, n, x, y);

    return 0;
}