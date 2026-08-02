/*
    Washief Hossain Mugdho
    17 September 2020
    Educational DP Coins
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
using namespace std;
bool visited[3005][3005];
double memo[3005][3005];
double arr[3005];
int n;

double dp(int a, int b)
{
    if (a >= n && b != 0)
        return 0.0;
    if (visited[a][b])
        return memo[a][b];
    visited[a][b] = 1;
    if (b == 0)
    {
        double res = 1.0;
        for (int i = a; i < n; i++)
            res *= (1 - arr[i]);
        return memo[a][b] = res;
    }
    return memo[a][b] = (1.0 - arr[a]) * dp(a + 1, b) + arr[a] * dp(a + 1, b - 1);
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
        cin >> arr[i];
    int m = n / 2 + 1;
    double res = 0.0;
    for (int i = m; i <= n; i++)
        res += dp(0, i);
    cout << fixed << setprecision(12) << res << endl;
}
