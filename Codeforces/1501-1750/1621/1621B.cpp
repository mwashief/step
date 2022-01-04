/*
    Washief Hossain Mugdho
    03 January 2022
    Codeforces 1501-1750 1621 1621B
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
    int n;
    cin >> n;
    int l = INT32_MAX;
    int r = INT32_MIN;
    int lind = -1;
    int rind = -1;
    int cl = INT32_MAX;
    int cr = INT32_MAX;
    int eq = 0;
    int eqCost = INT32_MAX;
    vector<pair<pii, int>> all;
    rep(i, n)
    {
        int ll, rr, cc;
        cin >> ll >> rr >> cc;
        all.pb({{ll, rr}, cc});
        if (ll == l && cc < cl)
        {
            l = ll;
            lind = i;
            cl = cc;
        }
        if (ll < l)
        {
            l = ll;
            lind = i;
            cl = cc;
            eq = 0;
            eqCost = INT32_MAX;
        }

        if (rr == r && cc < cr)
        {
            r = rr;
            rind = i;
            cr = cc;
        }
        if (rr > r)
        {
            r = rr;
            rind = i;
            cr = cc;
            eq = 0;
            eqCost = INT32_MAX;
        }
        if (ll == l && r == rr)
        {
            if (cc < eqCost)
            {
                eq = i;
                eqCost = cc;
            }
        }
        int ans = INT32_MAX;
        if (all[eq].fr.fr == l && all[eq].fr.sc == r)
            ans = all[eq].sc;

        int res = cl + cr;
        if (lind == rind)
            res -= cl;
        cout << min(res, ans) << endl;
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

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
-> Check simple logic errors
-> Read problem statements carefully
*/