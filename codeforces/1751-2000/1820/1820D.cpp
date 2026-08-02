/*
    15 April 2023
    Codeforces 1751-2000 1820 1820D
*/

#ifndef __DEBUG__
#pragma GCC optimize("Ofast")
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
#define MOD 1000000007 // 998244353
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
using vpll = vector<pair<ll, ll>>;

using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvpii = vector<vector<pair<int, int>>>;

using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

pll find(vector<pll> &recs)
{
    auto horizontal = [](pll a, pll b) -> bool
    {
        if (a.sc > b.sc)
            return true;
        if (a.sc < b.sc)
            return false;
        return a.fr > b.fr;
    };
    auto vertical = [](pll a, pll b) -> bool
    {
        if (a.fr > b.fr)
            return true;
        if (a.fr < b.fr)
            return false;
        return a.sc > b.sc;
    };
    multiset<pll, decltype(horizontal)> hori;
    multiset<pll, decltype(vertical)> ver;
    for (auto rec : recs)
    {
        hori.insert(rec);
        ver.insert(rec);
    }
    ll maxW = hori.begin()->sc;
    ll maxH = 0LL;
    while (gsz(hori) && hori.begin()->sc == maxW)
    {
        maxH += hori.begin()->fr;
        ver.erase(ver.find(*hori.begin()));
        hori.erase(hori.begin());
    }
    ll hleft = 0;
    ll wleft = maxW;

    if (gsz(ver))
    {
        maxH += ver.begin()->fr;
        hleft = ver.begin()->fr;

        bool h = true;

        while (gsz(hori))
        {
            h = !h;
            if (h)
            {
                if (hori.begin()->sc != wleft)
                    return {-1, -1};
                while (gsz(hori) && hori.begin()->sc == wleft)
                {
                    hleft -= hori.begin()->fr;
                    ver.erase(ver.find(*hori.begin()));
                    hori.erase(hori.begin());
                }
            }
            else
            {
                if (ver.begin()->fr != hleft)
                    return {-1, -1};
                while (gsz(ver) && ver.begin()->fr == hleft)
                {
                    wleft -= ver.begin()->sc;
                    hori.erase(hori.find(*ver.begin()));
                    ver.erase(ver.begin());
                }
            }
        }
    }

    if (hleft == 0LL || wleft == 0LL)
        return {maxH, maxW};

    return {-1, -1};
}

inline void __run_test()
{
    int n;
    cin >> n;
    vpll a(n);
    rep(i, n) cin >> a[i].fr >> a[i].sc;
    auto res = find(a);
    vpll all;
    if (res.fr != -1)
        all.pb(res);

    rep(i, n) swap(a[i].fr, a[i].sc);
    res = find(a);
    if (res.fr != -1 && (gsz(all) == 0 || (all.back().fr != res.sc || all.back().sc != res.fr)))
        all.pb({res.sc, res.fr});
    cout << gsz(all) << endl;
    for (auto [h, w] : all)
        cout << h << " " << w << endl;
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