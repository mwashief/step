#include <bits/stdc++.h>
using namespace std;
int n, k, m;
long long memo[52][52][52];

long long dp(int nn, int kk, int mm)
{
    if (kk > k || mm > m)
        return 0;
    if (nn == n)
    {
        if (k == kk)
            return 1;
        return 0;
    }
    if (memo[nn][kk][mm] != -1)
        return memo[nn][kk][mm];
    return memo[nn][kk][mm] = dp(nn + 1, kk, mm + 1) + dp(nn + 1, kk + 1, 1);
}

int main()
{
    while (cin >> n >> k >> m)
    {
        memset(memo, -1, sizeof memo);
        cout << dp(1, 1, 1) << endl;
    }
}
