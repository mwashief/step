#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll memo[205][25][15];
ll numbers[205];
ll n, q, d, m;

ll dp(int current, int now, int rest)
{
    if (current == n && rest == 0 && now == 0)
        return 1;
    if (current >= n)
        return 0;
    if (rest == 0)
        return !now;
    if (memo[current][now][rest] != -1)
        return memo[current][now][rest];

    return memo[current][now][rest] = dp(current + 1, now, rest) + dp(current + 1, (now + numbers[current] % d + d) % d, rest - 1);
}

int main()
{
    int set = 1;
    while (cin >> n >> q && n)
    {
        for (int i = 0; i < n; i++)
            cin >> numbers[i];

        cout << "SET " << set << ":" << endl;
        for (int i = 1; i <= q; i++)
        {
            memset(memo, -1, sizeof(memo));
            cin >> d >> m;
            cout << "QUERY " << i << ": " << dp(0, 0, m) << endl;
        }
        set++;
    }
}
