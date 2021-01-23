#include<iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int i = 2;
    int ansLength = 2;
    int currentLength = 2;
    int previousDiff = array[1] - array[0];
    
    while (i < n) {

        if ((array[i] - array[i - 1]) == previousDiff) {

            currentLength++;

        } else {

            previousDiff = array[i] - array[i - 1];
            currentLength = 2;
        }

        i++;
        ansLength = max(ansLength, currentLength);

    }

    cout << ansLength << " ";
    return 0;
}