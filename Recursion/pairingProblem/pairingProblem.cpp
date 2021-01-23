#include<iostream>
using namespace std;

int pairingProblem(int n) {

    if (n == 0 || n == 1 || n == 2) {
        return n;
    }

    return pairingProblem(n - 1) + (n - 1) * pairingProblem(n - 2);

}

int main() {

    cout << pairingProblem(4);
    return 0;

}