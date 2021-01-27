// find the max sum of subarrays

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

    // Approach 1
    // Brute Force Approach
    // time complexity is O(n3)

    // int maxSum = INT_MIN;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         int sum = 0;
    //         for (int k = i; k <= j; k++)
    //         {
    //             sum += array[k];
    //         }
    //         maxSum = max(maxSum, sum);
    //     }
    // }

    // cout << maxSum;

    // Approach 2
    // Cumulative Sum Approach
    // time complexity is O(n2)

    // int currSum[n + 1];
    // currSum[0] = 0;

    // for (int i = 1; i <= n; i++)
    // {
    //     currSum[i] = currSum[i - 1] + array[i - 1];
    // }

    // int maxSum = INT_MIN;
    // for (int i = 1; i <= n; i++)
    // {
    //     int sum = 0;
    //     for (int j = 0; j < i; j++)
    //     {
    //         sum = currSum[i] - currSum[j];
    //         maxSum = max(sum, maxSum);
    //     }
    // }

    // cout << maxSum;

    // Approach 3
    // kadane's Algorithm
    // time complexity is O(n)

    int currSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum += array[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }

    cout << maxSum;

    return 0;
}