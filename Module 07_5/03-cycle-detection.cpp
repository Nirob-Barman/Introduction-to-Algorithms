#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];
int parent[N];

bool dfs(int u, int p = -1)
{

    bool cycleExist = false;
    visited[u] = true;

    for (int v : adjList[u])
    {
        if (v == p)
            continue;

        if (visited[v])
            return true;

        cycleExist = cycleExist || dfs(v, u);
    }
    return cycleExist;
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

    bool isCycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        isCycle |= dfs(i);
    }
    if (isCycle)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

// input
// 4
// 4
// 1 2
// 2 3
// 3 4
// 4 2

// output
// YES

// input
// 6
// 4
// 1 2
// 2 3
// 3 4
// 5 6

// output
// NO