#include <iostream>
using namespace std;

class Queue
{
    int size;
    int front;
    int back;
    int *arr;

public:
    Queue(int n)
    {
        size = n;
        front = 0;
        back = 0;
        arr = new int[size];
    }

    void enqueue(int x)
    {
        if (((back + 1) % size) == front)
        {
            cout << "Queue is full" << endl;
            return;
        }
        back = ((back + 1) % size);
        arr[back] = x;
    }

    void dequeue()
    {
        if (front == back)
        {
            cout << "queue is empty" << endl;
            return;
        }
        front = ((front + 1) % size);
    }

    int peek()
    {
        if (front == back)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front + 1];
    }

    bool empty()
    {
        return front == back;
    }
};

int main()
{

    Queue q(6);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout << q.empty() << endl;
    q.dequeue();
    q.dequeue();
    q.enqueue(6);
    cout << q.peek() << endl;

    return 0;
}