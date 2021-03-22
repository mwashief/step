/*
    Washief Hossain Mugdho
    18 March 2021
    Codeforces 1499 1499B
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
#define MOD 1000000007

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
string s;
vector<vvi> memo;

bool dp(int pos, int phase, int must)
{
    if (pos >= s.size())
        return 1;
    if (memo[pos][phase][must] != -1)
        return memo[pos][phase][must];
    int c = s[pos] - '0';
    if (must)
    {
        if (c != phase)
            return memo[pos][phase][must] = 0;
        if (phase)
            return memo[pos][phase][must] = dp(pos + 1, 1, 0);
        return memo[pos][phase][must] = dp(pos + 1, 0, 0) | dp(pos + 1, 1, 0);
    }
    if (phase)
    {
        if (c)
            return memo[pos][phase][must] = dp(pos + 1, 1, 1) | dp(pos + 1, 1, 0);
        return memo[pos][phase][must] = dp(pos + 1, 1, 1);
    }
    if (c)
        return memo[pos][phase][must] = dp(pos + 1, 0, 1) | dp(pos + 1, 1, 0);
    return memo[pos][phase][must] = dp(pos + 1, 0, 0) | dp(pos + 1, 0, 1) | dp(pos + 1, 1, 0) | dp(pos + 1, 1, 1);
}

inline void _()
{
    cin >> s;
    memo = vector<vvi>(s.size(), vvi(2, vi(2, -1)));
    if (dp(0, 0, 0) | dp(0, 1, 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
    int __;
    cin >> __;
    while (__--)
        _();
}
