#include<iostream>
using namespace std;

// factorial function for approach 2

long factorial (int n) {
    int fact = 1;
    for (int i = n; i >= 1; i--) {
        fact = fact * i;
    }
    return fact;
}

int main() {

    int n;
    cin >> n;

    // Approach 1

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n - i; j++) {
    //         cout << "  ";
    //     }
    //     int number = 1;
    //     for (int j = 1; j <= i; j++) {
    //         cout << number << " " << "  ";
    //         number = number * (i - j) / j;
    //     }
    //     cout << endl;
    // }

    
    // Approach 2 using factorial function

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n - i - 1; j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << (factorial(i)/ (factorial(j) * factorial(i - j))) << "   ";
        }
        cout << endl;
    }

    return 0;
}