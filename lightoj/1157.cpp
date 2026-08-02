/*
    Washief Hossain Mugdho
    12 August 2020
    LightOJ 1157
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
#define mod 1000007
using namespace std;
string s1, s2;
int memo[1005][1005];
int ways[1005][1005];

int dp(int a, int b)
{
    if (memo[a][b] != -1)
        return memo[a][b];
    if (a >= s1.size() || b >= s2.size())
    {
        ways[a][b] = 1;
        return memo[a][b] = 0;
    }
    if (s1[a] == s2[b])
    {
        int x = dp(a + 1, b + 1);
        ways[a][b] = ways[a + 1][b + 1];
        return memo[a][b] = 1 + x;
    }
    int x = dp(a + 1, b);
    int y = dp(a, b + 1);
    if (x > y)
    {
        ways[a][b] = ways[a + 1][b];
        return memo[a][b] = x;
    }
    if (y > x)
    {
        ways[a][b] = ways[a][b + 1];
        return memo[a][b] = y;
    }
    dp(a + 1, b + 1);
    memo[a][b] = x;
    ways[a][b] = ways[a + 1][b] + ways[a][b + 1];
    if (memo[a + 1][b + 1] == memo[a][b])
        ways[a][b] -= ways[a + 1][b + 1];

    ways[a][b] = (ways[a][b] % mod + mod) % mod;
    return memo[a][b];
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        ms(memo, -1);
        cin >> s1 >> s2;
        dp(0, 0);
        cout << "Case " << tt << ": " << ways[0][0] << endl;
    }
}
