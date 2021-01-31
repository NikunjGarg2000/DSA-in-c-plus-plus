// Given two matrices, multiply them 

#include <iostream>
using namespace std;

int main()
{

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int matrix1[n1][n2];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin >> matrix1[i][j];
        }
    }

    int matrix2[n2][n3];
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            cin >> matrix2[i][j];
        }
    }

    int matrix3[n1][n3];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            matrix3[i][j] = 0;
        }
    }

    // Multiplying matrices
    // time complexity is O(n1 * n2 * n3)
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            for (int k = 0; k < n2; k++)
            {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // print
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            cout << matrix3[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}