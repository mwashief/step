/*
    Washief Hossain Mugdho
    01 August 2020
    LightOJ 1018
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
int x[20];
int y[20];
int memo[1 << 17];
int sameLine[20][20];

int dp(int mask)
{
    if (mask >= (1 << n) - 1)
        return 0;
    if (memo[mask] != -1)
        return memo[mask];
    int firstBit;
    int c = 0;

    for (int i = 0; i < n; i++)
        if ((mask & (1 << i)) == 0)
        {
            firstBit = i;
            c++;
        }
    if (c <= 2)
        return memo[mask] = 1;

    int ans = 10000;
    for (int i = 0; i < n; i++)
        if (i != firstBit)
            ans = min(ans, 1 + dp(mask | sameLine[firstBit][i]));

    return memo[mask] = ans;
}

int main()
{
    fastio;
    untie;
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> n;
        ms(memo, -1);
        ms(sameLine, 0);

        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = 0; k < n && i != j; k++)
                    if (((y[j] - y[i]) * (x[k] - x[j])) == ((y[k] - y[j]) * (x[j] - x[i])))
                        sameLine[i][j] = sameLine[j][i] = sameLine[i][j] | (1 << k);

        printf("Case %d: %d\n", tt, dp(0));
    }
}