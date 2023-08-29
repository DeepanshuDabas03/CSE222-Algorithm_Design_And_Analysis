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
#define sz(x) (ll) x.size()
#define mod 1000000007
#define moda 998244353
#define f(i, x) for (ll i = 0; i < x; ++i)
#define f1(i, x) for (int i = 1; i <= x; ++i)
#define endl '\n'

void prefixsum(vector<ll> &a)
{
    ll n = a.size();
    f1(i, n - 1) a[i] += a[i - 1];
}
ll sum_array(vector<int> &a)
{
    ll temp = 0;
    for (auto &i : a)
        temp += i;
    return temp;
}
ll product_array(vector<int> &a)
{
    ll temp = 1;
    for (auto &i : a)
        temp *= i;
    return temp;
}
void print(vector<ll> &a)
{
    for (auto &i : a)
        cout << i << ' ';
    cout << '\n';
}
ll digitSum(ll n)
{
    ll sum = 0;
    while (n != 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}
int search(vector<int> &nums, int target)
{
    int lo = 0, hi = nums.size() - 1;
    int mid;
    while (lo < hi)
    {
        mid = lo + (hi - lo + 1) / 2;
        if (target < nums[mid])
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid;
        }
    }
    return nums[lo] == target ? lo : -1;
}
bool check(string a, string b)
{
    if(a==b)return true;
    long long n=a.length();
    long long cnt1=0,cnt2=0;
    for(long long i=0;i<n;i++){
        if(a[i]=='0')cnt1++;
        if(b[i]=='0')cnt2++;
    }
    if(cnt1!=cnt2)return false;
    string a1,a2,b1,b2;
    for(long long i=0;i<n/2;i++){
        a1+=a[i];
        b1+=b[i];
    }
    for(long long i=n/2;i<n;i++){
        a2+=a[i];
        b2+=b[i];
    }
    return check(a1,b1)&&check(a2,b2)||check(a1,b2)&&check(a2,b1);
}
void solve(int tt)
{
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (n % 2 != 0)
    {
        if (a != b)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        return;
    }
    if (check(a, b))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int tt;
    cin >> tt;
    int cs;
    f1(cs, tt)
    {
        solve(cs);
    }
    return 0;
}
