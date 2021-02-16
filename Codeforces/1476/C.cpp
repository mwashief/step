/*
    Washief Hossain Mugdho
    29 January 2021
    Edu103 C
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
int n;
vl a, b, c;
vl memo;

ll dp(int x)
{
    if (memo[x] != -1LL)
        return memo[x];
    if (b[x] == a[x])
        return memo[x] = 2LL;
    return memo[x] = max(b[x] - a[x] + 2LL, c[x - 1] - b[x] + a[x] + dp(x - 1) + 1LL);
}

inline void _()
{
    cin >> n;
    a = vl(n);
    b = vl(n);
    c = vl(n);
    memo = vl(n, -1LL);
    rep(i, n) cin >> c[i];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) if (a[i] > b[i])
        swap(a[i], b[i]);
    memo[1] = b[1] - a[1] + 2LL;
    ll res = 0;
    for (int i = 1; i < n; i++)
        res = max(res, dp(i) + c[i] - 1LL);
    cout << res << endl;
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
