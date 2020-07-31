/*
    Washief Hossain Mugdho
    31 July 2020
    LightOJ 1057
*/

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
int k, complete;
int x[20];
int y[20];
int memo[1 << 17][20];

inline int getDistance(int a, int b)
{
    return max(abs(x[a] - x[b]), abs(y[a] - y[b]));
}

int tsp(int mask, int now)
{
    if (mask == complete)
        return getDistance(now, 0);
    if (memo[mask][now] != -1)
        return memo[mask][now];
    int ans = 10000;
    for (int i = 1; i < k; i++)
        if ((mask & (1 << i)) == 0)
            ans = min(ans, getDistance(now, i) + tsp(mask | (1 << i), i));

    return memo[mask][now] = ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int tt = 1; tt <= T; tt++)
    {
        ms(memo, -1);
        int n, m;
        k = 1;
        complete = 2;
        scanf("%d %d ", &n, &m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char c;
                cin >> c;
                if (c == 'x')
                {
                    x[0] = i;
                    y[0] = j;
                }
                else if (c == 'g')
                {
                    x[k] = i;
                    y[k] = j;
                    k++;
                    complete *= 2;
                }
            }
        }
        complete--;
        if (k == 1)
            printf("Case %d: 0\n", tt);
        else
            printf("Case %d: %d\n", tt, tsp(1, 0));
    }
}