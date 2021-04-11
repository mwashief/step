/*
    Washief Hossain Mugdho
    10 April 2021
    Codeforces 1512 1512F
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
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

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
    int n;
    ll c;
    cin >> n >> c;
    vl days(n);
    vl money(n);
    vl a(n), b(n - 1);
    rep(i, n) cin >> a[i];
    rep(i, n - 1) cin >> b[i];
    ll ans = INT64_MAX;
    rep(i, n - 1)
    {
        ll extra = max(0LL, b[i] - money[i]);
        ll take = (extra + a[i] - 1) / a[i];
        ll mm = money[i] + take * a[i];
        days[i + 1] = days[i] + take + 1LL;
        money[i + 1] = mm - b[i];
    }
    rep(i, n)
    {
        ll extraMoney = max(0LL, c - money[i]);
        ll d = (extraMoney + a[i] - 1LL) / a[i];
        ans = min(ans, days[i] + d);
    }
    cout << ans << endl;
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
