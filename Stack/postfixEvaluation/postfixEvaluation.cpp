#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int postfixEvaluation(string s)
{
    stack<int> st;

    // here we start from start and go to end
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        // s[i] is operand 
        {
            st.push(s[i] - '0');
        }
        else
        // s[i] is operator
        {
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();

            // here we do B operator A
            switch (s[i])
            {
            case '+':
                st.push(B + A);
                break;
            case '-':
                st.push(B - A);
                break;
            case '*':
                st.push(B * A);
                break;
            case '/':
                st.push(B / A);
                break;
            case '^':
                st.push(pow(B, A));
                break;

            default:
                break;
            }
        }
    }

    return st.top();
}

int main()
{
    string s = "46+2/5*7+";
    cout << postfixEvaluation(s);
    return 0;
}