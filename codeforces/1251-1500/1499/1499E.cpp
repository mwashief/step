/*
    Washief Hossain Mugdho
    20 March 2021
    Codeforces 1499 1499E
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rrepe(i, n) for (int i = n; i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define MOD 998244353

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &...args);
template <>
void print() {}
template <>
void input() {}
template <typename T, typename... ArgTypes>
void print(T t, ArgTypes... args)
{
    cout << t;
    print(args...);
}
template <typename T, typename... ArgTypes>
void input(T &t, ArgTypes &...args)
{
    cin >> t;
    input(args...);
}
string s, t;
int memo[27][1002][1002];

int dp(int prevChar, int a, int b)
{

    if (memo[prevChar][a][b] != -1)
        return memo[prevChar][a][b];
    int chA = prevChar;
    int chB = prevChar;
    if (a < s.size())
        chA = s[a] - 'a';
    if (b < t.size())
        chB = t[b] - 'a';
    int res = 0;
    if (chA != prevChar)
        res = (res + dp(chA, a + 1, b)) % MOD;
    if (chB != prevChar)
        res = (res + dp(chB, a, b + 1)) % MOD;
    res = (res + 1) % MOD;
    return memo[prevChar][a][b] = res;
}

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    cin >> s >> t;
    ms(memo, -1);
    int res = 0;
    rep(i, s.size()) rep(j, t.size())
        res = (res + dp(26, i, j)) % MOD;
    int last = s.size();
    for (int i = s.size() - 1; i > 0; i--)
    {
        int len = last - i + 1;
        res = (res + MOD - len * t.size()) % MOD;
        if (s[i] == s[i - 1])
            last = i;
    }
    res = (res + MOD - (last + 1) * t.size()) % MOD;
    last = t.size();
    for (int i = t.size() - 1; i > 0; i--)
    {
        int len = last - i;
        res = (res + MOD - len * s.size()) % MOD;
        if (t[i] == t[i - 1])
            last = i;
    }
    res = (res + MOD - last * s.size()) % MOD;
    cout << res << endl;
}
