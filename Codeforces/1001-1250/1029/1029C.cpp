/*
    Washief Hossain Mugdho
    13 January 2021
    Codeforces 1029C
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
    int n;
    cin >> n;
    vpii dt = vpii(n);
    rep(i, n) cin >> dt[i].fr >> dt[i].sc;
    vi leftMin(n + 2, INT32_MAX);
    vi rightMin(n + 2, INT32_MAX);
    vi leftMax(n + 2, INT32_MIN);
    vi rightMax(n + 2, INT32_MIN);
    rep(i, n) leftMin[i + 1] = min(leftMin[i], dt[i].sc);
    rrep(i, n) rightMin[i + 1] = min(rightMin[i + 2], dt[i].sc);
    rep(i, n) leftMax[i + 1] = max(leftMax[i], dt[i].fr);
    rrep(i, n) rightMax[i + 1] = max(rightMax[i + 2], dt[i].fr);
    int res = 0;
    rep(i, n)
        res = max(res, min(leftMin[i], rightMin[i + 2]) - max(leftMax[i], rightMax[i + 2]));
    cout << res << endl;
}
