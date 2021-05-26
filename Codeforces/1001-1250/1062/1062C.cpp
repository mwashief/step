/*
    Washief Hossain Mugdho
    11 January 2021
    Codeforces 1062C
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
int n, q;

ll power(ll k)
{
    ll res = 1;
    ll t = 2;
    while (k > 0)
    {
        if (k & 1)
            res = (ll)(res * t) % MOD;
        t = (ll)(t * t) % MOD;
        k >>= 1;
    }
    return res;
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
    cin >> n >> q;
    vl ones(n + 1);
    repe(i, n)
    {
        char c;
        cin >> c;
        ones[i] = ones[i - 1];
        if (c == '1')
            ones[i]++;
    }
    rep(i, q)
    {
        ll x, y;
        cin >> x >> y;
        ll one = ones[y] - ones[x - 1];
        ll zero = y - x + 1 - one;
        ll po = power(one);
        po = (ll)(po - 1 + MOD) % MOD;
        ll pz = power(zero);
        pz = (ll)(pz - 1 + MOD) % MOD;
        cout << (po + po * pz) % MOD << endl;
    }
}
