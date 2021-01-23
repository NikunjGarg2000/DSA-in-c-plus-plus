#include <iostream>
#include <climits>
using namespace std;

// // Approach 1 of TC = O(n^2)
// int leftMaxHeight(int array[], int n, int i)
// {
//     int maximum = INT_MIN;
//     for (int j = 0; j <= i; j++)
//     {
//         if (array[j] > maximum)
//         {
//             maximum = array[j];
//         }
//     }
//     return maximum;
// }

// int rightMaxHeight(int array[], int n, int i)
// {
//     int maximum = INT_MIN;
//     for (int j = n - 1; j >= i; j--)
//     {
//         if (array[j] > maximum)
//         {
//             maximum = array[j];
//         }
//     }
//     return maximum;
// }

// void totalWater(int array[], int n)
// {
//     int totalUnits = 0;
//     for (int i = 1; i < n - 1; i++)
//     {
//         int leftMax = leftMaxHeight(array, n, i);
//         int rightMax = rightMaxHeight(array, n, i);
//         totalUnits += min(leftMax, rightMax) - array[i];
//     }
//     cout << totalUnits << endl;
// }

// Approach 2
void totalWater(int array[], int n)
{
    int totalUnits = 0;
    int leftMax[n];
    int rightMax[n];

    leftMax[0] = array[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], array[i]);
    }

    rightMax[n - 1] = array[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], array[i]);
    }

    for (int i = 1; i < n - 1; i++)
    {
        totalUnits += min(leftMax[i], rightMax[i]) - array[i];
    }
    cout << totalUnits << endl;
} 

int main()
{

    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    totalWater(array, n);

    return 0;
}