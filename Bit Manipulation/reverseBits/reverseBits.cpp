// Given a 32 bit number X, reverse its binary form and print the answer in decimal.

// Example 1:

// Input:
// X = 1
// Output:
// 2147483648
// Explanation:
// Binary of 1 in 32 bits representation-
// 00000000000000000000000000000001
// Reversing the binary form we get,
// 10000000000000000000000000000000,
// whose decimal value is 2147483648.

#include <iostream>
using namespace std;

// time complexity is O(log n)
long long reversedBits(long long X)
{
    unsigned int ans = 0;
    int count = 31;
    while (X > 0)
    {
        if ((X & 1) == 1)
        {
            ans = (ans) + (1 << count);
        }
        count--;
        X = X >> 1;
    }
    long long ans1 = ans;
    return (ans1);
}

int main()
{

    cout << reversedBits(1);

    return 0;
}