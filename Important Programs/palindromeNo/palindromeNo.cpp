#include<iostream>
using namespace std;

int main() {

    cout << "Enter a no. to check if it is a palindrome or not" << endl;

    int n;
    cin >> n;

    int reverseNo = 0, originalNo = n;

    while (n > 0) {
        reverseNo = (reverseNo * 10) + (n % 10);
        n /= 10;
    }

    if (reverseNo == originalNo) {
        cout << "It is a palindrome no.";
    } else {
        cout << "It is not a palindrome no.";
    }
    
    return 0;

}