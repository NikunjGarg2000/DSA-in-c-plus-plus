// Question

// Isyana is given the number of visitors at her local theme park on N consecutive
// days. The number of visitors on the i-th day is Vi

// . A day is record breaking if it

// satisfies both of the following conditions:
// ● The number of visitors on the day is strictly larger than the number of
// visitors on each of the previous days.
// ● Either it is the last day, or the number of visitors on the day is strictly larger
// than the number of visitors on the following day.
// Note that the very first day could be a record breaking day!
// Please help Isyana find out the number of record breaking days.


// eg if arr is {1, 2, 0, 7, 2, 0, 2, 2} then at i = 1 and 3 i.e., 2, 7 are record breaking days therefore no of record breaking days are 2

#include <iostream>
#include <climits>
using namespace std;

int main()
{

    int n;
    cin >> n;

    // for handling last day we are taking arr of n+1 size. since for last day second condition not matters
    int array[n + 1];
    array[n] = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    if (n == 1)
    {
        cout << "1";
        return 0;
    }

    // efficient approach
    // time complexity is O(n)

    int recordBreakingDays = 0;
    int i = 0;
    int maximum = INT_MIN;
    while (i < n)
    {

        if (array[i] > maximum && array[i] > array[i + 1])
        {
            recordBreakingDays++;
        }
        maximum = max(maximum, array[i]);
        i++;
    }

    cout << recordBreakingDays << " ";

    return 0;
}