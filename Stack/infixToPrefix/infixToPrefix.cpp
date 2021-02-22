#include <iostream>
#include <stack>
using namespace std;

// reversing the string then changing opening and closing brackets
void reverse(string &s)
{
    string rev = "";
    int i, j;
    for (i = s.length() - 1, j = 0; i >= 0; i--, j++)
    {
        rev[j] = s[i];
        if (rev[j] == '(')
            rev[j] = ')';
        if (rev[j] == ')')
            rev[j] = '(';
    }
    s = rev;
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(string s)
{
    stack<char> st;
    string result = "";
    reverse(s);

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            result += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(st.top()) > precedence(s[i])) {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result);
    return result;
}

int main()
{
    string s = "(a-b/c)*(a/k-l)";
    reverse(s);
    cout << s;
    cout << infixToPrefix(s);
    return 0;
}