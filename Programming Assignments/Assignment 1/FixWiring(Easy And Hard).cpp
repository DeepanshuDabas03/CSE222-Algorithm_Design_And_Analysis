#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define f(i, x) for (int i = 0; i < x; ++i)
#define endl '\n'
ll merge(vector<ll> &ports, ll l, ll mid, ll r)
{
    ll inverse = 0;
    ll n1 = mid - l + 1;
    ll n2 = r - mid;
    ll a[n1];
    ll b[n2];
    f(i, n1)
    {
        a[i] = ports[l + i];
    }

    f(i, n2)
    {
        b[i] = ports[mid + i + 1];
    }
    ll i = 0, j = 0, k = l;
    while (i < n1 and j < n2)
    {
        if (a[i] <= b[j])
        {
            ports[k++] = a[i++];
        }
        else
        {
            ports[k++] = b[j++];
            inverse += n1 - i;
        }
    }
    while (i < n1)
    {
        ports[k++] = a[i++];
    }
    while (j < n2)
    {
        ports[k++] = b[j++];
    }
    return inverse;
}
ll count_Inversion(vector<ll> &ports, ll l, ll r)
{
    ll inverse = 0;
    if (l < r)
    {
        ll mid = l + (r - l) / 2;
        inverse += count_Inversion(ports, l, mid);
        inverse += count_Inversion(ports, mid + 1, r);
        inverse += merge(ports, l, mid, r);
    }
    return inverse;
}
bool compare(pair<ll, ll> a, pair<ll, ll> b)
{
   if(a.ff < b.ff){
        return true;

    }
    else if(a.ff == b.ff){
        if(a.ss < b.ss){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr1(n);
    f(i, n)
    {
        ll x,y;
        cin >>x>>y;
        arr1[i] = {x,y};
    }
    sort(all(arr1), compare);
    vector<ll> ports(n);
    f(i, n)
    {
        ports[i]=arr1[i].ss;
    }
    cout << count_Inversion(ports, 0, n - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
