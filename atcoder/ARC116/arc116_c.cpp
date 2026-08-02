/*
    Washief Hossain Mugdho
    12 April 2021
    AtCoder ARC_116 arc116_c
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
#define MOD 998244353
#define MAX 200005

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
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;

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

int modPow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
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
    int n, m;
    cin >> n >> m;
    vi fact(n + 20), inv(n + 20);
    fact[0] = 1;
    repe(i, n + 19) fact[i] = 1LL * fact[i - 1] * i % MOD;
    inv[n + 19] = modPow(fact[n + 19], MOD - 2);
    rrep(i, n + 19) inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
    vi spf(m + 1);
    repe(i, m)
        spf[i] = (i % 2 ? i : 2);

    for (int i = 3; i * i <= m; i += 2)
    {
        if (spf[i] != i)
            continue;
        for (int j = i * i; j <= m; j += (i << 1))
            spf[j] = min(spf[j], i);
    }
    int res = 0;
    repe(i, m)
    {
        umii facPow;
        int now = i;
        int ways = 1;
        while (now != 1)
        {
            facPow[spf[now]]++;
            now /= spf[now];
        }
        for (auto x : facPow)
        {
            ways = 1LL * ways * fact[n - 1 + x.sc] % MOD;
            ways = 1LL * ways * inv[n - 1] % MOD;
            ways = 1LL * ways * inv[x.sc] % MOD;
        }
        res = (res + ways) % MOD;
    }
    cout << res << endl;
}
