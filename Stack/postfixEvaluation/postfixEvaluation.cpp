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
            // analyze since starting from start like 25* so 2 will be at bottom so 5 will be B and 2 will be A
            int B = st.top();
            st.pop();
            int A = st.top();
            st.pop();

            // push A operator B
            switch (s[i])
            {
            case '+':
                st.push(A + B);
                break;
            case '-':
                st.push(A - B);
                break;
            case '*':
                st.push(A * B);
                break;
            case '/':
                st.push(A / B);
                break;
            case '^':
                st.push(pow(A, B));
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