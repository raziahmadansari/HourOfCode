#include <iostream>
#include <vector>
#include <string>

#define NO_OF_CHARS 256

using namespace std;

int longestUniqueSubsequence(string str)
{
    int n = str.length();
    int max_length = 0;

    vector<int> lastIndex(NO_OF_CHARS, -1);

    int i = 0;

    for (int j = 0; j < n; j++)
    {
        i = max(i, lastIndex[str[j]] + 1);
        max_length = max(max_length, j - i + 1);
        lastIndex[str[j]] = j;
    }

    return max_length;
}

int main()
{
    string str;
    cin >> str;
    int length = longestUniqueSubsequence(str);
    cout << length;
    return 0;
}
