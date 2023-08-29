#include <bits/stdc++.h>

using namespace std;

int parent[8] = {-1, -1, 1, 1, 6, 4, -1, -1};

int find(int n)
{
    while (parent[n] != -1)
    {
        n = parent[n];
    }
    return n;
}

int main()
{
    cout << find(1) << endl;
    cout << find(2) << endl;
    cout << find(3) << endl;
    cout << find(4) << endl;
    cout << find(5) << endl;
    cout << find(6) << endl;
    cout << find(7) << endl;

    return 0;
}