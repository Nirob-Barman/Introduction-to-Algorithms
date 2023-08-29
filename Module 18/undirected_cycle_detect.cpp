#include <bits/stdc++.h>

using namespace std;

int parent[1000];
int parentLevel[1000];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;
    }
}

int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentLevel[leaderA] > parentLevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentLevel[leaderB] > parentLevel[leaderA])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    dsu_set(node);

    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        // cout << leaderA << " " << leaderB << endl;
        if (leaderA == leaderB)
        {
            cout << "Cycel detected in between: " << a << " " << b << endl;
        }
        else
        {
            dsu_union(a, b);
        }
    }

    return 0;
}

// input
// 5 5
// 1 2
// 2 5
// 1 4
// 2 3
// 4 5

// output
// Cycel detected in between : 4 5

// input
// 5 5
// 1 2
// 4 5
// 2 5
// 1 4
// 2 3

// output
// Cycel detected in between: 1 4
