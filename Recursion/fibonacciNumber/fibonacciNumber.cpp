#include<iostream>
using namespace std;

int fibonacci(int n) {

    if (n == 0 || n == 1) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}


// 2 variables needed to store 2 values one for n-1, other for n-2
int tailFibonacci(int n, int a = 1, int b = 1) {
    if (n == 0 || n == 1) return b;
    return tailFibonacci(n-1, b, a+b);
}

int main() {

    int n;
    cin >> n;

    cout << fibonacci(n) << endl;
    cout << tailFibonacci(n) << endl;

    return 0;
}