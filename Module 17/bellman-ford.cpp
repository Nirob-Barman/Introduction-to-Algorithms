#include <bits/stdc++.h>

using namespace std;

class Edge
{
public:
    int u;
    int v;
    int w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edgeList;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge ed(u, v, w);
        edgeList.push_back(ed);
        // cout << ed.u << " " << ed.v << " " << ed.w << endl;
    }

    int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < edgeList.size(); j++)
        {
            Edge ed = edgeList[j];
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;

            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dis[i] << endl;
    }
    return 0;
}

// input
// 4 4
// 1 2 5
// 2 3 2
// 3 4 -2
// 1 4 10

// output
// Node 1: 0
// Node 2: 5
// Node 3: 7
// Node 4: 5
