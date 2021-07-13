#include <iostream>
using namespace std;

// Move all x to the end
string moveAllX(string s)
{

    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0];
    string ans = moveAllX(s.substr(1));

    if (ch == 'x')
    {
        return ans + ch;
    }

    return ch + ans;
}

// void moveAllX(string s)
// {
//     if (s.length() == 0)
//         return;
//     if (s[0] == 'x')
//     {
//         moveAllX(s.substr(1));
//         cout << "x";
//     }
//     else
//     {
//         cout << s[0];
//         moveAllX(s.substr(1));
//     }
// }

int main()
{

    string s;
    getline(cin, s);

    cout << moveAllX(s) << endl;

    return 0;
}