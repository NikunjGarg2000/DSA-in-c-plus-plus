#include<iostream>
#include<climits>
using namespace std;

int main() {

    int  n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // Approach 1
    // Brute Force Approach
    // int maxSum = INT_MIN;

    // for (int i = 0; i < n; i++) {
    //     for (int j = i; j < n; j++) {
    //         int sum = 0;
    //         for (int k = i; k <= j; k++) {
    //             sum += array[k];
    //         }
    //         maxSum = max(maxSum, sum);
    //     }
    // }

    // cout << maxSum;


    // Approach 2
    // Cumulative Sum Approach

    int currSum[n + 1];
    currSum[0] = 0;

    for (int i = 1; i <= n; i++) {
        currSum[i] = currSum[i - 1] + array[i - 1];
    }

    int maxSum = INT_MIN;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum = currSum[i] - currSum[j];
            maxSum = max(sum, maxSum);
        }
    }

    cout << maxSum;

    
    // Approach 3
    // kadane's Algorithm

    // int currSum = 0;
    // int maxSum = INT_MIN;

    // for (int i = 0; i < n; i++) {
    //     currSum += array[i];
    //     if (currSum < 0) {
    //         currSum = 0;
    //     }
    //     maxSum = max(maxSum, currSum);
    // }

    // cout << maxSum;

    return 0;
}