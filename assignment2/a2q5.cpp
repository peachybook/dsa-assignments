/*Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ
𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming an array is used to store elements of the following matrices,
implement an efficient way that reduces the space requirement.
(a) Diagonal Matrix.
(b) Tri-diagonal Matrix.
(c) Lower triangular Matrix.
(d) Upper triangular Matrix.
(e) Symmetric Matrix
*/ 


#include <iostream>
#include <vector>
using namespace std;


// (a) DIAGONAL MATRIX


void diagonalMatrix() {
    int n;
    cout << "Enter size of diagonal matrix: ";
    cin >> n;

    // Only n elements are required
    vector<int> A(n);

    cout << "Enter diagonal elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "\nDiagonal Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j)
                cout << A[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}


// (b) TRI-DIAGONAL MATRIX

void triDiagonalMatrix() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    // Number of elements = 3n - 2
    vector<int> A(3 * n - 2);

    cout << "Enter elements row-wise along the three diagonals:\n";

    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j || i == j + 1 || j == i + 1) {
                cin >> A[k++];
            }
        }
    }

    cout << "\nTri-diagonal Matrix:\n";

    k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j || i == j + 1 || j == i + 1)
                cout << A[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}


// (c) LOWER TRIANGULAR MATRIX

void lowerTriangularMatrix() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;

    // Number of elements = n(n+1)/2
    int size = n * (n + 1) / 2;

    vector<int> A(size);

    cout << "Enter lower triangular elements:\n";

    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> A[k++];
        }
    }

    cout << "\nLower Triangular Matrix:\n";

    k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i >= j)
                cout << A[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}


// (d) UPPER TRIANGULAR MATRIX


void upperTriangularMatrix() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;

    // Number of elements = n(n+1)/2
    int size = n * (n + 1) / 2;

    vector<int> A(size);

    cout << "Enter upper triangular elements:\n";

    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> A[k++];
        }
    }

    cout << "\nUpper Triangular Matrix:\n";

    k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i <= j)
                cout << A[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}



// (e) SYMMETRIC MATRIX


void symmetricMatrix() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    // Store only lower triangular part
    // Number of elements = n(n+1)/2
    int size = n * (n + 1) / 2;

    vector<int> A(size);

    cout << "Enter lower triangular elements:\n";

    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> A[k++];
        }
    }

    cout << "\nSymmetric Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i >= j) {
                // Lower triangular element
                k = i * (i + 1) / 2 + j;
            }
            else {
                // Use corresponding element from lower triangle
                k = j * (j + 1) / 2 + i;
            }

            cout << A[k] << " ";
        }

        cout << endl;
    }
}



int main() {

    int choice;

    cout << "1. Diagonal Matrix\n";
    cout << "2. Tri-diagonal Matrix\n";
    cout << "3. Lower Triangular Matrix\n";
    cout << "4. Upper Triangular Matrix\n";
    cout << "5. Symmetric Matrix\n";

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {

        case 1:
            diagonalMatrix();
            break;

        case 2:
            triDiagonalMatrix();
            break;

        case 3:
            lowerTriangularMatrix();
            break;

        case 4:
            upperTriangularMatrix();
            break;

        case 5:
            symmetricMatrix();
            break;

        default:
            cout << "Invalid choice!";
    }

    return 0;
}
