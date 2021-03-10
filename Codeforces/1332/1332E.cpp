/*
    Washief Hossain Mugdho
    10 March 2021
    1332 1332E
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
#define MOD 998244353LL

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

ll modPow(ll a, ll b)
{
    ll res = 1LL;
    while (b)
    {
        if (b & 1LL)
            res = res * a % MOD;
        a = a * a % MOD;
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

    ll n, m, L, R;
    cin >> n >> m >> L >> R;
    ll k = n * m;
    if ((n & 1LL) && (m & 1LL))
    {
        cout << modPow(R - L + 1, k) << endl;
        return 0;
    }
    ll odd = (R - L + 1) >> 1;
    ll even = (R - L + 1) >> 1;
    if ((L & 1LL) && (R & 1LL))
        odd++;
    else if (!(L & 1LL) && !(R & 1LL))
        even++;
    ll sum = (even + odd) % MOD;
    ll diff = abs(even - odd) % MOD;
    ll res = modPow(sum, k);
    res = (res + modPow(diff, k)) % MOD;
    res = res * modPow(2LL, MOD - 2LL) % MOD;
    cout << res << endl;
}
