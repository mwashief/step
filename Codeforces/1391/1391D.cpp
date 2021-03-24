/*
    Washief Hossain Mugdho
    24 March 2021
    Codeforces 1391 1391D
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
int n, m;
int mm[] = {2, 3, 0, 1};
vvb a;
vvi memo;

int dp(int col, int config)
{
    if (col < 0)
        return 0;
    if (memo[col][config] != -1)
        return memo[col][config];
    int extra = 0;
    for (int i = 0; i < n; i++)
    {
        bool x = a[i][col];
        bool y = config & (1 << i);
        if (x ^ y)
            extra++;
    }
    int compatible1 = mm[config > 3 ? 7 - config : config];
    int compatible2 = (1 << n) - compatible1 - 1;
    return memo[col][config] = extra + min(dp(col - 1, compatible1), dp(col - 1, compatible2));
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
    cin >> n >> m;
    if (n == 1 || m == 1)
        cout << 0 << endl;
    else if (n <= 3 || m <= 3)
    {
        vvb b(n, vb(m));
        rep(i, n) rep(j, m)
        {
            char c;
            cin >> c;
            c -= '0';
            b[i][j] = c;
        }
        if (n < m)
            a = b;
        else
        {
            a = vvb(m, vb(n));
            rep(i, n) rep(j, m) a[j][i] = b[i][j];
            swap(n, m);
        }
        memo = vvi(m, vi((1 << n), -1));
        int res = INT32_MAX;
        for (int i = 0; i < (1 << n); i++)
            res = min(res, dp(m - 1, i));
        cout << res << endl;
    }
    else
        cout << -1 << endl;
}
