#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long int ll;
#define mod (ll)(1e9 + 7)
#define f(i, a, x) for (ll i = a; i < x; ++i)
#define f2(i, x) for (ll i = 1; i <= x; ++i)
#define fa(i, x) for (auto &i : x)
#define endl '\n'
vector<vector<ll>> dp;
vector<bool> vis;
unordered_map<ll, list<ll>> adj;
void dfs(ll i)
{
    vis[i] = true;
    dp[i][0] = dp[i][1] = 1;
    fa(j, adj[i])
    {
        if (!vis[j])
        {
            dfs(j);
            dp[i][0] = (dp[i][0] * dp[j][1]) % mod;
            dp[i][1] = (dp[i][1] * (dp[j][0] + dp[j][1]) % mod) % mod;
        }
    }
}

void solve(int tt)
{
    ll n, u, v;
    cin >> n;
    dp.resize(n + 1, vector<ll>(2, 0));
    f(i, 0, n - 1)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis.resize(n + 1, false);
    dfs(1);
    ll ans = (dp[1][0] + dp[1][1]) % mod;
    cout << ans << endl;
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
    auto start1 = high_resolution_clock::now();
    int cs;
    solve(cs);
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cerr << "Time: " << duration.count() / 1000 << endl;
    return 0;
}
