#include <iostream>
using namespace std;

#define MAX 5

int q[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == MAX - 1;
}

void enqueue(int x) {
    if (isFull())
        cout << "Queue is Full\n";
    else {
        if (front == -1)
            front = 0;
        q[++rear] = x;
        cout << "Inserted\n";
    }
}

void dequeue() {
    if (isEmpty())
        cout << "Queue is Empty\n";
    else {
        cout << "Deleted: " << q[front] << endl;
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void peek() {
    if (isEmpty())
        cout << "Queue is Empty\n";
    else
        cout << "Front element: " << q[front] << endl;
}

void display() {
    if (isEmpty())
        cout << "Queue is Empty\n";
    else {
        for (int i = front; i <= rear; i++)
            cout << q[i] << " ";
        cout << endl;
    }
}

int main() {
    int choice, x;

    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. isEmpty";
        cout << "\n4. isFull";
        cout << "\n5. Display";
        cout << "\n6. Peek";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> x;
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                cout << (isEmpty() ? "Queue is Empty\n" : "Queue is Not Empty\n");
                break;

            case 4:
                cout << (isFull() ? "Queue is Full\n" : "Queue is Not Full\n");
                break;

            case 5:
                display();
                break;

            case 6:
                peek();
                break;

            case 7:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}