#include <bits/stdc++.h>
using namespace std;

int memo[54][54];
int cumSum[54];

int dp(int i, int j)
{
    if (j <= i)
        return 0;
    if (memo[i][j])
        return memo[i][j];
    int ans = INT_MAX;
    for (int p = i; p < j; p++)
    {
        ans = min(ans, cumSum[j] - cumSum[i - 1] + dp(i, p) + dp(p + 1, j));
    }
    return memo[i][j] = ans;
}

int main()
{
    int l;
    while (cin >> l && l)
    {
        int n;
        cin >> n;
        memset(memo, 0, sizeof(memo));
        int i;
        for (i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            cumSum[i] = x;
        }
        cumSum[i] = l;
        cout << "The minimum cutting is " << dp(1, n + 1) << "." << endl;
    }
}
