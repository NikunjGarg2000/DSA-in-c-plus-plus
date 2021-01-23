#include<iostream>
#include<climits>
using namespace std;

int kadane(int arr[], int n) {
    int currentSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        currentSum += arr[i];
        if (currentSum < 0) {
            currentSum = 0;
        }
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {

    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int wrapSum;
    int nonWrapSum;

    nonWrapSum = kadane(array, n);
    int totalSum = 0;

    for (int i = 0; i < n; i++) {
        totalSum += array[i];
        array[i] = -array[i];
    }

    wrapSum = totalSum + kadane(array, n);

    cout << max(wrapSum, nonWrapSum) << endl;


    return 0;
}