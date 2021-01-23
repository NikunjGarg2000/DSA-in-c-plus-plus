#include<iostream>
using namespace std;

void countSort(int arr[], int n) {

    int k = arr[0];
    for (int i = 0; i < n; i++) {
        k = max(k, arr[i]);
    }

    int count[k+1] = {0};
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

}

int main() {

    int arr[5] = {1, 5, 4, 6, 3};
    countSort(arr, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    // int size = sizeof(arr)/sizeof(arr[0]);
    // cout << endl << size;
    return 0;
}