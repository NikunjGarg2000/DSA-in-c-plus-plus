#include<iostream>
using namespace std;

int octalToDecimal(int octalNo) {

    int decimalNo = 0;
    int x = 1;     // represent value of power of 8 here

    while (octalNo > 0) {
        int lastDigit = octalNo % 10;
        decimalNo += lastDigit * x;
        x *= 8;
        octalNo /= 10;
    }

    return decimalNo;
}

int main() {

    int octalNo;
    cin >> octalNo;

    cout << octalToDecimal(octalNo) << endl;

    return 0;
}