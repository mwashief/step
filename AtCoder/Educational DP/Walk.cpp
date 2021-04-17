/*
    Washief Hossain Mugdho
    17 April 2021
    AtCoder Educational DP Walk
*/

#ifndef DEBUG
#pragma GCC optimize("O2")
#endif

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pyes cout << "YES"
#define pno cout << "NO"
#define fastio ios_base::sync_with_stdio(0)
#define untie cin.tie(0)
#define rep(i, n) for (int i = 0; i < (n); (i)++)
#define repe(i, n) for (int i = 1; i <= (n); (i)++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; (i)--)
#define rrepe(i, n) for (int i = (n); i > 0; (i)--)
#define ms(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define gsz(v) ((int)(v).size())
#define MOD 1000000007
#define MAX 1000005

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
    ll k;
    cin >> n >> k;
    vector<vvi> precalc(n, vvi(n, vi(65, 0)));
    rep(i, n) rep(j, n) cin >> precalc[i][j][0];
    repe(power, 63) rep(from, n) rep(to, n) rep(middle, n) precalc[from][to][power] = (precalc[from][to][power] + 1LL * precalc[from][middle][power - 1] * precalc[middle][to][power - 1] % MOD) % MOD;

    vi positions;
    rrep(i, 61) if (k & (1LL << i)) positions.pb(i);

    vvi memo(n, vi(gsz(positions), -1));
    function<int(int, int)> dp = [&](int node, int state) {
        if (state >= gsz(positions))
            return 1;
        if (memo[node][state] != -1)
            return memo[node][state];
        int ans = 0;
        rep(i, n) ans = (ans + 1LL * precalc[node][i][positions[state]] * dp(i, state + 1) % MOD) % MOD;
        return memo[node][state] = ans;
    };

    int res = 0;
    rep(i, n) res = (res + dp(i, 0)) % MOD;
    cout << res << endl;
}
