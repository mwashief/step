/*
    Washief Hossain Mugdho
    12 April 2021
    Codeforces 1513 1513E
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
    int n;
    cin >> n;
    vi a(n);
    vi fact(n + 1);
    vi inv(n + 1);
    fact[0] = 1;
    repe(i, n) fact[i] = 1LL * fact[i - 1] * i % MOD;
    inv[n] = modPow(fact[n], MOD - 2);
    rrep(i, n) inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
    ll sum = 0LL;
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n)
    {
        cout << 0 << endl;
        return 0;
    }
    int avg = sum / (ll)n;
    umii l, r;
    int sink = 0, source = 0, neutral = 0;

    rep(i, n)
    {
        if (a[i] == avg)
            neutral++;
        else if (a[i] < avg)
        {
            l[a[i]]++;
            sink++;
        }
        else
        {
            r[a[i]]++;
            source++;
        }
    }
    if (neutral == n)
        cout << 1 << endl;
    else if (source == 1 || sink == 1)
    {
        int res = fact[n];
        for (auto x : l)
            res = 1LL * res * inv[x.sc] % MOD;
        for (auto x : r)
            res = 1LL * res * inv[x.sc] % MOD;
        res = 1LL * res * inv[neutral] % MOD;
        cout << res << endl;
    }
    else
    {
        int lres = fact[sink];
        for (auto x : l)
            lres = 1LL * lres * inv[x.sc] % MOD;
        int rres = fact[source];
        for (auto x : r)
            rres = 1LL * rres * inv[x.sc] % MOD;
        int res = 1LL * lres * rres % MOD;
        int nres = 1LL * fact[n] * inv[neutral] % MOD;
        nres = 1LL * nres * inv[source + sink] % MOD;
        res = 2LL * res * nres % MOD;
        cout << res << endl;
    }
}
