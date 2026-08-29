/*
Write a program to reverse a linked list.

Input: 1 -> 2 -> 3 -> 4 -> NULL
Output: 4 -> 3 -> 2 -> 1 -> NULL
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


// Insert node at end
void insertEnd(Node*& head, int value) {

    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}


// Reverse linked list
void reverseList(Node*& head) {

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {

        next = current->next;

        current->next = prev;

        prev = current;

        current = next;
    }

    head = prev;
}


// Display linked list
void display(Node* head) {

    Node* temp = head;

    while (temp != NULL) {

        cout << temp->data << " -> ";

        temp = temp->next;
    }

    cout << "NULL";
}


// Main function
int main() {

    Node* head = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {

        cin >> value;

        insertEnd(head, value);
    }

    cout << "\nOriginal List: ";
    display(head);

    reverseList(head);

    cout << "\nReversed List: ";
    display(head);

    return 0;
}
