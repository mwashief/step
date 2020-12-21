/*
    Washief Hossain Mugdho
    20 December 2020
    Codeforces 691D
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
int n;
vector<int> a;
vector<int> b;

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
    cin >> n;
    a = vector<int>(n);
    b = vector<int>(n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        total += b[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(100 * n + 101, 0));
    vector<vector<bool>> valid(n + 1, vector<bool>(100 * n + 101, 0));
    valid[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= 0; j--)
            for (int k = 0; k < 100 * n; k++)
                if (valid[j][k])
                {
                    dp[j + 1][k + a[i]] = max(dp[j + 1][k + a[i]], dp[j][k] + b[i]);
                    valid[j + 1][k + a[i]] = 1;
                }

    for (int j = 1; j <= n; j++)
    {
        double ans = 0.0;
        for (int k = 1; k <= 100 * n; k++)
            if (valid[j][k])
                ans = max(ans, min(1.0 * k, 1.0 * dp[j][k] / 2.0 + total / 2.0));
        cout << ans << " ";
    }
    cout << endl;
}
