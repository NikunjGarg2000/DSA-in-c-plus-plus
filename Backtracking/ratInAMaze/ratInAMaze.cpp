#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{

    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }

    return false;
}
 
bool ratInAMaze(int **arr, int x, int y, int n, int **solArray)
{

    if (x == n - 1 && y == n - 1)
    {
        solArray[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n))
    {

        solArray[x][y] = 1;

        if (ratInAMaze(arr, x + 1, y, n, solArray))
        {
            return true;
        }

        if (ratInAMaze(arr, x, y + 1, n, solArray))
        {
            return true;
        }

        solArray[x][y] = 0;  // Backtracking
        return false;
    }
    return false;
}

int main()
{

    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int **solArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }

    if (ratInAMaze(arr, 0, 0, n, solArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}