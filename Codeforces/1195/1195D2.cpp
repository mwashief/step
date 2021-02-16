/*
    Washief Hossain Mugdho
    25 January 2021
    Codeforces 1195D2
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

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif

    int n, prevZeros = 0;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int pow = 1;
    int res = 0;
    int remaining = n;
    while (remaining)
    {
        int newZeros = 0;
        rep(i, n)
        {
            if (a[i] == 0)
                continue;
            res = (1LL * res + 2LL * prevZeros * a[i] * pow % MOD) % MOD;
            int digit = a[i] % 10;
            res = (1LL * res + 1LL * remaining * digit * pow % MOD) % MOD;
            res = (1LL * res + 1LL * remaining * digit * pow * 10 % MOD) % MOD;
            a[i] /= 10;
            if (a[i] == 0)
                newZeros++;
        }
        pow = 100LL * pow % MOD;
        prevZeros = newZeros;
        remaining -= newZeros;
    }
    cout << res << endl;
}
