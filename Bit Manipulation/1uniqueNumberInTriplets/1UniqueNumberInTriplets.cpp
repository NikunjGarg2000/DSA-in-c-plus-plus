// find a unique no. in the array where except
// this all numbers are present thrice

#include <iostream>
using namespace std;

int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

// time complexity is O(n)
int unique(int array[], int n)
{
    int result = 0;

    // assuming that maximum no. can be a 64 bit number
    for (int i = 0; i < 64; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            // checking if bit at i-th index is 1
            if (getBit(array[j], i))
            {
                count++;
            }
        }

        // checking if count is divisible by 3
        if (count % 3 != 0)
        {
            result = setBit(result, i);
        }
    }
    return result;
}

int main()
{

    int array[10] = {1, 2, 3, 4, 3, 2, 1, 1, 2, 3};
    cout << unique(array, 10) << endl;

    return 0;
}