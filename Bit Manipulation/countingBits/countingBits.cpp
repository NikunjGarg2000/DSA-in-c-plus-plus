// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

// Example 1:

// Input: 2
// Output: [0,1,1]

// Example 2:

// Input: 5
// Output: [0,1,1,2,1,2]

#include <iostream>
#include <vector>
using namespace std;

// time complexity is O(nm) where m is no of ones present
vector<int> countbits(int num)
{
    vector<int> count;
    for (int i = 0; i <= num; i++)
    {
        int noOfSetBits = 0;
        int a = i;
        while (a)
        {
            a = a & (a - 1);
            noOfSetBits++;
        }
        count.push_back(noOfSetBits);
    }
    return count;
}

// time complexity is O(n)
vector<int> countBits(int num)
{
    vector<int> count;
    // for i = 0
    count.push_back(0);
    for (int i = 1; i <= num; i++)
    {
        if (i % 2 != 0)
        {
            count.push_back(count[i - 1] + 1);
        }
        else
        {
            count.push_back(count[i / 2]);
        }
    }
    return count;
}

int main()
{

    int n;
    cin >> n;
    vector<int> ans;
    ans = countbits(n);
    for (int i = 0; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}