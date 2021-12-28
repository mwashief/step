/*
    Washief Hossain Mugdho
    28 December 2021
    Codeforces 1501-1750 1623 1623B
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
    seti already;
    already.insert(0);
    already.insert(n + 1);
    vi res;
    vpii ranges;
    vi taken;
    rep(i, n)
    {
        int l, r;
        cin >> l >> r;
        ranges.pb({l, r});
    }
    sort(a2z(ranges), [&](pii a, pii b)
         { return a.sc - a.fr > b.sc - b.fr; });

    rep(i, n)
    {
        int l = ranges[i].fr, r = ranges[i].sc;

        if (already.find(l - 1) == already.end())
        {
            already.insert(l - 1);
            taken.pb(l - 1);
        }
        if (already.find(r + 1) == already.end())
        {
            already.insert(r + 1);
            taken.pb(r + 1);
        }
    }

    rep(i, n)
    {
        int l = ranges[i].fr;
        int r = ranges[i].sc;
        if (l == r)
        {
            cout << l << " " << r << " " << l << endl;
            continue;
        }

        rep(j, gsz(taken)) if (taken[j] >= l && taken[j] <= r)
        {
            cout << l << " " << r << " " << taken[j] << endl;
            taken[j] = -1;
            break;
        }
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
*/