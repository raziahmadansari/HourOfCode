#include <iostream>
#include <string>

using namespace std;
/*
 *input: abcabca
 *output: 5
*/

/*
 *step-1: s1=a          s2=b        dp[]={1, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}
 *step-2: s1=ab         s2=ca       dp[]={1, 2, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}
 *step-3: s1=abc        s2=abc      dp[]={1, 2, 3, INT_MAX, INT_MAX, 4, INT_MAX}                   //since s1==s2
 *step-4: s1=abca       s2=bca      dp[]={1, 2, 3, 4, INT_MAX, 4, INT_MAX}
 *step-5: s1=abcab      s2=ca       dp[]={1, 2, 3, 4, 5, 4, INT_MAX}
 *step-6: s1=abcabc     s2=a        dp[]={1, 2, 3, 4, 5, 4, INT_MAX}
 *step-7: s1=abcabca    s2=""       dp[]={1, 2, 3, 4, 5, 4, 5}
 *now return dp[n-1] which is 5
*/

int minSteps(string s)
{
    int n = s.length();
    int dp[n];  // to keep track of number of steps

    // initialize the array
    for (int i = 0; i < n; i++)
        dp[i] = INT_MAX; // or use any  big integer like 999999

    string s1 = "";
    string s2 = "";

    s1 = s[0];
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        s1 += s[i];
        s2 = s.substr(i + 1, i + 1); // substring from (i + 1) to (i + 1) characters

        dp[i] = min(dp[i], dp[i - 1] + 1);

        if (s1 == s2)
            dp[i * 2 + 1] = min(dp[i] + 1, dp[i * 2 + 1]);
    }

    return dp[n - 1];
}

int main()
{
    string s;
    cin >> s;

    cout << minSteps(s);

    return 0;
}
