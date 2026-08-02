/*
    Washief Hossain Mugdho
    10 August 2020
    LightOJ 1420
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
#define mod 1000000007
using namespace std;

string s1, s2, s3;
int memo[105][105][105][4];

int dp(int a, int b, int c, int takeFrom)
{
    if (c < 0)
        return 1;

    if (a <= 0 && b <= 0)
        return 0;

    if (memo[a][b][c][takeFrom] != -1)
        return memo[a][b][c][takeFrom];
    memo[a][b][c][takeFrom] = 0;

    if (a > 0 && takeFrom != 2)
    {
        if (s1[a - 1] == s3[c])
            memo[a][b][c][takeFrom] = (memo[a][b][c][takeFrom] + dp(a - 1, b, c - 1, 0)) % mod;
        memo[a][b][c][takeFrom] = (memo[a][b][c][takeFrom] + dp(a - 1, b, c, 1)) % mod;
    }

    if (b > 0 && takeFrom != 1)
    {
        if (s2[b - 1] == s3[c])
            memo[a][b][c][takeFrom] = (memo[a][b][c][takeFrom] + dp(a, b - 1, c - 1, 0)) % mod;
        memo[a][b][c][takeFrom] = (memo[a][b][c][takeFrom] + dp(a, b - 1, c, 2)) % mod;
    }

    return memo[a][b][c][takeFrom];
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> s1 >> s2 >> s3;
        ms(memo, -1);
        cout << "Case " << tt << ": " << dp(s1.size(), s2.size(), s3.size() - 1, 0) << endl;
    }
}
