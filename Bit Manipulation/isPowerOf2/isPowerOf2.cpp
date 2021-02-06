// check if the input number is power of 2 using bit manipulation

#include <iostream>
using namespace std;

// concept used
// for a number n to be power of 2, n & (n-1) must be 0
// time complexity is O(1)


bool isPowerOf2(int n)
{
    // n-1 to handle 1 and n is to handle 0
    return (n - 1) && n && (!(n & (n - 1)));
}

int main()
{

    cout << isPowerOf2(513) << endl;

    return 0;
}