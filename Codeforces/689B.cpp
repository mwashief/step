/*
    Washief Hossain Mugdho
    14 December 2020
    Codeforces 689B
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

void solve()
{
    int n, m, counter;
    char c;
    cin >> n >> m;
    ll ans = 0;
    vector<vector<int>> d(2, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        counter = 1;
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            if (c == '*')
            {
                int level = (counter + 1) / 2;
                if (i != 0)
                    d[i & 1][j] = min(level, d[(i + 1) & 1][j - 1] + 1);
                else
                    d[i & 1][j] = 1;
                counter++;
                ans += (ll)d[i & 1][j];
            }
            else
            {
                counter = 1;
                d[i & 1][j] = 0;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
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
