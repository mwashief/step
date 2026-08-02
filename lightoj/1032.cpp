/*
    Washief Hossain Mugdho
    07 August 2020
    LightOJ 1032
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
ll n;
ll memo[35][2][35][35];

ll inline cons(ll n)
{
    if (n)
        return n - 1;
    return 0;
}

ll dp(int now, int alreadySmaller, ll co, ll taken)
{
    if (now < 0)
        return cons(co) + taken;
    if (memo[now][alreadySmaller][co][taken] != -1)
        return memo[now][alreadySmaller][co][taken];
    if (alreadySmaller)
        return memo[now][alreadySmaller][co][taken] = dp(now - 1, 1, co + 1, taken) + dp(now - 1, 1, 0, taken + cons(co));
    if ((n & (1LL << now)) == 0)
        return memo[now][0][co][taken] = dp(now - 1, 0, 0, taken + cons(co));
    return memo[now][0][co][taken] = dp(now - 1, 1, 0, taken + cons(co)) + dp(now - 1, 0, co + 1, taken);
}

int main()
{

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> n;
        ms(memo, -1);
        cout << "Case " << tt << ": " << dp(32, 0, 0, 0) << endl;
    }
}
