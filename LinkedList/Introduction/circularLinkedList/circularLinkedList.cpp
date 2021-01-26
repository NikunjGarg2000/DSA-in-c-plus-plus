#include <iostream>
using namespace std;

// same as in simple linked list
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

// inserting at start of linked list
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        n->next = n;
        return;
    }

    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;
}

// inserting at last of linked list
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void deletion(node *&head, int pos)
{
    int count = 1;
    node *temp = head;

    if (pos == 1)
    {
        node *toDelete = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = head->next;
        head = head->next;
        delete toDelete;
        return;
    }

    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }

    node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void display(node *head)
{
    node *temp = head;

    // here we can't use while loop since initially temp = head therefore using do while loop
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);

    cout << "NULL" << endl;
}

int main()
{

    node *head = NULL;
    insertAtHead(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    insertAtTail(head, 5);
    display(head);
    insertAtHead(head, 0);
    display(head);
    deletion(head, 6);
    display(head);
    deletion(head, 1);
    display(head);

    return 0;
}