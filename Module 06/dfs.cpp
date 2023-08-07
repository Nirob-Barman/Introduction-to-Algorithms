#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];

void dfs(int u)
{
    // section 1: actions just after entering a node u
    visited[u] = true;
    cout << "Visiting node: " << u << endl;
    for (int v : adjList[u])
    {
        // section 2: actions before entering a new neighbor
        if (!visited[v])
            dfs(v);

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

    return 0;
}

// input
// 10
// 9
// 1 2
// 1 3
// 1 10
// 2 4
// 3 5
// 3 6
// 4 7
// 4 8
// 6 9

// output
// Node 1: 2 3 10
// Node 2: 1 4
// Node 3: 1 5 6
// Node 4: 2 7 8
// Node 5: 3
// Node 6: 3 9
// Node 7: 4
// Node 8: 4
// Node 9: 6
// Node 10: 1

// Visiting node: 1
// Visiting node: 2
// Visiting node: 4
// Visiting node: 7
// Visiting node: 8
// Visiting node: 3
// Visiting node: 5
// Visiting node: 6
// Visiting node: 9
// Visiting node: 10

// input
// 11
// 10
// 1 2
// 1 3
// 1 10
// 2 4
// 3 5
// 3 6
// 4 7
// 4 8
// 6 9
// 10 11

// output
// Visiting node: 1
// Visiting node: 2
// Visiting node: 4
// Visiting node: 7
// Visiting node: 8
// Visiting node: 3
// Visiting node: 5
// Visiting node: 6
// Visiting node: 9
// Visiting node: 10
// Visiting node: 11


// input
// 9
// 10
// 1 2
// 2 3
// 3 8
// 1 5
// 5 4
// 5 6
// 4 7
// 6 7
// 7 8
// 8 9

// output
// Visiting node: 1
// Visiting node: 2
// Visiting node: 3
// Visiting node: 8
// Visiting node: 7
// Visiting node: 4
// Visiting node: 5
// Visiting node: 6
// Visiting node: 9
