/*
    Washief Hossain Mugdho
    14 December 2020
    Codeforces 687C
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
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
int n, p, k, x, y;
string s;
int memo[100005];

int dp(int cellNo)
{
    if (cellNo >= n)
        return 0;
    if (memo[cellNo] != -1)
        return memo[cellNo];
    if (s[cellNo] == '0')
        return memo[cellNo] = x + dp(cellNo + k);
    return memo[cellNo] = dp(cellNo + k);
}
void solve()
{
    cin >> n >> p >> k;
    ms(memo, -1);
    cin >> s >> x >> y;
    int res = INT32_MAX;
    for (int i = p - 1, j = 0; i < n; i++, j++)
        res = min(res, dp(i) + y * j);
    cout << res << endl;
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
