/*
    Washief Hossain Mugdho
    29 April 2021
    Codeforces 1498 1498F
*/

#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
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
#define a2z(x) (x).begin(), (x).end()
#define z2a(x) (x).rbegin(), (x).rend()
#define endl "\n"
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
int n, k, k2;
vvi adj, dmemo, umemo;
vi par, a;
vb visited;

void upDP(int node)
{
    if (visited[node])
        return;
    visited[node] = true;
    int parent = par[node];
    if (parent != node)
    {
        rep(i, k << 1)
            umemo[node][i] = dmemo[parent][(i - 1 + k2) % k2] ^ dmemo[node][(i - 2 + k2) % k2];
    }
    if (parent != 0)
    {
        upDP(parent);
        rep(i, k << 1) umemo[node][i] ^= umemo[parent][(i - 1 + k2) % k2];
    }
}

void downDP(int node, int parent)
{
    par[node] = parent;
    for (auto child : adj[node])
        if (child != parent)
        {
            downDP(child, node);
            rep(i, k2) dmemo[node][i] ^= dmemo[child][(i - 1 + k2) % k2];
        }

    dmemo[node][0] ^= a[node];
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
    cin >> n >> k;
    k2 = k << 1;
    adj = vvi(n);
    dmemo = vvi(n, vi(k << 1));
    umemo = vvi(n, vi(k << 1));
    par = vi(n);
    a = vi(n);
    visited = vb(n);
    rep(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    rep(i, n) cin >> a[i];
    downDP(0, 0);
    rep(i, n)
    {
        upDP(i);
        int res = 0;
        for (int j = k; j < k2; j++)
            res ^= dmemo[i][j] ^ umemo[i][j];
        if (res)
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    cout << endl;
}
