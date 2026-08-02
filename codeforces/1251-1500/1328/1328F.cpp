/*
    Washief Hossain Mugdho
    08 November 2021
    Codeforces 1251-1500 1328 1328F
*/
// https://codeforces.com/problemset/problem/1328/F

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
    ll n, k;
    cin >> n >> k;
    mii all;
    rep(i, n)
    {
        int x;
        cin >> x;
        all[x]++;
    }
    vector<pll> a;
    for (auto d : all)
        a.pb(d);
    n = gsz(a);
    vl suffixElements(n + 1), suffixCost(n + 1);
    vl prefixElements(n + 1), prefixCost(n + 1);
    rrep(i, n)
    {
        suffixElements[i] += suffixElements[i + 1] + a[i].sc;
        suffixCost[i] = suffixCost[i + 1];
        if (suffixElements[i + 1])
            suffixCost[i] += suffixElements[i + 1] * (a[i + 1].fr - a[i].fr);
    }
    rep(i, n)
    {
        prefixElements[i + 1] += prefixElements[i] + a[i].sc;
        prefixCost[i + 1] = prefixCost[i];
        if (prefixElements[i])
            prefixCost[i + 1] += prefixElements[i] * (a[i].fr - a[i - 1].fr);
    }
    ll res = INT64_MAX;
    rep(i, n)
    {
        ll need = max(0LL, k - a[i].sc);

        ll cost = 0LL;
        ll take = min(need, prefixElements[i]);
        if (take)
            cost += prefixCost[i] + take + prefixElements[i] * (a[i].fr - a[i - 1].fr - 1LL);
        take = need - take;
        if (take)
            cost += suffixCost[i + 1] + take + suffixElements[i + 1] * (a[i + 1].fr - a[i].fr - 1LL);
        res = min(res, cost);

        cost = 0LL;
        take = min(need, suffixElements[i + 1]);
        if (take)
            cost += suffixCost[i + 1] + take + suffixElements[i + 1] * (a[i + 1].fr - a[i].fr - 1LL);

        take = need - take;
        if (take)
            cost += prefixCost[i] + take + prefixElements[i] * (a[i].fr - a[i - 1].fr - 1LL);
        res = min(res, cost);
    }
    cout << res << endl;
}

/*
-> Check for data types
-> Fix macro
-> Run test case
-> Check the copied part
-> Set or multiset?
-> Check statement order
*/