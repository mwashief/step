/*
    Washief Hossain Mugdho
    18 March 2021
    Codeforces 1499 1499C
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

inline void _()
{
    ll n;
    cin >> n;
    vvl a(2);
    vvl b(2);
    rep(i, n)
    {
        ll x;
        cin >> x;
        a[i & 1].pb(x);
    }
    rep(k, 2)
    {
        ll elements = 0LL;
        ll mini = INT64_MAX;
        ll total = 0LL;
        for (auto d : a[k])
        {
            elements++;
            mini = min(mini, d);
            total += d;
            ll now = total + mini * (n - elements);
            b[k].pb(now);
        }
    }

    ll res = INT64_MAX;
    for (int i = 0; i < b[0].size(); i++)
    {
        if (i < b[1].size())
            res = min(res, b[0][i] + b[1][i]);
        if (i - 1 >= 0)
            res = min(res, b[0][i] + b[1][i - 1]);
    }
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
