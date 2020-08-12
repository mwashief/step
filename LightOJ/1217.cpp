/*
    Washief Hossain Mugdho
    12 August 2020
    LightOJ 1217
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
using namespace std;
int soaps[1005];
int memo[1005][3];
int n;

int dp(int now, int takeable)
{
    if (now >= n)
        return 0;
    if (memo[now][takeable] != -1)
        return memo[now][takeable];
    int a;
    if (now == n - 1 && !takeable)
        a = 0;
    else if (now == 0)
        a = soaps[now] + dp(now + 2, 0);
    else
        a = soaps[now] + dp(now + 2, takeable);
    return memo[now][takeable] = max(a, dp(now + 1, takeable));
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        ms(memo, -1);
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> soaps[i];
        cout << "Case " << tt << ": " << dp(0, 1) << endl;
    }
}
