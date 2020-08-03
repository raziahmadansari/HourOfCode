#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int> b)
{
    return a.second < b.second;
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

    sort(v.begin(), v.end(), cmp);


    int diff;
    int max_difference = 0;
    int prev_element = v[0].first;
    int next_element = v[1].first;

    for (int i = 0; i < n -1; i++)
    {
        diff = (v[i].second > v[i + 1].second)? v[i].second - v[i + 1].second : v[i + 1].second - v[i].second;
        if (diff > max_difference)
        {
            prev_element = v[i].first;
            next_element = v[i+1].first;
            max_difference = diff;

            // cout << "prev_element " << prev_element << ", next_element " << next_element << ", max_difference " << max_difference << endl;
        }
    }

    (prev_element < next_element) ? cout << prev_element << " " << next_element : cout << next_element << " " << prev_element;
}
