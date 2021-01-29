// Question

// Given an array of integers where each element represents the max 
// number of steps that can be made forward from that element. Find the
// minimum number of jumps to reach the end of the array (starting from
// the first element). If an element is 0, then you cannot move through that element.

// eg
// Input:
// N=11 
// arr=1 3 5 8 9 2 6 7 6 8 9 
// Output: 3 
// Explanation: 
// First jump from 1st element to 2nd 
// element with value 3. Now, from here 
// we jump to 5th element with value 9, 
// and from here we will jump to last. 

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Brute force approach
    // time complexity is O(n2)

    // int i = 0, minNoOfJumps = 0;
    // int allzeroes = 0;

    // if (arr[0] == 0)
    // {
    //     cout << -1 << endl;
    //     return -1;
    // }
    // if (n <= 1)
    // {
    //     cout << 1 << endl;
    //     return 0;
    // }

    // while (i < n - 1)
    // {
    //     if (allzeroes == 1)
    //     {
    //         return -1;
    //     }
    //     int k = i + arr[i];
    //     if (k >= n - 1)
    //     {
    //         minNoOfJumps++;
    //         break;
    //         // cout << minNoOfJumps;
    //         // return 0;
    //     }
    //     for (int j = i + 1; j <= k; j++)
    //     {
    //         if (arr[j] == 0)
    //         {
    //             continue;
    //             allzeroes = 1;
    //         }
    //         if (arr[j] - (k - j) >= arr[k])
    //         {
    //             minNoOfJumps++;
    //             i += arr[i];
    //             allzeroes = 0;
    //         }
    //     }
    // }

    // cout << minNoOfJumps << endl;


    // efficient approach
    // time complexity is O(n)

    int maxReach = arr[0], steps = arr[0], jumps = 1;
    int i = 1;

    if (arr[0] == 0) {
        cout << -1 << endl;
        return -1;
    }
    if (n <= 1) {
        cout << 1 << endl;
        return 0;
    }
    while (i < n - 1)
    {
        maxReach = max(maxReach, i + arr[i]);
        steps--;
        if (steps == 0)
        {
            jumps++;
            if (i > maxReach)
            {
                return -1;
            }
            steps = maxReach - i;
        }
        i++;
    }

    cout << jumps << endl;

    return 0;
}
