/*
    Washief Hossain Mugdho
    15 April 2021
    Codeforces 1388 1388D
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
int n;
vl a;
vi b, order;
vb visited;
vvi adj;

void dfs(int node)
{
    visited[node] = 1;
    for (auto a : adj[node])
        if (!visited[a])
            dfs(a);
    order.pb(node);
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
    a = vl(n);
    visited = vb(n);
    adj = vvi(n, vi());
    rep(i, n) cin >> a[i];
    rep(i, n)
    {
        int x;
        cin >> x;
        x--;
        b.pb(x);
        if (x != -2)
            adj[i].pb(x);
    }
    rep(i, n) if (!visited[i]) dfs(i);
    visited = vb(n);
    reverse(order.begin(), order.end());
    ll res = 0;
    vi ans;
    for (auto o : order)
    {
        if (a[o] < 0)
            continue;
        visited[o] = 1;
        ans.pb(o);
        res += a[o];
        if (b[o] != -2)
            a[b[o]] += a[o];
    }
    reverse(order.begin(), order.end());
    for (auto o : order)
    {
        if (visited[o])
            continue;
        ans.pb(o);
        res += a[o];
    }
    cout << res << endl;
    for (auto o : ans)
        cout << o + 1 << " ";
}