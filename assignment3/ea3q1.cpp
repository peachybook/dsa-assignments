#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    vector<int> A = {4, 5, 2, 10, 8};
    stack<int> s;

    for (int i = 0; i < A.size(); i++)
    {
        while (!s.empty() && s.top() >= A[i])
        {
            s.pop();
        }

        if (s.empty())
            cout << -1 << " ";
        else
            cout << s.top() << " ";

        s.push(A[i]);
    }

    return 0;
}