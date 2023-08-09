#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];

void dfs(int u, vector<int> &connectedVertices)
{
    // section 1: actions just after entering a node u
    visited[u] = true;
    connectedVertices.push_back(u);

    for (int v : adjList[u])
    {
        // section 2: actions before entering a new neighbor
        if (!visited[v])
            dfs(v, connectedVertices);

        // section 3: actions after exiting a neighbor
    }
    // section 4: actions before exiting a node u
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
        // section 1: A node is being processed
        for (int v : adjList[u])
        {
            // section 2 : Child Processing
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                // section 3: Child Processing
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

    cout << "Number of connected components: " << connectedComponents.size() << endl;

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
// Number of connected components : 1

// input
// 7
// 5
// 1 2
// 1 3
// 2 3
// 2 4
// 5 6

// output
// Number of connected components : 3
// input
// 7
// 5
// 1 2
// 1 3
// 2 3
// 2 4
// 5 6
// 6 7

// output
// Number of connected components : 2
