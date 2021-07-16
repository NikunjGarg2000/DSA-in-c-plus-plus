#include <iostream>
#include <stack>
#include<algorithm>
#include <vector>
using namespace std;

// reversing the string then changing opening and closing brackets
vector<char> reverse(string s)
{
    vector<char> rev;
    int n = s.length();
    for (int i = n - 1; i >= 0; i++) {
        if (s[i] == '(') {
            rev.push_back(')');
            continue;
        } 
        if (s[i] == ')') {
            rev.push_back('(');
            continue;
        }
        rev.push_back(s[i]);
    }
    return rev;
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

vector<char> infixToPrefix(string oldS)
{
    stack<char> st;
    string result = "";
    vector<char> s = reverse(oldS);

    for (int i = 0; i < s.size(); i++)
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
            if (!st.empty()) {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(s[i])) {
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
    vector<char> res = reverse(result);
    return res;
}

int main()
{
    string s = "(a-b/c)*(a/k-l)";
    vector<char> res = infixToPrefix(s);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }
    return 0;
}