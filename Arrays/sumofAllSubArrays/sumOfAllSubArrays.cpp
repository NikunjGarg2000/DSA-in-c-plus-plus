// Question
// Given an array a[] of size n. Output sum of each subarray of the given array.

// eg if array is {1, 2, 2} then sum of each subarray will be
// 1            1
// 1 2          3
// 1 2 2        5
// 2            2
// 2 2          4
// 2            2

#include <iostream>
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

    // time complexity is O(n2)
    int sum;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += array[j];
            cout << sum << endl;
        }
    }

    return 0;
}