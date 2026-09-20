#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> bitonicGenerator(vector<int> &arr)
{

    // Create arrays to store elements at even
    // and odd indices.
    vector<int> evenArr;
    vector<int> oddArr;

    // Put elements into evenArr[] and oddArr[]
    // according to their positions.
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
            evenArr.push_back(arr[i]);
        else
            oddArr.push_back(arr[i]);
    }

    // Sort even indexed elements in ascending order.
    sort(evenArr.begin(), evenArr.end());

    // Sort odd indexed elements in descending order.
    sort(oddArr.begin(), oddArr.end(), greater<int>());

    int idx = 0;

    // Copy all even indexed elements first.
    for (int i = 0; i < evenArr.size(); i++)
        arr[idx++] = evenArr[i];

    // Copy all odd indexed elements next.
    for (int i = 0; i < oddArr.size(); i++)
        arr[idx++] = oddArr[i];

    return arr;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4, 5, 9, 13, 14, 12};

    vector<int> res = bitonicGenerator(arr);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}