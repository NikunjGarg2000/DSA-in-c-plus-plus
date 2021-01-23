#include<bits/stdc++.h>
using namespace std;

int hexadecimalToDecimal(string hexadecimalNo) {

    int decimalNo = 0;
    int x = 1;        // represent value of power of 16

    int size = hexadecimalNo.size();

    for (int i = size - 1; i >= 0; i--) {
        if (hexadecimalNo[i] >= '0' && hexadecimalNo[i] <= '9') {
            decimalNo += x * (hexadecimalNo[i] - '0');
        } else if (hexadecimalNo[i] >= 'A' && hexadecimalNo[i] <= 'F') {
            decimalNo += x * (hexadecimalNo[i] - 'A' + 10);
        }
        x *= 16;
    }

    return decimalNo;
}

int main() {

    string hexadecimalNo; 
    cin >> hexadecimalNo;

    cout << hexadecimalToDecimal(hexadecimalNo) << endl;

    return 0;
}