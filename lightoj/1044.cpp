/*
    Washief Hossain Mugdho
    13 August 2020
    LightOJ 1044
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
string s;
bool pal[1005][1005];
bool visited[1005][1005];
int memo[1005];

bool isPal(int a, int b)
{
    if (a > b)
        return 1;
    if (visited[a][b])
        return pal[a][b];
    visited[a][b] = 1;
    if (s[a] == s[b])
        return pal[a][b] = isPal(a + 1, b - 1);
    return pal[a][b] = 0;
}

int dp(int a)
{
    if (a >= s.size())
        return 0;
    if (memo[a])
        return memo[a];
    int result = 10000;
    for (int i = a; i < s.size(); i++)
        if (isPal(a, i))
            result = min(result, 1 + dp(i + 1));
    return memo[a] = result;
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> s;
        ms(visited, 0);
        ms(memo, 0);

        cout << "Case " << tt << ": " << dp(0) << endl;
    }
}
