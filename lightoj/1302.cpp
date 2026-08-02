/*
    Washief Hossain Mugdho
    07 August 2020
    LightOJ 1302
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
using namespace std;
string s;
unordered_map<string, ull> memo;

inline ull isRed(string s, int k)
{
    return s[k] == 'R' ? 1 : 0;
}

ull dp(string s)
{
    if (s.size() == 0)
        return 1;
    if (memo.find(s) != memo.end())
        return memo[s];
    int co;
    ull ans = 0;
    for (int j = 1; j < s.size() - 1; j += 3)
    {
        int co = isRed(s, 0) + isRed(s, j);
        if (co < 2)
            for (int k = j + 1; k < s.size(); k += 3)
            {
                if (co + isRed(s, k) < 2)
                {
                    ull a = dp(s.substr(1, j - 1));
                    ull b = dp(s.substr(j + 1, k - j - 1));
                    ull c = dp(s.substr(k + 1, s.size() - k - 1));
                    ans += a * b * c;
                }
            }
    }
    return memo[s] = ans;
}

int main()
{
    int T, co;
    bool yes;
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        cin >> s;
        memo.clear();
        cout << "Case " << tt << ": " << dp(s) << endl;
    }
}
