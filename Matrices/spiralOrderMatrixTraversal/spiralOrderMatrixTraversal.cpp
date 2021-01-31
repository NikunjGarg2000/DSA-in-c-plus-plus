// Given a matrix, print it in spiral order

// eg
// Input:  1    2   3   4
//         5    6   7   8
//         9   10  11  12
//         13  14  15  16
// Output: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

#include <iostream>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;

    int array[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> array[i][j];
        }
    }

    // time complexity is O(m*n)

    int row_start = 0, row_end = n - 1, column_start = 0, column_end = m - 1;

    while (row_start <= row_end && column_start <= column_end)
    {

        // row_start
        for (int col = column_start; col <= column_end; col++)
        {
            cout << array[row_start][col] << " ";
        }
        row_start++;

        // colum_end
        for (int row = row_start; row <= row_end; row++)
        {
            cout << array[row][column_end] << " ";
        }
        column_end--;

        // row_end
        for (int col = column_end; col >= column_start; col--)
        {
            cout << array[row_end][col] << " ";
        }
        row_end--;

        // column_start
        for (int row = row_end; row >= row_start; row--)
        {
            cout << array[row][column_start] << " ";
        }
        column_start++;
    }

    return 0;
}