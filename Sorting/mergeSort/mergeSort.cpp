#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{

    int n1 = mid - l + 1;
    int n2 = r - mid;

    // temp arrays
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

    int i = 0;
    int j = 0;
    int k = l;

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
        }
    }

    while (i < n1) {
        arr[k] = arr1[i];
        k++;
        i++;
    }

     while (j < n2) {
        arr[k] = arr2[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r)
{

    if (l < r)
    {

        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main()
{
    int arr[5] = {2,4,1,5,3};
    mergeSort(arr, 0, 4);
    
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}