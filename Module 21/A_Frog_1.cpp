// // top down approach
// #include <bits/stdc++.h>

// using namespace std;

// const int N = 1e5 + 5;
// int dp[N];

// int solve(int a[], int n)
// {
//     if (n == 1)
//     {
//         return 0;
//     }

//     if (dp[n] != -1)
//         return dp[n];
//     else if (n == 2)
//     {
//         // dp[n] = abs(a[2] - a[1]);
//         // return dp[n];
//         return dp[n] = abs(a[2] - a[1]);
//     }
//     else
//     {
//         int choice1 = solve(a, n - 1) + abs(a[n] - a[n - 1]);
//         int choice2 = solve(a, n - 2) + abs(a[n] - a[n - 2]);
//         return dp[n] = min(choice1, choice2);
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int a[n + 1];
//     for (int i = 1; i <= n; i++)
//     {
//         dp[i] = -1;
//         cin >> a[i];
//     }

//     cout << solve(a, n);

//     return 0;
// }



// bottom up approach
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cost[n + 1], dp[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }

    dp[1] = 0;
    dp[2] = abs(cost[2] - cost[1]);
    
    for (int i = 3; i <= n; i++)
    {
        // int choice1 = dp[i - 2] + abs(cost[i] - cost[i - 2]);
        // int choice2 = dp[i - 1] + abs(cost[i] - cost[i - 1]);
        dp[i] = min(dp[i - 2] + abs(cost[i] - cost[i - 2]), dp[i - 1] + abs(cost[i] - cost[i - 1]));
    }
    cout << dp[n] << endl;
    
    return 0;
}