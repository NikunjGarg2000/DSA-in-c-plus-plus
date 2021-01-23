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

// function to find the length of linked list
int length(node *head)
{
    node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// function to intersect 2 linked lists
// at pos of first to end of other
void intersect(node *&head1, node *&head2, int pos)
{
    node *temp1 = head1;
    while (--pos)
    {
        temp1 = temp1->next;
    }

    node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

// function to find if there is an intersection
int findIntersection(node *head1, node *head2)
{
    int l1 = length(head1);
    int l2 = length(head2);

    node *ptr1;
    node *ptr2;

    // diff d
    int d;

    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d--)
    {
        if (ptr1 == NULL)
        {
            return -1;
        }
        ptr1 = ptr1->next;
    }

    while (ptr1->next != NULL && ptr2->next != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main()
{
    node *head1 = NULL;
    insertAtHead(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 6);
    display(head1);

    node *head2 = NULL;
    insertAtHead(head2, 9);
    insertAtTail(head2, 10);
    display(head2);

    intersect(head1, head2, 4);
    display(head1);
    display(head2);

    cout << findIntersection(head1, head2) << endl;

    return 0;
}