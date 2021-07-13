#include <iostream>
using namespace std;

void reverse(string s)
{

    if (s.length() == 0)
    {
        return;
    }

    string ros = s.substr(1); // ros = rest of string
    reverse(ros);
    cout << s[0];
}

// tail recursion
string Treverse(string s, int i, string ans = "")
{
    if (i == -1)
        return ans;
    return Treverse(s, i - 1, ans + s[i]);
}

// good approach
// assume rest except index 0 is reversed then just add s[0] to last of that;
string reverse(string s, int n, int i = 0)
{
    if (i == n)
        return "";
    string ans = reverse(s, n, i + 1) + s.substr(i, 1);
    return ans;
}

int main()
{
    string s;
    getline(cin, s);
    reverse(s);
    cout << endl;
    cout << Treverse(s, s.length() - 1) << endl;
    cout << reverse(s, s.length()) << endl;
    return 0;
}
