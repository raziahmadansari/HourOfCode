#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second < b.second;
}

int findLongestChain(vector<pair<int, int> >& v)
{
    if (v.size() == 0)
        return 1;

    // sort the vector based on second value
    sort(v.begin(), v.end(), cmp);

    int count = 1;
    int min = v[0].second;
    for (int i = 1; i < v.size(); i++)
    {
        // cout << "min = " << min << endl;
        if (min < v[i].first)
        {
            count++;
            min = v[i].second;
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    cout << findLongestChain(v);

    return 0;
}