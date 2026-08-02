/*
    20 January 2023
    Codeforces 1751-2000 1782 1782E
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
    vector<pair<pair<pii, pii>, int>> a(n);
    rep(i, n)
    {
        cin >> a[i].fr.fr.fr >> a[i].fr.fr.sc >> a[i].fr.sc.fr >> a[i].fr.sc.sc;
        a[i].sc = i;
    }

    sort(a2z(a),
         [&](auto x, auto y) -> bool
         {
             if (x.fr.fr.sc < y.fr.fr.sc)
                 return true;
             if (x.fr.fr.sc > y.fr.fr.sc)
                 return false;
             return x.fr.sc.fr - x.fr.fr.fr > y.fr.sc.fr - y.fr.fr.fr;
         });

    vector<pair<pair<pii, pii>, int>> r1, r2, b;
    for (int i = 0; i < n; i++)
    {
        auto &[x, y] = a[i];
        auto &[p1, p2] = x;
        auto &[u, l] = p1;
        auto &[d, r] = p2;

        if (u == 1 && d == 1)
        {
            if (gsz(b) && b.back().fr.sc.sc >= l)
            {
                if (b.back().fr.sc.sc >= r)
                {
                    u = 0;
                    l = 0;
                    d = 0;
                    r = 0;
                }
                else
                {
                    l = b.back().fr.sc.sc + 1;
                    i--;
                }
            }
            else if (gsz(r1) && r1.back().fr.sc.sc >= l)
            {
                if (r1.back().fr.sc.sc >= r)
                {
                    u = 0;
                    l = 0;
                    d = 0;
                    r = 0;
                }
                else
                {
                    l = r1.back().fr.sc.sc + 1;
                    r1.pb({x, i});
                }
            }
            else
                r1.pb({x, i});
        }
        else if (u == 2 && d == 2)
        {
            if (gsz(b) && b.back().fr.sc.sc >= l)
            {
                if (b.back().fr.sc.sc >= r)
                {
                    u = 0;
                    l = 0;
                    d = 0;
                    r = 0;
                }
                else
                {
                    l = b.back().fr.sc.sc + 1;
                    i--;
                }
            }
            else if (gsz(r2) && r2.back().fr.sc.sc >= l)
            {
                if (r2.back().fr.sc.sc >= r)
                {
                    u = 0;
                    l = 0;
                    d = 0;
                    r = 0;
                }
                else
                {
                    l = r2.back().fr.sc.sc + 1;
                    r2.pb({x, i});
                }
            }
            else
                r2.pb({x, i});
        }
        else
        {
            if (gsz(r1) && r1.back().fr.sc.sc >= l)
            {
                if (r1.back().fr.sc.sc >= r)
                    u = 2;
                else
                {
                    r1.back().fr.sc.sc = l - 1;
                    a[r1.back().sc].fr.sc.sc = l - 1;
                    if (r1.back().fr.sc.sc < r1.back().fr.fr.sc)
                    {
                        a[r1.back().sc].fr = {{0, 0}, {0, 0}};
                        r1.pop_back();
                    }
                }
                i--;
            }
            else if (gsz(r2) && r2.back().fr.sc.sc >= l)
            {
                if (r2.back().fr.sc.sc >= r)
                    d = 1;
                else
                {
                    r2.back().fr.sc.sc = l - 1;
                    a[r2.back().sc].fr.sc.sc = l - 1;
                    if (r2.back().fr.sc.sc < r2.back().fr.fr.sc)
                    {
                        a[r2.back().sc].fr = {{0, 0}, {0, 0}};
                        r2.pop_back();
                    }
                }
                i--;
            }
            else if (gsz(b) && b.back().fr.sc.sc >= l)
            {
                if (b.back().fr.sc.sc >= r)
                {
                    u = 0;
                    l = 0;
                    d = 0;
                    r = 0;
                }
                else
                {
                    l = b.back().fr.sc.sc + 1;
                    b.pb({x, i});
                }
            }
            else
                b.pb({x, i});
        }
    }

    sort(a2z(a),
         [&](auto x, auto y) -> bool
         {
             return x.sc < y.sc;
         });

    int res = 0;
    for (auto [x, _] : a)
    {
        auto &[p1, p2] = x;
        auto &[u, l] = p1;
        auto &[d, r] = p2;

        if (u)
            res += (r - l + 1) * (d - u + 1);
    }

    cout << res << endl;
    for (auto [x, _] : a)
    {
        auto &[p1, p2] = x;
        auto &[u, l] = p1;
        auto &[d, r] = p2;

        cout << u << " " << l << " " << d << " " << r << endl;
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