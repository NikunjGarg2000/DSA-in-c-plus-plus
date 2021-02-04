#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    
    int *arr;

    // Since in 1D array, row is 1
    // so dynamically allocating memory for columns in heap
    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}