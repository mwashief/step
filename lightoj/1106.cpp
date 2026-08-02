/*
    Washief Hossain Mugdho
    11 August 2020
    LightOJ 1106
*/

//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define ms(a, b) memset(a, b, sizeof a)
using namespace std;
int n, h;
int f[30];
int d[30];
int t[30];
int pos[30];
int memo[30][350][350];

int dp(int current, int passed, int left)
{
    if (current >= n || left <= 0)
        return 0;
    if (memo[current][passed][left] != -1)
        return memo[current][passed][left];
    int a = 0;
    int b = dp(current + 1, 0, left - t[current]);
    if (f[current] - d[current] * passed > 0)
        a = f[current] - d[current] * passed + dp(current, passed + 1, left - 1);
    else
        a = dp(current, passed + 1, left - 1);

    if (a >= b)
    {
        return memo[current][passed][left] = a;
    }
    return memo[current][passed][left] = b;
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        ms(memo, -1);
        ms(pos, 0);

        cin >> n >> h;
        for (int i = 0; i < n; i++)
            cin >> f[i];
        for (int i = 0; i < n; i++)
            cin >> d[i];
        for (int i = 0; i < n - 1; i++)
            cin >> t[i];

        h *= 12;
        int x = dp(0, 0, h);

        int current = 0;
        int passed = 0;
        int left = h;
        while (left > 0)
        {
            int a = 0;
            int b = memo[current + 1][0][left - t[current]];
            if (f[current] - d[current] * passed > 0)
                a = f[current] - d[current] * passed + memo[current][passed + 1][left - 1];
            else
                a = memo[current][passed + 1][left - 1];

            if (a >= b)
            {
                pos[current]++;
                left--;
                passed++;
            }
            else
            {
                left -= t[current];
                current++;
                passed = 0;
            }
        }

        cout << "Case " << tt << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                cout << ", ";
            cout << pos[i] * 5;
        }
        cout << endl;
        cout << "Number of fish expected: " << x << endl;
    }
}
