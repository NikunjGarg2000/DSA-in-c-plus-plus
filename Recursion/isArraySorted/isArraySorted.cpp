#include<iostream>
using namespace std;

bool isSorted(int array[], int n) {

    // Base Condition
    if (n == 1) {
        return true;
    }

    return (array[0] < array[1] && isSorted(array + 1, n - 1));

}

int main() {

    int array[5] = {1,2,3,4,5};
    cout << isSorted(array, 5) << endl;

    return 0;
}