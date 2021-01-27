// Question
// Given an array a[] of size n. For every i from 0 to n-1 output max(a[0], a[1],..., a[i]).

// eg if array is {1, 0, 5, 4, 6, 8} then maxTill_i will be {1, 1, 5, 5, 6, 8}

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
    int currentMax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currentMax = max(currentMax, array[i]);
        cout << currentMax << " ";
    }

    return 0;
}