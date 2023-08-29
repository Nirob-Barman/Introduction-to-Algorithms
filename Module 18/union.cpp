#include <bits/stdc++.h>

using namespace std;

int parent[1000];
int parentSize[1000];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
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
        parent[leaderB] = leaderA;
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
    cout << dsu_find(1)<<endl;
    cout << dsu_find(2)<<endl;
    cout << dsu_find(3)<<endl;
    cout << dsu_find(4)<<endl;
    cout << dsu_find(5)<<endl;
    cout << dsu_find(6)<<endl;
    cout << dsu_find(7)<<endl;
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
// 6
// 6
// 6
// 7
