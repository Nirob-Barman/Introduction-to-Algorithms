#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
vector<bool> visited(N, false);

void dfs(int u)
{
    visited[u] = true;
    for (int v : adjList[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<int> leaders;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            leaders.push_back(i);
            dfs(i);
        }
    }
    cout << leaders.size() - 1 << endl;
    // for (auto l : leaders)
    //     cout << l << " ";
    for (int i = 1; i < leaders.size(); i++)
        cout << leaders[i - 1] << " " << leaders[i] << endl;
    return 0;
}