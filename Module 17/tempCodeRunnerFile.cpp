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