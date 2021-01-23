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
    n -> next = head;
    head = n;
}

void insertAtTail (node* &head, int val) {
    node* n = new node(val);

    if (head == NULL) {
        head = n;
        return;
    }

    node* temp = head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = n;
}

void display (node* head) {
    node* temp = head;

    while (temp != NULL) {
        cout << temp -> data << "->";
        temp = temp -> next;
    }

    cout << "NULL" << endl;
}

// making a cycle in linked list
void makeCycle (node* &head, int pos) {
    node* temp = head;
    node* startNode;

    int count = 1;
    while (temp -> next != NULL) {
        if (count == pos) {
            startNode = temp;
        }

        temp = temp -> next;
        count++;
    }

    temp -> next = startNode;
}

// detecting whether a cycle is present in linked list
// using floyd's algorithm (tortoise and the hare algo)
bool detectCycle (node* head) {
    // representing hare (moves fast)
    node* fast = head;  
    // representing tortoise (moves slow)
    node* slow = head;

    while (fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

// removing cycle from a linked list assuming that it had a cycle for sure
// here too using floyd's algorithm (tortoise and the hare algo)
void removeCycle (node* &head) {
    node* fast = head;
    node* slow = head;

    do {
        fast = fast -> next -> next;
        slow = slow -> next;
    } while (fast != slow);

    fast = head;
    while (fast -> next != slow -> next) {
        fast = fast -> next;
        slow = slow -> next;
    }

    slow -> next = NULL;
}

int main () {

    node* head = NULL;
    insertAtHead (head, 1);
    insertAtTail (head, 2);
    insertAtTail (head, 3);
    insertAtTail (head, 4);
    insertAtTail (head, 5);
    insertAtTail (head, 6);
    display (head);
    makeCycle (head, 3);
    // display (head);
    cout << detectCycle (head) << endl;
    removeCycle (head);
    cout << detectCycle (head) << endl;
    display (head);

    return 0;
}