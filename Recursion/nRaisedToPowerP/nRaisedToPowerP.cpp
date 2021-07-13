// a ^ b
#include <iostream>
using namespace std;

// TC - O(n)
int power(int a, int b) {
    if (b == 0) return 1;
    return a * power(a, b-1);
}

// TC - O(n)
int tailPower(int a, int b, int ans = 1) {
    if (b == 0) return ans;
    return tailPower(a, b-1, ans * a);
}

// TC - O(log n)
int optimizedPower(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = ans * a;
            b = b - 1;
        } else {
            a = a*a;
            b = b/2;
        }
    }
    return ans;
}

// TC - O(log n)
int optimizedPowerUsingRecursion(int a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        return optimizedPowerUsingRecursion(a*a, b/2);
    }
    return a * optimizedPowerUsingRecursion(a*a, (b-1)/2);
}

int main()
{
    int a, b;
    cin >> a >> b;
    
    cout << power(a, b) << endl;
    cout << tailPower(a, b) << endl;
    cout << optimizedPower(a, b) << endl;
    cout << optimizedPowerUsingRecursion(a, b) << endl;

    return 0;
}
