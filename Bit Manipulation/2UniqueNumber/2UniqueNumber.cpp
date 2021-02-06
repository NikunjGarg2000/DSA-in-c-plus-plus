// find 2 unique no.s in the array where every
// number except these 2 are present twice

#include <iostream>
using namespace std;

int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

// time complexity is O(n)
void unique(int array[], int n)
{

    int xorSum = 0;
    for (int i = 0; i < n; i++)
    {
        xorSum = xorSum ^ array[i];
    }

    // xorsum basically now is xor of 2 unique numbers

    int tempXor = xorSum;
    int position = 0;
    int setBit = 0;

    // checking at which position there is 1 in tempXor

    while (!setBit)
    {
        setBit = 1 & tempXor;
        position++;
        tempXor >> 1;
    }

    int newXor = 0;
    for (int i = 0; i < n; i++)
    {
        // taking xor of every number at which there is 1 at position-1
        if (getBit(array[i], position - 1))
        {
            newXor = newXor ^ array[i];
        }
    }

    // newXor is one of our number
    cout << newXor << endl;
    cout << (newXor ^ xorSum) << endl;
}

int main()
{

    int array[8] = {5, 6, 7, 8, 9, 8, 9, 7};
    unique(array, 8);

    return 0;
}