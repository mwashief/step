/*
    Washief Hossain Mugdho
    13 April 2021
    Codeforces 677E
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

class State
{
public:
    int two, three, dis;
    long double val;
    State()
    {
        two = 0;
        three = 0;
        dis = 0;
        val = 0.0;
    }
    State(int k)
    {
        two = 0;
        three = 0;
        if (k == 2)
            two = 1;
        else if (k == 3)
            three = 1;
        dis = 1;
        val = log2((long double)k);
    }

    State(const State &rhs)
    {
        this->two = rhs.two;
        this->three = rhs.three;
        this->dis = rhs.dis;
        this->val = rhs.val;
    }

    State operator=(const State &rhs)
    {
        this->two = rhs.two;
        this->three = rhs.three;
        this->dis = rhs.dis;
        this->val = rhs.val;
        return *this;
    }

    bool operator<(const State &rhs)
    {
        return this->val < rhs.val;
    }

    int getVal()
    {
        int res = 1;
        rep(i, two) res = 2LL * res % MOD;
        rep(i, three) res = 3LL * res % MOD;
        return res;
    }
};

State combine(State a, State b)
{
    a.dis += b.dis;
    a.val += b.val;
    a.two += b.two;
    a.three += b.three;
    return a;
}

State subtract(State a, State b)
{
    a.dis -= b.dis;
    a.val -= b.val;
    a.two -= b.two;
    a.three -= b.three;
    return a;
}

int n;
vvi mat;
vector<vvb> visited;
vector<vector<vector<State>>> memo;
State ans;

int dr[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dc[] = {1, -1, 0, 0, 1, -1, -1, 1};

State dp(int r, int c, int s)
{
    if (r < 0 || r >= n || c < 0 || c >= n)
        return State();
    if (visited[r][c][s])
        return memo[r][c][s];
    visited[r][c][s] = 1;
    if (mat[r][c] == 0)
        return memo[r][c][s] = State();
    State res(mat[r][c]);
    memo[r][c][s] = combine(res, dp(r + dr[s], c + dc[s], s));
    return memo[r][c][s];
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
    mat = vvi(n, vi(n));
    memo = vector<vector<vector<State>>>(n, vector<vector<State>>(n, vector<State>(8, State())));
    visited = vector<vvb>(n, vvb(n, vb(8, 0)));
    int zeros = 0;
    rep(i, n) rep(j, n)
    {
        char c;
        cin >> c;
        if (c == '0')
            zeros++;
        mat[i][j] = c - '0';
    }
    if (zeros == n * n)
    {
        cout << 0 << endl;
        return 0;
    }
    rep(i, n) rep(j, n) if (mat[i][j])
    {
        State now(mat[i][j]);
        vector<State> temp;
        rep(k, 4) temp.pb(dp(i + dr[k], j + dc[k], k));
        int d = INT32_MAX;
        rep(k, 4) d = min(d, temp[k].dis);
        rep(k, 4) temp[k] = subtract(temp[k], dp(i + (d + 1) * dr[k], j + (d + 1) * dc[k], k));
        State res = now;
        rep(k, 4) res = combine(res, temp[k]);
        if (ans < res)
            ans = res;

        temp.clear();
        rep(k, 4) temp.pb(dp(i + dr[k + 4], j + dc[k + 4], k + 4));
        d = INT32_MAX;
        rep(k, 4) d = min(d, temp[k].dis);
        rep(k, 4) temp[k] = subtract(temp[k], dp(i + (d + 1) * dr[k + 4], j + (d + 1) * dc[k + 4], k + 4));
        res = now;
        rep(k, 4) res = combine(res, temp[k]);
        if (ans < res)
            ans = res;
    }
    cout << ans.getVal() << endl;
}
