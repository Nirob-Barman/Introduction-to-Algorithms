#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 9;

int main()
{
    int n, e;
    cin >> n >> e;

    int dis[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
            if (i == j)
                dis[i][j] = 0;
        }
    }

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = w;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (dis[i][j] == INF)
    //             cout << "X ";
    //         else
    //             cout << dis[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    // cout << "Updated" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dis[i][j] == INF)
                cout << "X ";
            else
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// input
// 4 6
// 1 2 3
// 2 1 2
// 1 4 5
// 4 3 2
// 3 2 1
// 2 4 4

// output
// 0 3 7 5
// 2 0 6 4
// 3 1 0 5
// 5 3 2 0
