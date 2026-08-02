/*
    Washief Hossain Mugdho
    12 August 2020
    LightOJ 1200
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
int p[105];
int c[105];
int w[105];
int n, W;
int memo[105][10009];

int dp(int current, int left)
{
    if (left <= 0 || current >= n)
        return 0;
    if (memo[current][left] != -1)
        return memo[current][left];
    int x = ((left - w[current]) >= 0) ? (p[current] + dp(current, left - w[current])) : 0;
    return memo[current][left] = max(x, dp(current + 1, left));
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> n >> W;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i] >> c[i] >> w[i];
            W -= c[i] * w[i];
        }
        cout << "Case " << tt << ": ";
        if (W < 0)
            cout << "Impossible";
        else
        {
            ms(memo, -1);
            cout << dp(0, W);
        }
        cout << endl;
    }
}
