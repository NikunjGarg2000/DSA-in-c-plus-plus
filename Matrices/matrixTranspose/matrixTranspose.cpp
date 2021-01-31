// Given a matrix, find transpose of that

// eg
// INPUT
// 1 2 3 
// 4 5 6 

// OUTPUT
// 1 4
// 2 5
// 3 6

#include <iostream>
using namespace std;

#define N 4
#define M 3

// time complexity is O(M*N)
void transpose(int A[N][M], int B[M][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            B[i][j] = A[j][i];
        }
    }
}

int main()
{

    int A[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    // This is for square matrix, no need to use another matrix B
    // just swapping upper diagonal elements

    // time complexity is O(n2)
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = i; j < 3; j++)
    //     {
    //         if (i != j)
    //         {
    //             // swap
    //             int temp = array[i][j];
    //             array[i][j] = array[j][i];
    //             array[j][i] = temp;
    //         }
    //     }
    // }

    int B[3][4];
    transpose(A, B);

    // print
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}