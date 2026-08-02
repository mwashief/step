/*
    Washief Hossain Mugdho
    06 August 2020
    LightOJ 1095
*/

#pragma GCC optimize("O3")
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
int n, m, k, co;
ll C[1005][1005];
ll memo[1005][1005];
ll fact[1005];

ll com(int a, int b)
{
    if (a < 0 || b < 0)
        return 0;
    if (C[a][b])
        return C[a][b];
    if (b == 0 || a == b)
        return C[a][b] = 1;
    return C[a][b] = (com(a - 1, b - 1) + com(a - 1, b)) % mod;
}

ll dp(int x, int y)
{
    if (y == 0)
        return fact[x];
    if (memo[x][y] != -1)
        return memo[x][y];
    memo[x][y] = ((x - 1) * dp(x - 1, y - 1)) % mod;
    ll temp = ((y - 1) * (dp(x - 2, y - 2))) % mod;
    return memo[x][y] = (memo[x][y] + temp) % mod;
}

int main()
{
    fact[0] = 1;
    for (ll i = 1; i <= 1003; i++)
        fact[i] = (i * fact[i - 1]) % mod;
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> n >> m >> k;
        ms(memo, -1);
        ll ans = com(m, k);
        ans = (ans * dp(n - k, m - k)) % mod;
        cout << "Case " << tt << ": " << ans << endl;
    }
}
