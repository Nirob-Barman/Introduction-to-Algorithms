#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];
int level[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        // pop a node from the queue and insert unvisited neighbours of the node
        int u = q.front();
        q.pop();
        // section 1: A node is being processed
        cout << "Visiting Node: " << u << endl;
        for (int v : adjList[u])
        {
            // section 2 : Child Processing
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                // section 3: Child Processing
                level[v] = level[u] + 1;
            }
        }
        // section 4: same as section 1
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

    bfs(1);

    for (int i = 1; i <= n; i++)
        cout << "Level of " << i << ": " << level[i] << endl;

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
// 7 8
// 10 11
// 10 12

// output
// Visiting Node: 1
// Visiting Node: 2
// Visiting Node: 3
// Visiting Node: 10
// Visiting Node: 4
// Visiting Node: 5
// Visiting Node: 9
// Visiting Node: 11
// Visiting Node: 12
// Visiting Node: 6
// Visiting Node: 7
// Visiting Node: 8

// Level of 1: 0
// Level of 2: 1
// Level of 3: 1
// Level of 4: 2
// Level of 5: 2
// Level of 6: 3
// Level of 7: 3
// Level of 8: 4
// Level of 9: 2
// Level of 10: 1
// Level of 11: 2
// Level of 12: 2