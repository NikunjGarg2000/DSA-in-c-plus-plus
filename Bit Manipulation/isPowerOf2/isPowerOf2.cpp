#include<iostream>
using namespace std;

bool isPowerOf2(int n) {
    return (n - 1) && n && (!(n & (n - 1)));
}

int main() {

    cout << isPowerOf2(512) << endl;
    
    return 0;
}