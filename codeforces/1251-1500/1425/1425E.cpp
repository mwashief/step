/*
    Washief Hossain Mugdho
    30 August 2021
    Codeforces 1251-1500 1425 1425E
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
    int n, k;
    cin >> n >> k;
    vi a(n), d(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> d[i];
    vl prefixSum(n + 1);
    rep(i, n) prefixSum[i + 1] = prefixSum[i] + a[i];
    ll res = 0;

    if (k == 1)
    {
        int lowest = d[0];
        repe(i, n - 1)
        {
            lowest = min(lowest, d[i]);
            res = max(res, prefixSum[n] - prefixSum[i] - (ll)d[i]); // i to last
            res = max(res, prefixSum[n] - a[i] - d[0]);             // first to last, except i
            res = max(res, prefixSum[n] - d[i] - d[0]);             // first to last, 2 excitations

            if (i != n - 1)
            {
                res = max(res, prefixSum[i + 1] - (ll)lowest);            // first to i, a cycle
                res = max(res, prefixSum[n] - (ll)lowest - (ll)d[i + 1]); // first to i, a cycle, and rest
            }
        }
    }
    else
    {
        rep(i, n) res = max(res, prefixSum[n] - prefixSum[i] - (ll)d[i]);
        if (k)
            rep(i, n - 1) res = max(res, prefixSum[n] - (ll)d[i]);
    }
    res = max<ll>(res, a[k] - d[k]);
    cout << res << endl;
}