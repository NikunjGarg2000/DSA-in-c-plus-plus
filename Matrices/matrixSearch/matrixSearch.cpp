// Given a matrix and a key, find out if that matrix have that key

#include <iostream>
using namespace std;

int main()
{

    int n, m, key;
    cin >> n >> m >> key;

    int matrix[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Brute Force Approach
    // time complexity is O(n*m)

    // bool found = false;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (matrix[i][j] == key)
    //         {
    //             found = true;
    //             break;
    //         }
    //     }
    // }

    // if (found == true)
    // {
    //     cout << "Element found!" << endl;
    // }
    // else
    // {
    //     cout << "Element not found!" << endl;
    // }


    // More Efficient Approach
    // Only if all rows and columns are sorted in asc order
    // time complexity is O(n + m)

    int r = 0, c = m - 1;
    bool found = false;
    while (r < n && c >= 0)
    {
        if (matrix[r][c] == key)
        {
            found = true;
            break;
        }
        else if (matrix[r][c] > key)
        {
            c--;
        }
        else
        {
            r++;
        }
    }

    if (found == true)
    {
        cout << "Element found!" << endl;
    }
    else
    {
        cout << "Element not found!" << endl;
    }

    return 0;
}