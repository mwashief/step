/*
    Washief Hossain Mugdho
    03 August 2020
    LightOJ 1228
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
int n, k, q;

int memo[1 << 12][12][15];
int fact[14];
unordered_set<int> enemy[12];

int dp(int mask, int now, int left)
{
    if (left < 0)
        return 0;
    if (mask == (1 << n) - 1)
        return 1;
    if (memo[mask][now][left] != -1)
        return memo[mask][now][left];
    int ans = 0;
    for (int i = 0; i < n; i++)
        if ((mask & (1 << i)) == 0)
            ans += dp(mask | (1 << i), i, left - (enemy[i].find(now) != enemy[i].end() ? 1 : 0));

    return memo[mask][now][left] = ans;
}

int main()
{
    int T;
    cin >> T;
    fact[0] = 1;
    for (int i = 1; i < 14; i++)
        fact[i] = i * fact[i - 1];
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> n >> k >> q;
        ms(memo, -1);
        for (int i = 0; i < n; i++)
            enemy[i].clear();
        for (int i = 0; i < n; i++)
        {
            int nn;
            cin >> nn;
            for (int j = 0; j < nn; j++)
            {
                int nnn;
                cin >> nnn;
                enemy[i].insert(nnn - 1);
            }
        }
        cout << "Case " << tt << ":" << endl;
        for (int i = 0; i < q; i++)
        {
            int ans = 0;
            int conflicts;
            cin >> conflicts;
            if (k == 0)
                conflicts = INT32_MAX;
            else
                conflicts /= k;

            if (conflicts >= n - 1)
            {
                cout << fact[n] << endl;
                continue;
            }
            for (int i = 0; i < n; i++)
                ans += dp(1 << i, i, conflicts);
            cout << ans << endl;
        }
    }
}
