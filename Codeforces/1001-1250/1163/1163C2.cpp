/*
    Washief Hossain Mugdho
    25 February 2021
    1163 1163C2
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

ll modPow(int a, int b)
{
    int res = 1;
    bool neg = 0;
    if (a < 0)
    {
        neg = 1;
        a = -a;
    }
    while (b > 0)
    {
        if (b & 1)
            res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    if (neg)
        res = -res;
    return res;
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
    int n;
    cin >> n;
    vpii all(n);
    unordered_map<ll, set<ll>> track;
    rep(i, n) cin >> all[i].fr >> all[i].sc;
    rep(i, n) for (int j = i + 1; j < n; j++)
    {
        int x1 = all[i].fr;
        int y1 = all[i].sc;
        int x2 = all[j].fr;
        int y2 = all[j].sc;
        ll m = INT64_MAX;
        ll c = x1;
        if (x1 != x2)
        {
            int temp = modPow(x1 - x2, MOD - 2);
            m = 1LL * (y1 - y2) * temp % MOD;
            c = (1LL * x1 * y2 % MOD - 1LL * x2 * y1 % MOD) * temp % MOD;
        }
        track[m].insert(c);
    }
    ll total = 0;
    ll res = 0;
    for (auto d : track)
    {
        total += d.sc.size();
        res -= 1LL * d.sc.size() * (d.sc.size() - 1LL) / 2LL;
    }
    res += 1LL * total * (total - 1) / 2LL;
    cout << res << endl;
}
