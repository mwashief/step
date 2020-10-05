/*
    Washief Hossain Mugdho
    04 October 2020
    Codeforces 675C
*/

#ifndef DEBUG
#pragma GCC optimize("O3")
#endif

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
#define mod 1000000007
using namespace std;
string s;

int memo[100005][2][2];
int howMany[100005][2][2];

int dp(int now, int must, int rejecting)
{
    if (now < 0)
    {
        howMany[now + 1][must][rejecting] = 1;
        return 0;
    }
    if (memo[now][must][rejecting] != -1)
        return memo[now][must][rejecting];
    if (must)
    {
        dp(now - 1, 1, 0);
        howMany[now + 1][1][0] = howMany[now][1][0];
        memo[now][1][0] = (1LL * 10 * dp(now - 1, 1, 0)) % mod;
        return memo[now][1][0] = (1LL * memo[now][1][0] + howMany[now][1][0] * (s[now] - '0')) % mod;
    }
    if (rejecting)
    {
        dp(now - 1, 1, 0);
        dp(now - 1, 0, 1);
        howMany[now + 1][0][1] = (howMany[now][1][0] + howMany[now][0][1]) % mod;
        memo[now][0][1] = (1LL * dp(now - 1, 0, 1)) % mod;
        memo[now][0][1] = (1LL * memo[now][0][1] + howMany[now][1][0] * (s[now] - '0')) % mod;
        return memo[now][0][1] = (1LL * memo[now][0][1] + 1LL * 10 * dp(now - 1, 1, 0)) % mod;
    }
    else
    {
        dp(now - 1, 0, 0);
        dp(now - 1, 0, 1);
        howMany[now + 1][0][0] = (howMany[now][0][0] + howMany[now][0][1]) % mod;
        memo[now][0][0] = (1LL * 10 * dp(now - 1, 0, 0)) % mod;
        memo[now][0][0] = (1LL * memo[now][0][0] + 1LL * howMany[now][0][0] * (s[now] - '0')) % mod;
        return memo[now][0][0] = (1LL * memo[now][0][0] + 1LL * dp(now - 1, 0, 1)) % mod;
    }
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> s;
    ms(memo, -1);
    ms(howMany, 0);
    int ans = dp(s.size() - 1, 0, 0);
    int power = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int minus = (1LL * power * (s[i] - '0')) % mod;
        ans = (ans - minus) % mod;
        if (ans < 0)
            ans += mod;
        power = (1LL * power * 10) % mod;
    }
    cout << ans << endl;
}
