// Question
// Given an array, rearrange it such that all negative elements comes before non-negative elements
// *order of elements doesn't matter

#include <iostream>
using namespace std;

void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if (arr[i] < 0 && arr[j] < 0)
        {
            i++;
        }
        else if (arr[i] >= 0 && arr[j] < 0)
        {
            swap(arr, i, j);
            i++;
            j--;
        }
        else if (arr[i] < 0 && arr[j] >= 0)
        {
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
