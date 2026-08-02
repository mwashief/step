/*
    Washief Hossain Mugdho
    16 April 2021
    Codeforces 1385 1385E
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
int n, m;
vvi adj;
vi order;
vi visited;

bool dfs(int node)
{
    visited[node] = 1;
    bool dag = 1;
    for (auto a : adj[node])
        if (visited[a] == 0)
            dag = dag & dfs(a);
        else if (visited[a] == 1)
            return 0;
    order.pb(node);
    visited[node] = 2;
    return dag;
}

inline void _()
{
    order.clear();
    cin >> n >> m;
    adj = vvi(n);
    visited = vi(n);
    vpii undirected;
    rep(i, m)
    {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        y--;
        if (t)
            adj[x].pb(y);
        else
            undirected.pb({x, y});
    }
    rep(i, n) if (visited[i] == 0 && !dfs(i))
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vi seq(n);
    rep(i, n) seq[order[i]] = i;
    rep(i, n) for (auto d : adj[i]) cout << i + 1 << " " << d + 1 << endl;
    for (auto d : undirected)
    {
        if (seq[d.fr] < seq[d.sc])
            swap(d.fr, d.sc);
        cout << d.fr + 1 << " " << d.sc + 1 << endl;
    }
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
