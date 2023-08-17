#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 7;
const int INF = 1e9 + 9;
int dist[N][N];
int n, m;

void dist_initialize()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                dist[i][j] = INF;
        }
    }
}

void printMatrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "X ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> m;

    dist_initialize();

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w;
    }

    printMatrix();

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    cout << "After Floyd Warshal: " << endl;
    printMatrix();
    return 0;
}

// input
// 5
// 7
// 1 2 2
// 1 3 6
// 2 3 1
// 3 4 4
// 4 2 6
// 2 5 3
// 5 4 9

// output
// 0 2 6 X X
// 2 0 1 6 3
// 6 1 0 4 X
// X 6 4 0 9
// X 3 X 9 0
// After Floyd Warshal:
// 0 2 3 7 5
// 2 0 1 5 3
// 3 1 0 4 4
// 7 5 4 0 8
// 5 3 4 8 0
