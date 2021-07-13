#include<iostream>
using namespace std;

int factorial(int n) {

    if (n == 0) {
        return 1;
    }

    int prevFact = factorial(n - 1);
    return n * prevFact;
}

int tailFactorial(int n, int ans = 1) {
    if (n == 0) return ans;
    return tailFactorial(n-1, ans * n);
}

int main() {
   
    int n;
    cin >> n;

    cout << factorial(n) << endl;
    cout << tailFactorial(n) << endl;

    return 0;
}