#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
#define moda 998244353
#define f(i, a, x) for (ll i = a; i < x; ++i)
#define endl '\n'

void solve()
{
    ll n;
    cin >> n;
    vi a(n), b(n);
    f(i, 0, n) { cin >> a[i] >> b[i]; }
    vector<vi> dp(n, vi(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    f(i, 1, n)
    {
        if (a[i] != a[i - 1] && a[i] != b[i - 1])
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % moda;
        }
        else if (a[i] != b[i - 1])
        {
            dp[i][0] = dp[i - 1][1];
        }
        else if (a[i] != a[i - 1])
        {
            dp[i][0] = dp[i - 1][0];
        }
        else
        {
            dp[i][0] = 0;
        }

        if (b[i] != b[i - 1] && b[i] != a[i - 1])
        {
            dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % moda;
        }
        else if (b[i] != a[i - 1])
        {
            dp[i][1] = dp[i - 1][0];
        }
        else if (b[i] != b[i - 1])
        {
            dp[i][1] = dp[i - 1][1];
        }
        else
        {
            dp[i][1] = 0;
        }
    }
    cout << (dp[n - 1][0] + dp[n - 1][1]) % moda << '\n'; // Total number of elegant sequences
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    solve();
    return 0;
}
