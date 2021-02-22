#include<iostream>
#include<stack>
using namespace std;

void reverseSentence(string str) {
    // using LIFO property of stack, we will solve this

    stack<string> s;
    int i = 0;
    while (i < str.length()) {
        string word = "";
        while (str[i] != ' ' && i < str.length()) {
            word += str[i];
            i++;
        }
        // this to neglect space otherwise this may go on!
        i++;
        s.push(word);
    }

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

int main() {
    string s = "Hey, how are you doing?";
    reverseSentence(s);
    return 0;
}