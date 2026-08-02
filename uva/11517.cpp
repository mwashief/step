#include <bits/stdc++.h>
using namespace std;
int coins[10004][102];
int extra[10004][102];
int bills[102];
int T, total, n;

int dp(int money, int c)
{
    if (money > 10000)
        return money;
    if (money >= total)
    {
        coins[money][c] = 0;
        return extra[money][c] = money;
    }
    if (extra[money][c])
        return extra[money][c];
    if (c >= n)
        return INT32_MAX;
    int result1 = dp(money, c + 1);
    int result2 = dp(money + bills[c], c + 1);
    int result;
    if (result1 == result2)
    {
        coins[money][c] = min(coins[money][c + 1], 1 + (money + bills[c] > 10000 ? 0 : coins[money + bills[c]][c + 1]));
        result = result1;
    }
    else if (result1 < result2)
    {
        coins[money][c] = coins[money][c + 1];
        result = result1;
    }
    else
    {
        coins[money][c] = 1 + (money + bills[c] > 10000 ? 0 : coins[money + bills[c]][c + 1]);
        result = result2;
    }
    return extra[money][c] = result;
}

int main()
{
    cin >> T;
    while (T--)
    {
        memset(extra, 0, sizeof extra);
        memset(coins, 0, sizeof coins);
        cin >> total >> n;
        for (int i = 0; i < n; i++)
            cin >> bills[i];
        dp(0, 0);
        cout << extra[0][0] << " " << coins[0][0] << endl;
    }
}
