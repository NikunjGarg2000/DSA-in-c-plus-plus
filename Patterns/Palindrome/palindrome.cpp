// palindrome pattern looks like

//           1
//         2 1 2
//       3 2 1 2 3
//     4 3 2 1 2 3 4
//   5 4 3 2 1 2 3 4 5

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        // code for half part

        //           1
        //         2 1
        //       3 2 1
        //     4 3 2 1
        //   5 4 3 2 1

        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }

        // code for other vertical half5

        for (int j = 2; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}