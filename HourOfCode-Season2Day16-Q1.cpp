#include <iostream>
#include <vector>

using namespace std;

void testCase()
{
    int n, k;
    cin >> n >> k;
    //creating 2D array at runtime
    vector<vector<char> > arr(n, vector<char> (n, '0'));
    
    // take input
    char num;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            arr[i][j] = num;
        }
    }

    int numberOfThiefCaught = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 'P')
            {
                int left = ((j - k) >= 0) ? (j - k) : 0;
                int right = ((j + k) < n) ? (j + k) : (n - 1);

                int itr = j - 1;
                //check left side
                while (itr >= left && arr[i][j] == 'P')
                {
                    if (arr[i][itr] == 'T')
                    {
                        arr[i][itr] = 'A'; // set it as achieved
                        arr[i][j] = 'A'; // Theif caught
                        numberOfThiefCaught++;
                    }
                    --itr;
                }

                itr = j + 1;
                // if not in left then check right side
                while (itr <= right && arr[i][j] == 'P')
                {
                    if (arr[i][itr] == 'T')
                    {
                        arr[i][itr] = 'A'; // set it as achieved
                        arr[i][j] = 'A'; // Theif caught
                        numberOfThiefCaught++;
                    }
                    ++itr;
                }
            }
        }
    }

    cout << numberOfThiefCaught << endl;
    return;
}

int main()
{
    int t;
    cin >> t;

    while (t > 0)
    {
        testCase();
        --t;
    }

    return 0;
}
