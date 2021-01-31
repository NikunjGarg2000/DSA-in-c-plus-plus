// find the largest word in a given sentence

#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    // ignore used to ignore previous buffer i.e., to input new in new variable even if previous memory is left
    cin.ignore();

    char arr[n + 1];

    // getline used to input a complete sentence
    cin.getline(arr, n + 1);
    cin.ignore();

    int currLength = 0, maxLength = 0, i = 0;
    int startIndex = 0, maxIndex = 0;

    // time complexity is O(n)
    while (1)
    {

        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currLength > maxLength)
            {
                maxLength = currLength;
                maxIndex = startIndex;
            }
            currLength = 0;
            startIndex = i + 1;
        }
        else
        {
            currLength++;
        }

        if (arr[i] == '\0')
        {
            break;
        }
        i++;
    }

    cout << maxLength << endl;
    for (int i = 0; i < maxLength; i++)
    {
        cout << arr[i + maxIndex];
    }

    return 0;
}