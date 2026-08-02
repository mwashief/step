/*
    Washief Hossain Mugdho
    21 June 2021
    Codeforces 1251-1500 1254 1254B2
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
    int n;
    cin >> n;
    ll total = 0;
    vl a(n);
    rep(i, n)
    {
        cin >> a[i];
        total += a[i];
    }
    if (total == 1LL)
    {
        cout << -1 << endl;
        return 0;
    }
    vl primes;
    primes.pb(2LL);
    vb visited(1000000);
    for (ll i = 3; i * i <= total; i += 2LL)
    {
        ll ind = (i - 3LL) >> 1;
        if (visited[ind])
            continue;
        primes.pb(i);
        for (ll j = i; j * j <= total; j += (i << 1))
            visited[(j - 3LL) >> 1] = true;
    }
    vl divisors;
    for (ll &prime : primes)
    {
        if (total % prime == 0)
            divisors.pb(prime);
        while (total % prime == 0)
            total /= prime;
    }
    if (total != 1LL)
        divisors.pb(total);

    ll res = INT64_MAX;
    for (ll &divisor : divisors)
    {
        ll cost = 0;
        ll propagated = 0;
        rep(i, n - 1)
        {
            ll now = a[i] + propagated;
            if (now > 0)
            {
                ll extra = now % divisor;
                if (extra < divisor - extra)
                {
                    propagated = extra;
                    cost += extra;
                }
                else
                {
                    propagated = -divisor + extra;
                    cost -= propagated;
                }
            }
            else
            {
                cost -= now;
                propagated = now;
            }
        }
        res = min(res, cost);
    }
    cout << res << endl;
}