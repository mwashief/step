/*
    Washief Hossain Mugdho
    31 March 2021
    Codeforces 1245 1245E
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
int dir[] = {-1, 1};
int ss[] = {9, 0};
int a[10][10];
long double memo[10][10][2];
bool visited[10][10][2];

long double dp(int r, int c, int stair)
{
    if (r == 0 && c == 0)
        return 0.0;
    if (visited[r][c][stair])
        return memo[r][c][stair];
    visited[r][c][stair] = 1;

    int rr = r, cc = c + dir[rr & 1];
    int chal = 0;
    long double res = 0.0;
    rep(i, 6)
    {
        if (cc < 0 || cc > 9)
        {
            rr--;
            if (rr < 0)
                break;
            cc = ss[rr & 1];
        }
        res += dp(rr, cc, 0) / 6.0;
        cc += dir[rr & 1];
        chal++;
    }
    res++;
    res *= 6.0;
    res /= 1.0 * chal;
    if (a[r][c] && !stair)
        res = min(res, dp(r - a[r][c], c, 1));
    return memo[r][c][stair] = res;
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
    rep(i, 10) rep(j, 10) cin >> a[i][j];
    ms(visited, 0);
    long double ans = dp(9, 0, 1);
    cout << fixed << setprecision(10) << ans << endl;
}
