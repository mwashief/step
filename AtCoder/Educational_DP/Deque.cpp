/*
    Washief Hossain Mugdho
    19 September 2020
    Educational DP Deque
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
ll a[3004];
ll memo[3004][3004];

ll dp(int x, int y)
{
    if (x > y)
        return 0;
    if (x == y)
        return a[x];
    if (memo[x][y])
        return memo[x][y];

    ll p = a[x] - dp(x + 1, y);
    ll q = a[y] - dp(x, y - 1);
    return memo[x][y] = max(p, q);
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
        cin >> a[i];

    cout << dp(1, n) << endl;
}
