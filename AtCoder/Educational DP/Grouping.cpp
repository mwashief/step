/*
    Washief Hossain Mugdho
    21 September 2020
    Educational DP Grouping
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
#define mx 70000
using namespace std;
int n, m;
ll arr[18][18];
ll memo[mx];
ll group[mx];

ll dp(int mask)
{
    if (memo[mask] != -1)
        return memo[mask];

    ll res = max(group[mask], 0LL);
    for (int i = mask; i; i = (i - 1) & mask)
        if (group[i] >= 0)
            res = max(res, group[i] + dp(mask ^ i));

    return memo[mask] = res;
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
            cin >> arr[i][j];

    m = (1 << n) - 1;
    for (int i = 0; i <= m; i++)
    {
        group[i] = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                for (int k = j + 1; k < n; k++)
                    if (i & (1 << k))
                        group[i] += arr[j][k];
    }
    cout << dp(m) << endl;
}
