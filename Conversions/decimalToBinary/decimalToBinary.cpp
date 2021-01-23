#include<iostream>
using namespace std;

int decimalToBinary(int decimalNo) {

    int x = 1;       // represent value of power of 2
    int binaryNo = 0;

    while (x <= decimalNo) {
        x *= 2;
    }
    x /= 2;

    while (x > 0) {
        int lastDigit = decimalNo/x;
        decimalNo -= lastDigit * x;
        x /= 2;
        binaryNo = binaryNo * 10 + lastDigit;
    }

    return binaryNo;
}

int main() {

    int decimalNo;
    cin >> decimalNo;

    cout << decimalToBinary(decimalNo) << endl;

    return 0;
}