#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> topKFrequent(vector<int>& arr, int k)
{
    unordered_map<int, int> freq;

    // Count frequency
    for (int x : arr)
    {
        freq[x]++;
    }

    // Store {frequency, number}
    vector<pair<int, int>> v;

    for (auto it : freq)
    {
        v.push_back({it.second, it.first});
    }

    // Sort by frequency first,
    // and number if frequencies are equal
    sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b)
    {
        if (a.first != b.first)
            return a.first > b.first;

        return a.second > b.second;
    });

    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        ans.push_back(v[i].second);
    }

    return ans;
}

int main()
{
    int n, k;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;

    vector<int> ans = topKFrequent(arr, k);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}