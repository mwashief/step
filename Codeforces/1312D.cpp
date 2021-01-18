/*
    Washief Hossain Mugdho
    18 January 2021
    Codeforces 1312D
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

int modPow(int base, int power)
{
    int res = 1;
    while (power > 0)
    {
        if (power & 1)
            res = 1LL * res * base % MOD;
        base = 1LL * base * base % MOD;
        power >>= 1;
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
    if (n == 2)
    {
        cout << 0 << endl;
        return 0;
    }
    vi fact;
    fact.pb(1);
    repe(i, m)
        fact.pb(1LL * fact.back() * i % MOD);
    vi inv(m + 1);
    inv[m] = modPow(fact[m], MOD - 2);
    rrep(i, m)
        inv[i] = 1LL * (i + 1) * inv[i + 1] % MOD;
    int ans = 0;
    for (int i = n - 1; i <= m; i++)
    {
        int term = 1LL * (i - 1) * fact[i - 2] % MOD;
        term = 1LL * term * inv[n - 3] % MOD;
        term = 1LL * term * inv[i - n + 1] % MOD;
        ans = (ans + term) % MOD;
    }
    ans = 1LL * ans * modPow(2, n - 3) % MOD;
    cout << ans << endl;
}
