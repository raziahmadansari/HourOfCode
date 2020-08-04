#include <iostream>
#include <algorithm>
#include <vector>
/*N = 7
 *K = 3
 * 10 100 300 200 1000 20 30
 * output: 20
*/

using namespace std;

int calculateDifference(vector<int>& v, int n, int k)
{
    // sliding window concept
    int min_difference = v[k - 1] - v[0];   //storing difference of first window

    for (int i = 1; i < (n - k); i++)
        min_difference = ((v[i + k - 1] - v[i]) < min_difference) ? v[i + k - 1] - v[i] : min_difference;

    return min_difference;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> v;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    // sort the array
    // 10 20 30 100 200 300 10000
    sort(v.begin(), v.end());

    cout << calculateDifference(v, N, K);

    return 0;
}
