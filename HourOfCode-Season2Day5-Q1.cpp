#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second < b.second;
}

bool comp(pair<int, int>& a, pair<int, int>& b)
{
    return a.first < b.first;
}

void confirmSort(vector<pair<int, int> >& v)
{
    int same = 0;
    int value;
    vector<pair<int, int> >::iterator itr = v.begin();
    vector<pair<int, int> >::iterator initial = v.begin();

    value = itr->second;
    bool flag = false;
    for (; itr != v.end(); itr++)
    {
        if (itr->second == value)
        {
            flag = true;
            same++;
        }
        else if(same > 1)
        {
            same = 1;
            flag = false;
            sort(initial, itr, comp);
            initial = itr;
            value = itr->second;
        }
    }
    if (flag)
    {
        sort(initial, itr, comp);
    }
}

int productOfDigit(int num)
{
    int rem;
    int product = 1;
    while (num > 0)
    {
        rem = num % 10;
        product *= rem;
        num /= 10;
    }
    return product;
}

void calculateProduct(vector<pair<int, int> >& v)
{
    vector<pair<int, int> >::iterator itr = v.begin();
    int product;
    for (; itr != v.end(); itr++)
    {
        // cout << itr->first << " ";
        product = productOfDigit(itr->first);
        itr->second = product;
        // cout << itr->second << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    // pair<number, product>
    vector<pair<int, int> > v;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(make_pair(num, 0));
    }

    calculateProduct(v);
    sort(v.begin(), v.end(), cmp);

    // for sorting of numbers based on their value whose products are same
    confirmSort(v);

    vector<pair<int, int> >::iterator itr = v.begin();

    for (; itr != v.end(); itr++)
    {
        cout << itr->first << " ";
    }
}
