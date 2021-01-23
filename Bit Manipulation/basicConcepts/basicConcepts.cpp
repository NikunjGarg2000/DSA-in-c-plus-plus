#include <iostream>
using namespace std;

// get the bit at posth position
int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

// set the bit to 1 at posth position
int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

// clear the bit at posth position i.e., set it to 0
int clearBit(int n, int pos)
{
    return (n & (~(1 << pos)));
}

// update the bit at posth position to value either 0 or 1
// First clear bit and then set bit to value
int updateBit(int n, int pos, int value)
{
    n = (n & (~(1 << pos)));
    return (n | (value << pos)); 
}

int main()
{

    // cout << getBit(5, 2) << endl;
    // cout << setBit(5, 1) << endl;
    // cout << clearBit(5, 2) << endl;
    cout << updateBit(5, 1, 1) << endl;
    return 0;
}