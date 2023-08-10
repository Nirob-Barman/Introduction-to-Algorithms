#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    stack<int> reverseOrder;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        reverseOrder.push(u);
        for (int v : adjList[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }

    while (!reverseOrder.empty())
    {
        cout << reverseOrder.top() << " ";
        reverseOrder.pop();
    }
    cout << endl;
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

    return 0;
}

// input
// 4
// 4
// 1 2
// 3 4
// 1 3
// 2 4

// output
// 4 3 2 1
