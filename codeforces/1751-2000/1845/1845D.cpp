/*
    29 June 2023
    Codeforces 1751-2000 1845 1845D
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

bool pos(ll x)
{
    return x > 0;
}

bool neg(ll x)
{
    return x < 0;
}

inline void __run_test()
{
    int n;
    cin >> n;
    vl a;
    rep(i, n)
    {
        ll x;
        cin >> x;
        if (gsz(a) == 0)
            a.pb(x);
        else if (pos(a.back()) != pos(x))
            a.pb(x);
        else
            a.back() += x;
    }
    if (!pos(a.back()))
        a.pb(0LL);

    ll maximum = 0LL;
    ll thre = 0LL;
    n = gsz(a);

    vl prefixSum = {0};
    rep(i, n) prefixSum.pb(prefixSum.back() + a[i]);
    ll val = 0LL;
    ll minusable = 0LL;

    rrep(i, n) if (neg(a[i]))
    {
        ll k = min(minusable, a[i + 1]);
        ll rating = a[i + 1] - k + val;
        if (rating + prefixSum[i] > maximum)
        {
            maximum = rating + prefixSum[i];
            thre = prefixSum[i];
        }

        val = rating;
        minusable -= a[i] + k;
    }

    cout << thre << endl;
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