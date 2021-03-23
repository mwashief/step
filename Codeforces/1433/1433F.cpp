/*
    Washief Hossain Mugdho
    23 March 2021
    Codeforces 1433 1433F
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
int n, m, k;
int memo[71][71][36][71];
int a[71][71];

int dp(int row, int col, int taken, int rem)
{
    if (taken == 0 && rem == 0)
        return 0;

    if (taken <= 0 || col < 0)
        return -2;

    if (memo[row][col][taken][rem] != -1)
        return memo[row][col][taken][rem];

    int elem = a[row][col];
    int newRem = (rem + k - elem % k) % k;
    int a = dp(row, col - 1, taken - 1, newRem);
    int b = dp(row, col - 1, taken, rem);
    int c = dp(row, col, taken - 1, rem);
    if (a == -2 && b == -2 && c == -2)
        return memo[row][col][taken][rem] = -2;
    if (a == -2 && b == -2)
        return memo[row][col][taken][rem] = c;
    if (c == -2 && b == -2)
        return memo[row][col][taken][rem] = a + elem;
    if (a == -2 && c == -2)
        return memo[row][col][taken][rem] = b;
    if (a == -2)
        return memo[row][col][taken][rem] = max(b, c);
    return memo[row][col][taken][rem] = max({a + elem, b, c});
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
    cin >> n >> m >> k;
    ms(memo, -1);
    rep(i, n) rep(j, m) cin >> a[i][j];
    vi previous(k);
    rep(i, k) previous[i] = dp(0, m - 1, m >> 1, i);
    for (int i = 1; i < n; i++)
    {
        vi now(k);
        rep(j, k)
            now[j] = dp(i, m - 1, m >> 1, j);
        vi nex(k, -2);
        rep(j, k) if (previous[j] != -2) rep(kk, k) if (now[kk] != -2)
            nex[(j + kk) % k] = max(nex[(j + kk) % k], previous[j] + now[kk]);
        swap(previous, nex);
    }
    cout << previous[0] << endl;
}
