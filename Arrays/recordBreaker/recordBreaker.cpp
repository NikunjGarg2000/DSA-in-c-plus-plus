#include<iostream>
#include<climits>
using namespace std;

int main() {

    int n;
    cin >> n;

    int array[n + 1];
    array[n] = -1;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    if (n == 1) {
        cout << "1";
        return 0;
    }

    int recordBreakingDays = 0;
    int i = 0;
    int maximum = INT_MIN;
    while (i < n) {

        if(array[i] > maximum && array[i] > array[i + 1]) {
            recordBreakingDays++;
        }
        maximum = max(maximum, array[i]);
        i++;
    }
    
    cout << recordBreakingDays << " ";

    return 0;
}