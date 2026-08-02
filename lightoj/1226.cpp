/*
    Washief Hossain Mugdho
    31 July 2020
    LightOJ 1226
*/

#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define ms(a, b) memset(a, b, sizeof a)
#define mod 1000000007
using namespace std;
ll memo[1005];
ll arr[1005];
ll fact[1000006];

ll bigmod(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll ans = bigmod(a, b / 2);
    ans *= ans;
    ans %= mod;
    if (b & 1)
        ans *= a;
    return ans % mod;
}

inline ll C(ll a, ll b)
{
    ll ans = (fact[a] * bigmod(fact[b], mod - 2)) % mod;
    ans = (ans * bigmod(fact[a - b], mod - 2)) % mod;
    return ans;
}

int main()
{
    int T;
    cin >> T;
    memo[1] = 1;
    fact[0] = 1;
    for (int i = 1; i <= 1000003; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    for (int tt = 1; tt <= T; tt++)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        ll sum = 0;
        for (int i = 2; i <= n; i++)
        {
            sum += arr[i - 1];
            memo[i] = (memo[i - 1] * C(sum + arr[i] - 1, sum)) % mod;
        }
        cout << "Case " << tt << ": " << memo[n] << endl;
    }
}
