#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];

int knapsack(int n, int s, int value[], int weight[])
{
    // base case
    if (n == 0 || s == 0)
        return 0;
    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }

    if (weight[n - 1] <= s)
    {
        int op1 = knapsack(n - 1, s - weight[n - 1], value, weight) + value[n - 1];
        int op2 = knapsack(n - 1, s, value, weight);
        return dp[n][s] = max(op1, op2);
    }
    else
    {
        return dp[n][s] = knapsack(n - 1, s, value, weight);
    }
}

int main()
{
    int n;
    cin >> n;
    int value[n], weight[n];
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int s;
    cin >> s;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << "Memoization: " << knapsack(n, s, value, weight) << endl;

    return 0;
}