#include <bits/stdc++.h>
using namespace std;
int memo[1002][3004];
int weight[1002];
int load[1002];

int dp(int box, int lw)
{
    if (box < 0 || lw > 3000)
        return 0;
    if (memo[box][lw] != -1)
        return memo[box][lw];
    if (lw > load[box])
        return memo[box][lw] = dp(box - 1, lw);
    return memo[box][lw] = max(1 + dp(box - 1, lw + weight[box]), dp(box - 1, lw));
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < n; i++)
            cin >> weight[i] >> load[i];

        cout << dp(n - 1, 0) << endl;
    }
}