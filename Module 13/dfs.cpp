#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
bool visited[N];
vector<int> adjList[N];

void dfs(int u)
{
    visited[u] = true;
    cout << u << endl;
    for (int i = 0; i < adjList[u].size(); i++)
    {
        int child = adjList[u][i];
        if (!visited[child])
        {
            dfs(child);
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

    dfs(1);

    return 0;
}

// input
// 5 4
// 1 2
// 1 3
// 2 4
// 4 5

// output
// 1
// 2
// 4
// 5
// 3