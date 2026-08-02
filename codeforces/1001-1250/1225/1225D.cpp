/*
    Washief Hossain Mugdho
    21 January 2021
    Codeforces 1225D
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
int n, k;
vi primes;
vi a;

void inline getPrimes()
{
    vb visited(351);
    primes.pb(2);
    for (int i = 3; i <= 350; i += 2)
    {
        if (visited[i])
            continue;
        primes.pb(i);
        for (int j = i * i; j <= 350 && j > i; j += i)
            visited[j] = 1;
    }
}

int getPow(int base, int p)
{
    int res = 1;
    while (p > 0)
    {
        if (p & 1)
            res *= base;
        if (res < 0)
            return 0;
        base = base * base;
        p >>= 1;
        if (base < 0 && p != 0)
            return 0;
    }
    return res;
}

pii getToken(int x)
{
    int token = 1;
    vpii against;
    for (auto prime : primes)
    {
        int howMany = 0;
        int multiplier = 1;
        while (x % prime == 0)
        {
            x /= prime;
            multiplier *= prime;
            howMany++;
            if (howMany == k)
            {
                howMany = 0;
                multiplier = 1;
            }
        }
        against.pb({prime, (k - howMany) % k});
        token *= multiplier;
    }
    if (x != 1)
    {
        token *= x;
        against.pb({x, k - 1});
    }
    int a = 1;
    for (auto ag : against)
    {
        a *= getPow(ag.fr, ag.sc);
        if (a < 0)
            a = 0;
    }
    return {token, a};
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
    mii howmany;
    mii against;
    cin >> n >> k;
    getPrimes();
    a = vi(n);
    rep(i, n)
    {
        int x;
        cin >> x;
        auto r = getToken(x);
        howmany[r.fr]++;
        against[r.fr] = r.sc;
    }
    ll res = 0;
    for (auto num : howmany)
    {
        int c1 = num.sc;
        int ag = against[num.fr];
        if (ag == 0)
            continue;
        if (num.fr == ag)
        {
            res = res + 1LL * c1 * (c1 - 1LL) / 2LL;
            continue;
        }
        if (howmany.find(ag) == howmany.end())
            continue;
        int c2 = howmany[ag];
        howmany[ag] = 0;
        howmany[num.fr] = 0;
        res = res + 1LL * c1 * c2;
    }
    cout << res << endl;
}
