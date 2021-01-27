// Question
// Given an unsorted array A of size N of non-negative integers, find a continuous
// subarray which adds to a given number S.

// eg. 
// Input:
// N = 5, S = 12
// A[] = {1,2,3,7,5}
// Output: 1 3

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

    // 2 pointer approach 
    // efficient one
    // time complexity is O(n)

    int sum;
    cin >> sum;

    int i = 0, j = 0, start = -1, end = -1, currSum = 0;

    while (j < n && currSum + array[j] <= sum)
    {
        currSum += array[j];
        j++;
    }

    if (currSum == sum)
    {
        cout << i << " " << j - 1 << endl;
        return 0;
    }

    while (j < n)
    {
        currSum += array[j];
        while (currSum > sum)
        {
            currSum -= array[i];
            i++;
        }

        if (currSum == sum)
        {
            start = i;
            end = j;
            break;
        }

        j++;
    }

    cout << start << " " << end << endl;

    return 0;
}