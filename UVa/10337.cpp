#include <bits/stdc++.h>
using namespace std;
int T, n;
int wind[12][1005];
int memo[12][1005];

int dp(int alt, int pos)
{
    if (n - pos < alt)
        return 99999999;
    if (pos == n)
        return 0;

    if (memo[alt][pos])
        return memo[alt][pos];
    int result = 30 + dp(alt, pos + 1);
    if (alt != 9)
        result = min(result, 60 + dp(alt + 1, pos + 1));
    if (alt != 0)
        result = min(result, 20 + dp(alt - 1, pos + 1));
    result -= wind[alt][pos];
    return memo[alt][pos] = result;
}

int main()
{
    cin >> T;
    while (T--)
    {
        memset(memo, 0, sizeof memo);
        cin >> n;
        n /= 100;
        for (int i = 9; i >= 0; i--)
            for (int j = 0; j < n; j++)
                cin >> wind[i][j];
        cout << dp(0, 0) << endl
             << endl;
    }
}
