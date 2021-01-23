#include<iostream>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int sum;
    cin >> sum;

    int i = 0, j = 0, start = -1, end = -1, currSum = 0;

    while (j < n && currSum + array[j] <= sum) {
        currSum += array[j];
        j++;
    }

    if (currSum == sum) {
        cout << i + 1 << " " << j << endl;
        return 0;
    }

    while (j < n) {
        currSum += array[j];
        while (currSum > sum) {
            currSum -= array[i];
            i++;
        }

        if (currSum == sum) {
            start = i + 1;
            end = j + 1;
            break;
        }

        j++;
    }

    cout << start << " " << end << endl;

    return 0;
}