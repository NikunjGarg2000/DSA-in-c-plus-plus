#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node (int val) {
        data = val;
        next = NULL;
    }
};

void insertAtHead (node* &head, int val) {
    node* n = new node(val);

    n->next = head;
    head = n;
}

void insertAtTail (node* &head, int val) {
    node* n = new node(val);

    if (head == NULL) {
        head = n;
        return;
    }

    node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = n;
}

void display (node* head) {
    node* temp = head;

    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int length(node* head) {
    node* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;

}

node* appendk (node* &head, int k) {    
    node* newHead;
    node* newTail;
    node* tail = head;

    int count = 1;
    int l = length(head);

    while (tail->next != NULL) {
        if (count == l - k) {
            newTail = tail;
        }
        if (count == l - k + 1) {
            newHead = tail;
        }
        count++;
        tail = tail->next;
    }

    tail ->next = head;
    newTail->next = NULL;

    return newHead;
}

int main() {

    node* head = NULL;
    insertAtHead(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);

    node* newHead = appendk(head, 3);
    display(newHead);

    return 0;
}