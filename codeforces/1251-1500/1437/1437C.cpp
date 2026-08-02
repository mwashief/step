/*
    Washief Hossain Mugdho
    14 January 2021
    Codeforces 1437C
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
int n;
vvi memo;
vi t;
const int MAXIMUM = 400 * 400;

int dp(int time, int dish)
{
    if (dish + 1 > time)
        return MAXIMUM;
    if (dish == 0)
        return abs(time - t[dish]);
    if (memo[time][dish] != -1)
        return memo[time][dish];
    int res = MAXIMUM;
    int now = abs(time - t[dish]);
    for (int i = 1; i < time; i++)
        res = min(res, dp(i, dish - 1) + now);
    return memo[time][dish] = res;
}

inline void run_tests()
{
    cin >> n;
    memo = vvi(2 * n + 10, vi(n, -1));
    t = vi(n);
    rep(i, n) cin >> t[i];
    sort(t.begin(), t.end());
    int res = MAXIMUM;
    for (int i = 1; i < 2 * n + 10; i++)
        res = min(res, dp(i, n - 1));
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
