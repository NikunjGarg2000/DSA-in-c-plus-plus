#include<iostream>
using namespace std;

int decimalToOctal(int decimalNo) {

    int x = 1;      // represent value of power of 8
    int octalNo = 0;

    while (x <= decimalNo) {
        x *= 8;
    }
    x /= 8;

    while (x > 0) {
        int lastDigit = decimalNo/x;
        decimalNo -= lastDigit * x;
        x /= 8;
        octalNo = octalNo * 10 + lastDigit;
    }
    
    return octalNo;
}

int main() {

    int decimalNo;
    cin >> decimalNo;

    cout << decimalToOctal(decimalNo) << endl;

    return 0;
}