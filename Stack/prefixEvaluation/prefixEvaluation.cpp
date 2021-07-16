#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int prefixEvaluation(string s)
{
    stack<int> st;

    // here we start from last and go to start
    for (int i = s.length() - 1; i >= 0; i--)
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
    string s = "-+7*45-20";
    cout << prefixEvaluation(s);
    return 0;
}