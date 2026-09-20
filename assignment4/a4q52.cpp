#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void push(int x)
{
    int n = q.size();

    q.push(x);

    for (int i = 0; i < n; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

void pop()
{
    if (q.empty())
        cout << "Stack is Empty\n";
    else
    {
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }
}

void peek()
{
    if (q.empty())
        cout << "Stack is Empty\n";
    else
        cout << "Top: " << q.front() << endl;
}

void display()
{
    if (q.empty())
        cout << "Stack is Empty\n";
    else
    {
        queue<int> temp = q;

        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    pop();
    peek();

    return 0;
}