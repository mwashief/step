/*
    Washief Hossain Mugdho
    12 August 2020
    LightOJ 1110
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
int memo[105][105];
char memo2[105][105];
bool visited[105][105];
string s1, s2, s[105][105];

string dp(int a, int b)
{
    if (a >= s1.size() || b >= s2.size())
        return "";
    if (visited[a][b])
        return s[a][b];
    visited[a][b] = 1;
    if (s1[a] == s2[b])
        return s[a][b] = string(1, s1[a]) + dp(a + 1, b + 1);
    string x = dp(a + 1, b);
    string y = dp(a, b + 1);
    if (x.size() > y.size())
        return s[a][b] = x;
    else if (x.size() < y.size())
        return s[a][b] = y;
    return s[a][b] = min(x, y);
}

int main()
{
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> s1 >> s2;
        ms(visited, 0);
        string ss = dp(0, 0);

        cout << "Case " << tt << ": ";
        if (!ss.size())
            cout << ":(";
        else
            cout << ss;
        cout << endl;
    }
}
