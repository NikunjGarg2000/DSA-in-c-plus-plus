#include <iostream>
using namespace std;

// remove duplicate only consecutively
string removeDupli(string s)
{

    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0];
    string ans = removeDupli(s.substr(1));

    if (ans[0] == ch)
    {
        return ans;
    }

    return ch + ans;
}

string removeDuplicates(string s, int n, int i = 0, string ans = "")
{
    if (i == n)
        return ans;
    if (s[i] == s[i + 1])
    {
        return removeDuplicates(s, n, i + 1, ans);
    }
    else
    {
        return removeDuplicates(s, n, i + 1, ans + s[i]);
    }
}

int main()
{

    // removeDuplicates("abaagsjaaababbbb");
    cout << removeDupli("aaaabbbbbcddddeeffffaaaa") << endl;

    return 0;
}