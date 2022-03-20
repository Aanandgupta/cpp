#include <bits/stdc++.h>
using namespace std;

void ser()
{
    return;
}
int main()
{
    unordered_map<int, vector<int>> m;
    unordered_map<int, int> visited1;
    int n, t, x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x] = {};
    }
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        m[x].push_back(y);
    }
    cin >> x >> y;
    vector<int> ans1;
    queue<int> q;
    visited1[x] = 1;
    q.push(x);
    while (!q.empty())
    {
        int z = q.front();
        q.pop();
        for (int i : m[z])
        {
            if (visited1[i] == 0)
            {
                if (i == y)
                    ans1.push_back(z);
                else
                {
                    visited1[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    sort(ans1.begin(), ans1.end());
    ser();
    for (int i : ans1)
        cout << i << " ";
    return 0;
}