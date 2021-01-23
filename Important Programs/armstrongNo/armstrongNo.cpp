#include<iostream>
#include<math.h>
using namespace std;

int main() {

    cout << "Enter a no. to check if it is an armstrong no." << endl;

    int n;
    cin >> n;

    int noOfDigits = 0, originalNo = n;
    double sum = 0;

    while (n > 0) {
       n /= 10;
       noOfDigits++;
    }

    n = originalNo;

    while (n > 0) {
        sum = sum + pow(n % 10, noOfDigits);
        n /= 10;
    }

    if (sum == originalNo) {
        cout << "It is an armstrong no.";
    } else {
        cout << "It is not an armstrong no.";
    }
    
    
    return 0;  

}