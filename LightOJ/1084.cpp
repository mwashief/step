/*
    Washief Hossain Mugdho
    13 August 2020
    LightOJ 1084
*/

#pragma GCC optimize("O3")
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
int n, k, tt, L[100005];
int memo[100005];

int dp(int now)
{
    if (now >= n)
        return 0;
    if (memo[now] != -1)
        return memo[now];
    int res = 2000000;

    int last;
    for (int i = now; i < n; i++)
    {
        if (L[i] - L[now] <= 2 * k)
            last = i;
        else
            break;
    }
    for (int i = last; i >= now + 2; i--)
    {
        res = min(res, 1 + dp(i + 1));
        if (res <= n)
            break;
    }
    return memo[now] = res;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (tt = 1; tt <= T; tt++)
    {
        ms(memo, -1);
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &L[i]);
        sort(L, L + n);
        int x = dp(0);
        printf("Case %d: %d\n", tt, x > n ? -1 : x);
    }
}
