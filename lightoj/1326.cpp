/*
    Washief Hossain Mugdho
    07 August 2020
    LightOJ 1326
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
#define mod 10056
using namespace std;
int fact[1002];
int memo[1005][1005];

int dp(int a, int b)
{
    if (b == 1)
        return 1;
    if (a == b)
        return fact[a];
    if (memo[a][b] != -1)
        return memo[a][b];
    memo[a][b] = (dp(a - 1, b) + dp(a - 1, b - 1)) % mod;
    memo[a][b] = (b * memo[a][b]) % mod;
    return memo[a][b];
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 1001; i++)
        fact[i] = (i * fact[i - 1]) % mod;
    ms(memo, -1);
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans + dp(n, i)) % mod;
        }
        cout << "Case " << tt << ": " << ans << endl;
    }
}
