// // quick sort using last element as pivot

// #include<iostream>
// using namespace std;

// void swap(int arr[], int a, int b) {
//     int temp = arr[a];
//     arr[a] = arr[b];
//     arr[b] = temp;
// }

// int partition(int arr[], int l, int h) {
//     int pivot = arr[h];
    
//     int i = l-1, j = l;
    
//     while (j < h) {
//         if (arr[j] < pivot) {
//             i++;
//             swap(arr, i, j);
//         }
//         j++;
//     }
//     swap(arr, i+1, h);
//     return i+1;
// }

// void quickSort(int arr[], int l, int h) {
//     if (l < h) {
//         int pivot = partition(arr, l, h);
//         quickSort(arr, l, pivot-1);
//         quickSort(arr, pivot+1, h);
//     }
// }

// int main() {
//     int n; 
//     cin >> n;
    
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
    
//     quickSort(arr, 0, n-1);
    
//     for (int i = 0; i < 6; i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }


// quick sort using first element as pivot
#include<iostream>
#include<climits>
using namespace std;

int swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int l, int h) {
    int pivot = arr[l];
    
    int i = l, j = h;
    
    while (i < j) {
        do {
            i++;
        } while (arr[i] <= pivot);
        
        do {
            j--;
        } while (arr[j] > pivot);
        
        if (i < j) {
            swap(arr, i, j);
        }
    }
    
    swap(arr, l, j);
    return j;
}

void quickSort(int arr[], int l, int h) {
    if (l < h) {
        int pivot = partition(arr, l, h);
        quickSort(arr, l, pivot);
        quickSort(arr, pivot+1, h);
    }
}

int main() {
    int n;
    cin >> n;
    
    int arr[n+1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    arr[n] = INT_MAX;
    
    quickSort(arr, 0, n);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}