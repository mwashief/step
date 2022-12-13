/*
    Washief Hossain Mugdho
    11 December 2022
    CodeChef DIVISIBLEBY
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

vi primes;

pair<vi, ll> factorize(int num)
{
    vi res;
    for (auto prime : primes)
    {
        int cnt = 0;
        while (num % prime == 0)
        {
            cnt++;
            num /= prime;
        }
        res.pb(cnt);
    }
    return {res, num};
}

ll pow(ll num, ll p)
{
    ll ans = 1LL;
    while (p > 0)
    {
        if (p & 1)
            ans *= num;
        num *= num;
        p >>= 1;
    }
    return ans;
}

inline void __run_test()
{
    int n;
    cin >> n;
    vi a(n);
    vi lowest(gsz(primes), 10000);
    ll all = 0;
    rep(i, n)
    {
        cin >> a[i];
        auto res = factorize(a[i]);
        auto factors = res.fr;
        ll extra = res.sc;
        rep(i, gsz(primes))
            lowest[i] = min(lowest[i], factors[i]);
        all = __gcd(all, extra);
    }

    rep(i, n)
    {
        auto res = factorize(a[i]);
        vi factors = res.fr;
        ll extra = res.sc;
        ll ans = 1LL;
        rep(j, gsz(primes))
            ans *= pow(primes[j], factors[j] - lowest[j]);
        cout << ans * extra / all << " ";
    }

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
    bool is_composite[1001];

    std::fill(is_composite, is_composite + 1001, false);
    for (int i = 2; i < 1001; ++i)
    {
        if (!is_composite[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] < 1001; ++j)
        {
            is_composite[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }

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