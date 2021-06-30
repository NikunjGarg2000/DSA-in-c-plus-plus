#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front;
    int back;

public:
    Queue(int n)
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
            cout << "Queue is full" << endl;
            return;
        }
        arr[++back] = x;
    }

    int dequeue()
    {
        int x = -1;
        if (front == back)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        front++;
        return arr[front];
    }

    bool isEmpty()
    {
        return front == back;
    }
};

void BFS(int graph[][8], int n, int start)
{
    Queue q(n);
    int u = start;
    int visitedArray[n] = {0};

    cout << u << " ";
    q.enqueue(u);
    visitedArray[u] = 1;

    while (!q.isEmpty())
    {
        int i = q.dequeue();
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] == 1 && visitedArray[j] == 0)
            {
                cout << j << " ";
                q.enqueue(j);
                visitedArray[j] = 1;
            }
        }
    }
}

int main()
{
    int graph[][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 1, 1, 1, 0, 0, 0},
                      {0, 1, 0, 0, 1, 0, 0, 0},
                      {0, 1, 0, 0, 0, 1, 0, 0},
                      {0, 1, 1, 0, 0, 1, 0, 0},
                      {0, 0, 0, 1, 1, 0, 1, 1},
                      {0, 0, 0, 0, 0, 1, 0, 0},
                      {0, 0, 0, 0, 0, 1, 0, 0}};
    BFS(graph, 8, 1);
    return 0;
}