/* Bubble Sort is the simplest sorting algorithm that works by repeatedly
swapping the adjacent elements if they are in the wrong order. Code the Bubble sort
with the following elements:
64 34 25 12 22 11 90 */
#include <bits/stdc++.h>
using namespace std;    
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
// time complexity of bubble sort is O(n^2) in the worst and average case, and O(n) in the best case when the array is already sorted.
//space complexity of bubble sort is O(1) as it requires a constant amount of additional space for the swap operation.