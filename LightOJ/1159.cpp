/*
    Washief Hossain Mugdho
    09 August 2020
    LightOJ 1159
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
string s1, s2, s3;
int memo[60][60][60];
int dp(int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0)
        return 0;
    if (memo[a][b][c] != -1)
        return memo[a][b][c];
    if (s1[a] == s2[b] && s2[b] == s3[c])
        return memo[a][b][c] = 1 + dp(a - 1, b - 1, c - 1);
    return memo[a][b][c] = max(max(dp(a - 1, b, c), dp(a, b - 1, c)), dp(a, b, c - 1));
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> s1 >> s2 >> s3;
        ms(memo, -1);
        cout << "Case " << tt << ": " << dp(s1.size() - 1, s2.size() - 1, s3.size() - 1) << endl;
    }
}
