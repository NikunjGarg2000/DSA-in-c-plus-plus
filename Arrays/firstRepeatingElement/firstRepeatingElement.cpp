// Question
// Given an array arr[] of size N. The task is to find the first repeating element in an
// array of integers, i.e., an element that occurs more than once and whose index of
// first occurrence is smallest.

#include <iostream>
#include <climits>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    // time complexity is O(n)
    const int N = 1e5 + 2;

    int idx[N];
    int minInd = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        idx[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (idx[array[i]] != -1)
        {
            minInd = min(minInd, idx[array[i]]);
        }
        else
        {
            idx[array[i]] = i;
        }
    }

    if (minInd == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << minInd + 1 << endl;
    }

    return 0;
}