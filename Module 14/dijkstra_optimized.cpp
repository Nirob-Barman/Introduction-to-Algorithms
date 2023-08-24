#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> adjList[N];
int dist[N];
bool visited[N];

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int parentNode = parent.second;

        if (visited[parentNode])
        {
            continue;
        }

        visited[parentNode] = true;
        int parentCost = parent.first;

        for (int i = 0; i < adjList[parentNode].size(); i++)
        {
            pair<int, int> child = adjList[parentNode][i];
            int childNode = child.first;
            int childWeight = child.second;

            if (parentCost + childWeight < dist[childNode])
            {
                dist[childNode] = parentCost + childWeight;
                pq.push({dist[childNode], childNode});
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
        int a, b, w;
        cin >> a >> b >> w;
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dist[i] << endl;
    }

    return 0;
}

// input
// 5 7
// 1 3 2
// 1 2 10
// 2 3 1
// 3 4 2
// 4 5 7
// 2 4 3
// 2 5 2

// output
// Node 1: 0
// Node 2: 3
// Node 3: 2
// Node 4: 4
// Node 5: 5