#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int dist[N];
bool visited[N];
int par[N];
vector<int> adjList[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    par[s] = -1;
    visited[s] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : adjList[parent])
        {
            if (!visited[child])
            {
                q.push(child);
                par[child] = parent;
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
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Node " << i << ": " << par[i] << endl;
    // }
    int d;
    cin >> d;

    if (visited[d])
    {
        vector<int> path;
        int x = d;
        while (x != -1)
        {
            // cout << x << endl;
            path.push_back(x);
            x = par[x];
        }
        reverse(path.begin(), path.end());
        for (int val : path)
        {
            cout << val << " ";
        }
    }
    else
    {
        cout << "Path nai" << endl;
    }
    return 0;
}

// input
// 5 7
// 1 3
// 1 2
// 3 4
// 2 3
// 2 5
// 4 5
// 2 4
// 5

// output
// 1 2 5