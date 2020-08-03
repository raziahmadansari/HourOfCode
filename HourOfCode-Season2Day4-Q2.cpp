#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

int main()
{
    int n;
    cin >> n;

    if (n < 2 || n > 50)
    {
        exit(0);
    }

    int num;
    // pair<number, frequency>
    vector<pair<int, int> > v;


    cin >> num;
    v.push_back(make_pair(num, 1));

    bool present = false;
    int count_unique = 1;

    for (int i = 1; i < n; i++)
    {

        cin >> num;
        for (int j = 0; j < i; j++)
        {
            if (v[j].first == num)
            {
                v[j].second += 1;
                present = true;
                break;
            }
        }
        if (!present)
        {
            v.push_back(make_pair(num, 1));
            count_unique++;
        }
        present = false;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < count_unique; i++)
    {
        for (int j = 0; j < v[i].second; j++)
            cout << v[i].first << " ";
    }

    return 0;
}
