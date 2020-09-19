/*
    Washief Hossain Mugdho
    19 September 2020
    Educational DP Slimes
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
using namespace std;
ull memo[405][405];
ull a[405];
ull dp(int x, int y)
{
    if (x == y)
        return 0;
    if (memo[x][y])
        return memo[x][y];
    ull res = INT64_MAX;
    for (int i = x; i < y; i++)
        res = min(res, dp(x, i) + dp(i + 1, y) + a[y] - a[x - 1]);
    return memo[x][y] = res;
}
int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cout << dp(1, n) << endl;
}
