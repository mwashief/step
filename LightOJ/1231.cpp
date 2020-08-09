/*
    Washief Hossain Mugdho
    05 August 2020
    LightOJ 1231
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

ll dp[2][1010];

int main()
{
    int a, c, n, k, T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        ms(dp, 0);
        dp[1][0] = 1;
        cin >> n >> k;
        vector<pair<int, int>> coins(n, mp(0, 0));

        for (int i = 0; i < n; i++)
            cin >> coins[i].fr;
        for (int i = 0; i < n; i++)
            cin >> coins[i].sc;

        for (int i = 0; i < coins.size(); i++)
        {
            ms(dp[i % 2], 0);
            for (int j = 0; j <= k; j++)
            {
                dp[(i) % 2][j] += dp[(i + 1) % 2][j];
                dp[(i) % 2][j] %= 100000007;
                if (dp[(i + 1) % 2][j] > 0)
                    for (int l = 1; l <= coins[i].sc; l++)
                    {
                        if ((j + l * coins[i].fr) > k)
                            break;
                        dp[i % 2][j + l * coins[i].fr] = (dp[i % 2][j + l * coins[i].fr] + dp[(i + 1) % 2][j]) % 100000007;
                    }
            }
        }
        cout << "Case " << tt << ": " << dp[(n + 1) % 2][k] << endl;
    }
}
