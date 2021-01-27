// Question
// Given an array arr[] of size, N, the task is to find the length of the longest subarray that forms an Arithmetic Progression.

// Input: arr[] = {3, 4, 5}
// Output: 3
// Explanation:The longest subarray forming an AP is {3, 4, 5} with common difference 1.
// Input: {10, 7, 4, 6, 8, 10, 11}
// Output: 4
// Explanation:The longest possible subarray forming an AP is {4, 6, 8, 10} with common difference(= 2).

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

    // can do it finding all subarrays and then doing it but that will take O(n3)

    // efficient approach
    // time complexity is O(n)

    int i = 2;
    int ansLength = 2;
    int currentLength = 2;
    int previousDiff = array[1] - array[0];

    while (i < n)
    {

        if ((array[i] - array[i - 1]) == previousDiff)
        {

            currentLength++;
        }
        else
        {

            previousDiff = array[i] - array[i - 1];
            currentLength = 2;
        }

        i++;
        ansLength = max(ansLength, currentLength);
    }

    cout << ansLength << " ";
    return 0;
}