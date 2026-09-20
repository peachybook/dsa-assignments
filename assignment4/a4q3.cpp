#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q, first, second;

    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }

    // Store first half
    for (int i = 0; i < n / 2; i++)
    {
        first.push(q.front());
        q.pop();
    }

    // Store second half
    while (!q.empty())
    {
        second.push(q.front());
        q.pop();
    }

    // Interleave
    while (!first.empty())
    {
        cout << first.front() << " ";
        first.pop();

        cout << second.front() << " ";
        second.pop();
    }

    return 0;
}