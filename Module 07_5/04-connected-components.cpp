#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];

void dfs(int u, vector<int> &connectedVertices)
{
    visited[u] = true;
    connectedVertices.push_back(u);

    for (int v : adjList[u])
    {
        if (!visited[v])
            dfs(v, connectedVertices);
    }
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        // pop a node from the queue and insert unvisited neighbours of the node
        int u = q.front();
        q.pop();
        for (int v : adjList[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
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
    int cc = 0;
    vector<vector<int>> connectedComponents;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            vector<int> connectedVertices;
            dfs(i, connectedVertices);
            cc++;
            connectedComponents.push_back(connectedVertices);
        }
    }
    cout << "Number of connected components: " << cc << endl;

    // cout << "Number of connected components: " << connectedComponents.size() << endl;

    for (auto &component : connectedComponents)
    {
        cout << "Vertices in connected component: ";
        for (int vertex : component)
        {
            cout << vertex << " ";
        }
        cout << endl;
    }
}

// input
// 6
// 4
// 1 2
// 2 3
// 3 4
// 5 6

// output
// Number of connected components : 2

// input
// 7
// 4
// 1 2
// 2 3
// 3 4
// 5 6

// output
// Number of connected components : 3
