// Given a positive integer n, find count of positive integers i such that 0 <= i <= n and n+i = n^i

#include <iostream>
using namespace std;

// Brute force approach
// time complexity is O(n)

int countValues(int n)
{
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if ((n + i) == (n ^ i))
        {
            count++;
        }
    }
    return count;
}

// efficient approach
// time complexity is O(log n) since n is getting divided by 2

// we know that (n+i)=(n^i)+(n&i)
// So n + i = n ^ i implies n & i = 0
// For n & i to be zero, i must unset all set-bits of n. If the kth bit is set at a particular in n, kth bit in i must be 0 always, else kth bit of i can be 0 or 1
// Hence, total such combinations are 2^(count of unset bits in n)
// For example, consider n = 12 (Binary representation : 1 1 0 0).
// All possible values of i that can unset all bits of n are 0 0 0/1 0/1 where 0/1 implies either 0 or 1. Number of such values of i are 2^2 = 4. \

int countValue(int n)
{
    // unset_bits keeps track of count of un-set
    // bits in binary representation of n
    int unset_bits = 0;
    while (n)
    {
        if ((n & 1) == 0)
            unset_bits++;
        n = n >> 1;
    }

    // Return 2 ^ unset_bits
    return 1 << unset_bits;
}

int main()
{

    int n;
    cin >> n;

    cout << countValues(n) << endl;
    cout << countValue(n) << endl;

    return 0;
}