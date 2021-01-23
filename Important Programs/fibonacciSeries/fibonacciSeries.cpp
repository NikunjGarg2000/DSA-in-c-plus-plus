#include<iostream>
using namespace std;

int main() {

    cout << "Enter a number upto which fibonacci series will be presented." << endl;

    int n;
    cin >> n;

    int x = 1, y = 1, z = 0;

    for (int i = 1; i <= n; i++) {
        cout << z << "  ";
        x = y;
        y = z;
        z = x + y;
    }
}