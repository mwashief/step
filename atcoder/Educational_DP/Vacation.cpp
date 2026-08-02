/*
    Washief Hossain Mugdho
    17 September 2020
    Educational DP Vacation
*/

#ifndef DEBUG
#pragma GCC optimize("O3")
#endif

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
#define mx 100005
using namespace std;
int n, memo[mx][3];
int a[mx][3];

int dp(int day, int prevActivity)
{
    if (day >= n)
        return 0;
    if (memo[day][prevActivity])
        return memo[day][prevActivity];
    int res = 0;
    for (int i = 0; i < 3; i++)
        if (i != prevActivity)
            res = max(res, a[day][i] + dp(day + 1, i));
    return memo[day][prevActivity] = res;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    cout << dp(0, -1) << endl;
}
