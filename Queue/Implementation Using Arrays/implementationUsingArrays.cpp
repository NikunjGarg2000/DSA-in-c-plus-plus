#include <iostream>
using namespace std;

class queue
{
    int size;
    int front;
    int back;
    int *arr;

public:
    queue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        back = -1;
    }

    void enqueue(int x)
    {
        if (back == size - 1)
        {
            cout << "No space in queue" << endl;
            return;
        }
        back++;
        arr[back] = x;

    }

    void dequeue()
    {
        if (front == back)
        {
            cout << "No elements in queue" << endl;
            return;
        }
        front++;
    }

    int peek()
    {
        if (front == back)
        {
            cout << "No elements in queue" << endl;
            return -1;
        }
        return arr[front+1];
    }

    bool empty()
    {
        if (front == back)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    queue q(5);
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