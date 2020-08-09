#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll regular[45], m, s;
ll tech[45];
ll memo[302][302];

ll dp(int x, int y)
{
    int coin;
    if (x < 0 || y < 0)
        return LLONG_MAX;
    if (memo[x][y] != -1)
        return memo[x][y];
    if (x == 0 && y == 0)
        return 0;
    ll result = LLONG_MAX;
    for (int i = 0; i < m; i++)
        if (dp(x - regular[i], y - tech[i]) != LLONG_MAX)
            result = min(result, 1 + dp(x - regular[i], y - tech[i]));
    return memo[x][y] = result;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        cin >> m >> s;
        for (int i = 0; i < m; i++)
            cin >> regular[i] >> tech[i];

        memset(memo, -1, sizeof(memo));
        ll ans = LLONG_MAX;
        for (int i = 0; i <= s; i++)
        {
            int other = s * s - i * i;
            int sq = sqrt(other);
            if (sq * sq == other)
                ans = min(ans, dp(i, sq));
        }

        if (ans != LLONG_MAX)
            cout << ans << endl;
        else
            cout << "not possible" << endl;
    }
}
