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
        dsu_union(a, b);
    }
    
    cout << dsu_find(1) << endl;
    cout << dsu_find(2) << endl;
    cout << dsu_find(3) << endl;
    cout << dsu_find(4) << endl;
    cout << dsu_find(5) << endl;
    cout << dsu_find(6) << endl;
    cout << dsu_find(7) << endl;

    return 0;
}

// input
// 7 4
// 1 2
// 2 3
// 4 5
// 6 5

// output
// 1
// 1
// 1
// 4
// 4
// 4
// 7