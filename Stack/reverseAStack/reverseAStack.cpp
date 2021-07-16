#include<iostream>
#include<stack>
using namespace std;

// brute force will be to take an empty stack and pop from given and push to that simply.
// this one is efficient without using another stack(recursive way)


// this function is using recursive call stack simply
void insertAtBottom(stack<int> &s, int element) {
    if (s.empty()) {
        s.push(element);
        return;
    }
    int topElement = s.top();
    s.pop();
    insertAtBottom(s, topElement);
    
    s.push(topElement);
}

void reverseAStack (stack<int> &s) {
    if (s.empty()) {
        return;
    }

    // assume we got reversed stack except top element.
    // so just pick top and insert at bottom
    int topElement = s.top();
    s.pop();
    reverseAStack(s);
    insertAtBottom(s, topElement);
}

int main() {

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseAStack(s);
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}