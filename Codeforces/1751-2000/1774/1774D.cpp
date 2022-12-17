/*
    17 December 2022
    Codeforces 1751-2000 1774 1774D
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

template <class T>
void swap(T &a, T &b)
{
    T c(std::move(a));
    a = std::move(b);
    b = std::move(c);
}

inline void __run_test()
{
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));

    int total = 0;
    rep(i, n) rep(j, m)
    {
        cin >> a[i][j];
        total += a[i][j];
    }

    if (total % n)
    {
        cout << -1 << endl;
        return;
    }

    int per = total / n;
    vi row(n);
    vvi giver(m);
    vvi taker(m);
    rep(i, n)
    {
        row[i] = accumulate(a2z(a[i]), 0);
        if (row[i] > per)
        {
            rep(j, m) if (a[i][j]) giver[j].pb(i);
        }
        else if (row[i] < per)
            rep(j, m) if (!a[i][j]) taker[j].pb(i);
    }

    vector<pair<pii, int>> res;

    rep(i, m) while (gsz(giver[i]) && gsz(taker[i]))
    {
        if (row[giver[i].back()] <= per)
        {
            giver[i].pop_back();
            continue;
        }
        if (row[taker[i].back()] >= per)
        {
            taker[i].pop_back();
            continue;
        }
        res.pb({{giver[i].back(), taker[i].back()}, i});
        row[giver[i].back()]--;
        row[taker[i].back()]++;
        giver[i].pop_back();
        taker[i].pop_back();
    }

    cout << gsz(res) << endl;
    for (auto mov : res)
        cout << mov.fr.fr + 1 << " " << mov.fr.sc + 1 << " " << mov.sc + 1 << endl;
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