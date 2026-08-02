/*
    Washief Hossain Mugdho
    13 August 2020
    LightOJ 1047
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
int cost[25][4];
int memo[25][4];

int dp(int now, int prevCol)
{
    if (now >= n)
        return 0;
    if (memo[now][prevCol] != -1)
        return memo[now][prevCol];
    int res = INT32_MAX;
    for (int i = 0; i < 3; i++)
    {
        if (i == prevCol)
            continue;
        res = min(res, cost[now][i] + dp(now + 1, i));
    }
    return memo[now][prevCol] = res;
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
            for (int j = 0; j < 3; j++)
                cin >> cost[i][j];
        cout << "Case " << tt << ": " << dp(0, 3) << endl;
    }
}
