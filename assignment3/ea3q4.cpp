#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures)
{
    vector<int> res(temperatures.size(), 0);
    stack<pair<int, int>> st;

    for (int i = 0; i < temperatures.size(); i++)
    {
        int t = temperatures[i];

        while (!st.empty() && t > st.top().first)
        {
            auto p = st.top();
            st.pop();

            res[p.second] = i - p.second;
        }

        st.push({t, i});
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> temperatures(n);

    for (int i = 0; i < n; i++)
        cin >> temperatures[i];

    vector<int> result = dailyTemperatures(temperatures);

    for (int x : result)
        cout << x << " ";

    return 0;
}