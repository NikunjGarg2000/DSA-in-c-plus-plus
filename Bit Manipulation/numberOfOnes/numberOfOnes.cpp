#include <iostream>
using namespace std;

// logic used
// n & n-1 has same bits as of n except the rightmost set bit
// so we will keep doing it unless n becomes 0

// time complexity is O(k) where k is number of ones present in n
int numberOfOnes(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
    ;
}

int main()
{

    cout << numberOfOnes(23) << endl;
    return 0;
}