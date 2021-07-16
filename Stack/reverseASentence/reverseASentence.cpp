#include <iostream>
#include <stack>
using namespace std;

// Ques: reverse a sentence. Also trim start and end spaces. Also if there are 2 or more spaces in between make that 1 space.
// eg. " hey,  how are you?  " 
// your result should look like: "you? are how hey,"
string reverseSentence(string s)
{
    stack<string> ans;
    int i = 0;
    string temp = "";
    while (i < s.size())
    {
        temp = "";
        while (s[i] != ' ' && i < s.size())
        {
            temp += s[i];
            i++;
        }
        i++;
        // handling 2 or more spaces, that we don't have to push
        if (temp == "")
        {
            continue;
        }
        ans.push(temp);
    }

    temp = "";
    while (!ans.empty())
    {
        temp += (ans.top() + " ");
        ans.pop();
    }
    return temp.substr(0, temp.length() - 1);
}

int main()
{
    string s = "Hey, how are you doing?";
    string result = reverseSentence(s);
    cout << result << endl;
    return 0;
}