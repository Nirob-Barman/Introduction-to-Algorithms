#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];
int depth[N];
int height[N];

void dfs(int u)
{
    visited[u] = true;
    for (int v : adjList[u])
    {
        if (!visited[v])
        {
            depth[v] = depth[u] + 1;
            dfs(v);
            // if (height[v] + 1 > height[u])
            //     height[u] = height[v] + 1;
            height[u] = max(height[u], height[v] + 1);
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

    dfs(1);

    int desiredNode;
    cin >> desiredNode;
    cout << "Depth of " << desiredNode << " = " << depth[desiredNode] << endl;
    cout << "Height of " << desiredNode << " = " << height[desiredNode] << endl;
    return 0;
}

// input
// 7
// 6
// 1 2
// 2 4
// 2 5
// 1 3
// 3 6
// 1 7
// 7

// output
// Depth of 7 = 1
// Height of 7 = 0

// input
// 7
// 6
// 1 2
// 2 4
// 2 5
// 1 3
// 3 6
// 1 7
// 7

// output
// Depth of 7 = 1
// Height of 7 = 0
