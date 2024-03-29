/*
    Washief Hossain Mugdho
    03 February 2021
    Codeforces 1472G
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
vvi adj;
vi d;
vi memo;

int dp(int node)
{
    if (memo[node] != -1)
        return memo[node];
    memo[node] = d[node];
    for (auto x : adj[node])
    {
        if (d[x] > d[node])
            memo[node] = min(memo[node], dp(x));
        else
            memo[node] = min(memo[node], d[x]);
    }
    return memo[node];
}

inline void _()
{
    cin >> n >> m;
    adj = vvi(n, vi());
    d = vi(n);
    memo = vi(n, -1);
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x - 1].pb(y - 1);
    }
    queue<pii> Q;
    Q.push({0, 0});
    vb visi(n);
    visi[0] = 1;
    while (!Q.empty())
    {
        int node = Q.front().fr;
        int dis = Q.front().sc;
        Q.pop();
        d[node] = dis;
        for (auto x : adj[node])
            if (!visi[x])
            {
                visi[x] = 1;
                Q.push({x, dis + 1});
            }
    }
    dp(0);
    rep(i, n) cout << memo[i] << " ";
    cout << endl;
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
    int __;
    cin >> __;
    while (__--)
        _();
}
