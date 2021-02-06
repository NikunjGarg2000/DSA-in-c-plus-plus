// find unique number in an array where every no except that is present twice

#include <iostream>
using namespace std;

// since xor of 2 same no gives 0 therefore xor of every 
// number present in array will give us unique no.

// time complexity is O(n)

int uniqueNumber(int array[], int n)
{
    int xorSum = 0;
    for (int i = 0; i < n; i++)
    {
        xorSum = xorSum ^ array[i];
    }
    return xorSum;
}

int main()
{

    int array[7] = {1, 2, 3, 4, 1, 2, 3};
    cout << uniqueNumber(array, 7) << endl;

    return 0;
}