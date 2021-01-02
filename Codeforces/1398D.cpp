/*
    Washief Hossain Mugdho
    31 December 2020
    Codeforces 1398D
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
void input(ArgTypes &... args);
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
void input(T &t, ArgTypes &... args)
{
    cin >> t;
    input(args...);
}

int main()
{
    fastio;
    untie;
#ifdef LOCAL_OUTPUT
    freopen(LOCAL_OUTPUT, "w", stdout);
#endif
#ifdef LOCAL_INPUT
    freopen(LOCAL_INPUT, "r", stdin);
#endif
    int r, g, b;
    vl rr, gg, bb;
    vector<vvl> memo;
    cin >> r >> g >> b;
    rr = vl(r);
    gg = vl(g);
    bb = vl(b);
    memo = vector<vvl>(r + 1, vvl(g + 1, vl(b + 1, 0)));
    rep(i, r) cin >> rr[i];
    rep(i, g) cin >> gg[i];
    rep(i, b) cin >> bb[i];
    sort(rr.begin(), rr.end(), greater<ll>());
    sort(gg.begin(), gg.end(), greater<ll>());
    sort(bb.begin(), bb.end(), greater<ll>());
    ll ans = 0;
    rep(i, r + 1) rep(j, g + 1) rep(k, b + 1)
    {
        if (i && j)
            memo[i][j][k] = max(memo[i][j][k], memo[i - 1][j - 1][k] + rr[i - 1] * gg[j - 1]);
        if (j && k)
            memo[i][j][k] = max(memo[i][j][k], memo[i][j - 1][k - 1] + gg[j - 1] * bb[k - 1]);
        if (k && i)
            memo[i][j][k] = max(memo[i][j][k], memo[i - 1][j][k - 1] + bb[k - 1] * rr[i - 1]);
        ans = max(ans, memo[i][j][k]);
    }
    cout << ans << endl;
}
