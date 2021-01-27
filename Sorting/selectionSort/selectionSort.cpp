// find min element in unsorted array and swap it with element in the beginning of unsorted array
// time complexity is O(n2)

#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[i])
            {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}