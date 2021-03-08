/*
    Washief Hossain Mugdho
    08 March 2021
    Educational DP Sushi
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
int n;
bool visited[305][305][305];
double memo[305][305][305];

long double dp(int o, int tw, int th)
{
    if (visited[o][tw][th])
        return memo[o][tw][th];
    visited[o][tw][th] = 1;
    int total = o + tw + th;
    int z = n - total;
    if (n == z)
        return memo[o][tw][th] = 0.0;
    long double res = 0.0;
    if (th)
        res += 1.0 * th / n * (1 + dp(o, tw + 1, th - 1));
    if (tw)
        res += 1.0 * tw / n * (1 + dp(o + 1, tw - 1, th));
    if (o)
        res += 1.0 * o / n * (1 + dp(o - 1, tw, th));
    if (z)
    {
        res += 1.0 * z / n;
        res /= (1.0 - 1.0 * z / n);
    }
    return memo[o][tw][th] = res;
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
    cin >> n;
    int k[4] = {0, 0, 0, 0};
    rep(i, n)
    {
        int x;
        cin >> x;
        k[x]++;
    }
    cout << fixed << setprecision(14) << dp(k[1], k[2], k[3]) << endl;
}
