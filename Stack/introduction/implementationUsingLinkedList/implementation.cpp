#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class stack
{
    public:

    node *top = NULL;

    // stack()
    // {
    //     top = NULL;
    // }

    void push(int val)
    {
        node *n = new node(val);
        n->next = top;
        top = n;
    }

    void pop()
    {
        if (!top)
        {
            cout << "No element to pop!" << endl;
            return;
        }
        node *temp = top;
        top = top->next;
        delete temp;
        temp = NULL;
    }

    void Top()
    {
        if (!top) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << top->data << endl;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        node* temp = top;
        while (temp) {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main()
{
    stack s;
    s.push(5);
    s.Top();
    s.pop();
    s.Top();
    cout << s.isEmpty() << endl;
    s.push(1);
    s.push(2);
    s.push(4);
    s.display();

    return 0;
}