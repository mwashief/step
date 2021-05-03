/*
    Washief Hossain Mugdho
    02 May 2021
    Codeforces 1515 1515E
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES"
#define pno cout << "NO"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define gsz(v) ((int)(v).size())
#define MAX 1000005

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
int n, MOD;

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
    cin >> n >> MOD;
    int fact[405];
    int inv[405];
    int ways[405];
    fact[0] = 1;
    repe(i, 404) fact[i] = 1LL * i * fact[i - 1] % MOD;
    inv[404] = modPow(fact[404], MOD - 2);
    rrep(i, 404) inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
    ms(ways, 0);

    for (int i = 1; i < 405; i++)
        for (int j = 1; j <= i; j++)
        {
            int k = 1LL * inv[j - 1] * inv[i - j] % MOD;
            ways[i] = ((ll)ways[i] + 1LL * k * fact[i - 1] % MOD) % MOD;
        }

    vector<vvi> memo(n + 1, vvi(n + 1, vi(n / 2 + 1, -1)));
    function<int(int, int, int)> dp = [&](int now, int man, int gaps) -> int {
        if (now == n)
        {
            if (man == 0)
                return 0;
            ll res = inv[man];
            res = 1LL * ways[man] * res % MOD;
            return 1LL * res * fact[n - gaps] % MOD;
        }

        if (memo[now][man][gaps] != -1)
            return memo[now][man][gaps];

        ll ans = dp(now + 1, man + 1, gaps);
        if (man == 0)
            return memo[now][man][gaps] = ans;

        ll res = inv[man];
        res = 1LL * ways[man] * res % MOD;
        res = 1LL * res * dp(now + 1, 0, gaps + 1) % MOD;
        return memo[now][man][gaps] = ((ll)ans + (ll)res) % MOD;
    };

    cout << dp(0, 0, 0) << endl;
}
