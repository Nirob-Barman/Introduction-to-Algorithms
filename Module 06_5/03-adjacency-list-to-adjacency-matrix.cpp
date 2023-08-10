#include <bits/stdc++.h>

using namespace std;

// const int N = 1e3 + 5; // Maximum number of nodes
// int adjMat[N][N];

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencyList(n + 1);

    // Read the adjacency list
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
    }

    // Convert adjacency list to adjacency matrix
    int adjacencyMatrix[n + 1][n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int neighbor : adjacencyList[i])
        {
            adjacencyMatrix[i][neighbor] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// input
// 3
// 5
// 1 2
// 2 3
// 1 3
// 3 1
// 3 2

// output
// 0 1 1
// 0 0 1
// 1 1 0
