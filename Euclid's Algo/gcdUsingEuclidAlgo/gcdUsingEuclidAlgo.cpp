#include<iostream>
using namespace std;

// int gcd(int a, int b) {
//     while(b) {
//         int rem = a % b;
//         a = b;
//         b = rem;
//     }
//     return a;
// }

// Using recursion
int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {

    int a, b;
    cin >> a >> b;

    cout << gcd(a,b);

    return 0;
}