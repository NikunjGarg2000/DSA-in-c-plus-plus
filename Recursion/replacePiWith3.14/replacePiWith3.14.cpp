#include <iostream>
using namespace std;

void replacePi(string s)
{

    if (s.length() == 0)
    {
        return;
    }

    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replacePi(s.substr(2));
    }
    else
    {
        cout << s[0];
        replacePi(s.substr(1));
    }
}

// or this
string replace(string s, int n, int i = 0, string ans = "")
{
    if (i >= n)
        return ans;
    if (s.substr(i, 2) == "pi")
    {
        ans = ans + "3.14";
        return replace(s, n, i + 2, ans);
    }
    else
    {
        ans = ans + s[i];
        return replace(s, n, i + 1, ans);
    }
}

int main()
{

    string s;
    cin >> s;

    replacePi(s);

    return 0;
}