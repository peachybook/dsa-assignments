//Write a program to count the number of occurrences of a given key in a singly linked
/* list and then delete all the occurrences.
Input: Linked List : 1->2->1->2->1->3->1 , key: 1
Output: Count: 4 , Updated Linked List: 2->2->3.*/

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


// Count occurrences and delete all occurrences
int countAndDelete(Node*& head, int key) {

    int count = 0;

    // Delete matching nodes from beginning
    while (head != NULL && head->data == key) {

        Node* temp = head;

        head = head->next;

        delete temp;

        count++;
    }

    // Delete matching nodes from the rest of the list
    Node* temp = head;

    while (temp != NULL && temp->next != NULL) {

        if (temp->next->data == key) {

            Node* toDelete = temp->next;

            temp->next = toDelete->next;

            delete toDelete;

            count++;
        }
        else {
            temp = temp->next;
        }
    }

    return count;
}


// Display linked list
void display(Node* head) {

    if (head == NULL) {
        cout << "List is empty.";
        return;
    }

    Node* temp = head;

    while (temp != NULL) {

        cout << temp->data;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }
}


// Main function
int main() {

    Node* head = NULL;

    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {

        cin >> value;

        insertEnd(head, value);
    }

    cout << "Enter key: ";
    cin >> key;

    int count = countAndDelete(head, key);

    cout << "\nCount: " << count << endl;

    cout << "Updated Linked List: ";
    display(head);

    return 0;
}

