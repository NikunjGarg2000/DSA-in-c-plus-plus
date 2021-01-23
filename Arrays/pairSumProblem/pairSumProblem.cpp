#include<iostream>
using namespace std;

int main() {

    int n; 
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int key;
    cin >> key;

    // Approach 1
    // Bute Force Approach

    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         if (array[i] + array[j] == key) {
    //             cout << i << " " << j; 
    //         }
    //         cout << endl;
    //     }
    // }

    // Approach 2
    // More Efficient
    // Array must be sorted

    // using Insertion sort for now
    for (int i = 1; i < n; i++) {
        int currentNo = array[i];
        int j = i - 1;
        while (array[j] > currentNo && j > 0) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = currentNo;
    }

    // Pair sum now

    int low = 0;
    int high = n - 1;

    while (low < high) {
        if(array[low] + array[high] == key) {
            cout << low << " " << high << endl;
            break;
        } else if (array[low] + array[high] > key) {
            high--;
        } else {
            low++;
        }
    }


    return 0;
}
