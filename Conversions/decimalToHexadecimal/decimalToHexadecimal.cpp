#include<iostream>
using namespace std;

string decimalToHexadecimal(int decimalNo) {

    int x = 1;        // represent value of power of 16
    string hexadecimalNo = "";

    while (x <= decimalNo) {
        x *= 16;
    }
    x /= 16;

    while (x > 0) {
        int lastDigit = decimalNo/x;
        decimalNo -= lastDigit * x;
        x /= 16;
        
        if (lastDigit <= 9) {
            hexadecimalNo = hexadecimalNo + to_string(lastDigit);
        } else {
            char c = 'A' + lastDigit - 10;
            hexadecimalNo.push_back(c);
        }
    }

    return hexadecimalNo;
}

int main() {

    int decimalNo;
    cin >> decimalNo;

    cout << decimalToHexadecimal(decimalNo) << endl;

    return 0;
}