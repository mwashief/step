#include <bits/stdc++.h>
using namespace std;
int m, n, minMoney, maxMoney;
int p[103];
int f[103];

int memo[102][10004];

int dp(int x, int money)
{
    if (money > m + 200 || (m < 1800 && money > m))
        return INT32_MIN;
    if (x == n)
    {
        if (money > m && money <= 2000)
            return INT32_MIN;
        return 0;
    }
    if (memo[x][money] != -1)
        return memo[x][money];
    return memo[x][money] = max(dp(x + 1, money), f[x] + dp(x + 1, money + p[x]));
}

int main()
{
    while (cin >> m >> n)
    {
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < n; i++)
            cin >> p[i] >> f[i];
        cout << dp(0, 0) << endl;
    }
}