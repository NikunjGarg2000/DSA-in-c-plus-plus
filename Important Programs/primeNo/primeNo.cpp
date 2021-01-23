#include<iostream>
#include<cmath>
using namespace std;

int main() {

    cout << "Enter a no. to check if it is prime or not"<< endl;

    int n;
    cin >> n;

    // Approach 1

    int i = 2;

    for (; i < n; i++) {
        if (n % i == 0) {
            break;
        }
    }

    if (i == n) {
        cout << "It is a prime no.";
    } else {
        cout << "It is not a prime no.";
    }


    // Approach 2

    // if (n < 2) {

    //     cout << "It is not a prime no.";

    // } else if (n == 2) {
        
    //     cout << "It is a prime no.";

    // } else {

    //     bool isPrime = 0;

    //     for (int i = 2; i <= sqrt(n); i++) {
    //         if (n % i == 0) {
    //             isPrime = 1;
    //             break;
    //         }
    //     }

    //     if (isPrime == 1) {
    //         cout << "It is not a prime no.";
    //     } else {
    //         cout << "It is a prime no.";
    //     }
    // }
    
    return 0;
}
