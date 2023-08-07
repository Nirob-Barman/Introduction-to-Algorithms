#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];
int depth[N];
int height[N];

void dfs(int u)
{
    // section 1: actions just after entering a node u
    visited[u] = true;
    // cout << "Visiting node: " << u << endl;
    for (int v : adjList[u])
    {
        // section 2: actions before entering a new neighbor
        if (!visited[v])
        {
            depth[v] = depth[u] + 1;
            dfs(v);
            // if (height[v] + 1 > height[u])
            //     height[u] = height[v] + 1;
            height[u] = max(height[u], height[v] + 1);
        }

        // section 3: actions after exiting a neighbor
    }
    // section 4: actions before exiting a node u
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

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Node " << i << ": ";
    //     for (int j : adjList[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Depth of Node: " << i << ": " << depth[i] << endl;
    }
    cout << "************************" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Height of Node: " << i << ": " << height[i] << endl;
    }

    return 0;
}

// input
// 12
// 11
// 1 2
// 1 3
// 1 10
// 2 4
// 2 5
// 3 9
// 5 6
// 5 7
// 6 8
// 10 11
// 10 12

// output
// Depth of Node: 1: 0
// Depth of Node: 2: 1
// Depth of Node: 3: 1
// Depth of Node: 4: 2
// Depth of Node: 5: 2
// Depth of Node: 6: 3
// Depth of Node: 7: 3
// Depth of Node: 8: 4
// Depth of Node: 9: 2
// Depth of Node: 10: 1
// Depth of Node: 11: 2
// Depth of Node: 12: 2
// ************************
// Height of Node: 1: 4
// Height of Node: 2: 3
// Height of Node: 3: 1
// Height of Node: 4: 0
// Height of Node: 5: 2
// Height of Node: 6: 1
// Height of Node: 7: 0
// Height of Node: 8: 0
// Height of Node: 9: 0
// Height of Node: 10: 1
// Height of Node: 11: 0
// Height of Node: 12: 0