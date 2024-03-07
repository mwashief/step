/*
    29 January 2024
    Codeforces 1751-2000 1922 1922D
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
    vi a(n), d(n), candidates(n);
    seti deletedLater;
    set<int, greater<int>> deletedBefore;

    rep(i, n) cin >> a[i];
    rep(i, n) cin >> d[i];
    rep(i, n)
    {
        deletedBefore.insert(i);
        deletedLater.insert(i);
        candidates[i] = i;
    }

    vi res;
    while (gsz(candidates))
    {
        vi deleted;
        for (auto candidate : candidates)
        {
            int la = 0, ra = 0;
            auto itl = deletedBefore.upper_bound(candidate);
            auto itr = deletedLater.upper_bound(candidate);
            if (itl != deletedBefore.end())
                la = a[*itl];
            if (itr != deletedLater.end())
                ra = a[*itr];

            if (d[candidate] < la + ra)
                deleted.pb(candidate);
        }

        res.pb(gsz(deleted));
        candidates.clear();

        for (auto candidate : deleted)
        {
            deletedBefore.erase(candidate);
            deletedLater.erase(candidate);
        }

        for (auto candidate : deleted)
        {
            auto itl = deletedBefore.upper_bound(candidate);
            auto itr = deletedLater.upper_bound(candidate);
            if (itl != deletedBefore.end())
                candidates.pb(*itl);
            if (itr != deletedLater.end())
                candidates.pb(*itr);
        }
        sort(a2z(candidates));
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    }

    while (gsz(res) < n)
        res.pb(0);
    for (auto r : res)
        cout << r << " ";
    cout << endl;
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