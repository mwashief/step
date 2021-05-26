/*
    Washief Hossain Mugdho
    11 March 2021
    1305 1305E
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

    int n, m;
    cin >> n >> m;
    int val = 0;
    if (n & 1)
        val = (n - 1) >> 1;
    int rn = (n - (n & 1)) >> 1;
    val += rn * (rn - 1);
    if (val == m)
    {
        repe(i, n) cout << i << " \n"[i == n - 1];
        return 0;
    }
    if (val < m)
    {
        cout << -1 << endl;
        return 0;
    }
    if (n < 3)
    {
        repe(i, n) cout << i << " \n"[i == n - 1];
        return 0;
    }
    vi res = {1, 2};
    for (int i = 3; i <= n; i++)
    {
        if (m == 0)
            break;
        int cost = (i - 1) >> 1;
        if (cost <= m)
        {
            m -= cost;
            res.pb(i);
        }
        else
        {
            cost = min(cost, m);
            res.pb(res.back() + res[res.size() - cost * 2]);
            m = 0;
        }
    }
    int gap = 2 * res.back() + 1;
    if (res.size() < n)
    {
        res.pb(res.back() + gap);
        if (res.back() & 1 == 0)
            res.back()++;
    }
    while (res.size() < n)
        res.pb(res.back() + gap);
    rep(i, n) cout << res[i] << " \n"[i == n - 1];
}
