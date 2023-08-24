#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adjList[n + 1];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "Index " << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
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
// Index 1: 2 4 3
// Index 2: 1
// Index 3: 1 4
// Index 4: 1 3
