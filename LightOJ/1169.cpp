/*
    Washief Hossain Mugdho
    11 August 2020
    LightOJ 1169
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
int jump[2][1005];
int fruits[2][1005];
int memo[2][1005];

int dp(int now, int floor)
{
    if (floor >= n - 1)
        return 0;
    if (memo[now][floor])
        return memo[now][floor];
    return memo[now][floor] = min(fruits[now][floor + 1] + dp(now, floor + 1), fruits[!now][floor + 1] + jump[now][floor] + dp(!now, floor + 1));
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        ms(memo, 0);
        cin >> n;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> fruits[i][j];

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n - 1; j++)
                cin >> jump[i][j];

        cout << "Case " << tt << ": "
             << min(fruits[0][0] + dp(0, 0), fruits[1][0] + dp(1, 0)) << endl;
    }
}
