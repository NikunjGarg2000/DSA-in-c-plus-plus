#include<iostream>
#include<climits>
using namespace std; 

int main() {

    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int currentMax = INT_MIN;
    for (int i = 0; i < n; i++) {
        currentMax = max(currentMax, array[i]);
        cout << currentMax << " "; 
    }

    return 0;
}