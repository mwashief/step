/*
    Washief Hossain Mugdho
    30 January 2021
    Codeforces 1402A
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
    stack<pll> S;
    S.push({0, 0});
    ll res = 0;
    vl h(n), w(n);
    rep(i, n) cin >> h[i];
    rep(i, n) cin >> w[i];
    rep(i, n)
    {
        ll hh = S.top().fr;
        ll ww = S.top().sc;
        if (h[i] == hh)
            S.top().sc = (S.top().sc + w[i]) % MOD;
        else if (h[i] > hh)
            S.push({h[i], w[i]});
        else
        {
            while (S.top().fr > h[i])
            {
                hh = S.top().fr;
                ww = S.top().sc;
                S.pop();
                ll extra = hh - max(S.top().fr, h[i]);
                ll toadd = extra * (extra + 1) / 2;
                toadd %= MOD;
                toadd += extra * max(S.top().fr, h[i]) % MOD;
                toadd %= MOD;
                toadd *= (ww * (ww + 1) / 2) % MOD;
                toadd %= MOD;
                res = (res + toadd) % MOD;
                if (h[i] > S.top().fr)
                    S.push({h[i], ww});
                else
                    S.top().sc = (S.top().sc + ww) % MOD;
            }
            i--;
        }
    }
    while (S.top().fr > 0LL)
    {
        ll hh = S.top().fr;
        ll ww = S.top().sc;
        S.pop();
        ll extra = hh - S.top().fr;
        ll toadd = extra * (extra + 1) / 2;
        toadd %= MOD;
        toadd += extra * S.top().fr % MOD;
        toadd %= MOD;
        toadd *= (ww * (ww + 1) / 2) % MOD;
        toadd %= MOD;
        res = (res + toadd) % MOD;
        S.top().sc = (S.top().sc + ww) % MOD;
    }
    cout << res << endl;
}
