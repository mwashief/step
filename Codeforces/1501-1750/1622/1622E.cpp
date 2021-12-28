/*
    Washief Hossain Mugdho
    28 December 2021
    Codeforces 1501-1750 1622 1622E
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

vpii cost(10000);
vi inv(10000);
vi perm(10000);

inline void __run_test()
{
    int n, m;
    cin >> n >> m;
    vi x(n);
    vector<string> d(n);
    rep(i, n) cin >> x[i];
    rep(i, n) cin >> d[i];
    ll val = -1;

    rep(i, m) cost[i].sc = i;
    rep(mask, 1 << n)
    {
        rep(i, m) cost[i].fr = 0;
        sort(cost.begin(), cost.begin() + m, [&](pii a, pii b) -> bool
             { return a.sc < b.sc; });
        rep(i, n) rep(j, m) if (d[i][j] == '1') cost[j].fr += (mask & (1 << i)) ? 1 : -1;
        sort(cost.begin(), cost.begin() + m);
        rep(i, m) inv[cost[i].sc] = i + 1;
        ll now = 0;
        rep(i, n)
        {
            ll r = 0;
            rep(j, m) if (d[i][j] == '1') r += inv[j];
            now += abs(x[i] - r);
        }
        if (now > val)
        {
            val = now;
            rep(i, m) perm[i] = inv[i];
        }
    }
    rep(i, m) cout << perm[i] << " ";
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
*/