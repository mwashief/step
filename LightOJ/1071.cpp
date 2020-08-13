/*
    Washief Hossain Mugdho
    13 August 2020
    LightOJ 1071
*/

//#pragma GCC optimize("O3")
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
int mat[105][105];
int m, n;
int memo[105][105][105];

int dp(int fDown, int fRight, int sRight)
{
    if (memo[fDown][fRight][sRight] != -1)
        return memo[fDown][fRight][sRight];

    int sDown = fDown + fRight - sRight;
    if (fDown == m - 1 && fRight == n - 2 && sDown == m - 2)
        return memo[fDown][fRight][sRight] = mat[fDown][fRight] + mat[sDown][sRight];
    if (fDown > m - 1 || fRight > n - 2 || sDown > m - 2 || sRight > n - 1)
        return memo[fDown][fRight][sRight] = INT32_MIN;
    memo[fDown][fRight][sRight] = mat[fDown][fRight] + mat[sDown][sRight];
    int res = 0;
    res = max(res, max(0, dp(fDown + 1, fRight, sRight)));
    res = max(res, max(0, dp(fDown, fRight + 1, sRight + 1)));
    res = max(res, max(0, dp(fDown + 1, fRight, sRight + 1)));
    if (fDown - sDown > 1)
        res = max(res, max(0, dp(fDown, fRight + 1, sRight)));
    return memo[fDown][fRight][sRight] += res;
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        ms(memo, -1);
        cin >> m >> n;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];

        cout << "Case " << tt << ": " << dp(1, 0, 1) + mat[0][0] + mat[m - 1][n - 1] << endl;
    }
}
