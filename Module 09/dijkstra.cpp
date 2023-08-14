#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 5;
const int INF = 1e9 + 10;

// vector<pair<int, int>> adjList[N];
vector<pii> adjList[N];
vector<int> dist(N, INF);
vector<bool> visited(N);

void dijkstra(int source)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (pii vPair : adjList[u])
        {
            int v = vPair.first;
            int w = vPair.second;
            if (visited[v])
                continue;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
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
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
        cout << "Distance of node " << i << " : " << dist[i] << endl;
}

// input
// 7
// 8
// 1 2 3
// 1 3 5
// 3 4 1
// 4 6 1
// 2 5 6
// 5 6 1
// 5 7 2
// 3 7 12

// output
// Distance: 3
// Path: 1 2 5 7

// output
// Distance of node 1 : 0
// Distance of node 2 : 3
// Distance of node 3 : 5
// Distance of node 4 : 6
// Distance of node 5 : 8
// Distance of node 6 : 7
// Distance of node 7 : 10