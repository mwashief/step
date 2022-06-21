/*
    Washief Hossain Mugdho
    21 September 2020
    Educational DP DigitSum
*/

#ifndef DEBUG
#pragma GCC optimize("-O2")
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
int d;
int memo[10009][105][2];

int dp(int n, int sofar, int small)
{
    if (n >= s.size())
        return (sofar == 0);
    if (memo[n][sofar][small] != -1)
        return memo[n][sofar][small];
    if (small)
    {
        int res = 0;
        for (int i = 0; i < 10; i++)
            res = (res + dp(n + 1, (sofar + i) % d, 1)) % mod;
        return memo[n][sofar][small] = res;
    }
    int digit = s[n] - '0';
    int res = dp(n + 1, (sofar + digit) % d, 0);
    for (int i = 0; i < digit; i++)
        res = (res + dp(n + 1, (sofar + i) % d, 1)) % mod;

    return memo[n][sofar][small] = res;
}

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    ms(memo, -1);
    cin >> s >> d;
    cout << (dp(0, 0, 0) - 1 + mod) % mod << endl;
}
