#include <iostream>
using namespace std;

void subsets(int array[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
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