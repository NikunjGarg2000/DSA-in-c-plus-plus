// Put elements at even position in the end of linked list

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

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);

    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void evenAfterOdd(node *&head)
{
    node *odd = head;
    node *even = head->next;
    node *evenStart = head->next;

    while (even->next != NULL && odd->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;

        // checking this if there are odd no. of nodes then odd->next would be NULL
        if (odd->next != NULL)
        {
            even->next = odd->next;
            even = even->next;
        }
    }

    odd->next = evenStart;

    // if there are even then even->next would automatically be NULL though we are doing this for odd no. of nodes
    even->next = NULL;
}

void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{

    node *head = NULL;

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        insertAtTail(head, arr[i]);
    }

    display(head);
    evenAfterOdd(head);
    display(head);

    return 0;
}