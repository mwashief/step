/*
    Washief Hossain Mugdho
    03 January 2021
    AtCoder abc185_e
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
int n, m;
vi a, b;
vvi memo;

int dp(int x, int y)
{
    if (x < 0)
        return y + 1;
    if (y < 0)
        return x + 1;
    if (memo[x][y] != -1)
        return memo[x][y];
    int res = dp(x - 1, y - 1) + (a[x] == b[y] ? 0 : 1);
    res = min(res, dp(x - 1, y) + 1);
    res = min(res, dp(x, y - 1) + 1);
    return memo[x][y] = res;
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

    int x;
    cin >> n >> m;
    rep(i, n)
    {
        cin >> x;
        a.pb(x);
    }
    rep(i, m)
    {
        cin >> x;
        b.pb(x);
    }
    memo = vvi(n, vi(m, -1));
    cout << dp(n - 1, m - 1) << endl;
}
