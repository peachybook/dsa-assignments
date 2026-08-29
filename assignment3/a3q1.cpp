/*Develop a menu driven program for the following operations on a Singly Linked
List.
(a) Insertion at the beginning.
(b) Insertion at the end.
(c) Insertion in between (before or after a node having a specific value, say 'Insert a
new Node 35 before/after the Node 30').
(d) Deletion from the beginning.
(e) Deletion from the end.
(f) Deletion of a specific node, say 'Delete Node 60').
(g) Search for a node and display its position from head.
(h) Display all the node values.*/


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;


// (a) INSERTION AT BEGINNING
void insertBeginning(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}


// (b) INSERTION AT END
void insertEnd(int value) {
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


// (c) INSERT BEFORE A SPECIFIC NODE
void insertBefore(int value, int target) {

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    // Target is the first node
    if (head->data == target) {
        insertBeginning(value);
        return;
    }

    Node* temp = head;

    while (temp->next != NULL &&
           temp->next->data != target) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Target node not found.\n";
        return;
    }

    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = temp->next;

    temp->next = newNode;
}


// (c) INSERT AFTER A SPECIFIC NODE
void insertAfter(int value, int target) {

    Node* temp = head;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Target node not found.\n";
        return;
    }

    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = temp->next;

    temp->next = newNode;
}


// (d) DELETE FROM BEGINNING
void deleteBeginning() {

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    head = head->next;

    delete temp;
}


// (e) DELETE FROM END
void deleteEnd() {

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    // Only one node
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}


// (f) DELETE A SPECIFIC NODE
void deleteSpecific(int value) {

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    // Delete first node
    if (head->data == value) {
        deleteBeginning();
        return;
    }

    Node* temp = head;

    while (temp->next != NULL &&
           temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Node not found.\n";
        return;
    }

    Node* toDelete = temp->next;

    temp->next = toDelete->next;

    delete toDelete;
}


// (g) SEARCH FOR A NODE
void search(int value) {

    Node* temp = head;

    int position = 1;

    while (temp != NULL) {

        if (temp->data == value) {
            cout << "Node found at position "
                 << position << " from head.\n";
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Node not found.\n";
}


// (h) DISPLAY ALL NODES
void display() {

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Linked List: ";

    while (temp != NULL) {
        cout << temp->data;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}


// MAIN FUNCTION
int main() {

    int choice;
    int value;
    int target;

    do {

        cout << "\n\n===== SINGLY LINKED LIST =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;

                insertBeginning(value);
                break;


            case 2:
                cout << "Enter value: ";
                cin >> value;

                insertEnd(value);
                break;


            case 3:
                cout << "Enter new value: ";
                cin >> value;

                cout << "Insert before which node: ";
                cin >> target;

                insertBefore(value, target);
                break;


            case 4:
                cout << "Enter new value: ";
                cin >> value;

                cout << "Insert after which node: ";
                cin >> target;

                insertAfter(value, target);
                break;


            case 5:
                deleteBeginning();
                break;


            case 6:
                deleteEnd();
                break;


            case 7:
                cout << "Enter value to delete: ";
                cin >> value;

                deleteSpecific(value);
                break;


            case 8:
                cout << "Enter value to search: ";
                cin >> value;

                search(value);
                break;


            case 9:
                display();
                break;


            case 10:
                cout << "Program ended.\n";
                break;


            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 10);

    return 0;
}
