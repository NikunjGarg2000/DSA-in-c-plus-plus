#include<iostream>
using namespace std;

int firstOccurence(int array[], int n, int i, int key) {

    if (i == n) {
        return -1;
    }

    if (array[i] == key) {
        return i;
    }

    return firstOccurence(array, n, i + 1, key);

}

int lastOccurence(int array[], int n, int i, int key) {

    if (i == n) {
        return -1;
    }

    int restArray = lastOccurence(array, n, i+1, key);
    if (restArray != -1) {
        return restArray;
    }

    if (array[i] == key) {
        return i;
    }
    return -1;
 
}

int main() {

    int array[10] = {1,2,4,1,2,3,4,2,4,2};

    cout << firstOccurence(array, 10, 0, 2) << endl;
    cout << lastOccurence(array, 10, 0, 2) << endl;


    return 0;
}