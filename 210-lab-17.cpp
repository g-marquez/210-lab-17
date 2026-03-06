//*****************************************************************************
// COMSC-210 | Lab 17 | Gabriel Marquez
// Description: this program modularizes linked list starter code in the lab 17
// module such that it leverages functions to perform linked list operations.
//*****************************************************************************

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void addAtHead(Node *);
void addAtTail(Node *);
void deleteNode(Node *);
void insertNode(Node *);
void deleteList(Node *);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        // adds node at head
        addAtHead(head);
    }
    output(head);

    // deleting a node
    deleteNode(head);
    output(head);

    // insert a node
    
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

//description: output() outputs the contents of a linked list to the console
//arguments: a pointer to the head of a linked list
//returns: void
void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

//description: addAtHead() adds a node to the head of a linked list
//arguments: a pointer to the head of a linked list
//returns: void
void addAtHead (Node *head) {
    int tmp_val = rand() % 100;
    Node *newVal = new Node; 
    if (!head) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else {
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
}

//description: addAtTail() adds a node to the tail of a linked list
//arguments: a pointer to the head of a linked list
//returns: void
void addAtTail (Node *head) {

}

//description: deleteNode() deletes a node chosen by the user from a linked list
//arguments: a pointer to the head of a linked list
//returns: void
void deleteNode(Node *head) {
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
}

//description: insertNode() inserts a node into a linked list at a position
//specified by the user
//arguments: a pointer to the head of a linked list
//returns: void
void insertNode (Node *head) {
    Node *current = head;
    Node *prev = nullptr;
    int entry;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }
}


//description: deleteList() deletes an entire linked list
//arguments: a pointer to the head of a linked list
//returns: void
void deleteList (Node *head) {

}