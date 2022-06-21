/*
    Washief Hossain Mugdho
    19 September 2020
    Educational DP Matching
*/

#ifndef DEBUG
#pragma GCC optimize("O3")
#endif

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
bool a[22][22];
int memo[22][1 << 22];
int n;

int dp(int now, int mask)
{
    if (now >= n)
        return 1;
    int res = 0;

    if (memo[now][mask] != -1)
        return memo[now][mask];

    for (int i = 0; i < n; i++)
        if (a[now][i] && !(mask & (1 << i)))
            res = (res + dp(now + 1, mask | (1 << i))) % mod;

    return memo[now][mask] = res;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n;
    ms(memo, -1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << dp(0, 0) << endl;
}
