#include<iostream>
using namespace std;

int uniqueNumber(int array[], int n) {
    int xorSum = 0;
    for(int i = 0; i < n; i++) {
        xorSum = xorSum ^ array[i];
    }
    return xorSum;
}

int main() {

    int array[7] = {1,2,3,4,1,2,3};
    cout << uniqueNumber(array, 7) << endl;
    
    return 0;
}