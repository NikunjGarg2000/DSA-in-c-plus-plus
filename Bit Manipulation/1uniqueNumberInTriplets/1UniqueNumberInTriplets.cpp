#include<iostream>
using namespace std;

int getBit(int n, int pos) {
    return ((n & (1 << pos)) != 0);
}

int setBit(int n, int  pos) {
    return (n | (1 << pos));
}

int unique(int array[], int n) {
    int result = 0;
    for (int i = 0; i < 64; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (getBit(array[j], i)) {
                count++;
            }
        }
        if (count % 3 != 0) {
            result = setBit(result, i);
        }
    }
    return result;
}

int main() {

    int array[10] = {1,2,3,4,3,2,1,1,2,3};
    cout << unique(array, 10) << endl;

    return 0;
}