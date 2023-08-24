#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int adjMat[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            adjMat[i][j] = 0;
            if (i == j)
                adjMat[i][j] = 1;
        }
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjMat[a][b] = 1;
        adjMat[b][a] = 1;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// input
// 4 4
// 1 2
// 4 1
// 1 3
// 3 4

// output
// 1 0 0 0 0
// 0 1 1 1 1
// 0 1 1 0 0
// 0 1 0 1 1
// 0 1 0 1 1