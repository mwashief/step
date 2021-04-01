/*
    Washief Hossain Mugdho
    01 April 2021
    Codeforces 1445 1445C
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rrepe(i, n) for (int i = n; i > 0; i--)
#define ms(a, b) memset(a, b, sizeof a)
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;

/***********IO Utility**************/
template <typename... ArgTypes>
void print(ArgTypes... args);
template <typename... ArgTypes>
void input(ArgTypes &...args);
template <>
void print() {}
template <>
void input() {}
template <typename T, typename... ArgTypes>
void print(T t, ArgTypes... args)
{
    cout << t;
    print(args...);
}
template <typename T, typename... ArgTypes>
void input(T &t, ArgTypes &...args)
{
    cin >> t;
    input(args...);
}
vl primes;

inline void _()
{
    ll p, q;
    cin >> p >> q;
    if (p % q)
    {
        cout << p << endl;
        return;
    }
    vector<pll> d;
    for (auto prime : primes)
    {
        ll num = 1;
        while (q % prime == 0)
        {
            num *= prime;
            q /= prime;
        }
        if (num != 1)
            d.pb({prime, num});
    }
    if (q != 1LL)
        d.pb({q, q});
    ll res = 1;
    for (auto a : d)
    {
        ll temp = p;
        while (temp % a.fr == 0)
            temp /= a.fr;

        res = max(res, temp * a.sc / a.fr);
    }
    cout << res << endl;
}

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    vb v(31700);
    primes.pb(2LL);
    for (int i = 3; i < 31700; i += 2)
    {
        if (v[i])
            continue;
        primes.pb((ll)i);
        for (int j = i * i; j < 31700; j += 2 * i)
            v[j] = 1;
    }
    int __;
    cin >> __;
    while (__--)
        _();
}
