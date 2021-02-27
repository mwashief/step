/*
    Washief Hossain Mugdho
    27 February 2021
    1467 1467D
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

int main()
{
    fastio;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int n, k, q;
    cin >> n >> k >> q;
    vi a(n);
    rep(i, n) cin >> a[i];
    vvi memo(n, vi(k + 1, 0));
    rep(i, n) memo[i][0] = 1;
    repe(i, k) rep(j, n)
    {
        if (j)
            memo[j][i] = (memo[j][i] + memo[j - 1][i - 1]) % MOD;
        if (j < n - 1)
            memo[j][i] = (memo[j][i] + memo[j + 1][i - 1]) % MOD;
    }
    vi ways(n, 0);
    rep(i, n) rep(step, k + 1)
        ways[i] = (ways[i] + 1LL * memo[i][step] * memo[i][k - step] % MOD) % MOD;
    int res = 0;
    rep(i, n) res = (res + 1LL * ways[i] * a[i] % MOD) % MOD;
    rep(qq, q)
    {
        int i, val;
        cin >> i >> val;
        i--;
        res = (res - 1LL * a[i] * ways[i] % MOD + MOD) % MOD;
        a[i] = val;
        res = (res + 1LL * a[i] * ways[i] % MOD) % MOD;
        cout << res << endl;
    }
}
