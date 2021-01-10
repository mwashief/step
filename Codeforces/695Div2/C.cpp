/*
    Washief Hossain Mugdho
    08 January 2021
    695Div2 C
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
    ll n[3];
    cin >> n[0] >> n[1] >> n[2];
    ll sum[3] = {0, 0, 0};
    vl p[3];
    rep(j, 3)
        rep(i, n[j])
    {
        ll x;
        cin >> x;
        sum[j] += x;
        p[j].pb(x);
    }
    rep(i, 3) sort(p[i].begin(), p[i].end());

    ll res = 0;
    for (int i = 0; i < 3; i++)
        res = max(res, sum[0] + sum[1] + sum[2] - 2 * sum[i]);
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++)
            res = max(res, sum[0] + sum[1] + sum[2] - 2 * (p[i][0] + p[j][0]));
    cout << res << endl;
}
