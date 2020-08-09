#include <bits/stdc++.h>
using namespace std;
int beeperX[14];
int beeperY[14];
int memo[3000][15];
int n, T;
int complete;

int dp(int mask, int last)
{
    if (mask == complete)
        return abs(beeperX[0] - beeperX[last]) + abs(beeperY[0] - beeperY[last]);
    if (memo[mask][last])
        return memo[mask][last];

    int result = INT32_MAX;
    for (int i = 1; i <= n; i++)
        if (!(mask & (1 << i)))
            result = min(result, abs(beeperX[i] - beeperX[last]) + abs(beeperY[i] - beeperY[last]) + dp(mask | (1 << i), i));

    return memo[mask][last] = result;
}

int main()
{
    cin >> T;
    while (T--)
    {
        memset(memo, 0, sizeof memo);
        cin >> beeperX[0] >> beeperY[0];
        cin >> beeperX[0] >> beeperY[0];
        cin >> n;

        complete = 1;
        for (int i = 0; i <= n; i++)
            complete *= 2;
        complete--;

        for (int i = 1; i <= n; i++)
            cin >> beeperX[i] >> beeperY[i];

        cout << "The shortest path has length " << dp(1, 0) << endl;
    }
}
