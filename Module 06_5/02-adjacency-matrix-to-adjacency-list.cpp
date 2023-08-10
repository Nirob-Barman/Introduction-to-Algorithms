#include <bits/stdc++.h>

using namespace std;

// const int N = 1e3 + 5; // Maximum number of nodes
// int adjMat[N][N];

int main()
{
    int n;
    cin >> n;

    int adjacencyMatrix[n + 1][n + 1];

    // Read the adjacency matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> adjacencyMatrix[i][j];
        }
    }

    vector<vector<int>> adjacencyList(n + 1);
    // Convert adjacency matrix to adjacency list
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adjacencyMatrix[i][j] == 1)
            {
                adjacencyList[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "Adjacency list of node " << i << ": ";
        for (int neighbor : adjacencyList[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}

// input
// 4
// 0 0 0 1
// 1 0 0 1
// 1 1 0 0
// 0 0 1 0

// output
// Adjacency list of node 1: 4
// Adjacency list of node 2: 1 4
// Adjacency list of node 3: 1 2
// Adjacency list of node 4: 3

// input
// 5
// 0 0 0 0 0
// 1 0 0 1 1
// 1 1 0 1 1
// 1 1 1 0 0
// 0 0 1 0 0

// output
// Adjacency list of node 1:
// Adjacency list of node 2: 1 4 5
// Adjacency list of node 3: 1 2 4 5
// Adjacency list of node 4: 1 2 3
// Adjacency list of node 5: 3
