/*Develop a Menu-driven program to demonstrate the following operations of Arrays
——MENU——-
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5. LINEAR SEARCH
6. EXIT
*/
#include <iostream>
using namespace std;
int arr[100];
int n = 0;
// one freate the array 
void create() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement() {
    int pos, value;

    if (n >= 100) {
        cout << "Array is full.\n";
        return;
    }

    cout << "Enter position (1 to " << n + 1 << "): ";
    cin >> pos;

    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position.\n";
        return;
    }

    cout << "Enter value: ";
    cin >> value;

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    n++;

    cout << "Element inserted successfully.\n";
}

void deleteElement() {
    int pos;

    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Enter position (1 to " << n << "): ";
    cin >> pos;

    if (pos < 1 || pos > n) {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Element deleted successfully.\n";
}

void linearSearch() {
    int value;
    bool found = false;

    cout << "Enter element to search: ";
    cin >> value;

    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            cout << "Element found at position " << i + 1 << ".\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Element not found.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n------ MENU ------\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                insertElement();
                break;

            case 4:
                deleteElement();
                break;

            case 5:
                linearSearch();
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}