#include <iostream>
using namespace std;

// 1 << n represents 2^n
// since there are 2^n subsets of a set having n elements

// time complexity is O(n * 2^n)
void subsets(int array[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            // using getBit operation
            // checking if in i-th number j-th bit is 1
            if (i & (1 << j))
            {
                cout << array[j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int array[3] = {1, 2, 3};
    subsets(array, 3);
    return 0;
}