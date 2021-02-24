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

class queue
{
    node *front;
    node *back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }

    void enqueue(int x)
    {
        node *n = new node(x);

        if (n == NULL) {
            cout << "No space in heap!" << endl;
            return;
        }

        if (front == NULL)
        {
            front = n;
            back = n;
            return;
        }

        back->next = n;
        back = n;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        node *toDelete = front;
        front = front->next;
        delete toDelete;
    }

    int peek()
    {
        if (front == NULL)
        {
            cout << "No element in queue" << endl;
            return -1;
        }
        return front->data;
    }

    bool empty()
    {
        return (front == NULL);
    }
};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.empty() << endl;
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.empty() << endl;

    return 0;
}