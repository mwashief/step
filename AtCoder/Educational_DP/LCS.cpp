/*
    Washief Hossain Mugdho
    17 September 2020
    Educational DP LCS
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
using namespace std;
string s, t;

int main()
{
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> s >> t;
    int memo[s.size() + 1][t.size() + 1];
    ms(memo, 0);
    for (int i = s.size() - 1; i >= 0; i--)
        for (int j = t.size() - 1; j >= 0; j--)
        {
            if (s[i] == t[j])
                memo[i][j] = memo[i + 1][j + 1] + 1;
            else
                memo[i][j] = max(memo[i + 1][j], memo[i][j + 1]);
        }
    int a = 0, b = 0;
    while (a < s.size() && b < t.size())
    {
        if (s[a] == t[b])
        {
            cout << s[a];
            a++;
            b++;
        }
        else if (memo[a + 1][b] > memo[a][b + 1])
            a++;
        else
            b++;
    }
    cout << endl;
}
