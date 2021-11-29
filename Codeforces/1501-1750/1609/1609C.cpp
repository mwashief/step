/*
    Washief Hossain Mugdho
    28 November 2021
    Codeforces 1501-1750 1609 1609C
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

vector<int> prime;
seti primes;
bool is_composite[1000001];

void sieve()
{
    for (int i = 2; i < 1000001; ++i)
    {
        if (!is_composite[i])
            prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] < 1000001; ++j)
        {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

ll get(vi &a)
{
    ll res = 0LL;
    rep(i, gsz(a))
    {
        if (primes.count(a[i]))
        {
            ll age = 1;
            for (int j = i - 1; j >= 0; j--)
                if (a[j] == 1)
                    age++;
                else
                    break;
            ll pore = 1;
            for (int j = i + 1; j < gsz(a); j++)
                if (a[j] == 1)
                    pore++;
                else
                    break;
            res += age * pore - 1LL;
        }
    }
    return res;
}

inline void __run_test()
{
    int n, e;
    cin >> n >> e;
    vvi d(e);
    rep(i, n)
    {
        int x;
        cin >> x;
        d[i % e].pb(x);
    }
    ll res = 0LL;
    rep(i, e) res += get(d[i]);
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

    sieve();
    for (auto p : prime)
        primes.insert(p);
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
*/