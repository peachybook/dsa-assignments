#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxCombinations(int N, int K, vector<int>& A, vector<int>& B) {
        
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());

        priority_queue<
            pair<int, pair<int, int>>
        > pq;

        set<pair<int, int>> visited;

        pq.push({A[0] + B[0], {0, 0}});
        visited.insert({0, 0});

        vector<int> ans;

        while (K--) {
            auto top = pq.top();
            pq.pop();

            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back(sum);

            // Move in A
            if (i + 1 < N && !visited.count({i + 1, j})) {
                pq.push({A[i + 1] + B[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            // Move in B
            if (j + 1 < N && !visited.count({i, j + 1})) {
                pq.push({A[i] + B[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return ans;
    }
};