/*
    Washief Hossain Mugdho
    17 September 2020
    Educational DP Frog1
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
    int a[n];
    vector<int> dp(n, INT32_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(a[i + 1] - a[i]));
        if (i + 2 < n)
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i + 2] - a[i]));
    }
    cout << dp[n - 1] << endl;
}
