#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'
typedef pair<ll, string> pss;
#define f(i, n) for (ll i = 0; i < n; i++)
pss check(string a, string b)
{
    ll ao = 0;
    ll n = a.length();
    string res = b;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
        {
            ao++;
            if (b[i] == '0')
                res[i] = '1';
            else
                res[i] = '0';
        }
    }
    if (ao == 0)
    {
        return {0, b};
    }
    if (n % 2 != 0)
    {
        return {ao, res};
    }
    string a1, a2, b1, b2;
    for (int i = 0; i < n / 2; ++i)
    {
        a1 += a[i];
        b1 += b[i];
    }
    for (int i = n / 2; i < n; ++i)
    {
        a2 += a[i];
        b2 += b[i];
    }
    pss flag = check(a1, b1);
    pss flag3 = check(a2, b2);
    pss flag1 = check(a1, b2);
    pss flag2 = check(a2, b1);
    if (flag.first + flag3.first < flag2.first + flag1.first)
    {
        if (flag.first + flag3.first < ao)
        {
            res = flag.second + flag3.second;
            return {flag.first + flag3.first, res};
        }
    }
    else
    {
        if (flag2.first + flag1.first < ao)
        {
            res = flag2.second + flag1.second;
            return {flag2.first + flag1.first, res};
        }
    }
    return {ao, res};
}

void solve(int tt)
{
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    pss ans = check(a, b);
    cout << ans.first << endl;
    cout << ans.second << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    ll tt;
    cin >> tt;
    f(i, tt)
    {
        solve(i + 1);
    }
}
