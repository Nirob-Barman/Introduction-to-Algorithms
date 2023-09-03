#include <bits/stdc++.h>

using namespace std;

int fibonaccci(int n)
{
    // if (n == 0 || n == 1)
    if (n <= 1)
        return 1;

    // int ans1 = fibonaccci(n - 1);
    // int ans2 = fibonaccci(n - 2);

    // return ans1 + ans2;

    return fibonaccci(n - 1) + fibonaccci(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << fibonaccci(n) << endl;
    return 0;
}