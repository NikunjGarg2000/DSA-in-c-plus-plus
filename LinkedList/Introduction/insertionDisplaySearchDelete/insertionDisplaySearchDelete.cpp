#include <iostream>
using namespace std;

// making a class node since no predefined node is there
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

// inserting at head i.e., at first
// taking head by reference since we have to modify linked list
// if we use by value it will update linked list here but not of the main function
void insertAtHead(node* &head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

// inserting at the tail i.e., at last
// taking head by reference since we have to modify linked list
void insertAtTail(node *&head, int val)
{

    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    // temp != NULL means data and next both are not NULL
    // if here we do temp -> next != NULL it will move ahead of last one and will not work
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

// printing the linked list
// taking head by value since we dont have to modify our linked list
void display(node *head)
{
    node *temp = head;

    // here if we use while(temp->next != NULL), it will not print last element
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// searching in the linked list
bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    } 
    return false;
}

// delete a node
void deletion(node *&head, int val)
{

    // if we are deleting head
    if (head->data == val)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // if linked list is empty
    if (head == NULL)
    {
        return;
    }

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

int main()
{

    node *head = NULL;
    insertAtHead(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    insertAtHead(head, 4);
    display(head);
    cout << search(head, 3) << endl;
    deletion(head, 4);
    display(head);
    deletion(head, 1);
    deletion(head, 2);
    deletion(head, 3);
    display(head);

    return 0;
}