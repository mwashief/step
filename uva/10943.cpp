#include <bits/stdc++.h>
using namespace std;

long long memo[103][103][103];

long long dp(long long nLeft, long long k, int numbersLeft)
{
    if (nLeft < 0)
        return 0;
    if (numbersLeft == 1)
    {
        if (nLeft <= k)
            return 1;
        return 0;
    }
    if (memo[nLeft][k][numbersLeft] != -1)
        return memo[nLeft][k][numbersLeft];
    long long ans = 0;
    for (int i = 0; i <= k; i++)
    {
        ans += dp(nLeft - i, k, numbersLeft - 1);
        ans %= 1000000;
    }
    return memo[nLeft][k][numbersLeft] = ans;
}

int main()
{
    long long n, k;
    memset(memo, -1, sizeof(memo));
    while (cin >> n >> k && n)
    {
        cout << dp(n, n, k) << endl;
    }
}
