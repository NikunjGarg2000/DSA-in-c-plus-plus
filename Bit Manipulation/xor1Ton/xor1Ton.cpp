#include <iostream>
using namespace std;

// brute force 
// using a for loop till n
// time complexity is O(n)
int xorFunc(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans ^= i;
    }
    return ans;
}

// Direct method (mathematical trick)
// time complexity is O(1)
int xorFrom1Ton(int n)
{
    if (n % 4 == 0)
    {
        return n;
    }
    else if (n % 4 == 1)
    {
        return 1;
    }
    else if (n % 4 == 2)
    {
        return n + 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    cin >> n;

    cout << xorFrom1Ton(n) << endl;
    cout << xorFunc(n) << endl;
}