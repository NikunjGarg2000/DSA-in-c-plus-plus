#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *previous;

    node(int val)
    {
        data = val;
        next = NULL;
        previous = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);

    n->next = head;
    if (head != NULL)
    {
        head->previous = n;
    }
    head = n;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->previous = temp;
}

void deletion(node *&head, int pos)
{
    node *temp = head;

    if (pos == 1)
    {
        temp->next->previous = NULL;
        head = temp->next;
        delete temp;
        return;
    }

    int count = 1;

    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next != NULL)
    {
        temp->next->previous = temp->previous;
    }
    temp->previous->next = temp->next;
    delete temp;
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

node* reverse(node *head)
{
    node* temp = head;
    while (head != NULL) {
        temp = head -> next;
        head -> next = head -> previous;
        head -> previous = temp;
        if (head -> previous == NULL) {
            temp = head;
        }
        head = head -> previous;
    }
    return temp;
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    deletion(head, 1);
    display(head);
    node* temp = reverse(head);
    display(temp);

    return 0;
}