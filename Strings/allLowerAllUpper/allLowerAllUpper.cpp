// Convert string into uppercase or lowercase

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{

    string s = "aybAjhKOdfudw";

    // time complexity is O(n) where n is the size of string

    // using STL
    // use #include <algorithm> to use it

    // Upper case
    transform(s.begin(), s.end(), s.begin(), ::toupper);

    cout << s << endl;

    // Lower case
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    cout << s << endl;

    // doing by ourself
    
    // Upper case
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
    }

    cout << s << endl;

    // Lower case
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
    }

    cout << s << endl;

    return 0;
}