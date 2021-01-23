#include<iostream>
using namespace std;

int getBit(int n, int pos) {
    return ((n & (1 << pos)) != 0);
}

void unique(int array[], int n) {

    int xorSum = 0;
    for (int i = 0; i < n; i++) {
        xorSum = xorSum ^ array[i]; 
    }

    int tempXor = xorSum;
    int position = 0;
    int setBit = 0;

    while (!setBit) {
        setBit = 1 & tempXor;
        position++;
        tempXor >> 1;
    }

    int newXor = 0;
    for (int i = 0; i < n; i++) {
        if (getBit(array[i], position - 1)) {
            newXor = newXor ^ array[i];
        }
    }

    cout << newXor << endl;
    cout << (newXor ^ xorSum) << endl;

}
 
int main() {

    int array[8] = {5,6,7,8,9,8,9,7};
    unique(array, 8);
 
    return 0;
}