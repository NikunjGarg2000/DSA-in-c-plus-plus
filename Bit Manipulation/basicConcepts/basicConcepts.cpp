#include <iostream>
using namespace std;

// time complexity of bitwise operators (&, |, ~, <<, >>) is O(1)

// get the bit at pos-th position
int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

// set the bit to 1 at pos-th position
int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

// clear the bit at pos-th position i.e., set it to 0
int clearBit(int n, int pos)
{
    return (n & (~(1 << pos)));
}

// update the bit at pos-th position to value either 0 or 1
// First clear bit and then set bit to value
int updateBit(int n, int pos, int value)
{
    n = (n & (~(1 << pos)));
    return (n | (value << pos));
}

// toggle bit at pos-th position
// change 0 to 1 or 1 to 0 at pos-th position
// using xor since
// 0 ^ 1 = 1
// 1 ^ 1 = 0
int toggleBit(int n, int pos)
{
    return (n ^ (1 << pos));
}

// important logic used frequently

// logic 1
// to get n-1 from n, just flip rightmost and all other bits after that
// eg
// 6 is 0110 so
// 5 is 0101

int main()
{

    // cout << getBit(5, 2) << endl;
    // cout << setBit(5, 1) << endl;
    // cout << clearBit(5, 2) << endl;
    // cout << updateBit(5, 1, 1) << endl;
    cout << toggleBit(5, 2);
    return 0;
}