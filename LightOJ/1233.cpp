/*
    Washief Hossain Mugdho
    06 August 2020
    LightOJ 1233
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
bool dp[100005];
int coinsTaken[100005];

int main()
{
    int a, c, n, k, T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        ms(dp, 0);
        dp[0] = 1;
        cin >> n >> k;
        vector<pair<int, int>> coins(n, mp(0, 0));

        for (int i = 0; i < n; i++)
            cin >> coins[i].fr;
        for (int i = 0; i < n; i++)
            cin >> coins[i].sc;
        int count = 0;

        for (int i = 0; i < coins.size(); i++)
        {
            ms(coinsTaken, 0);
            for (int j = coins[i].fr; j <= k; j++)
            {
                if (dp[j - coins[i].fr] && dp[j] == 0 && coinsTaken[j - coins[i].fr] < coins[i].sc)
                {
                    dp[j] = 1;
                    coinsTaken[j] = coinsTaken[j - coins[i].fr] + 1;
                    count++;
                }
            }
        }
        cout << "Case " << tt << ": " << count << endl;
    }
}
