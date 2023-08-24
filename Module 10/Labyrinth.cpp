#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 5;
vector<string> g;
int visited[N][N];
int level[N][N];
pii parent[N][N];
int n, m;
vector<pii> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();

        for (auto d : direction)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != '#')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j};
            }
        }
    }
}

int main()
{
    int si, sj, di, dj;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (x[j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
        g.push_back(x);
    }
    bfs(si, sj);
    if (level[di][dj] != 0)
    {
        cout << "YES" << endl;
        cout << level[di][dj] << endl;
    }
    else
        cout << "NO" << endl;

    vector<pii> path;
    pii current = {di, dj};
    while (!(current.first == si && current.second == sj))
    {
        path.push_back(current);
        current = parent[current.first][current.second];
    }
    reverse(path.begin(), path.end());
    // for (auto p : path)
    //     cout << p.first << " " << p.second << endl;
    for (int i = 1; i < path.size(); i++)
    {
        if (path[i - 1].first == path[i].first)
        {
            if (path[i - 1].second == path[i].second - 1)
                cout << "R";
            else
                cout << "L";
        }
        else
        {
            if (path[i - 1].first == path[i].first - 1)
                cout << "D";
            else
                cout << "U";
        }
    }
    return 0;
}