#include <iostream>
using namespace std;

long long merge(int arr[], int l, int mid, int r)
{
    long long inversion = 0;

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int arr1[n1];
    int arr2[n2];

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
            k++;
            inversion += n1 - i;
        }
    }

    while (i < n1) {
        arr[k] = arr1[i];
        k++; i++;
    }

    while (j < n2) {
        arr[k] = arr2[j];
        k++; j++;
    }
    
    return inversion;
}

long long mergeSort(int arr[], int l, int r)
{
    long long inversion = 0;

    if (l < r)
    {
        int mid = (l + r) / 2;
        inversion += mergeSort(arr, l, mid);
        inversion += mergeSort(arr, mid + 1, r);
        inversion += merge(arr, l, mid, r);
    }

    return inversion;
}

int main()
{

    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << mergeSort(array, 0, n - 1);

    return 0;
}