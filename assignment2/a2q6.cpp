/*Write a program to implement the following operations on a Sparse Matrix,
assuming the matrix is represented using a triplet.
(a) Transpose of a matrix.
(b) Addition of two matrices.
(c) Multiplication of two matrices.
*/
#include <iostream>
using namespace std;

struct Sparse {
    int row;
    int col;
    int value;
};


// Input sparse matrix
void input(Sparse a[]) {
    int rows, cols, nonZero;

    cout << "Enter rows, columns and number of non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    a[0].row = rows;
    a[0].col = cols;
    a[0].value = nonZero;

    cout << "Enter row, column and value:\n";

    for (int i = 1; i <= nonZero; i++) {
        cin >> a[i].row >> a[i].col >> a[i].value;
    }
}


// Display triplet
void display(Sparse a[]) {
    cout << "\nRow\tCol\tValue\n";

    for (int i = 0; i <= a[0].value; i++) {
        cout << a[i].row << "\t"
             << a[i].col << "\t"
             << a[i].value << endl;
    }
}


// (a) Transpose
void transpose(Sparse a[], Sparse b[]) {

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    int k = 1;

    for (int col = 0; col < a[0].col; col++) {

        for (int i = 1; i <= a[0].value; i++) {

            if (a[i].col == col) {

                b[k].row = a[i].col;
                b[k].col = a[i].row;
                b[k].value = a[i].value;

                k++;
            }
        }
    }
}


// (b) Addition
bool addition(Sparse a[], Sparse b[], Sparse c[]) {

    if (a[0].row != b[0].row ||
        a[0].col != b[0].col) {

        return false;
    }

    c[0].row = a[0].row;
    c[0].col = a[0].col;

    int i = 1;
    int j = 1;
    int k = 1;

    while (i <= a[0].value && j <= b[0].value) {

        if (a[i].row == b[j].row &&
            a[i].col == b[j].col) {

            int sum = a[i].value + b[j].value;

            if (sum != 0) {
                c[k].row = a[i].row;
                c[k].col = a[i].col;
                c[k].value = sum;
                k++;
            }

            i++;
            j++;
        }

        else if (a[i].row < b[j].row ||
                (a[i].row == b[j].row &&
                 a[i].col < b[j].col)) {

            c[k] = a[i];
            k++;
            i++;
        }

        else {
            c[k] = b[j];
            k++;
            j++;
        }
    }

    while (i <= a[0].value) {
        c[k++] = a[i++];
    }

    while (j <= b[0].value) {
        c[k++] = b[j++];
    }

    c[0].value = k - 1;

    return true;
}


// (c) Multiplication
bool multiplication(Sparse a[], Sparse b[], Sparse c[]) {

    if (a[0].col != b[0].row) {
        return false;
    }

    c[0].row = a[0].row;
    c[0].col = b[0].col;

    int k = 1;

    for (int i = 1; i <= a[0].value; i++) {

        for (int j = 1; j <= b[0].value; j++) {

            if (a[i].col == b[j].row) {

                int row = a[i].row;
                int col = b[j].col;
                int value = a[i].value * b[j].value;

                int x;

                for (x = 1; x < k; x++) {

                    if (c[x].row == row &&
                        c[x].col == col) {

                        c[x].value += value;
                        break;
                    }
                }

                if (x == k) {
                    c[k].row = row;
                    c[k].col = col;
                    c[k].value = value;
                    k++;
                }
            }
        }
    }

    c[0].value = k - 1;

    return true;
}


int main() {

    Sparse a[100], b[100], c[100];

    int choice;

    cout << "1. Transpose\n";
    cout << "2. Addition\n";
    cout << "3. Multiplication\n";

    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {

        input(a);

        transpose(a, b);

        cout << "\nOriginal Matrix:";
        display(a);

        cout << "\nTranspose:";
        display(b);
    }

    else if (choice == 2) {

        cout << "\nMatrix A:\n";
        input(a);

        cout << "\nMatrix B:\n";
        input(b);

        if (addition(a, b, c)) {
            cout << "\nResult:";
            display(c);
        }
        else {
            cout << "\nAddition not possible.";
        }
    }

    else if (choice == 3) {

        cout << "\nMatrix A:\n";
        input(a);

        cout << "\nMatrix B:\n";
        input(b);

        if (multiplication(a, b, c)) {
            cout << "\nResult:";
            display(c);
        }
        else {
            cout << "\nMultiplication not possible.";
        }
    }

    else {
        cout << "Invalid choice.";
    }

    return 0;
}

