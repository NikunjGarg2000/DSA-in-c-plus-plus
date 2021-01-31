// find if the given word, array of characters is a palindrome or not
// eg racecar is a palindrome word

#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    char arr[n + 1];
    cin >> arr;

    bool check = true;

    // time complexity is O(n)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[n - 1 - i])
        {
            check = false;
            break;
        }
    }

    if (check == true)
    {
        cout << "Word is a palindrome!";
    }
    else
    {
        cout << "Word is not a palindrome!";
    }

    return 0;
}