/*
    Washief Hossain Mugdho
    02 August 2020
    LightOJ 1119
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
int n;
int memo[1 << 14];
int cost[15][15];

int dp(int mask)
{
    if (mask == (1 << n) - 1)
        return 0;
    if (memo[mask] != -1)
        return memo[mask];
    int ans = 199900000;
    for (int i = 0; i < n; i++)
    {
        if ((mask & (1 << i)) == 0)
        {
            int val = 0;
            int temp = mask | (1 << i);
            for (int j = 0; j < n; j++)
            {
                if ((temp & (1 << j)) != 0)
                    val += cost[i][j];
            }
            ans = min(ans, val + dp(temp));
        }
    }
    return memo[mask] = ans;
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
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];
        printf("Case %d: %d\n", tt, dp(0));
    }
}
