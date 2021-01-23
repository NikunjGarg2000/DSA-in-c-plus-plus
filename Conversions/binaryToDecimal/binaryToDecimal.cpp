#include<iostream>
using namespace std;

int binaryToDecimal(int binaryNo) {

    int decimalNo = 0;
    int x = 1;          // represent value of power of 2 here

    while (binaryNo > 0) {
        int lastDigit = binaryNo % 10;
        decimalNo += lastDigit * x;
        x *= 2;
        binaryNo /= 10;
    }

    return decimalNo;
}

int main() {
    
    int binaryNo;
    cin >> binaryNo;

    cout << binaryToDecimal(binaryNo) << endl;

    return 0;
}