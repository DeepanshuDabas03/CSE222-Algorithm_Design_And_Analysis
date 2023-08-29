#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const ll INF = 1e18;
vector<vector<pair<ll, pair<ll, ll>>>> adj;
ll find_k(ll b, ll d)
{
    ll left = 0, right = b, k = 0,a;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        a = (d + mid + 1);

        if (a <=(ll)ceil(b*1.0/a))
        {
            k = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return k;
}
bool ok = 1;
vector<ll> solve()
{
    ll n, m;
    cin >> n >> m;

    if (m == 0)
    {
        ok = 0;
        return {0};
    }
    adj.resize(n);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        if (u == v)
            continue;
        adj[u].pb({v, {a, b}});
        adj[v].pb({u, {a, b}});
    }
    vector<ll> distances(n, INF);
    distances[0] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {

        ll u = pq.top().second;
        ll dist = pq.top().first;
        pq.pop();
        if (dist > distances[u])
            continue;

        for (auto [v, ab] : adj[u])
        {
            ll a = ab.first, b = ab.second;
            ll k = find_k(b, dist);
            ll time_to_v = k + a + (b / (k + dist + 1));
            if (dist + time_to_v < distances[v])
            {
                distances[v] = dist + time_to_v;
                pq.push({distances[v], v});
            }
        }
    }

    return distances;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ll> distances = solve();

    if (!ok)
    {
        cout << -1 << endl;
        return 0;
    }
    if (distances[distances.size() - 1] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << distances[distances.size() - 1] << endl;
    }

    return 0;
}
