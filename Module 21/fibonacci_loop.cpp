#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;

    ll fibonacci[n + 1];
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    cout << fibonacci[n] << endl;

    return 0;
}