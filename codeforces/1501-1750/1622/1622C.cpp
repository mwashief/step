/*
    Washief Hossain Mugdho
    27 December 2021
    Codeforces 1501-1750 1622 1622C
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
    ll n, k;
    cin >> n >> k;
    vl a(n), suff(n);
    rep(i, n) cin >> a[i];
    if (n == 1)
    {
        cout << max(0LL, a[0] - k) << endl;
        return;
    }
    sort(a2z(a));
    suff[0] = a[0];
    repe(i, n - 1) suff[i] = suff[i - 1] + a[i];
    if (suff.back() <= k)
    {
        cout << 0 << endl;
        return;
    }
    auto get = [&](int d) -> ll
    {
        return suff[d] - suff[0];
    };
    ll res = suff.back() - k;
    rrepe(i, n - 1)
    {
        ll dane = n - i;
        ll g = get(i - 1);
        ll addable = k - g;
        ll per = 0LL;
        if (addable >= 0)
            per = addable / (dane + 1);
        else
            per = -(-addable + dane) / (dane + 1);
        if (per > a[0])
            per = a[0];
        res = min(res, dane + a[0] - per);
    }
    cout << res << endl;
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