#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int& a, int& b)
{
    return a < b;
}

void findNumbers(vector<int>& v, int sum, vector<vector<int> >& result,
                 vector<int>& r, int i)
{
    // if sum becomes negative
    if (sum < 0)
        return;

    // if we get exact answer
    if (sum == 0)
    {
        result.push_back(r);
        return;
    }

    // recursion for all remaining elements that
    // have value smaller than sum
    while (i < v.size() && sum - v[i] >= 0)
    {
        r.push_back(v[i]);
        findNumbers(v, sum - v[i], result, r, i);
        i++;
        r.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int>& v, int sum)
{
    // sorting the input array
    sort(v.begin(), v.end(), cmp);

    // remove all duplicates
    // v.erase(unique(v.begin(), v.end()), v.end);

    vector<int>::iterator itr;
    itr = unique(v.begin(), v.end());
    v.resize(distance(v.begin(), itr));

    vector<int> r;
    vector<vector<int> > result;
    findNumbers(v, sum, result, r, 0);

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    int sum;
    cin >> sum;

    vector<vector<int> > result = combinationSum(v, sum);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    return 0;
}
