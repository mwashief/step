/*
    Washief Hossain Mugdho
    17 September 2020
    Educational DP Knapsack1
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
int N, W, w[105], v[105];
ull memo[100005][105];

ull dp(int remaining, int curObj)
{
    if (remaining <= 0 || curObj >= N)
        return 0;
    if (memo[remaining][curObj])
        return memo[remaining][curObj];
    ull res = 0;
    if (w[curObj] <= remaining)
        res = v[curObj] + dp(remaining - w[curObj], curObj + 1);
    return memo[remaining][curObj] = max(dp(remaining, curObj + 1), res);
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> N >> W;
    for (int i = 0; i < N; i++)
        cin >> w[i] >> v[i];
    cout << dp(W, 0) << endl;
}
