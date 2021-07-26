/*
    Washief Hossain Mugdho
    25 July 2021
    Codeforces 1501-1750 1551 1551D2
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#undef __INTERACTIVE__

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES" //"Yes"
#define pno cout << "NO"   //"No"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define rrepe(i, n) for (int i = (n); i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007 //998244353
#define MAX 1000005

#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
#define endl "\n"
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pair<int, int>>;

using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvpii = vector<vector<pair<int, int>>>;

using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

inline void __run_test()
{
    int n, m, k;
    cin >> n >> m >> k;
    bool swapped = false;
    vector<vector<char>> res;
    if (m % 2)
    {
        swap(n, m);
        k = n * m / 2 - k;
        swapped = true;
    }
    if (n & 1)
    {
        if (k < m / 2)
        {
            pno << endl;
            return;
        }
        k -= m / 2;
        n--;
        res.pb(vector<char>());
        rep(i, m >> 1)
        {
            res.back().pb('a');
            res.back().pb('a');
        }
    }

    if (k & 1)
    {
        pno << endl;
        return;
    }
    int full = 0, extra = 0;
    if (n)
    {
        full = k / n;
        extra = k % n;
    }
    vector<char> now(m, 'c');
    rep(i, full)
    {
        now[2 * i] = 'a';
        now[2 * i + 1] = 'a';
    }
    if (extra)
    {
        now[2 * full] = 'a';
        now[2 * full + 1] = 'a';
    }
    rep(i, extra) res.pb(now);
    if (extra)
    {
        now[2 * full] = 'c';
        now[2 * full + 1] = 'c';
    }
    rep(i, n - extra) res.pb(now);

    rep(i, gsz(res)) rep(j, m)
    {
        if ((j & 1) == 0 && (i & 1) ^ ((j >> 1) & 1) && res[i][j] == 'a')
        {
            res[i][j] = 'b';
            res[i][j + 1] = 'b';
        }
        if ((i & 1) == (gsz(res) & 1) && i < gsz(res) - 1 && (j & 1) ^ ((i >> 1) & 1) && res[i][j] == 'c')
        {
            res[i][j] = 'd';
            res[i + 1][j] = 'd';
        }
    }

    pyes << endl;

    rep(i, swapped ? m : gsz(res))
    {
        rep(j, swapped ? gsz(res) : m) cout << res[swapped ? j : i][swapped ? i : j];
        cout << endl;
    }
}

int main()
{
    fastio;
#if !defined(__INTERACTIVE__) && !defined(__DEBUG__)
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
#endif
    int __tests;
    cin >> __tests;
    while (__tests--)
        __run_test();
}