#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
vector<pair<int, int>> adjList[N];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        // adjList[u].push_back(make_pair(v, w));
        // adjList[v].push_back({u,w});
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << " : ";
        for (auto j : adjList[i])
        {
            cout << "(" << j.first << ", " << j.second << ")";
        }
        cout << endl;
    }

    return 0;
}

// input
// 4
// 5
// 1 2 8
// 1 3 9
// 2 4 11
// 4 3 17
// 3 2 15

// output
// List 1 : (2, 8)(3, 9)
// List 2 : (4, 11)
// List 3 : (2, 15)
// List 4 : (3, 17)
