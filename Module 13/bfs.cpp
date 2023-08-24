#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int dist[N];
bool visited[N];
vector<int> adjList[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    dist[source] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        // cout << parent << endl;
        for (int i = 0; i < adjList[parent].size(); i++)
        {
            int child = adjList[parent][i];
            if (!visited[child])
            {
                q.push(child);
                dist[child] = dist[parent] + 1;
                visited[child] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    bfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dist[i] << endl;
    }

    return 0;
}

// input
// 5 4
// 1 2
// 1 3
// 2 4
// 4 5

// output
// Node 1: 0
// Node 2: 1
// Node 3: 1
// Node 4: 2
// Node 5: 3
