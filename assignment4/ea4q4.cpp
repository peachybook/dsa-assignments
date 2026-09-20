#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;

        for (int student : students)
            q.push(student);

        int res = n;

        for (int sandwich : sandwiches) {
            int cnt = 0;

            while (cnt < n && q.front() != sandwich) {
                q.push(q.front());
                q.pop();
                cnt++;
            }

            if (q.front() == sandwich) {
                q.pop();
                res--;
            }
            else {
                break;
            }
        }

        return res;
    }
};

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    Solution obj;
    cout << obj.countStudents(students, sandwiches);

    return 0;
}