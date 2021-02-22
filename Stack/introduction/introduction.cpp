// imagine stack as a pile of books
// last book on top and hence first one to out
// it follows LIFO (last in first out)

#include <iostream>
using namespace std;

#define n 100

// implementation of stack using arrays (just to learn since we have stack already in stl)
class stack
{
    int *arr;
    int top;

    public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack is full!";
            return;
        }
        arr[++top] = x;
    }

    void pop()
    {
        if (top == -1) {
            cout << "No element to pop!";
            return;
        }
        top--;
    }

    int Top() {
        if (top == -1) {
            cout << "Stack is empty!";
            return -1;
        }
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    cout << s.Top() << endl;
    s.pop();
    cout << s.empty() << endl;
    s.pop();
    cout << s.Top() << endl;

    return 0;
}