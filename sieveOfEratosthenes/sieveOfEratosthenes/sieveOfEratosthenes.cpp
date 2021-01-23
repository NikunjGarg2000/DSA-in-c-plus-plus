#include<iostream>
using namespace std;

void sieveOfEratosthenes(int n) {

    bool isPrime[n + 1] = {0};

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i] == 0) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i] == 0) {
            cout << i << endl;
        }
    }

} 

int main() {

    int n;
    cin >> n;

    sieveOfEratosthenes(n);

    return 0;
}