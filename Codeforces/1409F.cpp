/*
    Washief Hossain Mugdho
    18 September 2020
    Codeforces 1409F
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
string s, t;
int n, k;
int memo[205][205][205];

int dp(int now, int remaining, int prefix)
{
    if (now >= n)
        return 0;
    if (memo[now][remaining][prefix] != -1)
        return memo[now][remaining][prefix];
    int res = 0;
    if (s[now] == t[1])
        res = max(res, prefix + dp(now + 1, remaining, prefix));
    if (s[now] == t[0])
        res = max(res, dp(now + 1, remaining, prefix + 1));
    if (remaining > 0 && s[now] != t[0])
        res = max(res, dp(now + 1, remaining - 1, prefix + 1));
    if (remaining > 0 && s[now] != t[1])
        res = max(res, prefix + dp(now + 1, remaining - 1, prefix));
    if (s[now] != t[1] && s[now] != t[0])
        res = max(res, dp(now + 1, remaining, prefix));
    return memo[now][remaining][prefix] = res;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n >> k >> s >> t;
    if (t[0] == t[1])
    {
        int c = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == t[0])
                c++;
        c = min(n, c + k);
        cout << c * (c - 1) / 2 << endl;
    }
    else
    {
        ms(memo, -1);
        cout << dp(0, k, 0) << endl;
    }
}
