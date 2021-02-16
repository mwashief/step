/*
    Washief Hossain Mugdho
    03 January 2021
    AtCoder abc187_e
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
int n, q;
vpii edges;
vvi adj;
vi p;
vl tree;

void dfs(int node, int parent)
{
    p[node] = parent;
    for (auto x : adj[node])
        if (x != parent)
            dfs(x, node);
}

void dfs2(int node, int parent, ll val)
{
    tree[node] += val;
    for (auto x : adj[node])
        if (x != parent)
            dfs2(x, node, tree[node]);
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
    cin >> n;
    tree = vl(n, 0);
    p = vi(n);
    adj = vvi(n, vi());
    rep(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
        edges.pb({x, y});
    }
    dfs(0, -1);
    cin >> q;
    rep(i, q)
    {
        int t, e, x, a, b;
        cin >> t >> e >> x;
        e--;
        a = edges[e].fr;
        b = edges[e].sc;
        if (t == 2)
        {
            a = edges[e].sc;
            b = edges[e].fr;
        }
        if (p[a] == b)
            tree[a] += x;
        else
        {
            tree[0] += (ll)x;
            tree[b] -= (ll)x;
        }
    }
    dfs2(0, -1, 0LL);
    rep(i, n) cout << tree[i] << endl;
}
