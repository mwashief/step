/*
    Washief Hossain Mugdho
    02 January 2021
    Codeforces 1196D2
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
void input(ArgTypes &... args);
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
void input(T &t, ArgTypes &... args)
{
    cin >> t;
    input(args...);
}
int n, k;
string s;
vvi memo;
char cc[] = {'R', 'G', 'B'};

int dp(int now, int color)
{
    if (now >= n)
        return 0;
    if (memo[now][color] != -1)
        return memo[now][color];
    return memo[now][color] = dp(now + 1, (color + 1) % 3) + (s[now] != cc[color]);
}

inline void run_tests()
{
    cin >> n >> k;
    cin >> s;
    memo = vvi(n + 1, vi(3, -1));
    memo[n][0] = memo[n][1] = memo[n][2] = 0;
    int res = INT32_MAX;
    for (int i = 0; i <= n - k; i++)
        for (int j = 0; j < 3; j++)
            res = min(res, dp(i, j) - dp(i + k, (j + k) % 3));

    cout << res << endl;
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int tc;
    cin >> tc;
    while (tc--)
        run_tests();
}
