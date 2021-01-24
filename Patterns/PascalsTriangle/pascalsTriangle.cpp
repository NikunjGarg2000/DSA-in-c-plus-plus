// pascal's triangle looks like for n = 5

//           1
//         1   1
//       1   2   1
//     1   3   3   1
//   1   4   6   4   1

#include <iostream>
using namespace std;

// factorial function for approach 2

long factorial(int n)
{
    int fact = 1;
    for (int i = n; i >= 1; i--)
    {
        fact = fact * i;
    }
    return fact;
}

int main()
{

    int n;
    cin >> n;

    // Approach 1

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n - i; j++) {
    //         cout << "  ";
    //     }
    //     int number = 1;
    //     for (int j = 1; j <= i; j++) {
    //         cout << number << " " << "  ";
    //         number = number * (i - j) / j;
    //     }
    //     cout << endl;
    // }

    // Approach 2 using factorial function

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++)
        {
            // since we know pascal's triangle have values acc to nCr
            cout << (factorial(i) / (factorial(j) * factorial(i - j))) << "   ";
        }
        cout << endl;
    }

    return 0;
}