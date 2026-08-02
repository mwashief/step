/*
    Washief Hossain Mugdho
    07 August 2020
    LightOJ 1025
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
ull memo[70][70];
string s;
ull dp(int start, int end)
{
    if (start > end)
        return 0;
    if (start == end)
        return 1;
    if (memo[start][end])
        return memo[start][end];
    memo[start][end] = dp(start + 1, end) + dp(start, end - 1) - dp(start + 1, end - 1);

    if (s[start] == s[end])
    {
        memo[start][end] += dp(start + 1, end - 1) + 1;
    }
    return memo[start][end];
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        ms(memo, 0);
        cin >> s;
        cout << "Case " << tt << ": " << dp(0, s.size() - 1) << endl;
    }
}
