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

void evenAfterOdd(node *head)
{
    node* oddPtr = head;
    node* evenPtr = head -> next;
    node* temp = head -> next;
    while (oddPtr -> next != NULL && evenPtr -> next != NULL) {
        oddPtr -> next = oddPtr -> next -> next;
        evenPtr -> next = evenPtr -> next -> next;
        oddPtr = oddPtr -> next;
        evenPtr = evenPtr -> next;
    }
    oddPtr->next = temp;
    if (evenPtr != NULL) {
        evenPtr->next = NULL;
    }
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

    int arr[] = {1, 2, 3, 4};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        insertAtTail(head, arr[i]);
    }

    display(head);
    evenAfterOdd(head);
    display(head);

    return 0;
}