#include <iostream>
using namespace std;

class Array
{
    int *A;
    int size;
    int length;
    void swap(int *a, int *b);

public:
    // construcutor
    Array(int s);

    // destructor since dma
    ~Array()
    {
        delete[] A;
    }

    // display all elements of array
    void display();

    // add element to the last
    void add(int num);

    // insert element at the given index
    void insert(int index, int num);

    // delete the element at index
    void deletion(int index);

    // linear search
    int linearSearch(int key);

    // binary search
    int binarySearch(int key);

    // get the element at index
    int get(int index);

    // set the element to num at index
    void set(int index, int num);

    // returns the max element in array
    int maxi();

    // returns the min element in array
    int mini();

    // returns the sum of all elements
    int sum();

    // returns the average of all elements
    float average();

    // reverse the array
    void reverse();

    // insert num in sorted Array
    void insertSort(int num);

    // check if array is sorted
    bool isSorted();

    // rearrange all negative elements on left and positive on right
    void reArrange();

    // merge 2 sorted arrays
    Array *merge(Array arr2);

    // union of 2 sorted arrays
    Array *unionOfArrays(Array arr2);

    // intersection of 2 sorted arrays
    Array *intersection(Array arr2);

    // tells the elements of first array which is not in second
    Array *difference(Array arr2);
};

// time complexity is O(1)
void Array ::swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// constructor
Array ::Array(int s)
{
    size = s;
    A = new int[s];
    length = 0;
}

// time complexity is O(n)
void Array ::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

// time complexity is O(1)
void Array ::add(int num)
{
    if (length >= size)
    {
        cout << "Sorry, array is full!" << endl;
        return;
    }
    A[length] = num;
    length++;
}

// time complexity is O(n)
void Array ::insert(int index, int num)
{
    if (length >= size)
    {
        cout << "Sorry, array is full!" << endl;
        return;
    }
    if (index >= length || index < 0)
    {
        cout << "Invalid index! It must be less than length of array and greater than 0" << endl;
        return;
    }
    int i;
    for (i = length; i > index; i--)
    {
        A[i] = A[i - 1];
    }
    A[i] = num;
    length++;
}

// time complexity is O(n)
void Array ::deletion(int index)
{
    if (index < 0 || index >= length)
    {
        cout << "Invalid index! It must be less than length of array and greater than 0" << endl;
        return;
    }
    for (int i = index; i < length - 1; i++)
    {
        A[i] = A[i + 1];
    }
    length--;
}

// time complexity is O(n)
int Array ::linearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {

            if (i == 0)
            {
                return i;
            }

            // improving linear search so that if user further search for same key, it will take less time

            // transposition (slowly brings key ahead)
            // swap(&A[i], &A[i-1]);

            // move to front/head (brings current key ahead)
            // swap(&A[i], &A[0]);

            return i;
        }
    }
    return -1;
}

// time complexity is O(log n)
int Array ::binarySearch(int key)
{
    int low = 0;
    int high = length - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == A[mid])
        {
            return mid;
        }
        else if (key < A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// time complexity is O(1)
int Array ::get(int index)
{
    if (index < 0 || index >= length)
    {
        cout << "Invalid index! It must be less than length of array and greater than 0" << endl;
        return -1;
    }
    return A[index];
}

// time complexity is O(1)
void Array ::set(int index, int num)
{
    if (index < 0 || index >= length)
    {
        cout << "Invalid index! It must be less than length of array and greater than 0" << endl;
        return;
    }
    A[index] = num;
}

// time complexity is O(n)
int Array ::maxi()
{
    int maxElement = A[0];
    for (int i = 1; i < length; i++)
    {
        maxElement = max(maxElement, A[i]);
    }
    return maxElement;
}

// time complexity is O(n)
int Array ::mini()
{
    int minElement = A[0];
    for (int i = 1; i < length; i++)
    {
        minElement = max(minElement, A[i]);
    }
    return minElement;
}

// time complexity is O(n)
int Array ::sum()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += A[i];
    }
    return sum;
}

// time complexity is O(n)
float Array ::average()
{
    return (float)sum() / length;
}

// time complexity is O(n)
void Array ::reverse()
{
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(&A[i], &A[j]);
    }
}

// time complexity is O(n)
void Array ::insertSort(int num)
{
    if (length == size)
    {
        cout << "Array is full!";
        return;
    }
    int i = length - 1;
    while (i >= 0 && A[i] > num)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = num;
    length++;
}

// time complexity is O(n)
bool Array ::isSorted()
{
    int i = 0;
    while (i < length - 1)
    {
        if (A[i + 1] < A[i])
        {
            return false;
        }
        i++;
    }
    return true;
}

// time complexity is O(n)
void Array ::reArrange()
{
    int i = 0;
    int j = length - 1;

    while (i < j)
    {
        while (A[i] < 0)
        {
            i++;
        }
        while (A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    }
}

// time complexity is O(m + n) or simply O(n)
Array *Array ::merge(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else
        {
            arr3->A[k++] = arr2.A[j++];
        }
    }
    while (i < length)
    {
        arr3->A[k++] = A[i++];
    }
    while (j < arr2.length)
    {
        arr3->A[k++] = arr2.A[j++];
    }

    arr3->length = k;

    return arr3;
}

// time complexity is O(m + n) or simply O(n)
Array *Array ::unionOfArrays(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else if (A[i] > arr2.A[j])
        {
            arr3->A[k++] = arr2.A[j++];
        }
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    while (i < length)
    {
        arr3->A[k++] = A[i++];
    }
    while (j < arr2.length)
    {
        arr3->A[k++] = arr2.A[j++];
    }

    arr3->length = k;

    return arr3;
}

// time complexity is O(m + n) or simply O(n)
Array *Array ::intersection(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
        {
            i++;
        }
        else if (A[i] > arr2.A[j])
        {
            j++;
        }
        else
        {
            arr3->A[k++] = A[i];
            i++;
            j++;
        }
    }

    arr3->length = k;
    return arr3;
}

// time complexity is O(m + n) or simply O(n)
Array *Array ::difference(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else if (A[i] > arr2.A[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    while (i < length) {
        arr3->A[k++] = A[i++];
    }

    arr3->length = k;
    return arr3;
}

int main()
{
    int size;
    cin >> size;
    Array arr(size);

    int length;
    cin >> length;

    for (int i = 0; i < length; i++)
    {
        int a;
        cin >> a;
        arr.add(a);
    }

    arr.display();

    // arr.insert(10, 10);
    // arr.display();

    // arr.deletion(2);
    // arr.display();

    // cout << arr.linearSearch(4) << endl;
    // arr.display();

    // cout << arr.binarySearch(4) << endl;

    // cout << arr.get(2) << endl;
    // arr.set(2, 45);
    // cout << arr.maxi() << endl;
    // cout << arr.mini() << endl;
    // cout << arr.sum() << endl;
    // cout << arr.average() << endl;
    // arr.reverse();
    // arr.insertSort(4);
    // cout << arr.isSorted() << endl;
    // arr.reArrange();

    Array arr2(size);

    int l;
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int a;
        cin >> a;
        arr2.add(a);
    }

    Array *a3 = arr.difference(arr2);
    a3->display();

    return 0;
}
