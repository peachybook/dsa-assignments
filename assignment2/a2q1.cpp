/*Implement the binary search algorithm regarded as a fast search algorithm
with run-time complexity of Ο(log n) in comparison to the Linear Search.*/
#include <iostream> 
using namespace std;
int Bs(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > x)
            right = mid - 1;

        else
            left = mid + 1;
    }

    return -1;
}


int main() { 
int arr[]= {2,3,4,10,40};
int x = 10;
 int n = sizeof(arr) / sizeof(arr[0]);
int result = Bs(arr ,0 , n-1 , x);

if(result ==-1) 
 cout << "element not found";
else 
 cout << "element found at index " << result; 
return 0; 
} 
/////////////////output//////////////////////
/////    element found at index 3     //////
