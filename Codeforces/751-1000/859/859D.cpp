/*
    Washief Hossain Mugdho
    15 April 2021
    Codeforces 859 859D
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
long double memo[200][200][200];
long double proba[200][200][200];
bool visited[200][200][200];
int mat[200][200];

long double dp(int l, int r, int winner)
{
    assert(l <= winner && winner <= r);
    if (visited[l][r][winner])
        return memo[l][r][winner];
    visited[l][r][winner] = 1;
    if (l == r)
    {
        proba[l][r][winner] = 1.0;
        return memo[l][r][winner] = 0.0;
    }
    int mid = (l + r) >> 1;
    int start;
    int finish;
    long double already;
    long double winnerProb;
    if (winner <= mid)
    {
        start = mid + 1;
        finish = r;
        already = dp(l, mid, winner);
        winnerProb = proba[l][mid][winner];
    }
    else
    {
        start = l;
        finish = mid;
        already = dp(mid + 1, r, winner);
        winnerProb = proba[mid + 1][r][winner];
    }

    long double p = 0;
    long double res = 0.0;

    for (int i = start; i <= finish; i++)
    {
        long double earning = dp(start, finish, i);
        long double thisScenario = winnerProb * proba[start][finish][i] * (long double)mat[winner][i] / 100.0;
        res = max(res, already + earning);
        p += thisScenario;
    }
    res += p * ((r - l + 1) >> 1);
    proba[l][r][winner] = p;
    return memo[l][r][winner] = res;
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
    n = (1 << n);
    rep(i, n) rep(j, n) cin >> mat[i][j];
    long double res = 0.0;
    rep(i, n) res = max(res, dp(0, n - 1, i));
    cout << fixed << setprecision(11) << res << endl;
}
