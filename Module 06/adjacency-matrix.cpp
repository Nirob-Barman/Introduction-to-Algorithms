#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int adjMat[N][N];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        // adjMat[v][u] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// input
// 4
// 5
// 1 2
// 1 3
// 2 4
// 4 3
// 3 2

// output
// 0 1 1 0 0 
// 0 0 0 1 0 
// 0 1 0 0 0 
// 0 0 1 0 0 
